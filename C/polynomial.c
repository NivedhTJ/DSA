#include<stdio.h>
#include<stdlib.h>

struct node {
int coeff;
int expo;
struct node *next;
};

typedef struct node Node;
Node *head=NULL;
Node *ptr;
int coeff,expo;

void insertnode(Node** head,int coeff,int expo) {
    Node *new = (Node*)malloc(sizeof(Node));
    new->coeff = coeff; 
    new->expo = expo; 
    new->next = NULL;
    
    if(*head == NULL)
    {
    *head = new;
    }
    else{
	ptr = *head;

   	while(ptr->next != NULL) {
   	ptr=ptr->next;
   	}
   	ptr->next = new;
   }
}

Node* addpoly(Node* phead,Node* qhead) {

Node* result = NULL;
Node* p = phead;
Node* q = qhead;

 while(p != NULL || q != NULL){
   if( p->expo == q->expo){
     coeff = p->coeff + q->coeff;
     expo = p->expo;
     p = p->next;
     q = q->next;
   }
   else if( p->expo < q->expo){
     coeff =  q->coeff;
     expo = q->expo;
     q = q->next;
   }
   else if( p->expo > q->expo){
     coeff = p->coeff;
     expo = p->expo;
     p = p->next;
   }
   else if(p == NULL){
     coeff =  q->coeff;
     expo = q->expo;
     q = q->next;
   }
   else{
     coeff = p->coeff;
     expo = p->expo;
     p = p->next;
   }
   insertnode(&result,coeff,expo);
   
 }
 return result;
}

void display(Node* poly) {
        Node* temp = poly;
        while(temp->next != NULL){
        printf("%d^%d+",temp->coeff,temp->expo);
        temp = temp->next;
        }
        printf("%d^%d",temp->coeff,temp->expo);
}

void main() {
 Node* p = NULL;
 Node* q = NULL;
 int end = 0;
 
 printf("Enter polynomial 1\n");
 
 while(end != 1 ) {
 printf("Enter coeff and exp\n");
  scanf("%d",&coeff);
  scanf("%d",&expo);
  insertnode(&p,coeff,expo);
  
  if(expo == 0 )
  end =1;
 }
 
 printf("Enter polynomial 2\n");
 end = 0;
 
 while(end != 1 ) {
 printf("Enter coeff and exp\n");
  scanf("%d",&coeff);
  scanf("%d",&expo);
  insertnode(&q,coeff,expo);
  
  if(expo == 0 )
  end =1;
 }
 
Node* result = addpoly(p,q);
 printf("Result :");
 display(result);
}

