#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int expo;
    struct node *next;
};

typedef struct node Node;
int coeff, expo;

Node* insertnode(Node* head, int coeff, int expo) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->coeff = coeff; 
    new->expo = expo; 
    new->next = NULL;
    
    if (head == NULL) {
        head = new;
    } else {
        Node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
    return head;
}

Node* addpoly(Node* phead, Node* qhead) {
    Node* result = NULL;
    Node* p = phead;
    Node* q = qhead;

    while (p != NULL || q != NULL) {
        if (p != NULL && q != NULL && p->expo == q->expo) {
            coeff = p->coeff + q->coeff;
            expo = p->expo;
            p = p->next;
            q = q->next;
        } else if (q != NULL && (p == NULL || p->expo < q->expo)) {
            coeff = q->coeff;
            expo = q->expo;
            q = q->next;
        } else {
            coeff = p->coeff;
            expo = p->expo;
            p = p->next;
        }
        result = insertnode(result, coeff, expo);
    }
    return result;
}

void display(Node* poly) {
    Node* temp = poly;
    while (temp->next != NULL) {
        printf("%d^%d + ", temp->coeff, temp->expo);
        temp = temp->next;
    }
    printf("%d^%d\n", temp->coeff, temp->expo);
}

int main() {
    Node* p = NULL;
    Node* q = NULL;
    int end = 0;

    printf("Enter polynomial 1\n");
    while (end != 1) {
        printf("Enter coeff and exp: ");
        scanf("%d %d", &coeff, &expo);
        p = insertnode(p, coeff, expo);
        if (expo == 0) end = 1;
    }

    printf("Enter polynomial 2\n");
    end = 0;
    while (end != 1) {
        printf("Enter coeff and exp: ");
        scanf("%d %d", &coeff, &expo);
        q = insertnode(q, coeff, expo);
        if (expo == 0) end = 1;
    }

    Node* result = addpoly(p, q);
    printf("Result: ");
    display(result);

    return 0;
}