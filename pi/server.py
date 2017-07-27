#!/usr/bin/python
from bottle import run, route, request, response
import subprocess
import serial
import sys
import time
import os

# http://stackoverflow.com/questions/10125881/send-a-message-from-javascript-running-in-a-browser-to-a-windows-batch-file
# e.g. curl --data 'command=left' -X POST http://localhost:8080/

 
GESTURE_NOBODY_HOME = [["2", "160"]]
GESTURE_SOMEBODY_HOME = [["2", "10"]]
GESTURE_HELLO = [["2","60"],["2","10"]]
GESTURE_LEAVING = [["2", "160"]]
GESTURE_LOOKING_ROUND = [["1", "60"],["1", "120"],["1", "90"]]
GESTURE_REVOLVE_ALL_LEFT = [["1", "180"]]
GESTURE_REVOLVE_ALL_RIGHT = [["1", "0"]]
GESTURE_A_BIT_RIGHT = [["1", "40", "p"]]
GESTURE_A_BIT_LEFT = [["1", "40", "n"]]

ser = serial.Serial('/dev/serial0', 9600)

@route('/', method=['OPTIONS', 'POST'])
def index():

    response.headers['Access-Control-Allow-Origin'] = '*'
    response.headers['Access-Control-Allow-Methods'] = 'PUT, GET, POST, DELETE, OPTIONS'
    response.headers['Access-Control-Allow-Headers'] = 'Origin, Accept, Content-Type, X-Requested-With, X-CSRF-Token'

    command = "none"

    if request.method == 'POST':
      command = request.POST['command']
      print command
      arduino_command = None
      if(command):

# used by the software mostly
        if(command == "gone"):
          arduino_command = GESTURE_NOBODY_HOME
        if(command == "arrived"):
          arduino_command = GESTURE_SOMEBODY_HOME

# used by the end user
        if(command == "hello"):
          arduino_command = GESTURE_HELLO
        if(command == "leaving"):
          arduino_command = GESTURE_LEAVING

        if(command == "left"):
          arduino_command = GESTURE_REVOLVE_ALL_LEFT
        if(command == "right"):
          arduino_command = GESTURE_REVOLVE_ALL_RIGHT


        if(command == "left_a_bit"):
          arduino_command = GESTURE_A_BIT_LEFT
        if(command == "right_a_bit"):
          arduino_command = GESTURE_A_BIT_RIGHT

# pass through

        if(command.startswith("1") or command.startswith("2")):
          arduino_command = [command.split(" ")]
          print(arduino_command)

# special for when the webrtc fails or for a manual stop

        if(command == "halt"):
          arduino_command = GESTURE_LEAVING
          ser.write(str(arduino_command)+"\n")
          time.sleep(5)
          result = os.system("sudo halt")
        if(command == "reboot"):
          arduino_command = GESTURE_LEAVING
          ser.write(str(arduino_command)+"\n")
          time.sleep(5)
          result = os.system("sudo reboot")

# each subarray is a command
# motor 1 is the base (rotate)
# motor 2 is the head (up / down)

        for ac in arduino_command: 
          print(" ".join(ac)+"\n")
          ser.write(" ".join(ac)+"\n")


    response.set_header('Access-Control-Allow-Origin', '*')
    result = "ok: "+command
    return result

run(host='localhost', port=8080, reloader=True)
