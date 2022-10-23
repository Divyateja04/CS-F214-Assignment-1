## Task 5: Evaluating the truth value of propositional logic formula in a bottoms up fashion
- Evaluating the truth value of propositional logic formula in a bottoms up fashion
- @param operation the operation that is supposed to take place between left and right
- @param left a reference to the left node of the tree
- @param right a reference to the right node of the tree
- @return int returns value 0/1 depending on the previous operation in stack

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