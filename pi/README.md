# Introduction

The idea is that you run a headless browser on the pi, and connect to it via a laptop or phone using a browser.

You need to do the server part of this first.

What you'll need:

 * Pi 3
 * right angled cable
 * IKEA lamp
 * long canera cable
 * raspi camera
 * 2 x 9g servos, small as you can get them
 * tiny breadboard
 * 2.3A USB plug
 * 3 x MM jumper cables
 * 6 x MF jumper cables 
 * a [Sennheiser USB speaker / mic](http://www.exteradirect.co.uk/product/sennheiser/sp20-portable-speakerphone-usb-&-3.5mm/3258/)
 * arduino nano (e.g. a clone)
 * a CD or a custom laser cut shape
 * Something to cut holes in the lamp's plastic like a dremel
 * a hacksaw
 * a phillip's head screwdriver
 * a USB mouse
 * maybe a USB keyboard
 * temporary use of an HDMI-compatible monitor or TV

The only really expensive thing is the speaker / mic. If you're going to 
use it seriously, this is the most important bit. I've tried a Jabra for 
this purpose but they are unreliable, guesing they have heavier power 
requirements then the Sennheiser.

Of course you don't have to use an IKEA ESPRESSIVO lamp. This project 
originally started off much more like a picture frame - you can see the 
pictures 
[here](https://www.flickr.com/photos/nicecupoftea/albums/72157677391353664) 
- but it's hard to fit in the speaker. My research has shown that 
showing my face to the participants of a teleconference is not necessary 
as long as I can hear, speak, see and move a little (in that order).

More on how to actually fit it into the lamp is in docs/.

# Installation

This is mostly a matter of making sure the audio and video drivers are 
in place, and then running chromium on boot, together with a simple 
python server for controlling the servos.

## set up the Pi with jessie (not Jessie-lite)

e.g. on a mac (here are full instructions)

Replace 'N' by the disk number you get in the first step.

    diskutil list
    diskutil unmountDisk /dev/diskN
    sudo dd bs=1m if=~/Downloads/2017-06-21-raspbian-jessie.img of=/dev/rdiskN

(optional, if you want to use ssh) - when it's done, do

    touch /Volumes/boot/ssh

(optional, [add in your wifi network creds](https://www.raspberrypi.org/blog/page/2/?fish#another-update-raspbian) to /Volumnes/boot/wpa_supplicant.conf:

    nano /Volumes/boot/wpa_supplicant.conf

contents:

     network={
       ssid="foo"
       psk="bar"
     }

or if you're going to move it around, you could [try this](https://planb.nicecupoftea.org/2015/12/04/raspberry-pi-create-an-access-point-for-easily-getting-limited-input-devices-on-wifi-chromecast-style/).

Eject the SD card and put it in a Pi3.

Log in, e.g. by using a screen and keyboard and mouse or by sharing your 
network over ethernet and sshing in, or sshing in over your network if 
you added the credentials beforehand.

Add audio andvideo drivers

    sudo nano /etc/modules

contents:

    i2c-dev
    snd-bcm2835
    bcm2835-v4l2

Add V4l2 video drivers (for Chromium to pick up the camera; this is the 
part that took me longest to find):

    sudo nano /etc/modprobe.d/bcm2835-v4l2.conf

contents:

    options bcm2835-v4l2 gst_v4l2src_is_broken=1

Enable USB audio

    sudo nano /boot/config.txt 

in contents

    #dtparam=audio=on ## comment this out

then

    sudo nano /lib/modprobe.d/aliases.conf

in contents

    #options snd-usb-audio index=-2 # comment this out

Add in a .asoundrc file

    sudo nano ~/.asoundrc

contents:

    defaults.pcm.card 0;
    defaults.ctl.card 0;

(I find USB audio on the pi very tricky and I'm not the only one. You 
can check this later with the USB speaker plugged in and do ```aplay 
-l```. See [more details](http://raspberrypi.stackexchange.com/questions/39928/unable-to-set-default-input-and-output-audio-device-on-raspberry-jessie).

Add autostart

    nano ~/.config/lxsession/LXDE-pi/autostart

contents:

    @lxpanel --profile LXDE-pi
    @pcmanfm --desktop --profile LXDE-pi
    @xscreensaver -no-splash
    @xset s off
    @xset -dpms
    @xset s noblank
    #@v4l2-ctl --set-ctrl=rotate=270 # if you need to rotate the camera picture
    @/bin/bash /home/pi/start_chromium.sh

Add the files start_chromium and server.py from this directory into the pi homedirectory. Edit start_chromium.sh to refer to your server.

    chmod a+x start_chromium.sh server.py

install the python server

    sudo pip install bottle

enable the camera and serial

    sudo raspi-config

enable in interfaces.

Change the pi name and password

    sudo nano /etc/hostname
    sudo nano /etc/hosts
    passwd

# Assemble everything

Shutdown and unplug the pi, then - 

 * [connect the camera to the pi](https://www.raspberrypi.org/documentation/usage/camera/README.md)
 * connect the sennheiser to the pi
 * connect the USB mouse to the pi
 * connect the pi to the HDMI screen
 * plug in the pi's power again

Hopefully it will boot fullscreen into the browser and request that you 
accept access to the the mic and camera. Allow it using the mouse.

Then connect to https://your-server:8443/remote11.html on a laptop, 
ideally in chrome. You should see whatever the camera is pointing at, 
and be able to hear too, and speak.



