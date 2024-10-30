#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

typedef struct node Node;
Node *head = NULL;
Node *ptr, *temp, *prev, *curr;
int item;

void InsertFront() {
	Node *new = (Node *)malloc(sizeof(Node));
	printf("Enter the data to insert at the front: ");
	scanf("%d", &item);
	new->data = item;

	if (head == NULL) {
		head = new;
		new->next = head;  // First node points to itself
	}
	else {
		ptr = head;
		while (ptr->next != head) {
			ptr = ptr->next;
		}
		new->next = head;
		ptr->next = new;  // Last node points to the new node
		head = new;       // Update head to the new node
	}
	printf("%d is inserted at the front\n", item);
}

void InsertEnd() {
	Node *new = (Node *)malloc(sizeof(Node));
	printf("Enter the data to insert at the end: ");
	scanf("%d", &item);
	new->data = item;

	if (head == NULL) {
		head = new;
		new->next = head;  // First node points to itself
	}
	else {
		ptr = head;
		while (ptr->next != head) {
			ptr = ptr->next;
		}
		ptr->next = new;
		new->next = head;  // Make the list circular
	}
	printf("%d is inserted at the end\n", item);
}

void InsertSpecific(int key) {
	if (head == NULL) {
		printf("List is empty, cannot insert at specific position\n");
		return;
	}

	ptr = head;
	do {
		if (ptr->data == key) {
			Node *new = (Node *)malloc(sizeof(Node));
			printf("Enter the data to insert after %d: ", key);
			scanf("%d", &item);
			new->data = item;
			new->next = ptr->next;
			ptr->next = new;
			printf("%d is inserted after %d\n", item, key);
			return;
		}
		ptr = ptr->next;
	} while (ptr != head);

	printf("Key %d not found in the list\n", key);
}

void DeleteFront() {
	if (head == NULL) {
		printf("List is empty, deletion not possible\n");
	}
	else if (head->next == head) {
		printf("%d is deleted from the front\n", head->data);
		free(head);
		head = NULL;
	}
	else {
		ptr = head;
		while (ptr->next != head) {
			ptr = ptr->next;
		}
		temp = head;
		printf("%d is deleted from the front\n", head->data);
		head = head->next;
		ptr->next = head;
		free(temp);
	}
}

void DeleteEnd() {
	if (head == NULL) {
		printf("List is empty, deletion not possible\n");
	}
	else if (head->next == head) {
		printf("%d is deleted from the end\n", head->data);
		temp = head;
		free(temp);
		head = NULL;
	}
	else {
		prev = head;
		curr = head->next;
		while (curr->next != head) {
			prev = curr;
			curr = curr->next;
		}
		prev->next = head;
		printf("%d is deleted from the end\n", curr->data);
		free(curr);
	}
}

void DeleteSpecific(int key) {
	if (head == NULL) {
		printf("List is empty, deletion not possible\n");
	}
	else if (head->data == key && head->next == head) {
		printf("%d is deleted from the list\n", head->data);
		temp = head;
		head = NULL;
		free(temp);
	}
	else {
		prev = head;
		curr = head;
		while (curr->next != head && curr->data != key) {
			prev = curr;
			curr = curr->next;
		}
		if(curr->data == key) {
			prev->next = curr->next;
			free (curr);
		}
		else {
			printf("Key %d not found in the list\n", key);

		}
	}

}


void Display() {
	if (head == NULL) {
		printf("List is empty\n");
	} else {
		printf("List elements are:\n");
		ptr = head;
		do {
			printf("%d -> ", ptr->data);
			ptr = ptr->next;
		} while (ptr != head);
		printf("(back to front)\n");
	}
}

int main() {
	int choice, key;

	do {
		printf("\n1. Insert at front\n2. Insert at end\n3. Insert after specific node\n4. Delete at front\n5. Delete at end\n6. Delete specific node\n7. Display\n8. Exit\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			InsertFront();
			break;
		case 2:
			InsertEnd();
			break;
		case 3:
			printf("Enter the key after which to insert: ");
			scanf("%d", &key);
			InsertSpecific(key);
			break;
		case 4:
			DeleteFront();
			break;
		case 5:
			DeleteEnd();
			break;
		case 6:
			printf("Enter the key to delete: ");
			scanf("%d", &key);
			DeleteSpecific(key);
			break;
		case 7:
			Display();
			break;
		case 8:
			printf("Exiting...\n");
			break;
		default:
			printf("Invalid choice\n");
			break;
		}
	} while (choice != 8);

	return 0;
}
