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

For Proper Code Documentation: Task.c

### Main Function
```c
/**
 * @brief Takes input from user
 * Creates a string for the input
 * Create a root and call the function
 * which returns inorder notation
 *
 * @return int
 */
int main()
{
    // Declare clock variables to time the code
    clock_t start, end;

    //----------------------------------------------------------------------------------------------------------
    // To mark the start time of the program
    start = clock();
    // Give default values to all the letters so that it doesn't cause any confusion
    for (int i = 0; i < 30; i++)
    {
        letters[i] = 999;
    }
    end = clock();
    // To mark end time of the function
    double t1 = end - start;
    //----------------------------------------------------------------------------------------------------------

    //----------------------------------------------------------------------------------------------------------
    printf("----------------CS F214 Assignment----------------");
    printf("\nPlease use only small alphabets as atoms :)");
    //----------------------------------------------------------------------------------------------------------

    //----------------------------------------------------------------------------------------------------------
    // Take input as infix from user
    printf("\nEnter in Infix notation: ");
    char inputInfix[max];
    scanf("%s", inputInfix);
    //----------------------------------------------------------------------------------------------------------

    //----------------------------------------------------------------------------------------------------------
    // To mark the start time of the function
    start = clock();
    // Create a string for the input 2nd time
    char inputPrefix[max];
    inFixToPreFix(inputInfix, &inputPrefix);
    end = clock(); // To mark the end time of the function
    double t2 = end - start;
    //----------------------------------------------------------------------------------------------------------

    //----------------------------------------------------------------------------------------------------------
    // To mark the start time of the functions
    start = clock();
    // Create a root to store the structure
    TreeNode *root = NULL;
    // Call the function first time
    convertPreOrderToTree(&root, inputPrefix);
    // Printing notation in inorder
    printf("\nThe Expression in Inorder Notation is: ");
    printInOrder(root);
    // Calculating Height of Parse Tree
    printf("\nCalculating Height of Parse Tree");
    printf("\nThe height of the parse Tree is: ");
    printf("%d", maxHeightOfParseTree(root));
    end = clock(); // To mark end time of the functions
    double t3 = end - start;
    //----------------------------------------------------------------------------------------------------------

    printf("\nThe Truth Value given the above inputs is: %d", recursiveTruthEvaluator(root->val, root->left, root->right));

    //----------------------------------------------------------------------------------------------------------
    // Printing out time taken by the program
    double time_taken = ((double)((t1 + t2 + t3) / CLOCKS_PER_SEC));
    printf("\nProgram took %f seconds to execute \n", time_taken);
    //----------------------------------------------------------------------------------------------------------
}
```