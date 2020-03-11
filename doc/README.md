# Introduction

Allow a few hours for this.

<a href="images/all_components.JPG"><img src="images/all_components.JPG" width="200px" /></a>

The idea is to hollow out the base to fit a Pi and and Arduino in it, and fit tiny servos to the top part (the 'head') and the base.

## Modify the case

Take your EXPRESSIVIO lamp, making sure it is unplugged from the mains, obviously, unscrew the base and remove and discard the transformer and related pieces, together with the power cable.

<a href="images/lamp.JPG"><img src="images/lamp.JPG" width="200px" /></a>

Remove the glass plate from the top, and the bulb and any bits of wires connected to it.

With pliers, snap off the inside segments of both parts of the base to make as much room as you can. 

<a href="images/snap_off1.JPG"><img src="images/snap_off1.JPG" width="200px" /></a><a href="images/snap_off1.JPG"><img src="images/snap_off1.JPG" width="200px" /></a>

Carefully saw the backs off the top ariel covers. Don't saw off too much - just up to the curved point to make a straight line, and then saw the corner off the inside of each one (see pictures)

<a href="images/ariel_saw1.JPG"><img src="images/ariel_saw1.JPG" width="200px" /></a><a href="images/ariel_saw2.JPG"><img src="images/ariel_saw2.JPG" width="200px" /></a><a href="images/ariel_saw3.JPG"><img src="images/ariel_saw3.JPG" width="200px" /></a>

