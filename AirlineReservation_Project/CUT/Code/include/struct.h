#pragma once
#include<macros.h>
typedef struct customers
{
	int cid,fno,age,not;
	char fname[MAX],lname[MAX],tdate[MAX];
	 
	struct customers *link;
}customer;

typedef struct flights
{
	int flightno, tnos;
	char fname[MAX];
	char sname[MAX] , dname[MAX];
	struct flights *link;
}flight;
		