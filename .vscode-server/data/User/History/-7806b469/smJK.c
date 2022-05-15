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
struct fileNode *pushdir(char new_data[])
{
    return makeTdir(0,new_data);
}
struct fileNode *deleteRNode(struct fileNode *prev_node, char new_data[])
{
    int size;
    if (strlen(("%s", prev_node->filename)) > strlen(("%s", prev_node->right->filename)))
    {
        size = strlen(("%s", prev_node->filename));
    }
    else
    {
        size = strlen(("%s", prev_node->right->filename));
    }
    char dir[100];
    char str[100];
    for (size_t i = 0; i < size; i++)
    {
        dir[i] = prev_node->filename[i];
        str[i] = prev_node->right->filename[i];
    }
    // printf("str:%s\n", str);
    strcat(dir, "/");
    strcat(dir, str);
    // printf("dir: %s\n", dir);
    //   printf("file: %s\n",new_node->filename);
    if (remove(("%s", dir)) == 0)
    {
        printf("The file is deleted successfully.");
    }
    else
    {
        printf("The file is not deleted.");
    }
    return NULL;
}
struct fileNode *deleteLNode(struct fileNode *prev_node, char new_data[])
{
    int size;
    if (strlen(("%s", prev_node->filename)) > strlen(("%s", prev_node->left->filename)))
    {
        size = strlen(("%s", prev_node->filename));
    }
    else
    {
        size = strlen(("%s", prev_node->left->filename));
    }
    char dir[100];
    char str[100];
    for (size_t i = 0; i < size; i++)
    {
        dir[i] = prev_node->filename[i];
        str[i] = prev_node->left->filename[i];
    }
    // printf("str:%s\n", str);
    strcat(dir, "/");
    strcat(dir, str);
    // printf("dir: %s\n", dir);
    //   printf("file: %s\n",new_node->filename);
    if (remove(("%s", dir)) == 0)
    {
        printf("The file is deleted successfully.");
    }
    else
    {
        printf("The file is not deleted.");
    }
    return NULL;
}
struct fileNode *createNode(struct fileNode *prev_node, char new_data[])
{
    struct fileNode *new_node = malloc(sizeof(struct fileNode));
    char dir[100]="";
    char str2[100]="";
    char str[100];
    char newF[100];
    int size;
    if (strlen(("%s", prev_node->filename)) > strlen(("%s", new_data)))
    {
        size = strlen(("%s", prev_node->filename));
    }
    else
    {
        size = strlen(("%s", new_data));
    }
    // printf("new DATA:%s\n\n", new_data);
    // printf("STR:%s\n", str2);
    for (size_t i = 0; i < size; i++)
    {
        new_node->filename[i] = new_data[i];
        dir[i] = prev_node->filename[i];
        str2[i] = new_data[i];
        // printf("DIR %s",dir);
        // printf("LOOP: %s\n",str2);
    }
    // printf("str:%s\n", str2);
    strcat(dir, "/");
    strcat(dir, str2);
    // printf("dir: %s\n", dir);
    // printf("file: %s\n", new_node->filename);
    // size_t bufsz=32;

    char ans[4];
    char ch;
    int i=0;
    char ans2[4]="";
    if (access(dir, F_OK) != -1)
    {
        printf("file already exists. Replace? (yes or no): ");
        scanf("%s\n", ans);
        // ans2="";
        printf("%s\n", ans2);
        for (size_t i = 0; i < strlen(ans); i++)
        {
            ans2[i] = ("%c", toupper(ans[i]));
        }
        printf("%s\n", ans2);
        if (strcmp(ans2, "YES") == 0)
        {
            delete(dir);
            printf("file is has been replaced");
            FILE *input = fopen(dir, "w");
            printf("What would you like to add to the file?(enter 'exitf' to submit inout to file):  ");
            while (scanf("%s", str2) == 1 && strcmp(("%s", str2), "exitf") != 0)
            {
                 printf("in: %d\n", strcmp(("%s", str2), "exitf"));
            ch=("%c",str2[i]);
            if(ch==0x0A)
            {
	            fprintf(input,"\n");
            }
            fprintf(input, "%s", str2);
            fflush(input);
            i++;
            }
            // printf("out\n");
            fclose(input);
        }else{
            printf("file not replaced. \n");
        }
    }
    else
    {
        printf("file is not found\n");
        FILE *input = fopen(dir, "w");
        printf("What would you like to add to the file? (enter 'exitf' to submit input to file): ");
        while (scanf("%s", str2) == 1 && strcmp(("%s", str2), "exitf") != 0)
        {
            printf("in: %d\n", strcmp(("%s", str2), "exitf"));
            ch=("%c",str2[i]);
            printf("%c\n",ch);
            if(ch==0x0A)
            {
	            fprintf(input,"%c\n",ch);
            }
            fprintf(input, "%s", str2);
            fflush(input);
            i++;
            // fprintf(input,"\n");
        }
        // printf("out\n");
        fclose(input);
        // str=NULL;
    }
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

struct fileNode *insertRight(struct fileNode *prev_node, char new_data[])
{

