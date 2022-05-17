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

  printf("Deleting... %s\n", args);

  int success = rmdir(args);

  printf("%d", success);
}
#include "fileTree.c"
void inorder_traversal(struct fileNode *root)
{
  if (root != NULL)
  {
    inorder_traversal(root->left);
    printf("%s  ", root->filename);
    inorder_traversal(root->right);
  }
}

char *changeDir(int direction, struct fileNode *curDir, char node[100], char newDir[100])
{
  if (curDir != NULL)
  {

    changeDir(direction, curDir->left, node, newDir);
    if (strncmp(("%s", curDir->filename), (head), 21) == 0)
    {
      printf("\n curdir: %s", curDir->filename);
      memset(node, 0, 100);
      strcat(node, ("%s", curDir->filename));
      if (strcmp(newDir, head))
      {
        return node;
      }
      strcat(node, "/");
      strcat(node, newDir);
      printf("\n node: %s\n", node);
      //  for (size_t i = 0; i < strlen(("%s",curDir->filename)); i++)
      // {
      //   node[i] = curDir->filename[i];
      // }
      struct stat st = {0};
      if (stat(node, &st) == 0)
      {
        return node;
      }
    }
    changeDir(direction, curDir->right, node, newDir);
  }
  memset(node, 0, 100);
  printf("\nbefore strcat node:%s", node);
  strcat(node, "false");
  printf("\nbefore return node:%s", node);
  return node;
}

char *traverseDir(int direction, struct fileNode *curDir, struct fileNode *prevDir, char node[])
{
  memset(node, 0, 100);
      // printf("\nBef:trav: %s : %s", curDir->filename, prevDir->filename);
      // printf("\nBef:travL: %s : %s", curDir->left->filename, prevDir->filename);
      // printf("\nBef:travR: %s : %s\n", curDir->right->filename, prevDir->filename);
  if (curDir != NULL && direction==1)
  {

    traverseDir(direction, curDir->left, prevDir, node);
      printf("\ntrav: %s : %s", curDir->filename, prevDir->filename);
    // if(curDir->right==NULL || curDir->left==NULL){

      printf("\ntrav1: %s : %s", curDir->filename, prevDir->filename);
    if (strcmp(("%s", curDir->filename), ("%s", prevDir->filename)) && direction == 1)
    {
      printf("\ntrav2: %s : %s", curDir->filename, prevDir->filename);
      for (size_t i = 0; i < strlen(("%s", curDir->filename)); i++)
      {
        node[i] = curDir->filename[i];
      }
      direction=2;
      return node;
    }
    // }

    traverseDir(direction, curDir->right, prevDir, node);
  }
  memset(node, 0, 100);
  strcat(node, "false");
  // printf("\nbefore return node:%s",node);
  return node;
}
// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void inorder_list(struct fileNode *root, struct fileNode *curDir)
{
  if (root != NULL)
  {
    inorder_traversal(root->left);
    if (root->left != NULL && root->right != NULL)
    {
      printf("%s  ", root->filename);
    }
    else if (strcmp(("%s", root->filename), ("%s", curDir->filename)) != 0)
    {
      printf(" Dir:%s ", root->filename);
    }
    inorder_traversal(root->right);
  }
}

// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void printPostorder(struct fileNode *dir, struct fileNode *node)
{
  if (node == NULL)
    return;

  // first recur on left subtree
  printPostorder(dir, node->left);

  // then recur on right subtree
  printPostorder(dir, node->right);

  // now deal with the node
  printf("\nnode: %s ", node->filename);
  char dirstr[100] = "";
  if (strcmp(("%s", node->filename), ("%s", dir->filename)) != 0)
  {

    // if(strcmp(("%s",dir->left->filename),("%s",node->filename))!=0 && strcmp(("%s",dir->right->filename),("%s",node->filename))!=0){
    for (size_t i = 0; i < strlen(("%s", dir->filename)); i++)
    {
      dirstr[i] = dir->filename[i];
    }
    // printf("\n node: %s",node->filename);

    strcat(dirstr, "/");
    strcat(dirstr, ("%s", node->filename));
    printf(" dirstr: %s", dirstr);
    remove(dirstr);
  }
  remove(("%s", node->filename));
}

