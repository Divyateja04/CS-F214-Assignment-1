// Task 1: To convert infix to preorder
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Define a constant to take care of max limit of input
#define max 100

// Make a switch statement for precedence of operators
int priority(char op)
{
    if (op == '(')
        return 1;
    if (op == '~')
        return 2;
    if (op == '+')
        return 3;
    if (op == '*')
        return 4;
    if (op == '>')
        return 4;
}

// Create a stack to keep track of operators
char stack[max];
int top = -1;

// Function to push onto stack
void stackPush(char i)
{
    stack[++top] = i;
}

// Function to pop from the stack
char stackPop()
{
    // Exception Case where we might have an empty stack
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

void inFixToPreFix(char *input)
{
    // Create a Variable to store the output
    char output[max];
    int outputCounter = 0;

    // Key Rule is We cannot have a lower precedence operator on top of a higher precedence operator
    // Also we cannot have 2 same precedence operators together
    // So we have to keep popping and adding into output
    // If we have a closing bracket we have to pop

    // But again through this method we get Postfix since
    // so we reverse the string inorder to get the reverse of preorder notation
    // First we replace ( with ) and ) with (
    // And in the end we reverse again
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

    // printf("%s", input);

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
    for (int i = outputCounter - 1; i >= 0; i--)
    {
        printf("%c", output[i]);
    }
}

int main()
{
    // Take input as infix from user
    printf("Enter in Infix notation: ");
    char input[max];
    scanf("%s", input);

    inFixToPreFix(input);
}