Saw or dremel a hole in the back of the base. This needs to be wide and deep enough to get a USB cable and a wifi camera cable into (it's also sometimes useful to be able to get the Ethernet cable in too if possible). About 1cm x 4cm half way between the bottoms of the ariels and the rim of the base will do the job (see picture).

<a href="images/usb_hole1.JPG"><img src="images/usb_hole1.JPG" width="200px" /></a><a href="images/usb_hole2.JPG"><img src="images/usb_hole2.JPG" width="200px" /></a>

Dremel or drill two holes in the centre of the flat base panel such that the servo exactly fits. 

<a href="images/servo_hole.JPG"><img src="images/servo_hole.JPG" width="200px" /></a>

You'll also need to saw a small wedge out of the base to fit the power supply cable in. It's easier to do this at the end - see below.

## Connect the top servo

 * flash the arduino with the code in [arduino](/arduino)
 * push on the servo's one-sided horn (the plastic bit that you attach to the motor itself) - but don't screw it on yet
 * connect the servo to 5V (red), GND (brown or black) and D4 (orange)

Hold the servo with the horn facing you.

In the serial part of the arduino IDE, type "2 10". This is the lowest point for the 'head'. Re-position the horn if need be so it's parallel to the body of the servo.
 
<a href="images/parallel_to_servo_body.JPG"><img src="images/parallel_to_servo_body.JPG" width="200px"  /></a>

Now type "2 60" in the Arduino IDE. This is the highest point of the head. Holding the horn with it facing you, the body of the servo should turn clockwise by 50 degrees. Type "2 10" again to get it back to its starting position.

Now reassemble and position the lamp:
 * tighten the ariel's bottom screws as tight as they go
 * move the lamp so its head is as far bowed as it will go.

<a href="images/head_bowed.JPG"><img src="images/head_bowed.JPG" width="200px"  /></a>

Replace the right hand screw at the top of the lamp with a servo and a screw through its spindle (you'll need to find a screw that's a bit longer than the usual one). Cable-tie the servo's horn to the downward ariel. Loosen the other screw so it is mobile.

<a href="images/head_servo_connect.JPG"><img src="images/head_servo_connect.JPG" width="200px"  /></a><a href="images/fit_head_servo.JPG"><img src="images/fit_head_servo.JPG" width="200px"  /></a><a href="fit_head_servo2.JPG"><img src="images/fit_head_servo2.JPG" width="200px"  /></a>

Glue-gun one or two of the flat plastic pieces between the servo and the bottom of the lamp top (how many you need depends a bit on your servo's size and how much plastic you took off the lamp).

<a href="images/fit_plastic_head.JPG"><img src="images/fit_plastic_head.JPG" width="200px"  /></a>
<a href="images/fitted_head.JPG"><img src="images/fitted_head.JPG" width="200px"  /></a>

Test the servo again.

## Connect the bottom servo

 * connect the servo to 5V, GND and D3 (orange)
 * Figure out where 90 degrees is (using ("1 90") in serial)

Place that point at the front of the lamp.

Wedge the servo into the holes you made, glue-gunning it in as well.

<a href="images/base_servo.JPG"><img src="images/base_servo.JPG" width="200px"  /></a>

When the glue has dried, test the servo again (e.g '1 10' '1 90' '1 170').

## Connect the arduino and the Pi

We're using a serial connection to save space.

On the Arduino you should have the top servo connected to pin D4 and the other to pin D3.

Connect:
 * 5v on Pi to 5v on the arduino (e.g. [GPIO physical numbering](https://www.raspberrypi.org/documentation/usage/gpio/) 2 or 4)
 * ground on the Pi to ground on the Arduino (e.g. GPIO physical numbering 6, 9 etc)
 * Pi's TDX (GPIO physical numbering pin 8) to Arduino's RX

<a href="images/pi_arduino.jpg"><img src="images/pi_arduino.jpg" width="200px"/></a><a href="images/pi_arduino2.JPG"><img src="images/pi_arduino2.JPG" width="200px"/></a>

Normally you'd [need a voltage divider](https://oscarliang.com/raspberry-pi-and-arduino-connected-serial-gpio/) 
to do this serial communication, but because we're only going one way - from the 
Pi to the Arduino - we get away with it.

Stick or rest the breadboard to the back of the Pi.

<a href="images/arduino_pi_stick.JPG"><img src="images/arduino_pi_stick.JPG" width="200px"/></a>

## Add the camera

Carefully widen the slit in the aluminum case at the bottom and thread the extra long camera cable through it. Connect and position the camera, screwing it (using plastic screws if you do) or glueing it into place.

<a href="images/thread_camera.JPG"><img src="images/thread_camera.JPG" width="200px"/></a>
<a href="images/thread_camera2.JPG"><img src="images/thread_camera2.JPG" width="200px"/></a>
<a href="images/thread_camera3.JPG"><img src="images/thread_camera3.JPG" width="200px"/></a>

Feed the other end into the slot you made in the base and attach it to the Pi (making sure the Pi is unplugged and that you're connecting it the [right way round](https://thepihut.com/blogs/raspberry-pi-tutorials/16021420-how-to-install-use-the-raspberry-pi-camera).) 

<a href="images/camera_base.JPG"><img src="images/camera_base.JPG" width="200px"/>


## Connect everything together

This is quite a wedge and it's why you need the smallest 9g servo you can find.

Basically the Pi goes in the bottom at an angle with the breadboard underneath the Pi. It needs to be placed at a downward angle so that the USB port is accessble through the slot, and so that there's room for the servo and the servo isn't squishing the camera cable.

<a href="images/asssemble.JPG"><img src="images/asssemble.JPG" width="200px" /></a>

First, make sure you've programmed the Arduino and got the Pi on the network you want to use it on, and that you've connected the Arduino via serial to the Pi (see above). You can't reprogramme the Arduino once it's in because it can't be programmed with the serial attached.

Connect the power cable to the Pi, and, making sure you have the lamp base the right way round (there's a notch at the back) carefully mark and saw a wedge out of the base for it to fit. It must not be forced or bend! You may also need to saw off the top of one of the base plate's screw casings (make sure you get the right one).

<a href="images/power_hole2.JPG"><img src="images/power_hole2.JPG" width="200px" /><a href="images/power_hole.JPG"><img src="images/power_hole.JPG" width="200px" /></a><a href="images/saw_a_notch.jpg"><img src="images/saw_a_notch.jpg" width="200px"/></a><img src="images/saw_the_screw_casing.jpg" width="300px"/></a><img src="images/fit_the_psu.jpg" width="300px"/></a>

Connect the Sennheiser through the slot to the USB port.

This is a good time to test everything works - plug it in and check the server for messages about the url to use and load the url in Chrome. 

If all is well, replace the bottom plate - you may need to twist it slightly to get it on its rails. Screw it on, omitting the screw near where you cut the notch. 

If you have laser-cut the base components in the [laser_cut_base](laser_cut_base/) directory, glue the servo horn to base 1 with the notch facing through the hole, glue base 2 to base 1, put the ball bearings in the holes and attach the 
two parts of the servo together, screwing them in. Otherwise, glue the servo horn part to the CD base and add rubber feet.

<a href="images/base_plate.JPG"><img src="images/base_plate.JPG" width="200px" /></a>

If all is well, you're ready to go. Plug it in!

