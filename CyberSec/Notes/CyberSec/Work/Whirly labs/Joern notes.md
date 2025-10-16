https://docs.joern.io/installation/

For large code bases we may need to manually allocate heap memory
 `./joern -J-Xmx${N}G"`

# Quick Start
cli for static code analysis 
good for dealing with large amounts of code 


`
```c
// X42.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
  if (argc > 1 && strcmp(argv[1], "42") == 0) {
    fprintf(stderr, "It depends!\n");
    exit(42);
  }
  printf("What is the meaning of life?\n");
  exit(0);
}
````

Goal: Use joern to find determine if an inpute exists that always writes a string to STDERR