    prev_node->right = createNode(prev_node, new_data);
    return prev_node->right;
}
struct fileNode *insertleft(struct fileNode *prev_node, char new_data[])
{

    prev_node->left = createNode(prev_node, new_data);
    return prev_node->left;
}

struct fileNode *insertRightF(struct fileNode *prev_node, char new_data[])
{

    prev_node->right->right = createNode(prev_node, new_data);
    return prev_node->right->right;
}
struct fileNode *insertleftF(struct fileNode *prev_node, char new_data[])
{

    prev_node->left->left = createNode(prev_node, new_data);
    return prev_node->left->left;
}

struct fileNode *removeleft(struct fileNode *prev_node, char new_data[])
{

    prev_node->left = deleteLNode(prev_node, new_data);
    return prev_node->left;
}
struct fileNode *removeRight(struct fileNode *prev_node, char new_data[])
{

    prev_node->right = deleteRNode(prev_node, new_data);
    return prev_node->right;
}

/* Given a reference (pointer to pointer) to the head
of a DLL and an int, appends a new node at the end */

// This function prints contents of linked list starting
// from the given node

void inorderTraversal(struct fileNode *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%s ->", root->filename);
    inorderTraversal(root->right);
}

void printList(struct fileNode *node)
{
    struct fileNode *last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL)
    {
        printf(" %s ", node->filename);
        last = node;
        node = node->right;
    }
    printf("\n\nTraverse in reverse direction \n");
    // int value = strcmp(("%s",node->filename),"book.txt");
    while (last != NULL)
    {
        printf("%s ", last->filename);
        node = last;
        last = last->left;
    }
    printf("\n\nprint desired file %s\n", node->filename);
    int value;
    value = strcmp(("%s", node->filename), "/home/jtorne2/newDir");
    printf("value: %d\n", value);
    while (node != NULL)
    {

        value = strcmp(("%s", node->filename), "new.txt");
        if (("%s", node->left) == NULL || value == 0)
        {
            if (value == 0)
            {
                printf("/%s\n", node->filename);
            }
            else
            {
                printf("%s", node->filename);
            }
            last = node;
            node = node->right;
        }
        else
        {
            last = node;
            node = node->right;
        }
    }
}

/* Driver program to test above functions*/
// int main()
// {
//     /* Start with the empty list */
//     struct fileNode *root = pushdir("newDir");

//     struct fileNode *head;
//     // struct dirNode* dirHead = NULL;
//     printf("head: %s\n", head->filename);
//     // Insert 6. So linked list becomes 6->NULL
//     // append(&head, "newfile.txt");

//     // Insert 7 at the beginning. So linked list becomes
//     // 7->6->NULL
//     // pushdir(&head, "newDir");

//     insertleft(root, "old.txt");
//     insertRight(root, "new.txt");
//     // printf("%s\n",root->left->left);
//     insertleftF(root, "bad.txt");
//     insertRightF(root, "good.txt");
//     // root->left = insertleftF(root, "older.txt");
//     // root->right = insertRightF(root, "newer.txt");

//     // Insert 1 at the beginning. So linked list becomes
//     // 1->7->6->NULL

//     // Insert 4 at the end. So linked list becomes
//     // 1->7->6->4->NULL
//     // append(&head, "book.txt");

//     // Insert 8, after 7. So linked list becomes
//     // 1->7->8->6->4->NULL
//     // insertAfter(head->right, "groceryList.txt");

//     printf("Created DLL is: ");
//     // printList(head);

//     inorderTraversal(root);
//     printf("\n");
//     // removeleft(root,"deleted");
//     getchar();
//     return 0;
// }
