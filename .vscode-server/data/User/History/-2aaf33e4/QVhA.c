#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

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