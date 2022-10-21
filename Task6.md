## Task 6 and Main Function
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