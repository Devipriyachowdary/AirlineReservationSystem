#include<macros.h>
#include<string.h>
#include<stdlib.h>
#include<functions.h>
#include<stdio.h>
int admin( )
{
	FILE *info;
	info = fopen("../data/password.txt","r");

	if (info == NULL)
	{
		printf("\nFile does not exists ");
		return 0;
	}
	else
	{
		clear( );
		char user[MAX] , pass[MAX] , username[MAX] , password[MAX];
		fscanf(info,"%s %s",user,pass);
		fclose(info);
		
		printf("\n\nEnter the username : ");
		scanf("%s",username);
		printf("\nEnter the password : ");
		scanf("%s",password);		

		if( strcmp(user,username)==0 && strcmp(pass,password)==0)
		{
			printf("\n\n**************************************************");
			printf("\n	  Admin Login sucessfully\n");
			printf("**************************************************\n");
			return 1;
		}
		else 
			return 0;
	}
}
