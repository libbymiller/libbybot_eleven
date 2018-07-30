#!/bin/bash

myrandom=$RANDOM
echo $myrandom

# sometimes it helps to remove everything
#rm -rf /home/pi/.config/chromium/

# this is for bad crashes, which leave a lock handing round
rm /home/pi/.config/chromium/SingletonLock

# run the server
sudo /home/pi/server.py &

sleep 1

# run the browser
/usr/bin/chromium-browser --kiosk --use-fake-ui-for-media-stream --disable-infobars --disable-session-crashed-bubble --no-first-run --allow-running-insecure-content --allow-insecure-localhost https://yourserver:8443/libbybot/bot11.html#$myrandom &
