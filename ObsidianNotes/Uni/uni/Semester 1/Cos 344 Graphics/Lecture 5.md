17-2.1 don't go into much deta

Display buffer: 2d screen array

cycle refresh
- Don't write to buffer that's being displayed (back buffer)
- Screen tear: refresh rate doesn't match swap rate
- Once swapped back buffer needs to be cleaned (glClear)

wireframe