#include <stdio.h>  // Using for printf, scanf etc.
#include <stdlib.h> // For malloc, calloc
#include <string.h> // Only for length of the string
#include <ctype.h>  // Used for isalpha function
#include <time.h>   // Used for time functions

/**
 * @brief Define a constant to take care of max limit of input
 *
 */
#define max 100000

/**
 * @brief Creating a structure with left and right leaves
 *
 */
typedef struct TreeNode
{
    char val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/**
 * @brief Helper Function: max() A function to find the max of 2 numbers
 *
 */
int calcMax(int a, int b) { return a > b ? a : b; }

/**
 * @brief Helper Function: To Create an Array as an alternate to using maps
 *
 */
int letters[30];

int returnValueForLetter(char letter)
{
    if (letter >= 'a' && letter <= 'z')
    {
        int letterNum = (int)letter - 97;

        if (letters[letterNum] == 999)
        {
            printf("\nEnter value for letter %c: ", letter);
            int temp;
            scanf("%d", &temp);
            letters[letterNum] = temp;
        }

        return letters[letterNum];
    }
}

// Task 1: To convert infix to preorder
/**
 * @brief Make a if-else function for precedence of operators
 *
 * @param operation
 * @return int
 */
int priority(char operation)
{
    if (operation == '(')
        return 1;
    if (operation == '~')
        return 2;
    if (operation == '*')
        return 3;
    if (operation == '+')
        return 4;
    if (operation == '>')
        return 5;
    return 0;
}

/**
 * @brief Create a stack to keep track of operators
 *
 */
char stack[max];
int top = -1;

/**
 * @brief Function to push onto stack
 *
 * @param val
 */
void stackPush(char val)
{
    stack[++top] = val;
}

/**
 * @brief Function to pop from the stack. Exception Case where we might have an empty stack
 *
 * @return char
 */
char stackPop()
{
    if (top == -1)
    {
        printf("Empty Stack");
    }
    else
        return stack[top--];
}

/**
 * @brief A function to check if stack is empty or not
 *
 * @return int
 */
int stackIsEmpty()
{
    return top == -1;
}

/**
 * @brief Key Rule is We cannot have a lower precedence operator on top of a higher precedence operator
 * Also we cannot have 2 same precedence operators together
 * So we have to keep popping and adding into output
 * If we have a closing bracket we have to pop
 * But again through this method we get Postfix
 * so we reverse the string inorder to get the reverse of preorder notation
 * First we replace ( with ) and ) with (
 * And in the end we reverse again
 *
 * @param input for the input string
 * @param outputToChar to store the output string
 */
void inFixToPreFix(char *input, char *outputToChar)
{
    // Create a Variable to store the output
    char output[max];
    int outputCounter = 0;

    // Reversing input Step1: Exchange Brackets
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
    int k = 0;
    for (int i = outputCounter - 1; i >= 0; i--)
    {
        printf("%c", output[i]);
        outputToChar[k] = output[i];
        k++;
    }
}

// Task 2: To convert prefix to tree
/**
 * @brief We observe that from the prefix notation, we can directly get the tree
 *  If we observe, it starts with an operator and goes on until it gets another operator
 *  Let us try if we can get tree from here
 *  References : https://www.geeksforgeeks.org/building-expression-tree-from-prefix-expression/
 *
 * @param root pointer to the root where the tree should be stored
 * @param start the current character in the prefix notation
 * @return char*
 */
char *convertPreOrderToTree(TreeNode **root, char *start)
{
    // Print the starting characters to check the flow of the code
    // printf("\nCurrent Character %c: ", *start);
    // Was there just to check if the code is working or not :)

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
            // Just to check if it's actually creating nodes
            // printf("\nNode doesn't exist, creating new Node");

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
            // Current location is used to keep track of location throughout the recursion calls
            return currentLocation;
        }
    }
}

// Task 3:
// Make a Global Variable
// to store the number of alphabets
// We are making this because we need
// to create an array of inputs and take from user

int noOfCharacters = 0;

/**
 * @brief Function to traverse through the tree in order.
 * We know that in order means first the pointer goes to the left node,
 * then prints the current node and then goes to the right node again
 * using simple recursion we get the following function
 *
 * @param root
 */
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

// Task 4:
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
 * @param root the root of the tree
 * @return int height of the tree
 */
int maxHeightOfParseTree(TreeNode *root)
{
    printf(".");
    if (root == NULL)
        return 0;
    int leftSubTreeHeight = maxHeightOfParseTree(root->left);
    int rightSubTreeHeight = maxHeightOfParseTree(root->right);
    return calcMax(leftSubTreeHeight, rightSubTreeHeight) + 1;
}

// Task 5:
/**
 * @brief Evaluating the truth value of propositional logic formula in a bottom up fashion
 *
 * @param operation the operation that is supposed to take place between left and right
 * @param left a reference to the left node of the tree
 * @param right a reference to the right node of the tree
 * @return int returns value 0/1 depending on the previous operation in stack
 */
int recursiveTruthEvaluator(char operation, TreeNode *left, TreeNode *right)
{
    // initializing variables for left sub tree and right sub tree
    // We initialize it to 999 just so that it doesn't mess up by taking initial
    // values as 0
    int leftVal = 999, rightVal = 999;

    if (left != NULL && operation != '~')
    {
        // If left is not an alphabet, call the function recursively
        if (!isalpha(left->val))
        {
            leftVal = recursiveTruthEvaluator(left->val, left->left, left->right);
        }
    }

    if (right != NULL)
    {
        // If right is not an alphabet, call the function recursively
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
            leftVal = returnValueForLetter(left->val);
        }
    }

    if (rightVal != 0 && rightVal != 1)
    {
        rightVal = returnValueForLetter(right->val);
    }

    // if both are alphabets, do the operation
    // Switch case taking care of all the possible operations
    switch (operation)
    {
    // Removed all printfs because we just added them
    // to check if the cases are actually working or not
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

// Task 6
// https://yuchen52.medium.com/profiling-with-gprof-64-bit-window-7-5e06ef614ba8
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
