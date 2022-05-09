#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct fileNode
{

char filename[100];
struct fileNode* right;
struct fileNode* left;
};


// struct Node
// {
// int data;
// struct Node* right;
// struct Node* left;
// };

// A complete working C program to
// demonstrate all insertion
// methods


// A linked list node
struct Node {
	int data;
	struct Node* right;
	struct Node* left;
};

/* Given a reference (pointer to pointer) to the head of a
list and an int, inserts a new node on the front of the
list. */
struct fileNode* makeTdir(int root,char new_data[])
{

	/* 1. allocate node */
	struct fileNode* new_node
		= (struct 
        fileNode*)malloc(sizeof(struct fileNode));


	/* 2. put in the data */
    for (size_t i = 0; i < strlen(new_data); i++)
    {
        new_node->filename[i]=new_data[i];
    }
    
	// new_node->filename = new_data;

    struct stat st = {0};
if(root==0){
    if (stat(("/home/jtorne2/.idea/%s",new_node->filename), &st) == -1) {
    mkdir(("/home/jtorne2/.idea/%s",new_node->filename), 0700);
}
}
if (stat(("/home/jtorne2/.idea/%s",new_node->filename), &st) == -1) {
    mkdir(("/home/jtorne2/.idea/%s",new_node->filename), 0700);
}
	/* 3. Make right of new node as head and previous as NULL
	*/
    // printf("filetree: %s\n",new_node->filename);
	new_node->right = NULL;
	new_node->left = NULL;
    return new_node;
	/* 4. change left of head node to new node */
	// if ((*head_ref) != NULL)
	// 	(*head_ref)->left = new_node;

	/* 5. move the head to point to the new node */
	// (*head_ref) = new_node;
}

struct fileNode *insertleft(struct fileNode *prev_node, char new_data[])
{

    prev_node->left = makeTdir(1,new_data);
    return prev_node->left;
}

// // This function prints contents of linked list starting
// // from the given node
// void printList(struct fileNode* node)
// {

// 	struct fileNode* last;
// 	printf("\nTraversal in forward direction \n");
// 	while (node != NULL) {
// 		printf(" %s ", node->filename);
// 		last = node;
// 		node = node->right;
// 	}
// 	printf("\n\nTraverse in reverse direction \n");
//     // int value = strcmp(("%s",node->filename),"book.txt");
// 	while (last != NULL) {
// 		printf("%s ", last->filename);
// 		node=last;
// 		last = last->left;
// 	}
// 	printf("\n\nprint desired file %s\n",node->filename);
//     int value; 
// 	value = strcmp(("%s",node->filename),"/home/jtorne2/.idea/");
// 	printf("value: %d\n",value);
// 	while (node != NULL) {

		
// 	value = strcmp(("%s",node->filename),"book.txt");
//         if(("%s",node->left)==NULL || value==0){

// 		printf("%s", node->filename);
// 		last = node;
//         node = node->right;
//         }else{
//             last=node;
//             node = node->right;
//         }
// 	}
// }

// /* Driver program to test above functions*/
// int main()
// {
// 	/* Start with the empty list */
// 	struct fileNode* head = NULL;


// 	// Insert 6. So linked list becomes 6->NULL
// 	append(&head, "newfile.txt");

// 	// Insert 7 at the beginning. So linked list becomes
// 	// 7->6->NULL
// 	push(&head, "old.txt");

// 	// Insert 1 at the beginning. So linked list becomes
// 	// 1->7->6->NULL
// 	pushdir(&head, "newDir");

// 	// Insert 4 at the end. So linked list becomes
// 	// 1->7->6->4->NULL
// 	append(&head, "book.txt");

// 	// Insert 8, after 7. So linked list becomes
// 	// 1->7->8->6->4->NULL
// 	insertAfter(head->right, "groceryList.txt");

// 	printf("Created DLL is: ");
// 	printList(head);

// 	getchar();
// 	return 0;
// }
