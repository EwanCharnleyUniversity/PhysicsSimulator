
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

To the Reviewers
	- All faucets of the program are open for crtiqiue. I would greatly appreciate honesty on any issues such as bugs, bad coding practises, code smells, non-abstracted functions (when they can/should be), etc.

	- Guidance on what to prioritise for the project is also appreciated.

	- This all includes the README, especially the TODO section down below. If the plans appear to be too much or the priorities are skewed, please let me know.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


-== PROGRAM STRUCTURE =--

Physics
	- Handles program loop and directs Graphics when to render.

	- Contains Objects such as Particles


Graphics
	- Handles the Window rendering and Shader application.

	- Shaders are contained in a class that handles one Vertex and Fragment shader respectively.

	- Buffers is a class that contains a VAO, VBO, and EBO, and is used to bind vertex data to the Shaders.


----------------------------------------------------------------------------------------------------------------

--= KNOWN ISSUES =--

	- Currently the only model is a hard coded cube in 3D space, it rotates thanks to a model matrix transformation.

	- Code is rather hard to follow IMO.

	- Graphics folder should contain the Shaders and Buffers.


-----------------------------------------------------------------------------------------------------------------

--= TODO / PLANS =--

	- Get Inputs to work for the window, and use that to parse in basic camera movement.
		- Later change would be to make the camera able to change its worldspace rotation depending on the mouse.

	- Abstract the Buffer, main goal is to make it able to parse in outside data such as models or hard-coded vertex arrays/vector to load stuff, rather than use a hard-coded cube for testing.
		- Might split it up if it is necessary.

	- Move all code relating to OpenGL shader and Buffer loading into the Graphics Folder.
		- But not the shader files themselves, move them to a /resource folder on the same path-level as /src

	- Make the project easier to follow and documented.