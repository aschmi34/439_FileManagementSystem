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
    struct fileNode *right;
    struct fileNode *left;
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
struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
};

/* Given a reference (pointer to pointer) to the head of a
list and an int, inserts a new node on the front of the
list. */
struct fileNode *makeTdir(int rootN, struct fileNode *root, char new_data[])
{
    char head[100] = "/home/jtorne2/";
    char branches[100] = "/home/jtorne2/rootDir/";
    /* 1. allocate node */
    struct fileNode *new_node = (struct fileNode *)malloc(sizeof(struct fileNode));

    if (rootN == 0)
    {
        for (size_t i = 0; i < strlen(head); i++)
        {
            new_node->filename[i] = head[i];
        }
            printf("\n Rnew_node: %s", new_node->filename);
        for (size_t i = 0; i < strlen(new_data); i++)
        {
            new_node->filename[strlen(head) + i] = new_data[i];
            // if (i == strlen(new_data) - 1)
            // {

            //     new_node->filename[strlen(head) + i + 1] = '/';
            // }
        }
            printf("\n new_nodeR: %s", new_node->filename);
    }
    else
    {
        for (size_t i = 0; i < strlen(("%s", root->filename)); i++)
        {
            new_node->filename[i] = root->filename[i];
            if (i == strlen(("%s", root->filename)) - 1)
            {

                new_node->filename[i + 1] = '/';
            }
        }
            printf("\n new_node: %s%s", new_node->filename,new_data);
        for (size_t j = 0; j < strlen(new_data); j++)
        {
            new_node->filename[strlen(("%s", new_node->filename)) + j] = new_data[j];
            printf("\n new_nodeL: %s/%ld", new_node->filename,j);
        }
    }
    /* 2. put in the data */

    // for (size_t i = 0; i < strlen(new_data); i++)
    // {
    //     new_node->filename[i]=new_data[i];
    // }

    // new_node->filename = new_data;

    struct stat st = {0};
    if (rootN == 0)
    {

        printf("\n3rd: %s\n", new_node->filename);
        if (stat(("%s", new_node->filename), &st) == -1)
        {
            mkdir(("%s", new_node->filename), 0777);
        }
    }
    else
    {

        if (stat(("%s", new_node->filename), &st) == -1)
        {
            mkdir(("%s", new_node->filename), 0777);
        }
        printf("\n4th: %s\n", new_node->filename);
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
struct fileNode *deleteRNodeD(struct fileNode *prev_node, char new_data[])
{
    int size;
    if (strlen(("%s", prev_node->filename)) > strlen(("%s", new_data)))
    {
        size = strlen(("%s", prev_node->filename));
    }
    else
    {
        size = strlen(("%s", new_data));
    }
    char dir[100] = "";
    char str[100] = "";
    for (size_t i = 0; i < size; i++)
    {
        dir[i] = prev_node->filename[i];
        str[i] = new_data[i];
    }

    if (remove(("%s", dir)) == 0)
    {
        printf("\nThe directory is deleted successfully.");
    }
    else
    {
        printf("\nThe directory is not deleted.");
    }
    return NULL;
}
struct fileNode *deleteLNodeD(struct fileNode *prev_node, char new_data[])
{
    int size;
    if (strlen(("%s", prev_node->filename)) > strlen(("%s", new_data)))
    {
        size = strlen(("%s", prev_node->filename));
    }
    else
    {
        size = strlen(("%s", new_data));
    }
    char dir[100] = "";
    char str[100] = "";
    for (size_t i = 0; i < size; i++)
    {
        dir[i] = prev_node->filename[i];
        str[i] = new_data[i];
    }

    if (remove(("%s", dir)) == 0)
    {
        printf("\nThe directory is deleted successfully.");
    }
    else
    {
        printf("\nThe directory is not deleted.");
    }
    return NULL;
}

struct fileNode *insertleftD(struct fileNode *prev_node, char new_data[])
{

    printf("\n insertRD: %s%s", prev_node->filename, new_data);
    prev_node->left = makeTdir(1, prev_node, new_data);
    return prev_node->left;
}
struct fileNode *insertRightD(struct fileNode *prev_node, char new_data[])
{

    printf("\n insertRD: %s%s", prev_node->filename, new_data);
    prev_node->right = makeTdir(1, prev_node, new_data);
    return prev_node->right;
}
struct fileNode *removeleftD(struct fileNode *prev_node, char new_data[])
{

    printf("\n removeRD: %s/%s", prev_node->filename, new_data);
    prev_node->left = deleteLNodeD(prev_node, new_data);
    return prev_node->left;
}
struct fileNode *removeRightD(struct fileNode *prev_node, char new_data[])
{

    printf("\n removeRd: %s/%s", prev_node->filename, new_data);
    prev_node->right = deleteRNodeD(prev_node, new_data);
    return prev_node->right;
}

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
