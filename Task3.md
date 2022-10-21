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