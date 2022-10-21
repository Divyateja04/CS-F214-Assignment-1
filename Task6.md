## Task 6 and Main Function
References Used: (https://yuchen52.medium.com/profiling-with-gprof-64-bit-window-7-5e06ef614ba8)

We chose to use C because of the fact that There is no proper implementation in C before this and we thought, it would be a good learning experience for us if we use our CP knowledge, and put it to use here instead of learning C++ again and shifting to another language

## Graphs
### Analysis 1
```
Function  = (a((b>c)>d)*e)>f
Inputs - a=0, b=1, c=0, d=0, e=1, f=1
Result= 1
```

<img src="https://user-images.githubusercontent.com/28446977/196999959-be4f98fa-de75-489d-a5dc-02f830be50f5.png" alt="drawing" width="600"/>

### Analysis 2
```
Function  = (a+b+c)*d
Inputs - a=1, b=0, c=0, d=1
Result= 1
```
<img src="https://user-images.githubusercontent.com/28446977/196999995-fa88adc7-8d89-4398-bada-4f431b694220.png" alt="drawing" width="600"/>

### Analysis 3
```
Function  = ((a+b)>c)>d
Inputs - a=1, b=0, c=0, d=0
Result= 1
```
<img src="https://user-images.githubusercontent.com/28446977/197000021-4065bb25-e4f0-4c04-8873-2bafc6676ae2.png" alt="drawing" width="600"/>

### Analysis 4
```
Function  = ((~a)\*b)>(c+(d\*e))
Inputs - a=1, b=0, c=0, d=1, e=0
Result= 1
```
<img src="https://user-images.githubusercontent.com/28446977/196999655-8b4f6085-2bc9-457d-9814-95d018429d5c.png" alt="drawing" width="600"/>

### Analysis 5
```
Function  = (a+b+c)*d
Inputs - a=1, b=0, c=0, d=1
Result= 1
```
<img src="https://user-images.githubusercontent.com/28446977/197000062-0cf40336-ceee-4f00-af94-b4facc069159.png" alt="drawing" width="600"/>

```c
int main()
{
    // Give default values to all the letters so that it doesn't cause any confusion
    for (int i = 0; i < 30; i++)
    {
        letters[i] = 999;
    }

    printf("----------------CS F214 Assignment----------------");
    printf("\nPlease use only small alphabets as atoms :)");
    // Take input as infix from user
    printf("\nEnter in Infix notation: ");
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