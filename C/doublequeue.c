#include<stdio.h>
# define n 5  
int r=-1,f=-1;  
int Q[n];  

int isempty(){
    if(f==-1 && r==-1)
        return 1;
    else 
        return 0;
}

int isfull(){
    if(f==(r+1)%n)
        return 1;
    else
        return 0;
}

void Enqueue(int x){
    if(isfull())
        printf("Queue full\n");
    else if(isempty()){
        f=r=0;
        Q[r]=x;
    }
    else{
        r=(r+1)%n;
        Q[r]=x;
    }
}

void Dequeue(){
    if(isempty())
        printf("Queue empty\n");
    else if(f==r){  
        printf("%d is popped from front\n",Q[f]);
        f=r=-1;
    }
    else{
        printf("%d is popped from front\n",Q[f]);
        f=(f+1)%n;
    }
}

void EnqueueF(int y){
    if(isfull())
        printf("Queue full\n");
    else if(isempty()){
        f=r=0;
        Q[f]=y;
    }
    else{
        f=(f+n-1)%n;  
        Q[f]=y;
    }
}

void DequeueR(){
    if(isempty())
        printf("Queue empty\n");
    else if(f==r){  
        printf("%d is popped from rear\n",Q[r]);
        f=r=-1;
    }
    else{
        printf("%d is popped from rear\n",Q[r]);
        r=(r+n-1)%n;  
    }
}

void display(){
    if(isempty()){
        printf("Queue is empty\n");
        return;
    }
    int i = f;
    while( i != r){
        printf("%d ",Q[i]);
        i=(i+1)%n;
    }
    printf("%d\n",Q[r]);
}

void main(){
    int item,ch;

    do{
        printf("1.Enqueue at rear\n2.Dequeue from front\n3.Enqueue at front\n4.Dequeue from rear\n5.Display\n6.Exit\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter the item: ");
                scanf("%d",&item);
                Enqueue(item);
                break;
            case 2: 
                Dequeue();
                break;
            case 3:
                printf("Enter the item: ");
                scanf("%d",&item);
                EnqueueF(item);
                break;
            case 4: 
                DequeueR();
                break;
            case 5: 
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(ch != 6);
}
