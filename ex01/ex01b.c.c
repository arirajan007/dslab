#iclude<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};
struct node* createNode(int data ){
struct node*newNode =(struct node*)malloc(SIzeof(struct Node));
if(newNode == NULL){
	fprintf(stderr,"memory allocation failed/n");
	exit(EXIT_FAILURE); U
     }
     newNode->data = data;
     newNode->next = NULL;
     return newNode;
}
void insertAtEnd(struct node**head,int data){
    struct node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
     }
    struct Node*temp = *head;
    while(temp->next !=NULL){
          temp = temp->next;
     }
     temp-next = newNode;
}
void insertAtposition(struct node** head,int data,int position){
	if(position < 0) {
		printf("error:Invalid position./n");
		return;
    }
    struct node* newNode = createNode(data);
    if(position ==0){
        newNode->next = *head;
 	*head = mewNode;
	return;
    }
    struct node* current =*head;
    struct node* previous = NULL;
    int currentpos = 0;
    while((current != NULL)&& (currentpos < position)){
	previous = current;
	current = current->next;
	currentpos++;
}
    if(currentpos != position){
	printf("error:Invalid position./n");
	free(newNode);
	return;
    }
    newNode->next = current;
    previous-next = newNode;
}
int searchElement(struct Node **head,int data ){
    struct Node* temp = *head;
    int position = 0;
    while(temp !=NULL){
	if(temp->data == data){
	    return position;
 	}
        temp = temp->next;
	position++;
    }
    return -1;
}
void deletedElement(struct Node **head, int position){
    if (*head == NULL){
	printf("error:list is empty./n");
	return;
    }
    if (position < 0) {
	printf("error:Invalid position./n");
	return;
    }
    struct Node* temp = *head;
    if (position ==0){
	*head = temp->next;
	free(temp);
	return;
    }
    struct Node* previous = NULL;
    int currentPos = 0;
    while (temp !=NULL && currentpos < position){
	previous = temp;
	temp = temp->next;
	currentpos++;
    }
    if (temp == NULL){
	printf("error:Invalid position./n");
	return;
    }
    previous->next = temp->next;
    free(temp);
}
void displayList(struct Node* head) {
    if (head == NULL) {
	printf("list is empty./n");
	return;
    }
    printf("linked list: ");
    struct Node* temp = head;
    while (temp != NULL){
	printf("%d -> ", temp->data);
	temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    int choice, data, position, result;
    while(1) {
	printf("\nsingly linked list operations Menu:\n");
	printf("1. Insert at end\n");
	printf("2. Insert at position \n");
	printf("3. Search Element\n");
	printf("4. Delete Element\n");
	printf("5.Display Element\n");
	printf("6.Exit\n");
	printf("Enter your choice:");
	scanf("%d", &choice);
	switch(choice) {
	    case 1:
		printf("enter data to insert at end:");
		scanf("%d",&data);
		insertAtEnd(&head, data);
		break;
	    case 2:
		printf("enter data to insert: ");
		scanf("%d, &data);
		printf("Enter position to insert (0 - based index):");
		scanf("%d, &position);
		insertAtPosition(&head, data, position);
		break;
	    case 3:
		printf("Enter element to search:");
		scanf("%d", &data);
		result = searchElement(&head, data);
		if(result != -1)
		    printf("Element found at position: %d\n", result);
		else
		    printf("Element not found in the list \n");
		break;
	    case 4:
  		printf("enter position to delete (0 - based index):;
		scanf("%d", &position);
		deleteElement(&head, position);
		break;
	    case 5:
		displayList(head);
		break;
	    case 6:
		while(head !=NULL){
		    struct Node* temp = head;
		    head = head->next;
		    free(temp);
		}
		return 0;
	    default:
		printf("Invalid choice! please enter a valid option.\n");
	}
    }
    return 0;
}
