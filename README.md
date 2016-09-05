# Bobina
## Description

A funny robot made with 3D printer and Arduino board.
Using four servo motors, it can move in any direction.
You can use the Android app to control it, or make it autonomous with the Ultrasonic sensor

## Files to print

The original project is available on 
[here](http://www.thingiverse.com/thing:594761)
, and my modificated pieces are available 
[here](http://www.thingiverse.com/thing:1754679)


## Instalation
### Assembly 
1. Put all the servos in 90º(You can use the 'initial angles' source to do this)
2. Assembly the part as showed in these pictures [here]()
3. Plug the servo on correspondent pins in your Arduino board, as specified on this [file](https://github.com/eduardossampaio/Bobina/blob/master/source/arduino/bobina/Robot.h)
4. Plug the bluetooth module on your Arduino, as specified [here](http://2.bp.blogspot.com/-2GuNBsL-IWs/ViBRZs51f-I/AAAAAAAAAIE/ErpAQiemPNs/s1600/image005.png)
5. Adjust the initial angles of each motor modifying the this  [file](https://github.com/eduardossampaio/Bobina/blob/master/source/arduino/bobina/Robot.h)

### Android app
1. Import the android project in eclipse (plugin ADT is needed)
2. Build the project and install in your phone
3. Turn on your bobina robot(with bluetooth on)
4. Open bluetooth settings on your pair with the robot
5. Open the Android App and connect with the bluetooth module
6. Start playing.

