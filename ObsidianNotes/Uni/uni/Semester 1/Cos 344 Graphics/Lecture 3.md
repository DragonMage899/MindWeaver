### **Rendering**
- Producing an array from a set of objects

**Rendering Approaches**
- **Object-order rendering**
	- Object by Object, for each object find pixel and update
- **Image-Order rendering**
	- Pixel by Pixel, for each pixel find object/s and compute pixel value

### Ray Tracing
**Ray Tracer**
- For each pixel, Determine which **objects** are **seen by said pixel**
- -> object must intersect viewing ray
- calculate the color that the pixel needs to represent 

#### Viewing Ray
- Line from viewpoint in direction the pixel is looking in
- Viewing rays need to pass through translucent materials

Once an object is found, shading is applied to it's surface 

### Ray Tracer
1. Ray Generation 
	- Use camera geometry to compute origin and direction of viewing ray or each pixel
2. Ray Intersection
	- Find closest object intersecting viewing ray (not always first intersection)
3. Shading
	- Compute the pixel color based on results on intersection

![[Pasted image 20250217102530.png]]

## Perspective
- Goal is to map 3B objects into 2D palce
![[Pasted image 20250217103844.png]]
### Linear perspective
![[Pasted image 20250217103931.png]]

#### Types  of projections
### Parallel
All viewing rays from each pixel is parallel 
	![[Pasted image 20250217104118.png]]
![[Pasted image 20250217104153.png]]
![[Pasted image 20250217104232.png]]
- Maintains size and shape of object

#### Perspective
- All viewing rays have the same origin but possibly a different direction
![[Pasted image 20250217104419.png]]

Further away == smaller
Closer == larger

![[Pasted image 20250217104504.png]]


## Computing viewing rays
![[Pasted image 20250217104739.png]]
Bold -> Vectors
Normal -> Scalars

### Orthographic views
- Want to construct an image plane (parr projection)

**nx, ny  -> max row, cols (starting a 0)**

For oblique parr views
- Use d instead of w
- Since w is perpendicular (we don't want perpendicular for oblique)
- Need to specify direction (since it can't be calculated)
- It can't be assumed

### Perspective View
- All rays have the same origin (diff directions)
- Image plane is distance d away from e
- d - How far away is image plane from view
- Ray Direction defined by viewpoint and position on image plane 
![[Pasted image 20250217105931.png]]
All rays start at the same point for perspective

Multiply -d by w
 - Scale image plane by -d in w direction
 - i.e. moving camera away by d in -w direction

## Ray Sphere intersection
- t is the point of intersection (which we don't know for a given ray)
## Triangle intersection
- solve for  t, B, Y using crammer to solve system of linear eq

![[Pasted image 20250217110436.png]]


![[Pasted image 20250217110528.png]]


