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
