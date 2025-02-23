
// C program for linked list implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// A structure to represent a stack
struct StackNode
{
    int data;
    int type;
    char eti[2][20];
    struct StackNode* next;
};

struct StackNode* newNode(int type, int data, char eti[2][20])
{
    struct StackNode* stackNode =
              (struct StackNode*) malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->type = type;
    if(eti != NULL){
        for(int i=0;i<2;i++)
            strcpy(stackNode->eti[i], eti[i]);
    }
    else{
        for(int i=0;i<2;i++)
            strcpy(stackNode->eti[i], "");
    }
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode *root)
{
    return !root;
}

void push(struct StackNode** root, int type,int data, char eti[2][20])
{
    struct StackNode* stackNode = newNode(type, data, eti);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}

int pop(struct StackNode** root)
{
    if (isEmpty(*root))
        return INT_MIN;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    //free(temp);

    return popped;
}

int peek(struct StackNode* root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}

struct StackNode* retrieve(struct StackNode* root, int type)
{
    if(isEmpty(root)){
        return NULL;
    }
    else{
        struct StackNode* temp = root;
        while(1){
            if(temp == NULL){
                return NULL;
            }
            printf("%d\n", temp->type);
            if(temp->type == type){
                return temp;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    struct StackNode* root = NULL;
    //printf("Top element is %d\n", peek(root));

    char a[2][20] ={"exit_if1","end_if1"};
    // strcpy(a[0],"exit_if1");
    // strcpy(a[1],"end_if1");
    push(&root, 2,10,a);
    printf("%s\n", root->eti[1]);
    // push(&root, 3,20);
    // push(&root, 1,30);
    // push(&root, 1,30);
    // push(&root, 2,10);
    // push(&root, 2,10);
    // push(&root, 2,10);
    // push(&root, 8,10);
    // push(&root, 5,10);
    // push(&root, 2,18);


    // printf("%d popped from stack\n", pop(&root));
    //
    // printf("Top element is %d\n", peek(root));
    //
    // struct StackNode* ret = retrieve(root, 2);
    // if(ret != NULL){
    //     printf("Elementoque se busco es: %d\n", ret->type);
    // }
    // else{
    //     printf("%s\n", "NULL");
    // }

    return 0;
}
