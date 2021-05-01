import pyttsx3
import speech_recognition as sr
import datetime
import webbrowser
import wikipedia
import os
import subprocess



engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
#print(voices[0].id)
engine.setProperty('voices',voices[0].id)

def speak(audio):
  engine.say(audio)
  engine.runAndWait()


def WishMe():
    hour = int(datetime.datetime.now().hour)
    if hour>=0 and hour<12:
        speak("Good Morning! Sir")

    elif hour>=12 and hour<18:
        speak("Good Afternoon! Sir")
    
    else:
        speak("Good Evening! Sir")

    speak("I am JARVIS. Please tell me, How may I help you ")
    
def takeCommand():
    #It takes microphone input from the user and returns the string output.

    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listerning...")
        r.pause_threshold = 1
        audio = r.listen(source)

    try:
        print("Recognizing...")
        query = r.recognize_google(audio,language='en-in')
        print(f"User said: {query}\n")

    except Exception as e:
        print(e)

        print("Say that again please...")
        return "None"
    return query

if __name__=="__main__":
     WishMe()
     while True:
        #if 1:
        query = takeCommand().lower()

     # Logic for executing tasks nased on query
        if 'wikipedia' in query:
            speak('Searching Wikipedia...')
            query = query.replace("wikipedia","")
            results = wikipedia.summary(query, sentences=2)
            speak("According to Wikipedia")
            print(results)
            speak(results)

        elif 'open google' in query:
            speak('Opening google, sir...')
            webbrowser.open("google.com")


        elif 'open water system' in query:
            speak('Yes sir, Opening Water Management System,Todays Water Analytic,  are as follows')
            webbrowser.open("https://thingspeak.com/channels/1376760/private_show")


        elif 'the time' in query:
            strTime = datetime.datetime.now().strftime("%H:%M:%S")
            speak(f"Sir, the time is {strTime}")
            print(strTime)


        elif 'thank you jarvis' in query:
            speak('Welcome, sir...')

 
        elif 'fine' in query or "good" in query:
            speak("It's good to know that your fine")
            
        elif "who are you" in query:
            speak("I am your virtual assistant sir")

        elif 'exit' in query:
            speak("Thanks for giving me your time")
            exit()   