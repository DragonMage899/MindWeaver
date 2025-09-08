![[Pasted image 20250317195004.png]]
want to pass into the vertex sahder

Manage memory we've allocated for this via the vertex object buffer (VBO)
- can store large number of vertices on gpu
- Allows us to send large batches of data at once to gpu and keep it there if enough memory is available  without having to send one vertex at a time
	- CPU -> GPU is quite slow, rather send directly to GPU
	- Once in GPU vertex shader has instant access to vertices 

`//vertex buffer object`
`unsigned int VBO; //ID unique to that buffer, can pass in ID when we want to use buffer`
`glGenBuffers(1, &VBO);`

OpenGL has many types of buffer objects
`vertexBuffer -> GL_ARRAY_BUFFER` type

Can bind several buffers at once so long as each one has a different type .
- Use glBindBuffer to bind newly created buffers 
![[Pasted image 20250317200556.png]]

After binding buffer call make (of type `GL_ARRAY_BUFFER`) will be used to configure current bound buffer

We can now make a call to glBufferData function that copies previously defined vertex data into buffer's memory
`glBufferData` -> copies user data into currently bound buffers

![[Pasted image 20250317201214.png]]
![[Pasted image 20250317201255.png]]

Vertex data is now within GPU memory manges by VBO
Next we want to create a vertex and fragment shader that actually
processes this data, so let’s start building those.

### Vertex Shader
Shader programmable by us.
Need to manually set it up

![[Pasted image 20250317202318.png]]
- Declare version and profile
- Declare input vertex attributes and vertex shader with in keyword
	- Only care about position in this case, see below for colour
- 3D -> vec3, input variable is called aPos
	- Set location of input via layout with location 0
![[Pasted image 20250317202831.png]]

To set output of vertex shader we have to assign position data to the predefined gl_Position variable which is a vec4.
At the end of main whatever we set gl_Position to will be used as output for the vertex shader. Since input is vec3 we need to cast to vec4 and set w component to 1.0f (explain why later)

Very simple vertex shader, no processing only forwarding


### Compiling a shader
![[Pasted image 20250317205450.png]]
![[Pasted image 20250317205832.png]]

### Fragment Shader
![[Pasted image 20250317205859.png]]
![[Pasted image 20250317205955.png]]
![[Pasted image 20250317210025.png]]

**A shader program object is the final linked version of multiple shaders combined.**

![[Pasted image 20250317210345.png]]
![[Pasted image 20250317210507.png]]
![[Pasted image 20250317210639.png]]
![[Pasted image 20250317211232.png]]
![[Pasted image 20250317211241.png]]
![[Pasted image 20250318114451.png]]
![[Pasted image 20250318114540.png]]
![[Pasted image 20250318114848.png]]
![[Pasted image 20250318114922.png]]
![[Pasted image 20250318120218.png]]
![[Pasted image 20250318120230.png]]
![[Pasted image 20250318120256.png]]
![[Pasted image 20250318120303.png]]

**Element Buffer Object**
Suppose we wanted to draw a rectangle (using two triangles)
![[Pasted image 20250318124845.png]]**Duplication of top left and bottom right, this duplication get's worse as the model grows**

![[Pasted image 20250318125519.png]]![[Pasted image 20250318125614.png]]
![[Pasted image 20250318125828.png]]
![[Pasted image 20250318130321.png]]
![[Pasted image 20250318130333.png]]
![[Pasted image 20250318130340.png]]
![[Pasted image 20250318130354.png]]
