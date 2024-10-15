

### PROJECT STRUCTURE ###
#########################

ENGINE contains all files related to the WORLDSPACE, CAMERA, and main Project stuff with a general application to all things within the scene.
	- WORLDSPACE contains the CAMERA and is a virtual emulation of 3D space.
	- CAMERA handles the view window and displays what would accurately be within eyesight expected for 3D view.
	- WORLDSPACE_DATATYPES holds useful data for worldspace related activities, such as an Object Container which handles Object storage.


OBJECTS holds data pertaining to individual components of the scene, such as particles, planes, etc. Independent simulation and rendering are done here.
	- PARTICLES are points with position, velocity, and radius.
		- they also have a boolean determining whether they are static or not, set to a base of false. If true, the particle will not be simulated, frozen in position.
	- OBJECT_DATATYPES holds data useful for all Objects in the scene, such as 3D Vectors.


#################### PLANS ####################
###############################################

 - Recompartilise Program to have a Graphics Engine and Physics Engine classes, seperate the Worldspace away from handling absolutely everything (important)
 - Obviously get the collision physics done.
 - 
 - 





#################### NOTES AND OTHER STUFF ####################
###############################################################


### HOW DOES WORLD SPACE WORK? ###
##################################

In a computer, WORLDSPACE is a digital representation of an enviroment - be it 2D, 3D, gas simulation volume, N-Body particle physics, etc. It is in essence an emulation of physical volume, although the actual accuracy
of said volume will not be accurate to real life physics - either due to simulation limitations, or the worldspace itself is not being used to gauge physics as a whole (rather, it can also be used in things like video
game enviroments, interesting visual experiments, etc).

A worldspace is NOT the same as the display window, a display window itself only shows a slice of the worldspace at a time - this is best examplified in the case of a game where the window can only display a portion of the games
level, the rest of the games level is still "there" within the worldspace, we just cannot observe it's entirety through the window.



### HOW DO WE DISPLAY THINGS? ###
#################################

Simple, we use a Camera.

Camera's in world space are effectively a point in space that faces in one direction, it possesses a viewing Distance from which it angles it's viewing frustum.
To calculate if a object (ie a particle) is within the camera's viewing frustrum, we calculate the distance between the camera and the origin point of an observed object.

If the object has a negative value, it is behind the camera and will not be shown. The viewing distance can also be cut into a near clip and far clip, preventing everything in front of the camera
from being shown. The clips are translated as the SFML window size, width and height, so it doesn't require any intermediate maths to adjust it.

To actually translate a point to the window, we take the viewing distance and particle distance from the camera and get:
/ distance between particle and view distance(pD) = Point distance - view distance
/ WPoint_X = pX * vD / pD
/ WPoint_Y = pY * vD / pD

NOTE: THIS IS ONLY FOR A STATIC CAMERA THAT CAN ONLY MOVE ALONG THE LENGTH OF ITS VIEW DISTANCE! Moving camera's are far more complicated and are typically done via creating an actual "Object" so that you can observe things
view a physical view fulstrum.

ANOTHER NOTE: We are using SFML which dictates screen size by xy pixel length, the X and Y are also dictated entirely as positives. Meanwhile, this camera system dictates that the center
of the screen is zero, while XY (or ZY, XZ, etc) can be positive or negative depending on what quarter of the screen a position lands on. This means we need to keep that in mind while drawing things to the SFML window.



### HOW DO WE MAKE SPHERES ADJUST PER PERSPECTIVE? ###
######################################################

SFML spheres aren't generated with perspective, we need to parse in the viewing distance between a point and adjust its radius by the product of something (TBD).










