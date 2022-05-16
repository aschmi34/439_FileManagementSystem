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
struct fileNode *pushdir(int level, struct fileNode *root, char new_data[])
{
    return makeTdir(level, root, new_data);
}
struct fileNode *deleteRNode(struct fileNode *prev_node, char new_data[])
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
    printf("\nDeleting %s..\n", str);
    strcat(dir, "/");
    strcat(dir, str);
    printf("from file path %s..\n", dir);
    //   printf("file: %s\n",new_node->filename);
    if (remove(("%s", dir)) == 0)
    {
        printf("\nThe file is deleted successfully.\n");
    }
    else
    {
        printf("\nThe file is not deleted.\n");
    }
    return NULL;
}
struct fileNode *deleteLNode(struct fileNode *prev_node, char new_data[])
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
    printf("\nDeleting %s..\n", str);
    strcat(dir, "/");
    strcat(dir, str);
    printf("from file path %s..\n", dir);
    //   printf("file: %s\n",new_node->filename);
    if (remove(("%s", dir)) == 0)
    {
        printf("\nThe file is deleted successfully.\n");
    }
    else
    {
        printf("\nThe file is not deleted.\n");
    }
    return NULL;
}
struct fileNode *createNode(struct fileNode *prev_node, char new_data[])
{
    struct fileNode *new_node = malloc(sizeof(struct fileNode));
    char dir[100] = "";
    char str2[100] = "";
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
    int i = 0;
    char ans2[4] = "";
    if (access(dir, F_OK) != -1)
    {
        printf("\nfile already exists. Replace? (yes or no): ");
        scanf("%s", ans);
        // ans2="";
        // printf("%s\n", ans2);
        for (size_t i = 0; i < strlen(ans); i++)
        {
            ans2[i] = ("%c", toupper(ans[i]));
        }
        // printf("%s\n", ans2);
        if (strcmp(ans2, "YES") == 0)
        {
            delete (dir);
            printf("\nfile has been replaced");
            FILE *input = fopen(dir, "w");
            printf("\nWhat would you like to add to the file?(enter 'exitf' to submit input to file):  ");
            while (scanf("%s", str2) == 1 && strcmp(("%s", str2), "exitf") != 0)
            {
                // printf("in: %d\n", strcmp(("%s", str2), "exitf"));
                ch = fgetc(stdin);
                fprintf(input, "%s ", str2);
                if (ch == 0x0A)
                {
                    fprintf(input, "%c", ch);
                }
                fflush(input);
                i++;
            }
            // printf("out\n");
            fclose(input);
        }
        else
        {
            printf("file not replaced. \n");
        }
    }
    else
    {
        printf("\nfile is not found\n");
        FILE *input = fopen(dir, "w");
        printf("What would you like to add to the file? (enter 'exitf' to submit input to file): ");
        while (scanf("%s", str2) == 1 && strcmp(("%s", str2), "exitf") != 0)
        {
            // printf("in: %d\n", strcmp(("%s", str2), "exitf"));
            ch = fgetc(stdin);
            // ("%c",str2[i]);
            // printf("%c:1\n",ch);
            fprintf(input, "%s ", str2);
            if (ch == 0x0A)
            {
                fprintf(input, "%c", ch);
            }
            fflush(input);
            i = strlen(str2);
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

    printf("\ninsertR: %s/%s", prev_node->filename, new_data);
    prev_node->right = createNode(prev_node, new_data);
    return prev_node->right;
}
struct fileNode *insertleft(struct fileNode *prev_node, char new_data[])
{
    printf("\ninsertL: %s/%s", prev_node->filename, new_data);
    prev_node->left = createNode(prev_node, new_data);
    return prev_node->left;
}

struct fileNode *insertRightF(struct fileNode *prev_node, char new_data[])
{

    printf("\ninsertRF: %s/%s", prev_node->filename, new_data);
    prev_node->right->right = createNode(prev_node, new_data);
    return prev_node->right->right;
}
struct fileNode *insertleftF(struct fileNode *prev_node, char new_data[])
{

    printf("\ninsertLF: %s/%s", prev_node->filename, new_data);
    prev_node->left->left = createNode(prev_node, new_data);
    return prev_node->left->left;
}

struct fileNode *removeleft(struct fileNode *prev_node, char new_data[], struct fileNode *copy)
{

    prev_node->left = deleteLNode(prev_node, new_data);
    return prev_node->left;
}
struct fileNode *removeRight(struct fileNode *prev_node, char new_data[], struct fileNode *copy)
{
    printf("\ncurrent dir: %s", copy->filename);
    while (prev_node->right != NULL)
    {
        printf("\ncurrent path: %s/%s", prev_node->filename, new_data);
        if (strcmp(("%s", prev_node->right->filename), ("%s", copy->filename)))
        {
            printf("\ncurrent path: %s/%s", prev_node->filename, new_data);
            if (prev_node->right->right != NULL && prev_node->right->left != NULL)
            {
            }
            else
            {

                prev_node->right->right = makeTdir(1, prev_node->right, new_data);
                return prev_node->left->right;
            }

            prev_node = prev_node->right;
        }
    }
    prev_node->right = deleteRNode(prev_node, new_data);
    return prev_node->right;
}
struct fileNode *removeleftF(struct fileNode *prev_node, char new_data[], struct fileNode *copy)
{

    prev_node->left->left = deleteLNode(prev_node, new_data);
    return prev_node->left->left;
}
struct fileNode *removeRightF(struct fileNode *prev_node, char new_data[], struct fileNode * copy)
{

    prev_node->right->right = deleteRNode(prev_node, new_data);
    return prev_node->right->right;
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
