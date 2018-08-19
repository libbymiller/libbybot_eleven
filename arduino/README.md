# Introduction

This is a very simple piece of code that expects commands over serial of the form:

    number degrees [p|n]

e.g. 

```1 90``` means turn servo 1 to absolute position of 90 degrees.

```1 10 p``` means turn servo 1 to 10 degrees in a positive direction.

```2 10 n``` means turn servo 1 to 10 degrees in a negative direction.

servo 1 is the base (rotating) and goes in arduino pin 3. Servo 2 is the "head" of the lamp (nodding, etc) and goes in arduino pin 4. Servos 3 and 4 are not used (I'm using them in later versions to give the shoulders more sass).

[server.py](../pi/server.py) uses groups of these commands passed through from the web browser via webRTC sockets and passes them via serial to the arduino.

# Installation

If you are using a Nano clone, you'll need 
[drivers](https://kig.re/2014/12/31/how-to-use-arduino-nano-mini-pro-with-CH340G-on-mac-osx-yosemite.html).

Note that you'll need to disconnect the serial connection from the Raspberry pi to flash the arduino (this catches me out every time). And then plug it back in again (this also catches me out every time).

