#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "projhead.h"

void showcal() {
	//defining needed variables such as: time variables, months names and counter variables
	struct tm *t;
	time_t rawtime;
	time(&rawtime);
	t = localtime(&rawtime);
	int i, w, counter;
	char *months[] = { "Jan","Feb","Mar","Apr","May","Jun",
		"Jul","Aug","Sep","Oct","Nov","Dec" };

	//printing the top of calendar.
	printf("%s %d\n", months[t->tm_mon], t->tm_year + 1900);
	puts("\tSa\tSu\tMo\tTu\tWe\tTh\tFr");

	//determinig what is the wday of first day of the month and printing the first day.
	for (i = t->tm_mday, w = t->tm_wday; i != 1; w--, i--);
	w %= 7;
	w = w>0 ? w : -w;
	switch (w) {
	case 0:
		printf("\t\t");
		counter = 2;
		break;
	case 1:
		printf("\t\t\t");
		counter = 3;
		break;
	case 2:
		printf("\t\t\t\t");
		counter = 4;
		break;
	case 3:
		printf("\t\t\t\t\t");
		counter = 5;
		break;
	case 4:
		printf("\t\t\t\t\t\t");
		counter = 6;
		break;
	case 5:
		printf("\t\t\t\t\t\t\t");
		counter = 7;
		break;
	case 6:
		printf("\t");
		counter = 1;
		break;
	}
	if (t->tm_mday == 1)
		printf("[1]\t");
	else
		printf("1\t");

	//determining how many days are there in months.
	int cofds;
	switch (t->tm_mon) {
	case 1:
		cofds = 28;
		break;
	case 0:
	case 2:
	case 4:
	case 6:
	case 7:
	case 9:
	case 10:
		cofds = 31;
		break;
	case 3:
	case 5:
	case 8:
		cofds = 30;
		break;
	}

	//printing the calendar
	for (i = 2; i <= cofds; i++) {
		if (i == t->tm_mday)
			printf("[%d]\t", i);
		else
			printf("%d\t", i);
		counter++;
		if (counter % 7 == 0)
			printf("\n\t");
	}
	puts("");
	return;
}


void pos(short C, short R)
{
	COORD xy;
	xy.X = C;
	xy.Y = R;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), xy);
}


void clr()
{
	pos(0, 0);
	for (int j = 0; j < 10000; j++)
		printf(" ");//prints 10000 space characters
	pos(0, 0);//sets the cursor position in the top of the console
}
