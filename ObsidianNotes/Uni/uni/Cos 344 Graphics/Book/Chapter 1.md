
**Computer Graphics**
- Use of computers to create and manipulate images 

**Area**
- Modeling - Mathematical spec of a shape and appearance properties to be stored
- Rendering - Creation of shaded images from 3D models
- Animation - Illusion of motion through sequence of images

Related areas
VR, User interaction, 3D scanning, Computational photography etc.

**Major Applications**
- Video Games
- Cartoons
- VFX
- CAD/CAM (Computer aided design/manufacturing)
- Simulation
- Medical Imaging
- Information visualization

**Graphics API**
- Set of functions that perform basic operations such as drawing images and 3D surfaces into windows

**Primary API's**
- Graphics 
	- to draw
- UI
	- to control

**API paradigms**
- Integrated
	- STL of a language, e.g Java
- Library
	- OpenGL, Direct3D etc
	- can suffer from lack of portability if a portable library is not 

**Graphics pipeline**
- Special Hardware / Software sub system that efficiently draws 3D primitives in perspective
- Optimised for processing 3D triangles with shared vertices
- Basic Operations:
	- Map 3D vertex locations to 2D screen positions 
	- Shade triangles to look realistic
	- appear in back-to-front order
		- Use z buffer (brute force technique)
- Geometric operations 
	- Use a 4D space
		- 3 traditional 
		- 1 homogeneous
			- Helps with perspective viewing
	- Thus pipeline is built to process matrices and vectors 
- Speed of generation proportional to amt of triangles being drawn 
- Since interactivity > visual fidelity in most cases
	- Minimise amt of triangles
	- use LOD based on distance 
- 