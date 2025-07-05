import subprocess
from datetime import datetime
import os
import time

# Prepare output
URL = "http://192.168.1.2/weather"
DATA_DIR = "data"
os.makedirs(DATA_DIR, exist_ok=True)
today = datetime.now().strftime("%m-%d-%Y")
filename = os.path.join(DATA_DIR, f"{today}.txt")

# Exact working command from manual test
cmd = f'curl --silent --http1.0 --no-keepalive --max-time 5 "{URL}"'

# Retry logic
while True:
    timestamp = datetime.now().strftime("[%H:%M:%S]")
    
    try:
        result = subprocess.run(
            cmd,
            shell=True,             # run through shell like manual test
            capture_output=True,
            text=True,
            check=True              # raise error if exit code != 0
        )

        # Write result to file
        with open(filename, "a") as f:
            f.write(f"{timestamp} {result.stdout.strip()}\n")

        print(f"✅ Weather data saved to {filename}")
        break

    except subprocess.CalledProcessError as e:
        print("stdout:", e.stdout.strip())
        print("stderr:", e.stderr.strip())

        # Write result to file
        with open(filename, "a") as f:
            f.write(f"{timestamp} {e.stdout.strip()}\n")

    time.sleep(20)
