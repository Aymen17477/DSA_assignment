//Next Greater Element

#include <stdio.h>

int stack[100];
int top = -1;          // stack top index

void push(int x)
{
    if (top == 99)     // check overflow
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;  
}

int pop()
{
    if (top == -1)     // check underflow
        return -1;
    return stack[top--]; 
}

int peek()
{
    if (top == -1)     // empty stack
        return -1;
    return stack[top]; // return top element
}

int isEmpty()
{
    return top == -1;  // check empty
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int data[100], result[100];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &data[i]);   // input array

    /*
     * Right to left traversal
     * Find Next Greater Element
     */

    for (int i = n - 1; i >= 0; i--)
    {
        while (!isEmpty() && peek() <= data[i])
            pop();               

        result[i] = peek();      // store next greater (-1 if none)

        push(data[i]);           // push current element
    }

    printf("\nOutput:\n");
    for (int i = 0; i < n; i++)
        printf("%d -> %d\n", data[i], result[i]);  // print result

    return 0;
}