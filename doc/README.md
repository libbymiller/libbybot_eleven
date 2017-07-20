# Introduction

This is a bit complicated, but fun!

The idea is to hollow out the base to fit a Pi and and Arduino in it, and 
fit tiny servos to the top part (the 'head') and the base.

## Modify the case

Take your EXPRESSIVIO lamp, making sure it's unplugged from the mains 
obviously, unscrew the base and remove the transformer and related 
pieces, toegther with the power cable.

Remove the glass plate from the top, the bulb and any bits of wires 
connected to it.

Snap off the inside segments of the base to make as much room as you can.

Carefully saw the backs off the top arial covers. But don't saw off too much....

Saw or dremel a hole in the back of the base. This needs to be wide and 
deep enough to get a USB cable and a wifi camera cable into (it's also 
sometimes useful to be able to get the Ethernet cable in too if possible).

Dremel two holes in the centre of the flat base panel such that the servo 
exactly fits. 

## Connect the top servo

This is extra fiddly.

Make sure your servo is at its minimal point, e.g.

 * flash the arduino with the code in [arduino](/arduino)
 * connect the servo to 5V, GND and D3 (orange)
 * in the serial part of the arduino IDE type "1 0" and "1 180" to check that the servo is going from min to max in the right direction

Move the lamp so its head is as far bowed as it will go.

Replace the right hand screw at the top of the lamp with a servo and a 
screw through its spindle (you'll need to find a screw that's a bit longer 
than the usual one). Cable tie the servo's white plastic bit to the 
downward arial. Loosen the other screw so it is mobile.

Glue the flat plastic piece between the servo and the bottom of the lamp top.

Test the servo again

## Connect the bottom servo

 * connect the servo to 5V, GND and D4 (orange)
 * Figure out where 90 degrees is (using ("2 90") in serial)

Place that point at the front of the lamp, altering the white plastic part 
if need be. Screw in the white plastic part to the spindle.

Wedge the servo into the holes you made, gluegunning it in as well.

Test the servo again.

## Connect the arduino and the Pi

We're using a serial connection to save space.

You should have the top servo connected to pin D3 and the other to pin D4. 
Connect the pi's RX to ....@@

Stick the breadboard to the back of the Pi.

## Add the camera

Carefully make a slit in the aluminum case at the top and thread the extra 
long camera cable through it. Connect and position the camera, screwing it 
(using plastic screws if you do) or glueing it into place.

Feed the other end into the slot you made in the base and attach it to the 
pi (making sure the pi is unplugged and that you're connecting it the right 
way round.)

## Connect everything together

This is quite a wedge and it's why you need to get the right angled power 
cable and the smallest 9g servo you can find.

Basically the pi goes at the bottom at an angle with the brreadboard with 
its arduino on top of it. It needs to be placed at an angle so that the USB 
port is accessble through the slot, and so that there's room for the servo. 
Connect the power cable and feed it through the gap in the back. Replace 
the bottom plate - you may need to twist it slightly to get it on its 
rails. Screw it on. Glue the white part to the CD base and add rubber feet.

If you have laser cut the base components in the 
[laser_cut_base](laser_cut_base/) directory, glue the white part of the 
servo to base 1, glue base 2 to base 1, put the ball bearings in the holes 
and attach the two parts of teh servo together, screwing them in.

If all is well, you're ready to go. Plug it in!

