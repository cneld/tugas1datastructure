#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    int x;
    struct tnode *next;
    struct tnode *prev;
}*head,*tail,*curr;

struct tnode* next;
struct tnode* prev;

void push_front(int value){
    struct tnode* node =(struct tnode*) malloc(sizeof(struct tnode));
    node->x = value;
    node->prev = NULL;
    if(head==NULL){
        head = tail = node;
        node->next = NULL;
    }else{
        node->next = head;
        head->prev = node;
        head = node;
    }
}

void push_back(int value){
    struct tnode* node =(struct tnode*) malloc(sizeof(struct tnode));
    node->x = value;
    node->next = NULL;
    if(head==NULL){
        head = tail = node;
        node->prev = NULL;
    } else{
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
}

void push_mid(int value, int searchKey) {
    struct tnode* node = (struct tnode*) malloc(sizeof(struct tnode));
    node->x = value;

    if (head == NULL) {
        head = tail = node;
        node->next = NULL;
        node->prev = NULL;
    }else{
        struct tnode* curr = head;
        while (curr != NULL) {
            if (curr->x == searchKey) {
                node->next = curr->next;
                node->prev = curr;
                if (curr->next!= NULL) {
                    curr->next->prev = node;
                }
                curr->next = node;
                if (curr == tail) {
                    tail = node;
                }
                break;
            }
            curr = curr->next;
        }
        if(curr == NULL) {
            printf("data %d not found in the list\n",searchKey);
        }
    }
 }

 void delete_front(){
    if(head==NULL){
        printf("List is empty\n");
        return;
    } else{
        struct tnode* del = head;
        if(head==tail){
            free(del);
            head = tail = NULL;
        }else{
            head = head->next;
            head->prev = NULL;
            free(del);
        }
    }
 }

 void delete_back(){
    if(head==NULL){
        printf("List is empty\n");
        return;
    } else{
        struct tnode* del = tail;
        if(head==tail){
            free(del);
            head = tail = NULL;
        }else{
            tail = tail->prev;
            tail->next = NULL;
            free(del);
        }
    }
 }

 void delete_mid(int searchKey){
    if(head==NULL){
        printf("List is empty\n");
        return;
    } else{
        struct tnode* curr = head;
        while(curr!=NULL){
            if(curr->x == searchKey && curr != head && curr!=tail){
             curr->prev->next = curr->next;
             if (curr->next != NULL){
                curr->next->prev = curr->prev;
             }
             free(curr);
             break;
            }
            curr = curr->next;
        }
        if(curr == NULL){
            printf("Data %d not found in the list\n",searchKey);
        }
    }
 }

 void printlist(){
    if (head==NULL){
        printf("List is empty\n");
        return;
    }
    struct tnode* curr = head;
    while(curr!=NULL){
        printf("%d ", curr->x);
        curr = curr->next;
    }
    printf("\n");
 }

 int main(){
    int pilih,value,searchKey;
    while(1){
        printf("\nMenu:\n");
        printf("1. Push Front\n");
        printf("2. Push Back\n");
        printf("3. Push Mid\n");
        printf("4. Delete Front\n");
        printf("5. Delete Back\n");
        printf("6. Delete Mid\n");
        printf("7. Print Linked List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &pilih);
        switch(pilih){
            case 1:
                printf("Enter value to push front: ");
                scanf("%d", &value);
                push_front(value);
                break;
            case 2:
                printf("Enter value to push back: ");
                scanf("%d", &value);
                push_back(value);
                break;
            case 3:
                printf("Enter value to push mid: ");
                scanf("%d", &value);
                printf("Enter search key: ");
                scanf("%d", &searchKey);
                push_mid(value, searchKey);
                break;
            case 4:
                delete_front();
                break;
            case 5:
                delete_back();
                break;
            case 6:
                printf("Enter search key to delete mid: ");
                scanf("%d", &searchKey);
                delete_mid(searchKey);
                break;
            case 7:
                printlist();
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
 }