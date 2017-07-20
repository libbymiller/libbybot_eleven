# libbybot_eleven

Eleventh incarnation of 
[libbybot](https://planb.nicecupoftea.org/2017/03/03/libbybot-presence-with-chromium-51-raspberry-pi-and-rtcmulticonnection-for-webrtc/), 
a cheapo presence robot using webRTC and a Raspberry Pi, currently living 
in an IKEA lamp

Contains full instructions and code.

<img src="https://farm4.staticflickr.com/3936/33471118606_f3867f28b7_k.jpg" 
width="500" alt="Libbybot 8"/>

The idea is that you run a headless browser on a Raspberry Pi in the lamp, 
and connect to it via a laptop or phone using a browser.

You need to do the [server](/server) part of this first, then set up the 
[arduino](/arduino) and [pi](/pi). Construction instructions are in 
[docs](docs/)

## What you'll need:

 * Raspberry Pi 3 (other versions don't have the oomph to run chromium and do video, though they can do audio, if you don't want to "see").
 * right angled power cable - make sure you get the right way round ([e.g.](http://www.ebay.co.uk/itm/2m-USB-2-0-A-To-RIGHT-ANGLE-MICRO-B-Data-Charging-Cable-Lead-007244/191324559571))
 * IKEA EXPRESSIVO lamp (discontinued, but most people have one at hoem)
 * [long raspberry pi camera cable](https://shop.pimoroni.com/products/raspberry-pi-camera-cable)
 * [raspberry pi camera](https://shop.pimoroni.com/products/raspberry-pi-camera-module-v2-1-with-mount)
 * 2 x 9g servos, small as you can get them ([e.g.](http://www.ebay.co.uk/itm/Mini-SG90-SG-90-Gear-9g-Micro-Servo-For-RC-Airplane-Helicopter-Car-Boat-Arduino/252297215595))
 * a [tiny breadboard](https://shop.pimoroni.com/products/colourful-mini-breadboard)
 * 2.3A USB plug
 * 3 x MM jumper cables
 * 6 x MF jumper cables 
 * a [Sennheiser USB speaker / mic](http://www.exteradirect.co.uk/product/sennheiser/sp20-portable-speakerphone-usb-&-3.5mm/3258/)
 * arduino nano (e.g. a [clone](http://www.ebay.co.uk/itm/Mini-USB-Nano-V3-0-ATmega328P-CH340-5V-16MHz-SOLDERED-HEADS-Arduino-UK-/262738901345))
 * an old CD or a custom laser cut shape
 * little rubber feet
 * a thin small cable tie
 * a 2cm x 1cm x 3mm (or 5mm) piee of plastic or something equally tough

and

 * Something to cut holes in the lamp's plastic like a dremel
 * a hacksaw
 * a phillip's head screwdriver
 * a gluegun
 * a USB mouse
 * maybe a USB keyboard
 * temporary use of an HDMI-compatible monitor or TV

The only really expensive thing is the speaker / mic. If you're going to 
use it seriously, this is the most important bit. I've tried a Jabra for 
this purpose but they are unreliable, I'm guessing they have heavier power 
requirements than the Sennheiser.

Of course you don't have to use an IKEA ESPRESSIVO lamp. This project 
originally started off much more like a picture frame - you can see the 
pictures 
[here](https://www.flickr.com/photos/nicecupoftea/albums/72157677391353664), 
but it's hard to fit the speaker nto some sort of sensible shape. My 
research has shown that showing my face to the participants of a 
teleconference is not necessary as long as I can hear, speak, see and move 
a little (in that order).

More on how to actually fit it into the lamp is in [docs](docs/).
