**Raster Display**
- Show image as a rectangular array of pixels
- Mix different values of rgb to achieve multi colour 

Raster Image: 2d array of pixel values
- Problems occur with this if taken naively, for instance each display would need a specific array size
- Raster images are a device independent 2d array of pixel values 

Alternatives such as vectors exist
- store description of shapes, areas of colors etc
- no reference to any pixel 
- Store instructions for displaying image rather than pixels
- resolution independent
- Must be rasterized before rendering 
- Good for crispness / precision  / high res


# Images, Pixels and Geometry 
![[Pasted image 20250331131153.png]]
R: rectangular area
V: set of possible pixels (can be any dimensionality, 1 = brightness values only, 3 = rgb etc)
- LDR: integers to represent pixels
- HDR: floats to represent pixels

Suppose the amount of bits stored is less than the amount of bits captured
![[Pasted image 20250331133010.png]]

# RGB color
![[Pasted image 20250331134316.png]]
![[Pasted image 20250331134334.png]]
![[Pasted image 20250331134356.png]]

# Alpha Compositing 
![[Pasted image 20250331134429.png]]
![[Pasted image 20250331134442.png]]

![[Pasted image 20250331134451.png]]
![[Pasted image 20250331134511.png]]
![[Pasted image 20250331134526.png]]
![[Pasted image 20250331134539.png]]


![[Pasted image 20250331134558.png]]

![[Pasted image 20250331134614.png]]
