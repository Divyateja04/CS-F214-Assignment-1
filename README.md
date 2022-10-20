# Code Analysis

- [Code Analysis](#code-analysis)
  - [Members](#members)
  - [Task 0: Initializing all the constants and libraries](#task-0-initializing-all-the-constants-and-libraries)
    - [Importing libraries for the Code](#importing-libraries-for-the-code)
    - [Define a constant to take care of max limit of input](#define-a-constant-to-take-care-of-max-limit-of-input)
    - [Creating a structure with left and right leaves](#creating-a-structure-with-left-and-right-leaves)
    - [Helper Function: max() A function to find the max of 2 numbers](#helper-function-max-a-function-to-find-the-max-of-2-numbers)
  - [Task 1: To convert infix to preorder](#task-1-to-convert-infix-to-preorder)
    - [Create a stack to keep track of operators](#create-a-stack-to-keep-track-of-operators)
    - [Function to convert Infix to Prefix](#function-to-convert-infix-to-prefix)
  - [Task 2: To convert prefix to tree](#task-2-to-convert-prefix-to-tree)
  - [Task 3: Function to traverse through the tree in order](#task-3-function-to-traverse-through-the-tree-in-order)
  - [Task 4: Height of the Parse Tree](#task-4-height-of-the-parse-tree)
  - [Task 5: Evaluating the truth value of propositional logic formula in a bottoms up fashion](#task-5-evaluating-the-truth-value-of-propositional-logic-formula-in-a-bottoms-up-fashion)
  - [Task 6](#task-6)
  - [Running the Code](#running-the-code)
  - [Basic Git Commands you might want to know to push onto this repository](#basic-git-commands-you-might-want-to-know-to-push-onto-this-repository)

## Members
- Divyateja Pasupuleti 2021A7PS0075H
- Kumarasamy Chelliah 2021A7PS0096H
- Harsh Rachalwar 2021A7PS0200H
- Manan Gupta 2021A7PS2091H
  
---

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

## Task 1: To convert infix to preorder
- First we make the helper functions as well
- Make a if-else function for precedence of operators
```c
int priority(char op)
{
    if (op == '(')
        return 1;
    if (op == '~')
        return 2;
    if (op == '+')
        return 3;
    if (op == '*')
        return 4;
    if (op == '>')
        return 4;
    return 0;
}
```

### Create a stack to keep track of operators
```c
char stack[max];
int top = -1;

// Function to push onto stack
void stackPush(char i)
{
    stack[++top] = i;
}

// Function to pop from the stack, Exception Case where we might have an empty stack
char stackPop()
{
    if (top == -1)
    {
        printf("Empty Stack");
    }
    else
        return stack[top--];
}

// A function to check if stack is empty or not
int stackIsEmpty()
{
    return top == -1;
}
```

### Function to convert Infix to Prefix
    Key Rule is We cannot have a lower precedence operator on top of a higher precedence operator
    Also we cannot have 2 same precedence operators together
    So we have to keep popping and adding into output
    If we have a closing bracket we have to pop
    But again through this method we get Postfix 
    so we reverse the string inorder to get the reverse of preorder notation
    First we replace ( with ) and ) with (
    And in the end we reverse again
```c
void inFixToPreFix(char *input)
{
    // Create a Variable to store the output
    char output[max];
    int outputCounter = 0;
 
    //Reversing input Step1: Exchange Brackets
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == '(')
            input[i] = ')';
        else if (input[i] == ')')
            input[i] = '(';
    }

    // Here we are reversing full string
    for (int i = 0; i < strlen(input) / 2; i++)
    {
        char tempChar = input[i];
        input[i] = input[strlen(input) - i - 1];
        input[strlen(input) - i - 1] = tempChar;
    }

    // Take a temporary variable to the first character of the input
    char temp;
    int t = 0;

    // Make a loop that goes through full input
    while ((temp = input[t++]) != '\0')
    {
        // Check if the character is operator or operand
        if (!isalpha(temp))
        {
            // Means it's an operator
            // Check if the top of stack has less or equal priority
            if (top != -1)
            {
                if (temp == ')')
                {
                    // We should check the case where we have a closing bracket coming
                    // Incases like this we have to pop until stack pops '('
                    char currentOperator;
                    while ((currentOperator = stackPop()) != '(' && !stackIsEmpty())
                    {
                        output[outputCounter++] = currentOperator;
                    }
                }
                else if (temp == '(')
                    stackPush('(');
                // Even though we aren't actually considering ( for pushing
                // it matters for the next one coming on to the stack
                else if (priority(stack[top]) > priority(temp))
                {
                    // Basically means priority of element on stack is higher
                    // Pop the top of the stack and add it to the output
                    output[outputCounter++] = stackPop();
                    stackPush(temp);
                }
                else
                {
                    // Here it means priority of element on stack is lower then the incoming one
                    stackPush(temp);
                }
            }
            else
            {
                // Just push it on to the stack
                stackPush(temp);
            }
        }
        else
        {
            // Means it's an operand i.e. Letter
            // Just push it on to the output
            output[outputCounter++] = temp;
        }
    }

    // If there are still operators in the stack, they should be considered as well
    while (top != -1)
    {
        output[outputCounter++] = stackPop();
    }

    printf("Output in PreOrder Notation: ");
    for (int i = outputCounter - 1; i >= 0; i--)
    {
        printf("%c", output[i]);
    }
}
```

## Task 2: To convert prefix to tree
- We observe that from the prefix notation, we can directly get tree
- If we observe, it starts with an operator and goes on until it gets another operator
- Let us try if we can get tree from here
- References : https://www.geeksforgeeks.org/building-expression-tree-from-prefix-expression/

```c
char *convertPreOrderToTree(TreeNode **root, char *start)
{
    // Print the starting characters to check the flow of the code
    // printf("\nCurrent Character %c: ", *start);
    // If Character is \0 return \0
    if (*start == '\0')
        return '\0';

    // Start an infinite loop to go through all the letters
    while (1)
    {
        char *currentLocation = NULL;
        if (*root == NULL)
        {
            // Print statement to check how many nodes are being created
            printf("\nNode doesn't exist, creating new Node");
            // Create a new TreeNode to store these variables
            // Initialize left and right to null initially
            TreeNode *newTreeNode = (TreeNode *)malloc(sizeof(TreeNode));
            // Initialize it's value to the character sent
            newTreeNode->val = *start;
            // Initialize left and right subtrees to NULL
            newTreeNode->left = NULL;
            newTreeNode->right = NULL;
            // Replace root with the newly created TreeNode
            *root = newTreeNode;
        }
        else
        {
            if (isalpha(*start))
            {
                // Check if it's an alphabet, if it is return it directly
                return start;
            }
            if (*start == '~')
            {
                // If the operator is negation
                // We should not go left but rather only go right
                // So we directly go right instead of considering left
                currentLocation = convertPreOrderToTree(&(*root)->right, start + 1);
                return currentLocation;
            }
            // Start with the left subtree
            currentLocation = convertPreOrderToTree(&(*root)->left, start + 1);
            // Start with the right subtree
            currentLocation = convertPreOrderToTree(&(*root)->right, currentLocation + 1);
            return currentLocation;
        }
    }
}
```


## Task 3: Function to traverse through the tree in order
- We know that in order means first
- the pointer goes to the left node, then prints the
- current node and then goes to the right node again
- using simple recursion we get the following function
- Make a Global Variable to store the number of alphabets
- We are making this because we need
- to create an array of inputs and take from user

```c
int noOfCharacters = 0;

void printInOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    // A new statement to figure out the number of characters
    if (isalpha(root->val))
        noOfCharacters++;
    // Goes to the left sub tree
    printInOrder(root->left);
    // Prints current value
    printf("%c", root->val);
    // Goes to the right sub tree
    printInOrder(root->right);
}
```
## Task 4: Height of the Parse Tree 
```c
/**
 * @brief We need to find max height of tree. We can use Depth First Search for this,
 *  i.e. we keep traversing lower into the tree until we find an end and
 *  we take max of this
 *  For example, let's say we have
 *      4
 *    3   5
 *   2     6
 *  1
 *  Here we start from 4, then we say that height is max(leftSubTreeHeight, rightSubTreeHeight) + 1
 *  That extra 1 due to the current node itself
 *  When we go to the left node, we get that it is max(leftSubTreeHeight, rightSubTreeHeight) + 1 again
 * 
 * @param root 
 * @return int 
 */
int maxHeightOfParseTree(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int leftSubTreeHeight = maxHeightOfParseTree(root->left);
    int rightSubTreeHeight = maxHeightOfParseTree(root->right);
    return calcMax(leftSubTreeHeight, rightSubTreeHeight) + 1;
}
```

## Task 5: Evaluating the truth value of propositional logic formula in a bottoms up fashion

```c
int recursiveTruthEvaluator(char operation, TreeNode *left, TreeNode *right)
{
    // initializing variables for left sub tree and right sub tree
    // We initialize it to 999 just so that it doesn't mess up by taking initial
    // values as 0
    int leftVal = 999, rightVal = 999;

    if (left != NULL && operation != '~')
    {
        // If left is not alphabet call the function recursively
        if (!isalpha(left->val))
        {
            leftVal = recursiveTruthEvaluator(left->val, left->left, left->right);
        }
    }

    if (right != NULL)
    {
        // If right is not alphabet call the function recursively
        if (!isalpha(right->val))
        {
            rightVal = recursiveTruthEvaluator(right->val, right->left, right->right);
        }
    }

    // If Operation is ~ then we won't have left root
    //  So we don't take left root
    if (operation != '~')
    {
        if (leftVal != 0 && leftVal != 1)
        {
            printf("\nEnter Truth Value for left branch %c: ", left->val);
            scanf("%d", &leftVal);
        }
    }

    if (rightVal != 0 && rightVal != 1)
    {
        printf("\nEnter Truth Value for right branch %c: ", right->val);
        scanf("%d", &rightVal);
    }

    // if both are alphabets, do the operation
    // Switch case taking care of all the possible operations
    switch (operation)
    {
    case '~':
        // printf("\n::>Performing ~");
        return !(rightVal);
    case '+':
        // printf("\n::>Performing +");
        return ((leftVal) | (rightVal));
    case '*':
        // printf("\n::>Performing *");
        return ((leftVal) & (rightVal));
    case '>':
        // printf("\n::>Performing >");
        return ((!(leftVal)) | (rightVal));
    }
}
```

## Task 6
References Used: (https://yuchen52.medium.com/profiling-with-gprof-64-bit-window-7-5e06ef614ba8)

```c
int main()
{
    // Take input as infix from user
    printf("Enter in Infix notation: ");
    char inputInfix[max];
    scanf("%s", inputInfix);

    inFixToPreFix(inputInfix);

    // Create a string for the input 2nd time
    char inputPrefix[100];
    printf("\nEnter the string in prefix format: ");
    scanf("%s", inputPrefix);

    // Create a root to store the structure
    TreeNode *root = NULL;

    // Call the function first time
    convertPreOrderToTree(&root, inputPrefix);

    printf("\nThe Expression in Inorder Notation is: ");
    printInOrder(root);

    printf("\nThe height of the parse Tree is: ");
    printf("%d", maxHeightOfParseTree(root));

    printf("\nThe number of inputs we need is: %d", noOfCharacters);
    printf("\n%d", recursiveTruthEvaluator(root->val, root->left, root->right));
}
```

## Graphs :)
### Analysis 1
Function  = ((~a)*b)>(c+(d*e))
Inputs - a=1, b=0, c=0, d=1, e=0
Result= 1
![image](https://user-images.githubusercontent.com/28446977/196999959-be4f98fa-de75-489d-a5dc-02f830be50f5.png)

### Analysis 2

![image](https://user-images.githubusercontent.com/28446977/196999995-fa88adc7-8d89-4398-bada-4f431b694220.png)
![image](https://user-images.githubusercontent.com/28446977/197000021-4065bb25-e4f0-4c04-8873-2bafc6676ae2.png)
![image](https://user-images.githubusercontent.com/28446977/196999655-8b4f6085-2bc9-457d-9814-95d018429d5c.png)
![image](https://user-images.githubusercontent.com/28446977/197000062-0cf40336-ceee-4f00-af94-b4facc069159.png)



## Running the Code
- This was a project made for Logic in CS Course Assignment 1
- Compile by using `gcc -Wall -pg Task.c -o Task.exe`
- Then Run the exe
- You get the gmon file
- `gprof Task.exe gmon.out >> analysis.txt` Use this to get analysis
- To graph this in points use gprof2dot and graph

## Basic Git Commands you might want to know to push onto this repository
- `git pull`: to pull from remote
- `git add .`: to add your files
- `git commit -m "Message Goes here"`: Add Message for the commit
- `git push`: push files to remote

NOTE: Pushing Task.exe leads to merge conflicts :)
