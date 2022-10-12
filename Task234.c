#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Creating a structure with left and right leaves
typedef struct TreeNode
{
    char val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Helper Function: max()
// A function to find the max of 2 numbers
int max(int a, int b) { return a > b ? a : b; }

// Task 2: To convert prefix to tree
// We observe that from the prefix notation, we can directly get tree
// If we observe, it starts with an operator and goes on until it gets another operator
// Let us try if we can get tree from here
// References : https://www.geeksforgeeks.org/building-expression-tree-from-prefix-expression/

char *convertPreOrderToTree(TreeNode **root, char *start)
{
    // Print the starting characters to check the flow of the code
    printf("Current Character %c: ", *start);
    // If Character is \0 return \0
    if (*start == '\0')
        return '\0';
    // Start an infinite loop to go through all the letters
    while (1)
    {
        char *temp = NULL;
        if (*root == NULL)
        {
            // Print statement to check how many nodes are being created
            printf("Node doesn't exist, creating new Node\n");
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
            // Start with the left subtree
            temp = convertPreOrderToTree(&(*root)->left, start + 1);
            // Start with the right subtree
            temp = convertPreOrderToTree(&(*root)->right, temp + 1);
            return temp;
        }
    }
}

// Task 3:
// Function to traverse through the tree in order
// We know that in order means first
// the pointer goes to the left node, then prints the
// current node and then goes to the right node again
// using simple recursion we get the following function

void printInOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    // Goes to the left sub tree
    printInOrder(root->left);
    // Prints current value
    printf("%c", root->val);
    // Goes to the right sub tree
    printInOrder(root->right);
}

// Task 4:
// We need to find max height of tree
// We can use Depth First Search for this, i.e. we keep traversing
// lower into the tree until we find an end
// and we take max of this
// For example, let's say we have
//     4
//   3   5
//  2     6
// 1
// Here we start from 4, then we say that height is max(leftSubTreeHeight, rightSubTreeHeight) + 1
// That extra 1 due to the current node itself
// When we go to the left node, we get that it is max(leftSubTreeHeight, rightSubTreeHeight) + 1 again
int maxHeightOfParseTree(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int leftSubTreeHeight = maxHeightOfParseTree(root->left);
    int rightSubTreeHeight = maxHeightOfParseTree(root->right);
    return max(leftSubTreeHeight, rightSubTreeHeight) + 1;
}

int main()
{
    // Create a string for the input
    char input[100];
    printf("Enter the string in prefix format: ");
    scanf("%s", input);

    // Create a root to store the structure
    TreeNode *root = NULL;

    // Call the function first time
    convertPreOrderToTree(&root, input);

    printf("\nThe Expression in Inorder Notation is: ");
    printInOrder(root);

    printf("\nThe height of the parse Tree is: ");
    printf("%d", maxHeightOfParseTree(root));
}