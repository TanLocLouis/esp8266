import speech_recognition as sr
import requests
import time

# === CONFIG ===
ESP_IP = "http://192.168.1.2"  # Replace with your ESP8266 IP
TRIGGER_WORDS = {
    "nigga": "/open",
    "nikka": "/open",
    "niger": "/open",
    "mika": "/open",
    "shut": "/open",
    "close": "/close"
}

def send_command(command_path):
    try:
        url = f"{ESP_IP}{command_path}"
        print(f"Sending command to ESP: {url}")
        response = requests.get(url, timeout=3)
        print("ESP response:", response.text)
    except requests.exceptions.RequestException as e:
        print("Error sending command:", e)

def listen_and_process():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("\n🎙️  Say 'open' or 'close' to control the servo...")
        r.adjust_for_ambient_noise(source)
        audio = r.listen(source)

    try:
        text = r.recognize_google(audio).lower()
        print("🗣️ You said:", text)

        for word, path in TRIGGER_WORDS.items():
            if word in text:
                print(f"✅ Trigger word detected: {word}")
                send_command(path)

                time.sleep(1) # Reload
                send_command("/close")
                return

        print("⚠️ No valid command word detected.")
    except sr.UnknownValueError:
        print("❌ Could not understand the audio.")
    except sr.RequestError as e:
        print("🔌 Speech Recognition API error:", e)

# === MAIN LOOP ===
while True:
    listen_and_process()
