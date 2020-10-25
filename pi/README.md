# Introduction

The idea is that you run a headless browser on the pi, and connect to it 
via a laptop or phone using a browser. 

You'll need a [server](/server) to connect to first.

More on how to actually fit it into the lamp, including assembling everything, is in 
[doc](doc/).

# Installation

This is mostly a matter of making sure the audio and video drivers are 
in place, and then running chromium on boot, together with a simple 
python server for controlling the servos.

## Set up the Pi with Buster (not Buster-lite)

[Here are full instructions for burning an SD card](https://www.raspberrypi.org/documentation/installation/installing-images/) or use [Etcher](https://etcher.io).

When it's done, still with the SD card in the card reader (you may have to unplug the reader / plug it in again), do

    touch /Volumes/boot/ssh 

(This is on a Mac; other OS you need to figure out where `boot` is mounted and create an empty file)

[Add in your wifi network creds](https://www.raspberrypi.org/blog/page/2/?fish#another-update-raspbian) to /Volumes/boot/wpa_supplicant.conf:

    nano /Volumes/boot/wpa_supplicant.conf

contents (the country first line is important, though it doesn't have to be GB, obviously):

    country=GB
    ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
    update_config=1

    network={
       ssid="foo"
       psk="bar"
    }

or if you're going to move it around, you could [try this](https://planb.nicecupoftea.org/2015/12/04/raspberry-pi-create-an-access-point-for-easily-getting-limited-input-devices-on-wifi-chromecast-style/).

Eject the SD card and put it in a Pi3.

Log in, e.g. by using a screen and keyboard and mouse or by sharing your 
network over ethernet and sshing in, or sshing in over your network if 
you added the `wpa_supplicant.conf` credentials as above.

## Add audio and video drivers

    sudo nano /etc/modules

contents:

    i2c-dev
    snd-bcm2835
    bcm2835-v4l2

(bcm2835-v4l2 is the V4l2 video drivers for Chromium to pick up the camera; there used to be a [bug](https://stackoverflow.com/questions/25941171/how-to-get-gstreamer1-0-working-with-v4l2-raspicam-driver) but not any more)

## Enable USB audio

    sudo nano /boot/config.txt 

in contents

    #dtparam=audio=on ## comment this out

then

    sudo nano /lib/modprobe.d/aliases.conf

in contents

    #options snd-usb-audio index=-2 # comment this out

(I find USB audio on the linux / Pi very tricky and I'm not the only one. However, in 
recent Raspian versions USB audio seems to Just Work. The above is belt and braces. 
[More on linux 
audio](http://raspberrypi.stackexchange.com/questions/39928/unable-to-set-default-input-and-output-audio-device-on-raspberry-jessie).)

## Give the GPU more oomph

This is optional, but you'll get smoother video performance at the cost of the chip getting hotter...! ([more info](https://raspberrypi.stackexchange.com/a/1885)).

Edit config.txt

    sudo nano /boot/config.txt  

contents - add or edit:

    gpu_mem=192 

## Add autostart

    sudo nano /etc/xdg/lxsession/LXDE-pi/autostart

contents:

    @lxpanel --profile LXDE-pi
    @pcmanfm --desktop --profile LXDE-pi
    @xscreensaver -no-splash
    @xset s off
    @xset -dpms
    @xset s noblank
    #@v4l2-ctl --set-ctrl=rotate=270 # if you need to rotate the camera picture
    @/bin/bash /home/pi/start_chromium.sh

Add the files start_chromium and server.py from this directory into the pi 
homedirectory. Edit ```start_chromium.sh``` to refer to your server.

Make them executable:

    chmod a+x start_chromium.sh server.py

install the python server

    sudo pip install bottle

enable the camera and serial in ```interfacing options``` using

    sudo raspi-config

for serial, select 'no' for 'would you like a login shell to be accessible over 
serial?' and 'yes' to 'Would you like the serial port hardware to be enabled?'

Change the pi name and password

    sudo nano /etc/hostname
    sudo nano /etc/hosts
    passwd

## Assemble everything and test

Shutdown and unplug the pi, then - 

 * [connect the camera to the pi](https://www.raspberrypi.org/documentation/usage/camera/README.md)
 * connect the sennheiser to the pi
 * plug in the pi's power again

On your-server, check the logs of `server.js` and you'll see the number of the room 
it's connected to.

Connect to https://your-server:8443/remote.html#roomnumber on a laptop, 
in Chrome or Firefox. You should see whatever the Pi's camera is pointing at, 
and be able to hear too, and speak. 

Longer term, you need to figure out how to do notifications. There's a place in 
[server.js](/../server/server.js) where you can send a dm tweet or a slack notification 
for example.

More on how to actually fit it into the lamp, including adding the Arduino, is in 
[doc](doc/).



