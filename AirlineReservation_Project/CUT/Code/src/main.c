#include<functions.h>
#include<stdlib.h>
#include<stdio.h>
int main( )
{
	printf("\n\n\n\n\n\n\t\tWelcome to Airline Reservation System");
	while(1)
	{
		int result = admin( );
		if(result == 1)
			menu_admin( );
		else
			printf("\nUsername and password is incorrect\n\n ");
	}
	return EXIT_SUCCESS;
}
