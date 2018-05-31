/**
 * prog6.1.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h> /* 記錄bool列舉值 */

typedef struct {
    int ItemKey;
} element;

#define MaxStackSize 100
typedef struct {
    element stack[MaxStackSize];
    int top;
} StackADT;

bool isEmpty(StackADT S) {
    if (S.top < 0) return true;
    else return false;
}

bool isFull(StackADT S) {
    if (S.top >= MaxStackSize - 1) return true;
    else return false;
}

void push(StackADT *S, element item) {
    if (isFull(*S) == true) {
        printf("Stack is full!");
        exit(1);
    } else {
        S->stack[++S->top] = item;
    }
}

element pop(StackADT *S) {
    if (isEmpty(*S) == true) {
        printf("Stack is empty!!");
        exit(1);
    } else {
        return S->stack[S->top--];
    }
}

void PrintStack(StackADT *S) {
    int i;
    printf("Stack's top value is %d, Stack's contents is : \n",S->top);
    
    if (S->top < 0) {
        printf("Stack is empty!\n");
        return;
    }
//    printf("     |   :  |\n", S->stack[S->top - i]);
	printf("     |   :  |\n");
    printf("      ------ \n");
    for (i = S->top; i >= 0; i--) {
        printf("S[%d] |  %2d  |\n", i, S->stack[i]);
        printf("      ------ \n");
    }   
}

int main(void) {
    element Item;
    int i;
    StackADT S1;
    char ch = 'I';   
    S1.top = -1;

    while (ch != 'E') {
        fflush(stdin);
        printf("[I]=push,[O]=pop,[E] and [Others]=Exit:");
        scanf("%c", &ch);
        switch(ch) {
            case 'I':
            case 'i':
                printf("push :");
                scanf("%d", &Item.ItemKey);
                push(&S1, Item);
                printf("push人%d,", Item.ItemKey);
                PrintStack(&S1);
                break;
            case 'O':
            case 'o':
            	// 回傳值是一個element結構型態的變數，可透過.取出項目
                printf("pop出%d,", pop(&S1).ItemKey);
                PrintStack(&S1);  
                break;              
            default:
                ch = 'E';
                printf("Byebye!!\n");
                break;            
        }
    }
    
    system("pause");
	return 0;
}

