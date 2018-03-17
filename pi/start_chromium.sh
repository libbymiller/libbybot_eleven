#!/bin/bash

myrandom=$RANDOM
echo $myrandom

# if you remove all the profile, you'll have to reenable the camera and mic in the browser
#rm -rf /home/pi/.config/chromium/

# this is for bad crashes, which leave a lock handing round
rm /home/pi/.config/chromium/SingletonLock

# run the server
sudo /home/pi/server.py &

sleep 1

# run the browser
/usr/bin/chromium-browser --kiosk --disable-infobars --disable-session-crashed-bubble --no-first-run --allow-running-insecure-content --allow-insecure-localhost https://yourserver:8443/libbybot/bot11.html#$myrandom &
