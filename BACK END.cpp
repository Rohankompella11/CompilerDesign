#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
	int i=2,j=0,k=2,k1=0;
	char ip[10],kk[10];
	FILE *fp;
	printf("\nEnter the filename of the intermediate code");
	scanf("%s",&kk);
fp=fopen(kk,"r");
if(fp==NULL)
{ 
	printf("\nError in Opening the file");
	getch();
}
while(!feof(fp))
{
	fscanf(fp,"%s\n",ip); 
	printf("\t\t%s\n",ip);
}
rewind(fp); 
printf("\n------------------------------\n"); 
printf("\tStatement \t\t target code\n"); 
printf("\n------------------------------\n");
while(!feof(fp))
{
	fscanf(fp,"%s",ip); 
	printf("\t%s",ip); 
	printf("\t\tMOV %c,R%d\n\t",ip[i+k],j);
	if(ip[i+1]=='+') 
	printf("\t\tADD");
	else 
	printf("\t\tSUB");
	if(islower(ip[i])) 
	printf("%c,R%d\n\n",ip[i+k1],j);
	else 
	printf("%c,%c\n",ip[i],ip[i+2]); 
	j++;
	k1=2;
	k=0;
} 
printf("\n-------------------------------\n");
getch();
fclose(fp);
}
