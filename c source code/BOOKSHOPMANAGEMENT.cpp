#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
char date[20];
char uname[20];
char bname[20];
char mno[15];
long int cost;
int n,i;


//function for writing entry book into file
void write()
{
	FILE *fp;
	char dat[20];
	char unam[20];
	char bnam[20];
	char mn[15];
	long int cos;
	printf("\nEnter Date   ::");
	scanf("%s",dat);
	printf("\nEnter Name of Customer  ::");
	scanf("%s",unam);
	printf("\nEnter mobile number    ::");
	scanf("%s",bnam);
	printf("\nEnter Name of the book    ::");
	scanf("%s",mn);
	printf("\nEnter cost of the book     ::");
	scanf("%ld",&cos);
	fp=fopen("Record.txt","a");
	fprintf(fp,"\n%s %s %s %s %ld\n",dat,unam,bnam,mn,cos);
	printf("\n Record written successfully!!!!");
}

//function to display the record by date
void display(char da[])
{
	FILE *fp;
	int res;
	fp=fopen("Record.txt","r");
	while(fscanf(fp,"%s %s %s %s %ld",date,uname,bname,mno,&cost)!=EOF)
	{
		res = strcmp(date,da);
		if(res==0)
		{
			printf("\n\n Customer name = %s",uname);
			printf("\n Mobile no = %s",mno);
			printf("\n Book name = %s",bname);
			printf("\n Book cost = %ld",cost);
		}
	}
	fclose(fp);
  }
  
  
  int main()  
  {
  	int ch;
  	char lm[20];
	do
	{
		printf("\n\n\n\tWELCOME TO BOOK SHOP\n");
		printf("\n Press <1> to create entry for book");
		printf("\n Press <2> to display on specific date");
		printf("\n Press <0> to exit");
		printf("\n\nEnter choice  ::");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:write();
			   break;
			case 2:printf("\nEnter date  ::");
			   scanf("%s",&lm);
			   display(lm);
			   break;
			case 0:exit(0);
			   default:printf("\n Invalid selection");
		}
		getch();
	}
	while(ch !=0);
	return 0;
	 
  }


