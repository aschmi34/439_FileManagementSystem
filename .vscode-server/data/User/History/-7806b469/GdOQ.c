#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "dirTree.c"

// struct fileNode
// {
// char filename[100];
// struct fileNode* right;
// struct fileNode* left;
// };

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
// struct Node {
// 	int data;
// 	struct Node* right;
// 	struct Node* left;
// };

/* Given a reference (pointer to pointer) to the head of a
list and an int, inserts a new node on the front of the
list. */
struct fileNode* pushdir( char new_data[])
{
	return makeTdir(new_data);
    
}
struct fileNode* deleteNode(struct fileNode* prev_node, char new_data[])
{

    prev_node->left = createNode(prev_node,new_data);
    return NULL

}
struct fileNode* createNode(struct fileNode* prev_node,char new_data[]) {
  struct fileNode* new_node = malloc(sizeof(struct fileNode));
  char dir[100];
  char str[100];
    for (size_t i = 0; i < strlen(new_data); i++)
    {
        new_node->filename[i]=new_data[i];
    	dir[i]=prev_node->filename[i];
		str[i]=new_data[i];

    }
  printf("str:%s\n",str);
  strcat(dir,"/");
  strcat(dir,str);
  printf("dir: %s\n",dir); 
  printf("file: %s\n",new_node->filename);
	// size_t bufsz=32;

//  char number[]=();
 FILE* input = fopen(dir,"w");
	printf("What would you like to add to the file?: ");
    while(scanf("%s",str)==1 && strcmp(("%s",str),"exitf")!=0){
        printf("in: %d\n",strcmp(("%s",str),"exitf"));
 	fprintf(input,"%s ", str);
	fflush(input);
    }
// printf("out\n");
    fclose(input);
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}

struct fileNode* insertRight(struct fileNode* prev_node, char new_data[])
{


	prev_node->right = createNode(prev_node,new_data);
    return prev_node->right;
	
    
}
struct fileNode* insertleft(struct fileNode* prev_node, char new_data[])
{

    prev_node->left = createNode(prev_node,new_data);
    return prev_node->left;

}

struct fileNode* removeleft(struct fileNode* prev_node, char new_data[])
{

    prev_node->left = createNode(prev_node,new_data);
    return prev_node->left;

}
struct fileNode* removeRight(struct fileNode* prev_node, char new_data[])
{

    prev_node->left = createNode(prev_node,new_data);
    return prev_node->left;

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

	/* 4. Make right of new node as right of prev_node */
	new_node->right = prev_node->right;

	/* 5. Make the right of prev_node as new_node */
	prev_node->right = new_node;

	/* 6. Make prev_node as previous of new_node */
	new_node->left = prev_node;

	/* 7. Change previous of new_node's right node */
	if (new_node->right != NULL)
		new_node->right->left = new_node;
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
		make right of it as NULL*/
	new_node->right = NULL;

	/* 4. If the Linked List is empty, then make the new
		node as head */
	if (*head_ref == NULL) {
		new_node->left = NULL;
		*head_ref = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->right != NULL)
		last = last->right;

	/* 6. Change the right of last node */
	last->right = new_node;

	/* 7. Make last node as previous of new node */
	new_node->left = last;

	return;
}

// This function prints contents of linked list starting
// from the given node

void inorderTraversal(struct fileNode* root ) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%s ->", root->filename);
  inorderTraversal(root->right);
}


void printList(struct fileNode* node)
{
	struct fileNode* last;
	printf("\nTraversal in forward direction \n");
	while (node != NULL) {
		printf(" %s ", node->filename);
		last = node;
		node = node->right;
	}
	printf("\n\nTraverse in reverse direction \n");
    // int value = strcmp(("%s",node->filename),"book.txt");
	while (last != NULL) {
		printf("%s ", last->filename);
		node=last;
		last = last->left;
	}
	printf("\n\nprint desired file %s\n",node->filename);
    int value; 
	value = strcmp(("%s",node->filename),"/home/jtorne2/newDir");
	printf("value: %d\n",value);
	while (node != NULL) {

		
	value = strcmp(("%s",node->filename),"new.txt");
        if(("%s",node->left)==NULL || value==0){
			if( value==0){
				printf("/%s\n", node->filename);
			}else{
				printf("%s",node->filename);
			}
		last = node;
        node = node->right;
        }else{
            last=node;
            node = node->right;
        }
	}
}

/* Driver program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct fileNode* head = pushdir("newDir");
	// struct dirNode* dirHead = NULL;
    printf("head: %s\n",head->filename);
	// Insert 6. So linked list becomes 6->NULL
	// append(&head, "newfile.txt");

	// Insert 7 at the beginning. So linked list becomes
	// 7->6->NULL
	// pushdir(&head, "newDir");
	
	
	insertleft(head, "old.txt");
	insertRight(head, "new.txt");
	

	// Insert 1 at the beginning. So linked list becomes
	// 1->7->6->NULL

	// Insert 4 at the end. So linked list becomes
	// 1->7->6->4->NULL
	// append(&head, "book.txt");

	// Insert 8, after 7. So linked list becomes
	// 1->7->8->6->4->NULL
	// insertAfter(head->right, "groceryList.txt");

	printf("Created DLL is: ");
	// printList(head);

    inorderTraversal(head);

	getchar();
	return 0;
}
