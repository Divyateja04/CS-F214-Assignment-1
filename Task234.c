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
        char *currentLocation = NULL;
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
            if(*start == '~'){
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

// Task 3:
// Function to traverse through the tree in order
// We know that in order means first
// the pointer goes to the left node, then prints the
// current node and then goes to the right node again
// using simple recursion we get the following function

//Make a Global Variable
//to store the number of alphabets
//We are making this because we need 
//to create an array of inputs and take from user

int noOfCharacters = 0;

void printInOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    //A new statement to figure out the number of characters
    if(isalpha(root->val)) noOfCharacters++;
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

// Task 5:
// Evaluating the truth value of propositional logic formula in a bottoms up fashion
int recursiveTruthEvaluator(char operation, TreeNode* left, TreeNode* right){
    int leftVal, rightVal;
    if(!isalpha(left->val)){
        leftVal = recursiveTruthEvaluator(left->val, left->left, left->right);
    }
    if(!isalpha(right->val)){
        rightVal = recursiveTruthEvaluator(right->val, right->left, right->right);
    }
    switch(operation){
        case '~':
            return !(right->val);
        case '+':
            return ((left->val) | (right->val));
        case '*':
            return ((left->val) & (right->val));
        case '>':
            return ((!(left->val)) | (right->val));
    }
}

int findInputsForTruthEvaluator(){
    int inputs[noOfCharacters];
    for(int i=0; i<noOfCharacters; i++){
        printf("Enter Truth Value %d: ", i);
        scanf("%d", &inputs[i]);
    }
    
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