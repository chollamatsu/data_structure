
//  main.c
//  cs251
//
//  CHONLAMAS  CHAIKHAMWANG
//  
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>// for use bool in C

struct Node {
    int item;
    struct Node* next;
};

typedef struct Node Node;

Node* Head = NULL;

bool isEmpty()
{
   if (Head == NULL){
        return true;
   }
   else{
        return false;
   }
}
int getSize()

{
    int size = 0;
    Node* cur = Head;

    while(cur != NULL){
        cur = cur->next;
        size++;

   }
    return size;

}
Node* find(int index){
   int i;
   if(index < 1 || index >getSize())
   		return NULL;
   	else{
   		Node* cur = Head;
   		for(i=1;i<index;i++){
   			cur = cur->next;
		   }
		   return cur;
	   }

   }
   //Node* cur = Head;
   /*
   if (index >=1 && index <= (getSize()+1)){

        for(i=1;i<index;i++){

            cur = cur-> next;}
        return cur;
        }
   else{
        return NULL;

   }
   */

void insert(int index, int val)
{
   if (index >=0 && index <= (getSize()+1)){
        Node*newPtr = new Node;
       // Node* newPtr = (Node*)malloc(sizeof(Node));
        newPtr->item = val;//define newptr can access an element
        if(index==1){//if insert index is the first index.
            newPtr->next = Head;//define next of pointer which is going to insert route to head node.
            Head = newPtr;//assign head=the insert.(ตัวที่เราจะแทรก)

        }
        else{
            Node *prev = find(index-1);
            newPtr->next = prev -> next;
            prev->next = newPtr;
        }

   }


}

void removeList(int index) // remove operation
{

   Node *cur;
   int size = getSize();
   if(index > 0 && index <= size){
        if(index == 1){
                cur = Head;
                Head = Head->next;
                free(cur);
        }
        else{
                Node* prev = find(index-1);/*ก็คือตัวpointer/node ต้อง find ตำแหน่งทุกรอบ ให้โปรแกรมรู้ ไม่ว่าจะเข้า function ไหน ก็ต้องประกาศ node และ หาตำแหน่งให้มันทุกรอบ ทั้ง curทั้ง prev*/
                cur = prev->next;/*ถ้าเป็นบรรทัดนี้ ถ้าเราใช้เป็น cur = find(index) แบบนี้จะได้ไหม*/
                prev->next = cur->next;
                free(cur);/*ถ้าจะลบ node ทุกครั้ง ต้องใช้คำสั่ง free(ตัวที่จะลบ)*/
        }
   }


}

int retrieve(int index) // return -1 if not found
{
    if(index >=1 && index <= getSize()){
        return find(index)->item;//return element of list
    }
    return -1;
    /*
    if(find(index)==NULL){
        return -1;
    }
    
    */
}
int findList(int val) // return -1 if not found
{
    int i;
    //ให้ function ทำการคืนค่า index ของ val ที่เราต้องการหา
    for(i=1;i<=getSize();i++){
        if(find(i)->item==val){
            return i;
        }
        
    }
    return -1;

}

void DisplayAll()
{
    Node* cur=Head;
    while(cur!=NULL){
        printf("%d ",cur->item);
        cur=cur->next;
    }
    printf("\n");
}

void freeAll()
{
    Node* cur = Head;
    while (cur != NULL) {
        Node* next = cur->next;
        free(cur);
        cur = next;
    }
}

int main()
{
    int n = 0;
    int pos, val;
    while (n != 8) {
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
            scanf("%d", &pos);
            scanf("%d", &val);
            insert(pos, val);
        }
        else if (n == 4) {
            scanf("%d", &pos);
            removeList(pos);
        }
        else if (n == 5) {
            scanf("%d", &pos);
            int temp = retrieve(pos);
            if (temp == -1) {
                printf("no\n");
            }
            else {
                printf("%d\n", temp);
            }
        }
        else if (n == 6) {
            scanf("%d", &val);
            int temp = findList(val);
            if (temp == -1) {
                printf("no\n");
            }
            else {
                printf("%d\n", temp);
            }
        }
        else if (n == 7) {
            DisplayAll();
        }
    }
    freeAll();
    return 0;
}
