#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct semantic_record
{
    char name[200];
    int type;
    struct semantic_record* next;
};

struct semantic_record* newNode(int type, char name[200])
{
    struct semantic_record* semantic_record =
              (struct semantic_record*) malloc(sizeof(struct semantic_record));
    strcpy(semantic_record->name, name);
    semantic_record->type = type;
    semantic_record->next = NULL;
    return semantic_record;
}

int isEmpty(struct semantic_record *root)
{
    return !root;
}

void push(struct semantic_record** root, int type,char name[200])
{
    struct semantic_record* semantic_record = newNode(type, name);
    semantic_record->next = *root;
    *root = semantic_record;
    printf("%s pushed to stack\n", name);
}

struct semantic_record* pop(struct semantic_record** root)
{
    if (isEmpty(*root))
        return NULL;
    struct semantic_record* temp = *root;
    *root = (*root)->next;
    free(temp);
    return *root;
}

int top(struct semantic_record* root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->type;
}

void clearStack(struct semantic_record* root){
    if (isEmpty(root))
        return;
    while(root != NULL){
        struct semantic_record* temp = root;
        root = root->next;
        free(temp);
    }
    return;
}

struct semantic_record* retrieve(struct semantic_record* root, int type)
{
    if(isEmpty(root)){
        return NULL;
    }
    else{
        struct semantic_record* temp = root;
        while(1){
            if(temp == NULL){
                return NULL;
            }
            if(temp->type == type){
                return temp;
            }
            temp = temp->next;
        }
    }
}
