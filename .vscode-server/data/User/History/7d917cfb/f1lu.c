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

struct Node
{
int data;
struct Node* next;
struct Node* prev;
};

void main(){

}