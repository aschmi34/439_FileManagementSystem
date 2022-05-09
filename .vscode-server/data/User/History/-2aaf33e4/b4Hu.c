#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

void delete(char args[100]){
  char ans[4];
  char ans2[4];

  printf("Are you sure that you want to delete this file? (yes or no): ");
  scanf("%s",ans);

  for (size_t i = 0; i < strlen(ans); i++)
  {
    ans2[i]= ("%c",toupper(ans[i]));
  }
  printf("%s .",ans2);
  printf("%lu",sizeof(ans2));

  if(strcmp(("%s",ans2),"YES")==1){
    printf("\ndeleting...\n");
    remove(args);
  }else{
    printf("\n file was not deleted. \n");
  }


}

void main(){

char str[100];
 char dir[]="/home/jtorne2/.idea/";
printf("Hello.\n\n");
printf("\thelp: display a list of possible commands \n\tcurrentdir: display name of the current directory\n\tmoveup: move up one directory\n\tchangedir: DIRNAME: move into another directory if it is inside current directory\n\tnewfile FILENAME / newdir DIRNAME: creates a new file or directory\n\tdelfile FILENAME / deldir DIRNAME: deletes the specified name or directory
renamefile FILENAME NEWNAME / renamedir DIRNAME NEWNAME: renames spedified file or directory to NEWNAME
list: lists all files and directories in current directory
exit: ends program
");

 printf("Enter file name to be created: ");
 scanf("%s",str); 
  //  printf("%s",str);
  strcat(dir,str);
printf("%s\n",dir); 

//  char number[]=();
 FILE* input = fopen(dir,"w");
 fprintf(input,"%s", str);
 delete(dir);
// fgets(info,100,input);
}