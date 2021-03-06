# libbybot_eleven

Eleventh incarnation of 
[libbybot](https://planb.nicecupoftea.org/2017/03/03/libbybot-presence-with-chromium-51-raspberry-pi-and-rtcmulticonnection-for-webrtc/), a cheapo, remotely-posable presence robot using [webRTC](https://en.wikipedia.org/wiki/WebRTC) and a Raspberry Pi, currently living in an IKEA lamp

Contains full instructions and code. 

<img src="https://libbymiller.files.wordpress.com/2017/07/image_uploaded_from_ios.jpg" width="500" alt="Libbybot 8"/>

The idea is that you run a headless browser on a Raspberry Pi in the lamp, and connect to it remotely via a laptop or phone using a browser (Chrome or Firefox).

You need to do the [server](/server) part of this first, then set up the [arduino](/arduino) and [pi](/pi). Construction instructions are in [doc](doc/)

## What you'll need:

 * Time: this takes a few hours at least even if you know what you are doing. It's not a quick project.
 * Raspberry Pi 3 (other versions don't have the oomph to run chromium and do video, though they can do audio, if you don't want to "see").
 * an official [Raspberry pi power cable](https://shop.pimoroni.com/products/raspberry-pi-universal-power-supply) - we're using a lot of amps! else you may get strange outages.
 * IKEA EXPRESSIVO lamp (discontinued, but most people have one at home, ask around). Or [this (thanks Barnoid!)](http://cpc.farnell.com/lloytron/l1101bk/lamp-desk/dp/LA04023) looks very similar.
 * [long (45cm) Raspberry Pi camera cable](https://shop.pimoroni.com/products/raspberry-pi-camera-cable)
 * [Raspberry Pi camera](https://shop.pimoroni.com/products/raspberry-pi-camera-module-v2-1-with-mount)
 * a [Sennheiser USB speaker / mic](http://www.exteradirect.co.uk/product/sennheiser/sp20-portable-speakerphone-usb-&-3.5mm/3258/)
 * 2 x 9g servos, small as you can get them ([e.g.](http://www.ebay.co.uk/itm/Mini-SG90-SG-90-Gear-9g-Micro-Servo-For-RC-Airplane-Helicopter-Car-Boat-Arduino/252297215595)). The blue type are the ones you need - the black ones are fractionally too long.
 * a [tiny breadboard](https://shop.pimoroni.com/products/colourful-mini-breadboard)
 * 6 x MM jumper cables 
 * 3 x MF jumper cables 
 * Arduino nano (e.g. a [clone](http://www.ebay.co.uk/itm/Mini-USB-Nano-V3-0-ATmega328P-CH340-5V-16MHz-SOLDERED-HEADS-Arduino-UK-/262738901345))
 * an old CD or a [custom laser cut shape](doc/laser_cut_base) - and 6 x 3mm diameter ball barings
 * little rubber feet ([e.g.](https://www.amazon.co.uk/Domed-Rubber-Buffers-Kitchen-Doors/dp/6040143746/ref=sr_1_1))
 * 1 thin small cable tie
 * two pieces of 2cm x 1cm x 3mm (or 1 x 5-6mm) plastic or something equally tough
 * two M2 plastic bolts

and

 * Something to cut holes in the lamp's plastic like a dremel (you can just about manage with a hacksaw and drill, but it's messy) plus suitable eye protection
 * a hacksaw
 * a phillip's head screwdriver
 * a gluegun
 * a vice
 * a pen
 * a tape measure

and, once you're up and running

 * a friendly helper in the remote place where you want to be, to plug the lamp in

The only really expensive thing is the speaker / mic. If you're going to use it seriously, this is the most important bit. I've tried a Jabra for this purpose but they are unreliable, I'm guessing they have heavier power 
requirements than the Sennheiser. The Sennheiser works really well - the best I've come across for this sort of thing.

Of course you don't have to use an IKEA ESPRESSIVO lamp. This project originally started off much more like a picture frame - you can see the pictures [here](https://planb.nicecupoftea.org/2017/03/03/libbybot-presence-with-chromium-51-raspberry-pi-and-rtcmulticonnection-for-webrtc/) - but it's hard to fit the speaker into some sort of sensible shape. My robot research has shown that showing my face to the participants of a teleconference is not necessary as long as I can hear, speak, see and move  a little (in that order).

More on how to actually fit it into the lamp is in [doc](doc/).
