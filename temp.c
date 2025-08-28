#include<stdio.h>
#include<stdlib.h>

#define MAX 100
int arr[MAX];
int top1, top2, size;

void push1(int x) {
    if (top1 < top2 - 1) {
        arr[++top1] = x;
    } else {
        printf("Stack Overflow in stack1\n");
    }
}

void push2(int x) {
    if (top1 < top2 - 1) {
        arr[--top2] = x;
    } else {
        printf("Stack Overflow in stack1\n");
    }
}

int pop1() {
    if (top1 >= 0) {
        return arr[top1--];
    }
    else {
        printf("Stack Underflow in stack1\n");
        return -1;
    } 
}

int pop2() 
{
    if (top2 < MAX) {
        return arr[top2--];
    }
    else {
        printf("Stack Underflow in stack1\n");
        return -1;
    } 
}
void moveFromStack1toStack2() {
    int val = pop1();
    if (val != -1) push2(val);
}

void moveFromStack2toStack1() {
    int val = pop2();
    if (val != -1) push1(val);
}
void printStacks() {
    printf("stack 1: ");
    for (int i = 0; i <= top1; i++) printf("%d ", arr[i]);
    printf("\n");

    printf("stack 2: ");
    for (int i = size - 1; i >= top2; i--) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice, val;
    printf("Enter size of array: ");
    scanf("%d", &size);

    top1 = -1;
    top2 = size;

    while (1)
    {
    
        printf("\nPress:\n");
        printf("1 to push in stack1\n");
        printf("2 to pop from stack1\n");
        printf("3 to push in stack2\n");
        printf("4 to pop from stack2\n");
        printf("5 to move top element from stack1 -> stack2\n");
        printf("6 to move top element from stack2 -> stack1\n");
        printf("7 to exit\n");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push1(val);
                break;
            case 2:
                pop1();
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                push2(val);
                break;
            case 4:
                pop2();
                break;
            case 5:
                moveFromStack1toStack2();
                break;
            case 6:
                moveFromStack2toStack1();
                break;
            case 7:
                printStacks();
                break;
            case 8:
            exit (0);
        }
    } 

    return 0;
}