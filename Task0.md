## Task 0: Initializing all the constants and libraries
### Importing libraries for the Code
```c
#include <stdio.h>  // Using for printf, scanf etc.
#include <stdlib.h> // For malloc, calloc
#include <string.h> // Only for length of the string
#include <ctype.h> // Used for isalpha function
```

### Define a constant to take care of max limit of input
```c
#define max 100
```

### Creating a structure with left and right leaves
```c
typedef struct TreeNode
{
    char val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
```

### Helper Function: max() A function to find the max of 2 numbers
```c
int calcMax(int a, int b) { return a > b ? a : b; }
```