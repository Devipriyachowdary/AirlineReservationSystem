
#include<functions.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<struct.h>
flight *head = NULL;
int validatename(char *name)
{
	for(int i=0 ; i<strlen(name) ; i++)
	{
		if (isalpha(name[i]))
			continue;
		else
			return 0;
	}
	return 1;
}
void addflight( )
{
	FILE *fp = fopen("../data/flights.txt","a");
	flight *temp = (flight *)calloc(1,sizeof(flight));
	printf("\nEnter the flight number : ");
	scanf("%d",&temp->flightno);
	while(1)
	{
		printf("\nEnter the flight name : ");
		scanf("%s",temp->fname);
		if(validatename(temp->fname))
			break;
		else
			printf("Flight Name is not valid ");
	}	
	while(1)
	{
		printf("\nEnter the Source city name : ");
		scanf("%s",temp->sname);
		if(validatename(temp->sname))
			break;
		else
			printf("\nSource city Name is not valid ");
	}
	while(1)
	{
		printf("\nEnter the Destination city name : ");
		scanf("%s",temp->dname);
		if(validatename(temp->dname))
			break;
		else
			printf("Destiation city Name is not valid ");
	}	
	printf("\nEnter total number of seats : ");
	scanf("%d",&temp->tnos);
	temp->link = NULL;
	if(head == NULL)
	{
		head = temp;
		fprintf(fp,"%d %s %s %s %d\n",temp->flightno,temp->fname,temp->sname,temp->dname,temp->tnos);
	}
	else
	{
		flight *q = head;
		while(q->link != NULL)
			q=q->link;
		q->link = temp;
fprintf(fp,"%d %s %s %s %d\n",temp->flightno,temp->fname,temp->sname,temp->dname,temp->tnos);
	}
	fclose(fp);
}
void displayflight( )
{
	FILE *fr = fopen("../data/flights.txt","r");
	if(fr == NULL)
	{
		printf("File does not exists ");
	}
	else
	{
		flight *start = NULL;
		char fname[MAX] , sname[MAX] , dname[MAX];
		int tnos , fno;
		clear();
		printf("\n**************************************************************************************************\n");
		printf("*                   			Details Of Flights				             *");
		printf("\n**************************************************************************************************\n");
		printf("%-10s%-20s%-20s%-20s%-20s","Fno","Name","Source city","Destination city","Number of seats");
		fscanf(fr,"%d%s%s%s%d",&fno,fname,sname,dname,&tnos);
		while(!feof(fr))
		{
			flight *temp = (flight *) calloc(1,sizeof(flight));
			temp->flightno = fno;
			strcpy(temp->fname,fname);
			strcpy(temp->sname,sname);
			strcpy(temp->dname,dname);
			temp->tnos = tnos;
			temp->link = NULL;
			if(start == NULL)
			{
				start = temp;
			}
			else
			{
				flight *q = start;
				while(q->link != NULL)
					q = q->link;
				q->link = temp;
			}
			fscanf(fr,"%d%s%s%s%d",&fno,fname,sname,dname,&tnos);
		
		}
		fclose(fr);
			
		flight *q = start;
		while(q!=NULL)
		{
			printf("\n%-10d%-20s%-20s%-20s%d",q->flightno,q->fname,q->sname,q->dname,q->tnos);
			q=q->link;
		}
	}
}
void searchflight( )
{
FILE *fr = fopen("../data/flights.txt","r");
	if(fr == NULL)
	{
		printf("File does not exists ");
	}
	else
	{
		flight *start = NULL;
		char fname[MAX] , sname[MAX] , dname[MAX];
		int tnos , fno;
		fscanf(fr,"%d%s%s%s%d",&fno,fname,sname,dname,&tnos);
		while(!feof(fr))
		{
			flight *temp = (flight *) calloc(1,sizeof(flight));
			temp->flightno = fno;
			strcpy(temp->fname,fname);
			strcpy(temp->sname,sname);
			strcpy(temp->dname,dname);
			temp->tnos = tnos;
			temp->link = NULL;
			if(start == NULL)
			{
				start = temp;
			}
			else
			{
				flight *q = start;
				while(q->link != NULL)
					q = q->link;
				q->link = temp;
			}
			fscanf(fr,"%d%s%s%s%d",&fno,fname,sname,dname,&tnos);
		
		}
		fclose(fr);
		int no;
		printf("\n\nEnter the flight number ");		
		scanf("%d",&no);
		clear();			
		flight *q = start;
		while(q!=NULL)
		{
			if(no == q->flightno)
			{
			printf("\n**************************************************************************************************\n");
			printf("*                   			Details Of Flights				             *");
			printf("\n**************************************************************************************************\n");
			printf("%-10s%-20s%-20s%-20s%-20s","Fno","Name","Source city","Destination city","Number of seats");
			printf("\n%-10d%-20s%-20s%-20s%d",q->flightno,q->fname,q->sname,q->dname,q->tnos);
			return ;
			}
			q=q->link;
		}
		printf("\n\nFlight does not exists ");
	}
}
void add_customer( )
{
	FILE *fw = fopen("../data/customer.txt","a");
	int cid , fno , age , not;
	char lname[MAX] , fname[MAX] , tdate[MAX];
	printf("\nEnter the customer number : ");
	scanf("%d",&cid);
	printf("\nEnter the flight number : ");
	scanf("%d",&fno);
	printf("\nEnter the first name : ");
	scanf("%s",fname);
	printf("\nEnter the last name : ");
	scanf("%s",lname);
	printf("\nEnter the age : ");
	scanf("%d",&age);
	printf("\nEnter the travelling date : ");
	scanf("%s",tdate);
	printf("\nEnter the number of tickets : ");
	scanf("%d",&not);
	fprintf(fw,"%d %d %s %s %d %s %d\n",cid,fno,fname,lname,age,tdate,not);
	fclose(fw);

	FILE *fr = fopen("../data/flights.txt","r");
	FILE *fw1 = fopen("../data/temp.txt","w");

	
	int fid , nos;
	char sn[MAX] , dn[MAX] , fn[MAX];
	fscanf(fr,"%d%s%s%S%d",&fid,fn,sn,dn,&nos);
	while(!feof(fr))
	{
		if(fid == fno)
			nos = nos - not;
		fprintf(fw1,"%d %s %s %s %d\n",fid,fn,sn,dn,nos);
		fscanf(fr,"%d%s%s%s%d",&fid,fn,sn,dn,&nos);
	}
	fclose(fr);
	fclose(fw1);
	remove("../data/flights.txt");
	rename("../data/temp.txt","../data/flights.txt");
}
void displaycustomer( )
{
	FILE *fb = fopen("../data/customer.txt","r");
	if(fb == NULL)
	{
		printf("File doesnot exist");
	}
	else
	{
	
		int cid,fno,not,age;
		char fname[MAX],lname[MAX],tdate[MAX];
		clear();
		printf("\n*************************************************************************************\n");
		printf("*                   		Details Of Customers           			      *");
		printf("\n*************************************************************************************\n");
		printf("%-10s%-10s%-10s%-10s%-10s%-20s%-20s\n","cid","fno","fname","lname","age","tdate","Number of tickets");
		fscanf(fb,"%d%d%s%s%d%s%d",&cid,&fno,fname,lname,&age,tdate,&not);
		while(!feof(fb))
		{
			printf("%-10d%-10d%-10s%-10s%-10d%-20s%-20d\n",cid,fno,fname,lname,age,tdate,not);
			fscanf(fb,"%d%d%s%s%d%s%d",&cid,&fno,fname,lname,&age,tdate,&not);
		
		}
		fclose(fb);
		
	}
}
void searchcustomer( )
{
FILE *fb = fopen("../data/customer.txt","r");
	if(fb == NULL)
	{
		printf("File not found ");
	}
	else
	{
		int cid,fno,not,age;
		char fname[MAX],lname[MAX],tdate[MAX];
		int no;
		printf("\nEnter the customer id to be searched ");
		scanf("%d",&no);
		clear();
		printf("\n*************************************************************************************\n");
		printf("*                   		Details Of Customers           			      *");
		printf("\n*************************************************************************************\n");
		printf("%-10s%-10s%-10s%-10s%-10s%-20s%-20s\n","cid","fno","fname","lname","age","tdate","Number of tickets");
		fscanf(fb,"%d%d%s%s%d%s%d",&cid,&fno,fname,lname,&age,tdate,&not);
		while(!feof(fb))
		{
			if(cid==no)
			printf("%-10d%-10d%-10s%-10s%-10d%-20s%-20d\n",cid,fno,fname,lname,age,tdate,not);
			fscanf(fb,"%d%d%s%s%d%s%d",&cid,&fno,fname,lname,&age,tdate,&not);
		}
		fclose(fb);
		

	}
}

void menu_admin( )
{
	int choice;
	while(1)
	{
	
		printf("\n\n1:Book the Tickets\n\n2:Flights\n\n3:Exit");
		printf("\n\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
	
			case 1: clear ();
				while(1)
				{
		printf("\n\n*******************Customer Choices******************");
		printf("\n\n1:Add customer and Book the ticket\n\n2:Display customer\n\n3:Search customer\n\n4:Back to main menu");
		printf("\n\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: add_customer( );
				break;
			case 2: displaycustomer( );
				break;
			case 3: searchcustomer( );
				break;
			case 4:menu_admin( );
			default:printf("\nInvalid Choice!!!");

		}
				}
				break;
			case 2: clear ();
				while(1)
				{
		printf("\n\n********************Flight Choices*******************");
		printf("\n\n1:Add Flight\n\n2:Display Flight\n\n3:Search Flights\n\n4:Back to main menu");
		printf("\n\nEnter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: addflight( );
				break;
			case 2: displayflight ();
				break;
			case 3: searchflight( );
				break;
			case 4:menu_admin( );
			default:printf("\nInvalid Choice!!!");

		}
				}
				break;
		
			case 3: exit(0);
		}
	}
}

