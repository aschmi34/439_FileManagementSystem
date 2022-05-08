#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

void delete(char args[100]){
  char ans[3];
  char ans2[3];

  printf("Are you sure that you want to delete this file? (yes or no): ");
  scanf("%s",ans);

  for (size_t i = 0; i < strlen(ans); i++)
  {
    ans2[i]= ("%c",toupper(ans[i]));
  }
  printf("%s .",ans2);

  if(strcmp(ans2,"YES")==1){
    remove(args);
  }else{
    printf("\n file was not deleted. \n");
  }


}

void main(){

char str[100];
 char dir[]="/home/jtorne2/.idea/";
 int infot[50];
 int tok;
 char tokk;
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