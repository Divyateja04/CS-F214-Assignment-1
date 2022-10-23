## Task 0: Initializing all the constants and libraries
### Importing libraries for the Code
```c
#include <stdio.h>  // Using for printf, scanf etc.
#include <stdlib.h> // For malloc, calloc
#include <string.h> // Only for length of the string
#include <ctype.h> // Used for isalpha function
#include <time.h>   // Used for time functions
```

### Define a constant to take care of max limit of input
```c
#define max 100000
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

### Helper Function: To Create an Array as an alternate to using maps
```c
int letters[30];

int returnValueForLetter(char letter)
{
    if (letter >= 'a' && letter <= 'z')
    {
        int letterNum = (int) letter - 97;

        if(letters[letterNum] == 999){
            printf("\nEnter value for letter %c: ", letter);
            int temp;
            scanf("%d", &temp);
            letters[letterNum] = temp;
        }

        return letters[letterNum];
    }
}
```

For Proper Code Documentation: [Click Here](_task_8c.html)