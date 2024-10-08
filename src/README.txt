

### HOW DOES WORLD SPACE WORK? ###

worldspace is not SFML window space, SFML is a window handler and is soley used to display things to the computer in a user friendly way.
We create a Worldspace (which will be referred as WD) to actually represent 3D position and calculation.



### HOW DO WE DISPLAY THINGS? ###
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
SFML spheres aren't generated with perspective, we need to parse in the viewing distance between a point and adjust its radius by the product of something (TBD).