#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void delete (char args[100])
{
  // char ans[4];
  // char ans2[4];

  printf("Deleting... %s\n",args);

  int success = rmdir(args);
  
  printf("%d",success);
  
}
#include "fileTree.c"
void inorder_traversal(struct fileNode* root) {
   if(root != NULL) {
      inorder_traversal(root->left);
      printf("%s ",root->filename);          
      inorder_traversal(root->right);
   }
}
void printPostorder(struct fileNode *dir,struct fileNode* node)
{
    if (node == NULL)
        return;
 
    // first recur on left subtree
    printPostorder(dir,node->left);
 
    // then recur on right subtree
    printPostorder(dir,node->right);
 
    // now deal with the node
    printf("\nnode: %s ", node->filename);
    char dirstr[100]="";
    if(strcmp(("%s",node->filename), ("%s",dir->filename))!=0){
      for (size_t i = 0; i < strlen(("%s",dir->filename)); i++)
        {
          dirstr[i] = dir->filename[i];
        }
        // printf("\n node: %s",node->filename);
        
        
        strcat(dirstr,"/");
        strcat(dirstr,("%s",node->filename));
        printf(" dirstr: %s",dirstr);
        remove(dirstr);
    }
    remove(("%s",node->filename));
}
 
void deleteAll(struct fileNode* node)
{


  printf("\nDeleting... %s\n",node->filename);
  struct fileNode * root =node;
    struct fileNode *last;
    // printf("\nTraversal in forward direction \n");
    // while (node != NULL)
    // {
    //     printf(" %s ", node->filename);
    //     last = node;
    //     node = node->right;
    // }
    // printf("\n\nTraverse in reverse direction \n");
    // // int value = strcmp(("%s",node->filename),"book.txt");
    // while (last != NULL)
    // {
    //     printf("%s ", last->filename);
    //     node = last;
    //     last = last->left;
    // }
    while(node!=NULL){

      if (("%s", node->left) == NULL)
        {
            // if (value == 0)
            // {
            //     printf("/%s\n", node->filename);
            // }
            // else
            // {
                printf("\nnode0: %s", node->filename);
            // }
            
            last = node;
            node = node->right;
        }
        else
        {
          
            printf("\nnode: %s", node->filename);
            last = node;
            node = node->left;
        }
    }
        while(last!=NULL){

      if (("%s", last->left) == NULL)
        {
            // if (value == 0)
            // {
            //     printf("/%s\n", node->filename);
            // }
            // else
            // {
                printf("\nnode1: %s", last->filename);
            // }
            node = last;
            removeRight(root,("%s",last->filename));
            removeRightD(root,("%s",last->filename));
            last = last->right;
        }
        else
        {
          
            printf("\nnode2: %s", last->filename);
            node = last;
            removeleft(root,("%s",last->filename));
            removeleftD(root,("%s",last->filename));
            removeRight(root,("%s",last->filename));
            removeRightD(root,("%s",last->filename));
            last = last->left;
        }
    }
  int success = rmdir(("%s",node->filename));
  
  printf(" succ: %d\n",success);
  
}

