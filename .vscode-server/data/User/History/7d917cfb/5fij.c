#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

struct fileNode
{
char filename[100];
struct fileNode* next;
struct fileNode* prev;
};

// struct Node
// {
// int data;
// struct Node* next;
// struct Node* prev;
// };

// A complete working C program to
// demonstrate all insertion
// methods


// A linked list node
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

/* Given a reference (pointer to pointer) to the head of a
list and an int, inserts a new node on the front of the
list. */
void push(struct fileNode** head_ref, char new_data[])
{
	/* 1. allocate node */
	struct fileNode* new_node
		= (struct fileNode*)malloc(sizeof(struct fileNode));

	/* 2. put in the data */
    for (size_t i = 0; i < strlen(new_data); i++)
    {
        new_node->filename[i]=new_data[i];
    }
    
	// new_node->filename = new_data;

	/* 3. Make next of new node as head and previous as NULL
	*/
	new_node->next = (*head_ref);
	new_node->prev = NULL;

	/* 4. change prev of head node to new node */
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	/* 5. move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Given a node as prev_node, insert a new node after the
* given node */
void insertAfter(struct fileNode* prev_node, char new_data[])
{
	/*1. check if the given prev_node is NULL */
	if (prev_node == NULL) {
		printf("the given previous node cannot be NULL");
		return;
	}

	/* 2. allocate new node */
	struct fileNode* new_node
		= (struct fileNode*)malloc(sizeof(struct fileNode));

	/* 3. put in the data */
     for (size_t i = 0; i < strlen(new_data); i++)
    {
        new_node->filename[i]=new_data[i];
    }
	// new_node->data = new_data;

	/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next;

	/* 5. Make the next of prev_node as new_node */
	prev_node->next = new_node;

	/* 6. Make prev_node as previous of new_node */
	new_node->prev = prev_node;

	/* 7. Change previous of new_node's next node */
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

/* Given a reference (pointer to pointer) to the head
of a DLL and an int, appends a new node at the end */
void append(struct fileNode** head_ref, char new_data[])
{
	/* 1. allocate node */
	struct fileNode* new_node
		= (struct fileNode*)malloc(sizeof(struct fileNode));

	struct fileNode* last = *head_ref; /* used in step 5*/

	/* 2. put in the data */
	 for (size_t i = 0; i < strlen(new_data); i++)
    {
        new_node->filename[i]=new_data[i];
    }
    // new_node->data = new_data;


	/* 3. This new node is going to be the last node, so
		make next of it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty, then make the new
		node as head */
	if (*head_ref == NULL) {
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;

	/* 7. Make last node as previous of new node */
	new_node->prev = last;

	return;
}

// This function prints contents of linked list starting
// from the given node
void printList(struct fileNode* node)
{
	struct fileNode* last;
	printf("\nTraversal in forward direction \n");
	while (node != NULL) {
		printf(" %s ", node->filename);
		last = node;
		node = node->next;
	}
	printf("\ntraverse in reverse direction \n");
    // int value = strcmp(("%s",node->filename),"book.txt");
	while (last != NULL) {
		printf("%s ", last->filename);
		node=last;
		last = last->prev;
		// node = last;
		// node->prev =
	}
	printf("\nprint desired file %s\n",node->filename);
    int value 
	value = strcmp(("%s",node->filename),"book.txt");
	printf("%d\n",value);
	while (node != NULL) {
        if(("%s",node->prev)==NULL || value==1){

		printf("%s ", node->filename);
		last = node;
        node = node->next;
        }else{
            last=node;
            node = node->next;
        }
	}
}

/* Driver program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct fileNode* head = NULL;

	// Insert 6. So linked list becomes 6->NULL
	append(&head, "newfile.txt");

	// Insert 7 at the beginning. So linked list becomes
	// 7->6->NULL
	push(&head, "old.txt");

	// Insert 1 at the beginning. So linked list becomes
	// 1->7->6->NULL
	push(&head, "/home/jtorne2/.idea/");

	// Insert 4 at the end. So linked list becomes
	// 1->7->6->4->NULL
	append(&head, "book.txt");

	// Insert 8, after 7. So linked list becomes
	// 1->7->8->6->4->NULL
	insertAfter(head->next, "groceryList.txt");

	printf("Created DLL is: ");
	printList(head);

	getchar();
	return 0;
}
