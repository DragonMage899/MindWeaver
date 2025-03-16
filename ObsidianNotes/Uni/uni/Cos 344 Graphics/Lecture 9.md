Midpoint algo
case 1:
- Draw at some y level till a condition is met
- Jump to next level once reached
- Determines realisticness of line

![[Pasted image 20250310084232.png]]
f(...)
Is the midpoint (jumping point)

**Test question**
- Given pen and paper, apply algorithm
- Critique realisticness of line

**Barycentric**
- Finding pixels in a triangle

**Overlapping pixels of two triangles**
- Choose some off screen point and see which side of the triangle is facing that point, if point is on diagonal choose a different point
- Can be generalized to any amount of intersection

Z-buffer algo
- initial value = infinity 

Pre vertex
- Don't need to implement, bg stuff
- Shading occurs during vertex stage
- Far away stuff

Pre fragment shading
- information needs to be passed through the entire pipeline
- nearby stuff

Anti aliasing
- Add a bit of blurr to make lines more realistic
- ![[Pasted image 20250310091510.png]]