// xxxxxxxxxxx DElete xxxxxxxxxxxxxxxxxxxxx
void deleteAll(struct fileNode *node, struct fileNode *copy)
{

  printf("\nDeleting %s content... \n", node->filename);
  struct fileNode *root = node;
  struct fileNode *last;

  while (root != NULL)
  {

    if (("%s", root->left) == NULL)
    {

      printf("\nnode0: %s", root->filename);

      last = root;
      root = root->right;
    }
    else
    {

      printf("\nnode: %s", root->filename);
      last = root;
      root = root->left;
    }
  }
  while (last != NULL)
  {
    printf("\nin /last\n");
    if (("%s", last->right) == NULL)
    {

      printf("\nnode1: %s", last->filename);
      // }
      root = last;
      if (strncmp(("%s", last->filename), head, 21) == 0)
      {

        removeleftD(node, ("%s", last->filename), copy);
      }
      else
      {
        removeleft(node, ("%s", last->filename), copy);
      }
      //   removeleft(root, ("%s", last->filename));
      // removeleftD(root, ("%s", last->filename));
      // removeRight(root, ("%s", last->filename));
      // removeRightD(root, ("%s", last->filename));
      printf("%s", root->filename);
      last = last->left;
    }
    else
    {

      printf("\nnode2: %s", last->filename);
      root = last;
      if (strncmp(("%s", last->filename), head, 21) == 0)
      {

        removeRightD(node, ("%s", last->filename), copy);
      }
      else
      {
        removeRight(node, ("%s", last->filename), copy);
      }
      // removeleft(root, ("%s", last->filename));
      // removeleftD(root, ("%s", last->filename));
      // removeRight(root, ("%s", last->filename));
      // removeRightD(root, ("%s", last->filename));
      last = last->left;
    }
  }
  int success = rmdir(("%s", node->filename));

  // printf(" succ: %d\n", success);
}
int sideD = 0;
void main()
{
  // delete(head);
  char str[100];
  int start = 0;
  char exit[100] = "";
  char err[100] = "";
  char dir[100] = "";
  // int sideD = 0;
  int sideF = 0;
  int ans = -2;
  printf("Hello.\n\n");
  struct fileNode *root = pushdir(0, root, "");
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
      printf("\n If Input was was of an incorrect format..");
      ans = 9;
      printf("%d", ans);
      memset(err, 0, 100);
    }
    else if (ans == 8) // Option 8, exit the program xxxxxxxxxxxxxxxxxx
    {
      char end[] = "exit";
      for (size_t i = 0; i < 5; i++)
      {
        exit[i] = end[i];
      }
    }
    else if (ans == 0) // Option 0, show help interface xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    {

      printf("\n\t 0: help: display a list of possible commands \n\t 1: currentdir: display name of the current directory\n\t 2: moveup: move up one directory\n\t 3: changedir: DIRNAME: move into another directory if it is inside current directory\n\t 4: newfile FILENAME / newdir DIRNAME: creates a new file or directory\n\t 5: delfile FILENAME / deldir DIRNAME: deletes the specified name or directory\n\t 6: renamefile FILENAME NEWNAME / renamedir DIRNAME NEWNAME: renames spedified file or directory to NEWNAME\n\t 7: list: lists all files and directories in current directory\n\t 8: exit: ends program\n");
      printf("\nPlease choose an option: ");
      if (
          !scanf("%d", &ans)
          // strlen(err)>0
      )
      {
        printf("\n0 Input was was of an incorrect format...");
        ans = 9;
        // printf("%d",ans);
        memset(err, 0, 100);
        printf("\nEnter a command number, enter '0' to display list of commanads, and '8' to exit: ");
        scanf("%d", &ans);
      }
    }
    else if (ans == 1) // Option 1, display current directory xxxxxxxxxxxxxxxxxxxxxxx
    {
      printf("\nThe current directory is: %s\n", dir);
      ans = 9;
    }
    else if (ans == 2) // Option 2 move up directory xxxxxxxxxxxxx
    {
      printf("\nMoving up a directory..%s : %s",root->filename,copy->filename);
      char *newDir = traverseDir(1, root, copy, err);
      struct fileNode *last;
      copy=root;
      start = 3;
      if (strcmp(newDir, "false") != 0)
      {
        printf("\nTraversal in forward direction %s\n",newDir);
        printf("\ncopy1: %s\n",copy->filename);
          printf("\n copy:%s ", copy->right->filename);
          printf("\n copy:%s ", copy->left->filename);
        while (copy != NULL && start == 3)
        {
          printf("\n copy:%s ", copy->filename);
          if (strcmp(("%s", copy->filename), newDir) == 0)
          {
          int i = strlen(("%s", copy->filename)) - 1;
          char newstr[100]="";
          printf("\ncopy4:%s",copy->filename);
          for (size_t j = 0; j < strlen(("%s", copy->filename)); j++)
          {
            newstr[j] = copy->filename[j];
          }
            memset(dir, 0, 100);
            for (i; i > 0; i--)
            {
              printf("\nchar:%c",newstr[i]);
              if(newstr[i]!='/'){
              //   for(int x=0;i<strlen(newstr);x++){
                  
              //   printf("\n%c",dir[x]);

              //   dir[x] = newstr[i];
              //   i++;
              //   }
              // i=0;
              }else if(newstr[i]=='/'){
                i++;
                 for(int x=0;i<strlen(newstr);x++){
                  
                printf("\n%c",dir[x]);

                dir[x] = newstr[i];
                i++;
                }
              i=0;
              }
                }
            start = 2;
            }
            
            printf("\n NewDir:%s",dir);
            // copy=last;
          last = copy;
          copy = copy->left;
          }
        printf("\n\nTraverse in reverse direction \n");
        // int value = strcmp(("%s",node->filename),"book.txt");
        while (last != NULL && start == 3)
        {
          printf("\nlast: %s : %s", last->filename, copy->filename);
          copy = last;
          if (strcmp(("%s", copy->filename), newDir) == 0)
          {
            memset(dir, 0, 100);
            for (size_t i = 0; i < strlen(str); i++)
            {
              dir[i] = str[i];
            }
            printf("\n NewDir%s",dir);
            start = 2;
          }
          last = last->right;
        }
        }
      // }
      // copy=
      ans = 9;
    }
    else if (ans == 3) // Option 3 change directory xxxxxxxxxxxxxxxxx
    {
      printf("\nWhat is the name of the directory you would like to change to: ");
      scanf("%s", str);

      char *newDir = changeDir(2, root, err, str);
      printf("\nnewDir: %s", newDir);
      struct fileNode *last;
      start = 3;
      if (strcmp(newDir, "false") != 0)
      {
        printf("\nTraversal in forward direction copy:%s\n", root->filename);
        while (root != NULL && start == 3)
        {
          printf("\nTraversal in forward direction copy:%s\n", root->filename);
          // if (copy->filename!=NULL ){
          printf("\n 3root:%s ", root->filename);

          if (strcmp(("%s", root->filename), newDir) == 0)
          {
            start = 2;
            memset(dir, 0, 100);
            for (size_t i = 0; i < strlen(str); i++)
            {

              dir[i] = str[i];
            }
            copy = root;
          }
          // }
          last = root;
          root = root->left;
          // printf("\n 3last:%s ", last->filename);
        }
        printf("\n\nTraverse in reverse direction \n");
        // int value = strcmp(("%s",node->filename),"book.txt");
        while (last != NULL && start == 3)
        {
          printf("\n3last%s ", last->filename);
          root = last;
          last = last->right;
          if (strcmp(("%s", last->filename), newDir) == 0)
          {
            start = 2;
            memset(dir, 0, 100);
            for (size_t i = 0; i < strlen(str); i++)
            {

              dir[i] = str[i];
            }
            copy = last;
          }
        }
      }
      ans = 9;
      memset(err, 0, 100);
    }
    else if (ans == 4) // Option 4 add file or directory xxxxxxxxxxxxxxxx
    {
      printf("To create a file enter '1', to create a directory enter '2': ");
      if (
          !scanf("%d", &ans)
          // strlen(err)>0
      )
      {
        scanf("%s", err);
        printf("\n4 Input was was of an incorrect format..\"%s\"", err);
        ans = 9;
        // printf("%d",ans);
        memset(err, 0, 100);
        fflush(stdin);
      }
      if (ans == 2)
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
            // if(){

            // }
            copy = insertleftD(root, str, copy);
            // root = insertleftD(root, str);
            // copy=root;
            // sideD = 1;
          }
          else if (sideD == 1)
          {
            copy = insertRightD(root, str, copy);
            // root = insertRightD(root, str);
            // copy = root;
            sideD = 0;
          }
          // root = pushdir(1, dir);
        }
      }
      else if (ans == 1)
      {

        printf("Enter file name to be created: ");
        scanf("%s", str);
        //  printf("%s",str);
        // strcat(dire,str);
        printf("root: %s\n", root->filename);
        printf("current dir: %s\n", copy->filename);
        if (sideF == 0)
        {
          if(copy->left!=NULL){
            sideF =1;
          }else[
            
          ]
          insertleft(root, str,copy);
          sideF = 1;
        }
        else if (sideF == 1)
        {
          insertRight(root, str,copy);
          sideF = 0;
        }
        else if (sideF == 2)
        {
          insertleftF(root, str,copy);
          sideF = 3;
        }
        else if (sideF == 3)
        {
          insertRightF(root, str,copy);
          sideF = 2;
        }
      }

      start = 1;
      ans = 9;
    }
    else if (ans == 5) // Option 5 Delete file or directory xxxxxxxxxxxxxxxxxxxxxxx
    {
      // struct fileNode *root = pushdir(0, "rootDir");

      printf("To delete a file enter '1', to delete a directory enter '2': ");
      if (
          !scanf("%d", &ans)
          // strlen(err)>0
      )
      {
        scanf("%s", err);
        printf("\n5 Input was was of an incorrect format..\"%s\"", err);
        ans = 9;
        // printf("%d",ans);
        memset(err, 0, 100);
        fflush(stdin);
      }

      if (ans == 2)
      {

        printf("Enter directory name to be deleted: ");
        scanf("%s", str);

        removeleftD(root, str, copy);
        // root = pushdir(("%s",root->left->filename));
        struct fileNode *last;
        printf("\nTraversal in forward direction \n");
        if (root->left != NULL)
        {
          printf(" %s ", root->filename);
          last = root;
          root = root->left;
        }

        memset(dir, 0, 100);
        for (size_t i = 0; i < strlen(("%s", root->filename)); i++)
        {

          dir[i] = root->filename[i];
        }
        // removeRightD(root,str);
      }
      else if (ans == 1)
      {
        printf("Enter file name to be deleted: ");
        scanf("%s", str);
        printf("\nstr: %s/%s\n", root->filename, str);
        // strcat(dire,str);
        printf("%d\n", sideF);
        if (sideF == 0)
        {
          removeleft(root, str, copy);
          sideF = 1;
        }
        else if (sideF == 1)
        {
          removeRight(root, str, copy);
          sideF = 2;
        }
        else if (sideF == 2)
        {
          removeleftF(root, str, copy);
          sideF = 3;
        }
        else if (sideF == 3)
        {
          removeRightF(root, str, copy);
          sideF = 2;
        }
      }
      ans = 9;
    }
    else if (ans == 6)
    { // Option 6 rename file or directory xxxxxxxxxxxxxxx
      printf("\nEnter '1' to change file name, and '2' to change directory name: ");
      if (
          !scanf("%d", &ans)
          // strlen(err)>0
      )
      {
        scanf("%s", err);
        printf("\n6 Input was was of an incorrect format..\"%s\"", err);
        ans = 9;
        // printf("%d",ans);
        memset(err, 0, 100);
        fflush(stdin);
      }

      int suc;
      char dirstr[100] = "";
      char newstr[100] = "";
      if (ans == 1)
      {
        if (("%s", copy->left->filename) != NULL && sideF == 1)
        {

          if (strncmp(("%s", copy->left->filename), (head), 21) != 0)
          {
            printf("\nWhat would you like to rename the current file '%s' to? ", copy->left->filename);
            scanf("%s", str);
            strcat(dirstr, ("%s", copy->filename));
            strcat(dirstr, "/");
            printf("\ndirstr:%s", dirstr);
            strcat(dirstr, ("%s", copy->left->filename));
            printf("\ndirstr2:%s", dirstr);
            strcat(newstr, ("%s", copy->filename));
            strcat(newstr, "/");
            strcat(newstr, str);
            suc = rename(dirstr, newstr);
            memset((copy->left->filename), 0, 100);
            for (size_t i = 0; i < strlen(str); i++)
            {
              copy->left->filename[i] = str[i];
            }
            if (suc == 0)
            {

              printf("\nfile name changed to '%s': ", copy->left->filename);
            }
            else
            {

              printf("\nfile name '%s'  not changed: ", copy->left->filename);
            }
          }
        }
        else if (("%s", copy->right->filename) != NULL && sideF == 0)
        {
          if (strncmp(("%s", copy->right->filename), (head), 21) != 0)
          {
            memset(dirstr, 0, 100);
            memset(newstr, 0, 100);
            printf("\nWhat would you like to rename the current file '%s' to? ", copy->right->filename);
            scanf("%s", str);
            strcat(dirstr, ("%s", copy->filename));
            strcat(dirstr, "/");
            printf("\ndirstr:%s", dirstr);
            strcat(dirstr, ("%s", copy->left->filename));
            printf("\ndirstr2:%s", dirstr);
            strcat(newstr, ("%s", copy->filename));
            strcat(newstr, "/");
            strcat(newstr, str);
            suc = rename(dirstr, newstr);
            memset((copy->left->filename), 0, 100);
            for (size_t i = 0; i < strlen(str); i++)
            {
              copy->right->filename[i] = str[i];
            }
            if (suc == 0)
            {
              printf("\nfile name changed to '%s': ", copy->right->filename);
            }
            else
            {

              printf("\nfile name '%s'  not changed: ", copy->right->filename);
            }
          }
        }
        else
        {
          printf("\nCurrent location is not a file '%s': ", copy->filename);
        }
      }
      else if (ans == 2)
      {
        if (strncmp(("%s", copy->filename), (head), 21) == 0)
        {
          memset(newstr, 0, 100);
          memset(dirstr, 0, 100);
          printf("\nroot directory '%s': ", root->filename);
          printf("\nWhat would you like to rename the current directory '%s' to? ", copy->filename);
          scanf("%s", str);
          int i = strlen(("%s", copy->filename)) - 1;
          for (size_t i = 0; i < strlen(("%s", copy->filename)); i++)
          {
            newstr[i] = copy->filename[i];
          }
          // printf("\ni initial size:'%d': ", i);
          while (i > 0)
          {
            if (newstr[i] != '/')
            {
              // printf("\ni:%d: char: %c",i,copy->filename[i]);
            }
            else
            {
              // printf("\n\ni:%d: char2: %c",i,copy->filename[i]);
              for (size_t j = 0; j < i + 1; j++)
              {
                // printf("\nj:%ld: char23: %c",j,newstr[j]);
                dirstr[j] = newstr[j];
              }
              i = 0;
            }
            i--;
          }
          // strcat(dirstr, ("%s",root->filename));
          // strcat(dirstr, "/");
          printf("\ndirstrD: %s", dirstr);
          memset(newstr, 0, 100);
          // strcat(dirstr, ("%s", copy->left->filename));
          strcat(newstr, dirstr);
          strcat(dirstr, dir);
          strcat(newstr, str);
          suc = rename(("%s", copy->filename), newstr);
          printf("\ncurrent directory may change to '%s': ", newstr);
          if (suc == 0)
          {

            printf("\ncurrent directory changed to '%s': ", newstr);
          }
          memset(dir, 0, 100);
          for (size_t i = 0; i < strlen(str); i++)
          {
            dir[i] = str[i];
          }
        }
        else
        {
          printf("\nCurrent location is not a directory '%s': ", copy->filename);
        }
      }
      ans = 9;
    }
    else if (ans == 7)
    { // Option 7 list all files and directories in current directory xxxxxxxxxxx
      printf("\na List of all the files in current directory\n");
      inorder_list(root, copy);
      ans = 9;
    }
    else // else prompt user for option input
    {
      // if(
      //   "%s",err
      //   // strlen(err)>0
      //   ){
      // printf("\nInput was was of an incorrect format..");
      // ans=9;
      // memset(err,0,100);
      // }
      printf("\nEnter a command number, enter '0' to display list of commanads, and '8' to exit: ");
      if (
          !scanf("%d", &ans)
          // strlen(err)>0
      )
      {
        scanf("%s", err);
        printf("\nelse :Input was was of an incorrect format..\"%s\"", err);

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
  if (root->left != NULL && sideD == 1)
  {
    printf("\nvRootL: %s", root->left->filename);
    printPostorder(root->left, copy);
  }
  else if (root->right != NULL && sideD == 0)
  {
    printf("\n RootR: %s", root->right->filename);
    printPostorder(root->right, copy);
  }
  printf("\n\nList of files and directories:\n ");
  inorder_traversal(root);
  printf("\n");
  // inorder_traversal(copy);
  deleteAll(root, copy);
  // delete(strcat(head,""));
  // fgets(info,100,input);
}