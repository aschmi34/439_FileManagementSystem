#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main()
{
 char str[100];
 char info[100];
 int infot[50];
 int tok;
 char tokk;
 printf("Enter file name: ");
 scanf("%s",str); 
  //  printf("%s",str);
// printf(str);
//  char number[]=();
 FILE* input = fopen(str,"r");
//  fscanf(input,"%s", info);
// fgets(info,100,input);
//  fprintf(input,"%s",info);
 printf("info:");
 printf("%zu:\n",strlen(info));
 printf("%s:\n",info);
//  printf("%zu\n",sizeof infot); 
 int i =0;
//  str[100]={};
 char * cptr = info;
  if (! input ) // equivalent to saying if ( in_file == NULL ) 
             {  
                printf("oops, file can't be read\n"); 
                exit(-1); 
             } 
  while (1)  
             { 
               // scanf(info, "%c",tokk);
               // printf("%s\n",info);
               // scanf("%c",&tokk);
               tok =fgetc(info);
               // if(tok ==" "){
               //    i++;
               // }else{
               printf("info: %c\n", tok);
               // i++;

               // }
                // cptr++;
             } 
 printf("\nHello World\n");
}