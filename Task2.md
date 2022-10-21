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