void main()
{
// delete("/home/jtorne2/rootDir");
  char str[100];
  int start = 0;
  char exit[100] = "";
  char err[100] = "";
  char dir[100] = "";
  int sideD = 0;
  int sideF = 0;
  int ans = -2;
  printf("Hello.\n\n");
  struct fileNode *root = pushdir(0, "rootDir");
  for (size_t i = 0; i < strlen(root->filename); i++)
  {
    dir[i] = root->filename[i];
  }

  start = 1;
  printf("Enter a command number or enter '0' to display list of commanads:");
  scanf("%d", &ans);
  while (ans == -2)
  {

    if (scanf("%s", err))
    {
      printf("\nInput was of incorrect format...");
      printf("\nEnter a command number or enter '0' to display list of commanads:");
      scanf("%d", &ans);
      printf("%s", err);
    }
  }
struct fileNode *copy = root;
  while (strcmp(("%s", exit), "exit") != 0)
  {
    printf("%s\n", err);
    if (strlen(err) > 0)
    {
      printf("\nInput was was of an incorrect format..");
      ans = 9;
      printf("%d", ans);
      memset(err, 0, 100);
    }
    else if (ans == -1)
    {
      char end[] = "exit";
      for (size_t i = 0; i < 5; i++)
      {
        exit[i] = end[i];
      }
      // delete(("/home/jtorne2/rootDir/%s",dir));
    }
    else if (ans == 0)
    {

      printf("\t -1:to exit \n\t 0: help: display a list of possible commands \n\t 1: currentdir: display name of the current directory\n\t 2: moveup: move up one directory\n\t 3: changedir: DIRNAME: move into another directory if it is inside current directory\n\t 4: newfile FILENAME / newdir DIRNAME: creates a new file or directory\n\t 5: delfile FILENAME / deldir DIRNAME: deletes the specified name or directory\n\t 6: renamefile FILENAME NEWNAME / renamedir DIRNAME NEWNAME: renames spedified file or directory to NEWNAME\n\t 7: list: lists all files and directories in current directory\n\t 8: exit: ends program\n");
      printf("\nPlease choose an option: ");
      if (
          !scanf("%d", &ans)
          // strlen(err)>0
      )
      {
        printf("\nInput was was of an incorrect format...");
        ans = 9;
        // printf("%d",ans);
        memset(err, 0, 100);
        printf("\nEnter a command number, enter '0' to display list of commanads, and '-1' to exit: ");
        scanf("%d", &ans);
      }
    }
    else if (ans == 1)
    {
      printf("The current directory is: %s\n", dir);
      ans = 9;
    }
    else if (ans == 4)
    {
      printf("To create a file enter '0', to create a directory enter '1': ");
      if (
          !scanf("%d", &ans)
          // strlen(err)>0
      )
      {
        scanf("%s", err);
        printf("\nInput was was of an incorrect format..\"%s\"", err);
        ans = 9;
        // printf("%d",ans);
        memset(err, 0, 100);
        fflush(stdin);
      }

      // if (start == 0)
      // {
      //   char newD[] = "rootDir";
      //   for (size_t i = 0; i < strlen(newD); i++)
      //   {
      //     dir[i] = newD[i];
      //   }
      //   // start=1;
      // }
      if (ans == 1)
      {

        printf("Enter directory name to be created: ");
        scanf("%s", str);

        // struct fileNode *root;
        if (start != 0)
        {
          memset(dir, 0, 100);
          for (size_t i = 0; i < strlen(str); i++)
          {

            dir[i] = str[i];
          }
          if (sideD == 0)
        {
          insertleftD(root, str);
          sideD = 1;
        }
        else if (sideD == 1)
        {
          insertRightD(root, str);
          sideD=0;
        }
          // root = pushdir(1, dir);
        }
        // else
        // {
        //   root = pushdir(0, dir);
        //   printf("1st: %s\n", dir);
        //   memset(dir, 0, 100);
        //   for (size_t i = 0; i < strlen(str); i++)
        //   {

        //     dir[i] = str[i];
        //   }

        //   printf("2nd: %s\n", dir);
        //   root = pushdir(1, dir);
        // }
        // if(start=0){
        //   }else{
        //   }
      }
      else if (ans == 0)
      {
        // struct fileNode *root;
        // if (start = 0)
        // {
        //   root = pushdir(0, dir);
        // }
        // else
        // {
        //   root = pushdir(1, dir);
        // }
        printf("Enter file name to be created: ");
        scanf("%s", str);
        //  printf("%s",str);
        // strcat(dire,str);
        printf("%s\n",root->filename);
        if (sideF == 0)
        {
          insertleft(root, str);
          sideF = 1;
        }
        else if (sideF == 1)
        {
          insertRight(root, str);
          sideF=2;
        }
        else if (sideF == 2)
        {
          insertleftF(root, str);
          sideF = 3;
        }
        else if (sideF == 3)
        {
          insertRightF(root, str);
          sideF = 2;
        }
      }

      start = 1;
      ans = 9;
    }
    else if (ans == 5) // Option 5 xxxxxxxxxxxxxxxxxxxxxxx
    {
      // struct fileNode *root = pushdir(0, "rootDir");

      printf("To delete a file enter '0', to delete a directory enter '1': ");
      if (
          !scanf("%d", &ans)
          // strlen(err)>0
      )
      {
        scanf("%s", err);
        printf("\nInput was was of an incorrect format..\"%s\"", err);
        ans = 9;
        // printf("%d",ans);
        memset(err, 0, 100);
        fflush(stdin);
      }

      if (ans == 1)
      {

        printf("Enter directory name to be deleted: ");
        scanf("%s", str);

        removeleftD(root, str);
        // root = pushdir(("%s",root->left->filename));
        struct fileNode *last;
        printf("\nTraversal in forward direction \n");
        if (root->left != NULL)
        {
          printf(" %s ", root->filename);
          last = root;
          root = root->left;
        }
        // printf("\n\nTraverse in reverse direction \n");
        // // int value = strcmp(("%s",node->filename),"book.txt");
        // while (last != NULL)
        // {
        //   printf("%s ", last->filename);
        //   root = last;
        //   last = last->left;
        // }
        memset(dir, 0, 100);
        for (size_t i = 0; i < strlen(("%s", root->filename)); i++)
        {

          dir[i] = root->filename[i];
        }
        // removeRightD(root,str);
      }
      else if (ans == 0)
      {
        printf("Enter file name to be deleted: ");
        scanf("%s", str);
        printf("\nstr: %s%s\n", root->filename, str);
        // strcat(dire,str);
        printf("%d\n", sideF);
        if (sideF == 0)
        {
          removeleft(root, str);
          sideF = 1;
        }
        else if (sideF == 1)
        {
          removeRight(root, str);
          sideF=2;
        }
        else if (sideF == 2)
        {
          removeleftF(root, str);
          sideF = 3;
        }
        else if (sideF == 3)
        {
          removeRightF(root, str);
          sideF = 2;
        }
      }
      ans = 9;
    }
    else
    {
      // if(
      //   "%s",err
      //   // strlen(err)>0
      //   ){
      // printf("\nInput was was of an incorrect format..");
      // ans=9;
      // memset(err,0,100);
      // }
      printf("\nEnter a command number, enter '0' to display list of commanads, and '-1' to exit: ");
      if (
          !scanf("%d", &ans)
          // strlen(err)>0
      )
      {
        scanf("%s", err);
        printf("\nInput was was of an incorrect format..\"%s\"", err);

        ans = 9;
        printf("%s", err);
        memset(err, 0, 100);
        // printf("\nEnter a command number, enter '0' to display list of commanads, and '-1' to exit: ");
        // scanf("%d",&ans);
      }
    }

    // printf("Enter a command number, enter '0' to display list of commanads, '-1' to exit");
    // scanf("%d",&ans);

    //  char number[]=();
    //  FILE* input = fopen(dir,"w");
    //  fprintf(input,"%s", str);
  }
  
  // printPostorder(root,root);
  printf("\n");
  inorder_traversal(root);
  printf("\n");
  inorder_traversal(copy);
  deleteAll(root);
  delete("/home/jtorne2/rootDir");
  // fgets(info,100,input);
}