## Task 1: To convert infix to preorder
- First we make the helper functions as well
- Make a if-else function for precedence of operators
```c
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

### Infix to Prefix Function
```c
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
```