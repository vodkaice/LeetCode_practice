#include <stdio.h>
#include <stdlib.h>
/*
* You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
*
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
*/
typedef struct listnode
{
    int data;
    struct listnode* next;
} linkedList;

linkedList* add(linkedList* l1,linkedList* l2);
linkedList* create(int data);
void insert(linkedList *n1,linkedList *n2);
void printL(linkedList *n);
void freeL(linkedList *list);
int main(){
    linkedList* l1,*l2;
    linkedList* l11 = create(9);
    linkedList* l12 = create(9);
    linkedList* l13 = create(9);
    linkedList* l21 = create(1);
    //linkedList* l22 = create(1);
    //linkedList* l23 = create(9);

    insert(l11,l12);
    insert(l12,l13);
    //insert(l21,l22);
    ///insert(l22,l23);

    printL(l11);
    printL(l21);
    add(l11,l21);

    freeL(l11);
    freeL(l21);
    return 0;
}

linkedList* create(int data){
    linkedList* n = (linkedList*)malloc(sizeof(linkedList));
    n->data = data;
    n->next = NULL;
    return n;
}
void insert(linkedList *n1,linkedList *n2){
    // n1->n2->NULL
    n2->next = n1->next;
    n1->next = n2;
}
void printL(linkedList *n){
    linkedList *node = n;
    while (n!=NULL){
        printf("%d->",n->data);
        n = n->next;
    }
    printf("\n");
}
void freeL(linkedList *list){
    if(list->next != NULL){
        freeL(list->next);
    }
    free(list);
}
linkedList* add(linkedList* l1,linkedList* l2){
    linkedList *l3;
    l3 = l1;
    while(1){
        if(l1->next == NULL && l2->next == NULL){   //case 1
            l1->data = l1->data + l2->data;
            if(l1->data >= 10){
                l1->data = l1->data %10;
                if(l1->next !=NULL){    //overflow
                    l1->next->data ++;
                }
                else{
                    linkedList *l3a=(linkedList*)malloc(sizeof(linkedList));
                    l3a->data = 1;
                    l1->next = l3a;
                    l3a->next = NULL;
                }
            }
            printL(l3);
            return l3;
        }
        else if (l1->next == NULL && l2->next != NULL){ //case 2
            l1->data = l1->data + l2->data;
            if(l1->data >= 10){     //overflow
                l1->data = l1->data %10;
                linkedList *l3a=(linkedList*)malloc(sizeof(linkedList));
                l3a->data = 1;
                l1->next = l3a;
                l3a->next = NULL;
                l1 = l1->next;
                l2 = l2->next;
            }
            else{
                l1->next = l2->next;
                printL(l3);
                return l3;
            }
        }
        else if (l1->next != NULL && l2->next == NULL){ //case 3
            l1->data = l1->data + l2->data;
            if(l1->data >= 10){
                l1->data = l1->data %10;
                l1->next->data ++;
                l1 = l1->next;
                l2->data = 0;
            }
            else{
                printL(l3);
                return l3;
            }
        }
        else if (l1->next != NULL && l2->next != NULL){ //case 4
            l1->data = l1->data + l2->data;
            if(l1->data >= 10){
                l1->data = l1->data %10;
                l1->next->data ++;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
    }
}
