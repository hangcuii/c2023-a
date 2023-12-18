#include <stdio.h>
#include<stdlib.h>
int nodenum=0;
struct node
        {int data;
            struct node* next;

};
   typedef struct node node;
   node*head=NULL;

   node*create(int x)
   {node*newnode=(node*)malloc(sizeof(node));
       newnode->data=x;
       newnode->next=NULL;
       nodenum++;
       return newnode;
   }
   void printlist()
   {node*p=head;
       while(p!=NULL)
       {printf("%d  ",p->data);
       p=p->next;
       }


   }

void insert(int y) {
    node *temp = create(y);
    if (head == NULL) {
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}//头插


void fanxunode() {
    node* prev = NULL;
    node* curr = head;
    node* next;

    while (curr != NULL) {
       next=curr->next;
       curr->next=prev;
       prev=curr;
       curr=next;


    }

    head = prev;
}
int search(int i, int j) {
    int times = 0;
    int result = 1;
    node* p = head;
    while (p != NULL && (p->data != i || times != j)) {
        p = p->next;
        if (p != NULL && p->data == i) {
            times++;
        }
        result++;
    }

    if (result > nodenum ) {
        result = -1;
    }

    return result;
}

   int main()
   {insert(1);
       insert(2);
       insert(3);
       insert(4);
       insert(5);
       insert(5);
       printlist();

       fanxunode();
       printlist();
printf("%d ",search(5,1));
printf("%d ",search(5,2));
printf("%d ",search(5,3));


       return 0;
   }