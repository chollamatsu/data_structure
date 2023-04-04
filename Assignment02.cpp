//  CHONLAMAS  CHAIKHAMWANG

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // for use bool in C


struct Node {
    int item;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;

Node* Head = (struct Node*)malloc(sizeof(struct Node));
Node* Tail = (struct Node*)malloc(sizeof(struct Node));

bool isEmpty(){
    if(Head->next != Tail){
        return false;
    }
    else{
        return true;
    }
}

int getSize(){
    Node* cur = Head->next;
    int size_ = 0;
    while(cur!=Tail){
        cur=cur->next;
        size_++;
    }
    return size_;
}

void insertFirst(int newitem){
    Node* newNode = new Node;
    Node* cur = Head->next;
    newNode->item = newitem;
    newNode->next = cur;
    newNode->prev = cur -> prev;
    cur->prev->next = newNode;
    cur -> prev = newNode;
}

void insertLast(int newitem){
    Node* newNode = new Node;
    Node* cur = Tail ;
    newNode->item = newitem;
    newNode->next=cur;
    newNode->prev=cur->prev;
    cur -> prev -> next = newNode;
    cur -> prev = newNode;
}

void remove(Node* cur){
    Node* p = cur -> prev;
    Node* q = cur -> next;
    p -> next = q;
    q -> prev = p;
    delete cur;
}

void removeFirst(){
    remove(Head -> next);
}

void removeLast(){
    remove(Tail -> prev);
}

void DisplayAll(){
    Node* cur = Head->next;
    while(cur != Tail){
        printf("%d ",cur->item);
        cur = cur -> next;
    }
    printf("\n");

}

void traverseList(int n, char* text){
    Node* cur = Head->next;
    for(int i=0;i<n;i++){
        if(text[i]=='L' && cur->prev!=Head){
            cur=cur->prev;
        }
        else{
        	if(text[i]=='R' && cur->next!=Tail){
        		cur=cur->next;
			}
            
        }
    }
    printf("%d\n",cur->item);
}

void freeAll(){
    Node* frontptr = Head;
    while (cur != NULL) {
        Node* next = cur->next;
        free(cur);
        cur = next;
    }
}

int main(){
    Head->prev=NULL;
    Head->next=Tail;
    Tail->prev=Head;
    Tail->next=NULL;
    int n = 0;
    int num;
    int newitem;
    while (n != 9) {
        scanf("%d", &n);
        if (n == 1) {
            if (isEmpty())
                printf("yes\n");
            else
                printf("no\n");
        }
        else if (n == 2) {
            printf("%d\n", getSize());
        }
        else if (n == 3) {
            scanf("%d", &newitem);
            insertFirst(newitem);
        }
        else if (n == 4) {
            scanf("%d", &newitem);
            insertLast(newitem);
        }
        else if (n == 5) {
            if(!isEmpty())removeFirst();
        }
        else if (n == 6) {
            if(!isEmpty())removeLast();
        }

        else if (n == 7) {
            DisplayAll();
        }
        else if (n==8){
            scanf("%d", &num);
            char text[num];
            scanf("%s", &text);
            if(isEmpty()){
                printf("no\n");
            }
            else{
                traverseList(num, text);
            }
        }
    }
    freeAll();
    return 0;

}

