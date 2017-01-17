#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <conio.h>
#include "projhead.h"


int  user_level = 0, exit_value = 0;
char user_name[30];
long int today ;
char path[500];
char curdir[30]="root"; //current directory & user

//game section------------------------------------
int lvl (unsigned int level);//get level

int lvl1 (unsigned int type11[9][9],unsigned int type1[9][9],int x, int y,int sum);

void T (int lvl1(unsigned int type11[9][9],unsigned int type1[9][9],int x, int y,int sum),unsigned int type11[9][9],unsigned int type1[9][9],int x, int y,int sum);

void lvlT1(void T (int lvl1(unsigned int type11[9][9],unsigned int type1[9][9],int x, int y,int sum),unsigned int type11[9][9],unsigned int type1[9][9],int x, int y,int sum),int lvl1(unsigned int type11[9][9],unsigned int type1[9][9],int x, int y,int sum),unsigned int type11[9][9],unsigned int type1[9][9],int x, int y,int sum);

int lvl2 (unsigned int type22[16][16],unsigned int type2[16][16],int x, int y,int sum);

void T2 (int lvl2(unsigned int type22[16][16],unsigned int type2[16][16],int x, int y,int sum),unsigned int type22[16][16],unsigned int type2[16][16],int x, int y,int sum);

void lvlT2(void T2 (int lvl2(unsigned int type22[16][16],unsigned int type2[16][16],int x, int y,int sum),unsigned int type22[16][16],unsigned int type2[16][16],int x, int y,int sum),int lvl2(unsigned int type22[16][16],unsigned int type2[16][16],int x, int y,int sum),unsigned int type22[16][16],unsigned int type2[16][16],int x, int y,int sum);

int lvl3 (unsigned int type33[22][22],unsigned int type3[22][22],int x, int y,int sum);

void T3 (int lvl3(unsigned int type33[22][22],unsigned int type3[22][22],int x, int y,int sum),unsigned int type33[22][22],unsigned int type3[22][22],int x, int y,int sum);

void lvlT3(void T3 (int lvl3(unsigned int type33[22][22],unsigned int type3[22][22],int x, int y,int sum),unsigned int type33[22][22],unsigned int type3[22][22],int x, int y,int sum),int lvl3(unsigned int type33[22][22],unsigned int type3[22][22],int x, int y,int sum),unsigned int type33[22][22],unsigned int type3[22][22],int x, int y,int sum);

void game (void)
{
	srand(time(NULL));
	int loser = 0;
	int sum = 0;
	char str = 234;
	char str1 = 223;
	char str2 = 143;
	int std;
	int m1, m2, x, y;	
	int pooch = 0;
	unsigned int wrong = 0;
	unsigned int level;
	unsigned int type1 [9][9]={};
	unsigned int type11[9][9]={};
	unsigned int type2 [16][16]={};
	unsigned int type22[16][16]={};
	unsigned int type3 [22][22]={};
	unsigned int type33[22][22]={};
	
	int g = 0;
	int f = 0;
	//end ...............................................
	FILE*game;
	char savepath[50];
		sprintf(savepath, "%s/savegame.txt",user_name);
		game = fopen(savepath,"r");
	fscanf(game,"%d", &g);
	if(g != -1){
		printf("                                %s\n                               %s\n                              ","if you want start a new game press 1","if you want keep on the last game press 2");
		scanf("%d",&f);
		while(!feof(stdin)){
			if(f == 1 || f == 2)
				break;
			else{
				printf("wrong command!\n");
				scanf("%d",&f);
			}
		}
		if(f == 1){
			fclose(game);
			char savepath[50];
		sprintf(savepath, "%s/savegame.txt",user_name);
		game = fopen(savepath,"w");
			fprintf(game,"%d",-1);
			rewind(game);
			g = -1;
			fclose(game);
		}
		else{
			fclose(game);
		}
	}

	if(g != -1){
		char savepath[50];
		sprintf(savepath, "%s/savegame.txt",user_name);
		game = fopen(savepath,"r");
		fscanf(game,"%d",&level);
		printf("level is%d\n",level);
		if(level == 1){
			for(int j = 0;j < 9;j++){
				for(int i = 0;i < 9;i++){
					fscanf(game,"%u",&type1[i][j]);
				}
			}
			for(int j = 0;j < 9;j++){
				for(int i = 0;i < 9;i++){
					fscanf(game,"%u",&type11[i][j]);
				}
			}
		}
		else
		{
			if(level == 2)
			{
				for(int j = 0;j < 16;j++){
					for(int i = 0;i < 16;i++){
						fscanf(game,"%u",&type2[i][j]);
					}
				}
				for(int j = 0;j < 16;j++){
					for(int i = 0;i < 16;i++){
						fscanf(game,"%u",&type22[i][j]);
					}
				}
			}
			else
			{
				for(int j = 0;j < 22;j++){
					for(int i = 0;i < 22;i++){
						fscanf(game,"%u",&type3[i][j]);
					}
				}
				for(int j = 0;j < 22;j++){
					for(int i = 0;i < 22;i++){
						fscanf(game,"%u",&type33[i][j]);
					}
				}
			}
		}
		fclose(game);
	//start game with x & y
		std = 3;
	while(std == 3){
		std = 3;
		clr();
		switch (level){
	case 1://////////////////////////////////////////////////////////////level 1
		color(3);
		printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9\n");
		for(int j = 0;j < 9;j++){
			color(3);
			printf("                  %2d",j+1);
			for(int i = 0;i < 9;i++){
				if (type11[i][j] == 0)
					printf("%c ",str);
				else{
					if(type11[i][j] == 9)
						printf("%c ",str1);
					else{
						if(type11[i][j] == 10){
							color(5);
							printf("%c ",str2);
							color(3);
						}
						else
						{
							color(5);
							printf("%u ",type11[i][j]);
							color(3);
						}
					}
				}
			}
			printf("\n");
		}
		color(7);
		while(!feof(stdin)){
			printf("%s\n%s","please Enter Coordinates","Enter x: ");
			scanf("%d",&x);
			while(!feof(stdin)){
				if(x > 0 && x < 10)
					break;
				else{
					printf("%s\n%s","please Enter right Coordinates!!!","Enter x again : ");
					scanf("%d",&x);
				}
			}
			if(feof(stdin)){
				std = 1;
				break;
			}
			printf("Enter y: ");
			scanf("%d",&y);
			while(!feof(stdin)){
				if(y > 0 && y < 10)
					break;
				else{
					printf("%s\n%s","please Enter right Coordinates!!!","Enter y again : ");
					scanf("%d",&y);
				}
			}
			if(feof(stdin)){
				std = 1;
				break;
			}
			x--;
			y--;
			clr();
			if(type1[x][y] == 0){
				lvlT1(T,lvl1,type11,type1,x,y,sum);			
				for(int o = 0; o < 81; o++){
					for(int i = 0;i < 9;i++){
						for(int j = 0;j < 9;j++){
							if(type11[i][j] == 0){
								lvlT1(T,lvl1,type11,type1,i,j,sum);
							}
						}
					}
				}
				color(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9\n");
		for(int j = 0;j < 9;j++){
			color(3);
			printf("                  %2d",j+1);
			for(int i = 0;i < 9;i++){
				if (type11[i][j] == 0)
					printf("%c ",str);
				else{
					if(type11[i][j] == 9)
						printf("%c ",str1);
					else{
						if(type11[i][j] == 10){
							color(5);
							printf("%c ",str2);
							color(3);
						}
						else
						{
							color(5);
							printf("%u ",type11[i][j]);
							color(3);
						}
					}
				}
			}
			printf("\n");
		}
		color(7);
			}
			else{
				loser = 1;
				break;
			}
			pooch = 0;
			for(int j = 0;j < 9;j++){
				for(int i = 0;i < 9;i++){
					if(type11[j][i] != 9)
						pooch++;
				}
			}
			if(pooch == 71)
				break;
			if(loser == 1)
				break;
		}
		break;/////////////////////////////////////////////////end level 1


	case 2:////////////////////////////////////////////////////start level 2
		color(3);
		printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9 .........\n");
		for(int j = 0;j < 16;j++){
			color(3);
			printf("                  %2d",j+1);
			for(int i = 0;i < 16;i++){
				if (type22[i][j] == 0)
					printf("%c ",str);
				else{
					if(type22[i][j] == 9)
						printf("%c ",str1);
					else{
						if(type22[i][j] == 10){
							color(5);
							printf("%c ",str2);
							color(3);
						}
						else
						{
							color(4);
							printf("%u ",type22[i][j]);
							color(3);
						}
					}
				}
			}
			printf("\n");
		}
		color(7);
		while(!feof(stdin)){
			printf("%s\n%s","please Enter Coordinates","Enter x: ");
			scanf("%d",&x);
			while(!feof(stdin)){
				if(x > 0 && x < 17)
					break;
				else{
					printf("%s\n%s","please Enter right Coordinates!!!","Enter x again: ");
					scanf("%d",&x);
				}
			}
			if(feof(stdin)){
				std = 1;
				break;
			}
			printf("Enter y: ");
			scanf("%d",&y);
			while(!feof(stdin)){
				if(y > 0 && y < 17)
					break;
				else{
					printf("%s\n%s","please Enter right Coordinates!!!","Enter y again: ");
					scanf("%d",&y);
				}
			}
			if(feof(stdin)){
				std = 1;
				break;
			}
			x--;
			y--;
			clr();
			if(type2[x][y] == 0)
			{
				lvlT2(T2,lvl2,type22,type2,x,y,sum);
			
				for(int o = 0; o < 81; o++){
					for(int i = 0;i < 16;i++){
						for(int j = 0;j < 16;j++){
							if(type22[i][j] == 0){
								lvlT2(T2,lvl2,type22,type2,i,j,sum);
							}
						}
					}
				}
				color(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9 ........\n");
		for(int j = 0;j < 16;j++){
			color(3);
			printf("                  %2d",j+1);
			for(int i = 0;i < 16;i++){
				if (type22[i][j] == 0)
					printf("%c ",str);
				else{
					if(type22[i][j] == 9)
						printf("%c ",str1);
					else{
						if(type22[i][j] == 10){
							color(5);
							printf("%c ",str2);
							color(3);
						}
						else
						{
							color(4);
							printf("%u ",type22[i][j]);
							color(3);
						}
					}
				}
			}
			printf("\n");
		}
		color(7);
	}
	else{
		loser = 1;
		break;
	}
	pooch = 0;
	for(int j = 0;j < 16;j++){
		for(int i = 0;i < 16;i++){
			if(type22[j][i] != 9)
				pooch++;
		}
	}
	if(pooch == 216)
		break;
	if(loser == 1)
		break;
	}
		break;///////////////////////////////////////////////////////////end level 2



	case 3://////////////////////////////////////////////////////////////level 3
		color(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9 ..............\n");
				for(int j = 0;j < 22;j++){
					color(3);
					printf("                  %2d",j+1);
					for(int i = 0;i < 22;i++){
						if (type33[i][j] == 0)
							printf("%c ",str);
						else{
							if(type33[i][j] == 9)
								printf("%c ",str1);
							else{
								if(type33[i][j] == 10){
									color(5);
									printf("%c ",str2);
									color(3);
								}
								else
								{
									color(4);
									printf("%u ",type33[i][j]);
									color(3);
								}
							}
						}
					}
					printf("\n");
				}
				color(7);

		while(!feof(stdin)){
			printf("%s\n%s","please Enter Coordinates","Enter x: ");
			scanf("%d",&x);
			while(!feof(stdin)){
				if(x > 0 && x < 23)
					break;
				else{
					printf("%s\n%s","please Enter right Coordinates!!!","Enter x again : ");
					scanf("%d",&x);
				}
			}
			if(feof(stdin)){
				std = 1;
				break;
			}
			printf("Enter y: ");
			scanf("%d",&y);
			while(!feof(stdin)){
				if(y > 0 && y < 23)
					break;
				else{
					printf("%s\n%s","please Enter right Coordinates!!!","Enter y again : ");
					scanf("%d",&y);
				}
			}
			if(feof(stdin)){
				std = 1;
				break;
			}
			x--;
			y--;
			clr();
			if(type3[x][y] == 0)
			{
				lvlT3(T3,lvl3,type33,type3,x,y,sum);

				for(int o = 0; o < 90; o++){
					for(int i = 0;i < 22;i++){
						for(int j = 0;j < 22;j++){
							if(type33[i][j] == 0){
								lvlT3(T3,lvl3,type33,type3,i,j,sum);
							}
						}
					}
				}
				color(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9 ..............\n");
				for(int j = 0;j < 22;j++){
					color(3);
					printf("                  %2d",j+1);
					for(int i = 0;i < 22;i++){
						if (type33[i][j] == 0)
							printf("%c ",str);
						else{
							if(type33[i][j] == 9)
								printf("%c ",str1);
							else{
								if(type33[i][j] == 10){
									color(5);
									printf("%c ",str2);
									color(3);
								}
								else
								{
									color(4);
									printf("%u ",type33[i][j]);
									color(3);
								}
							}
						}
					}
					printf("\n");
				}
				color(7);
			}
			else
			{
				loser = 1;
				break;
			}
					pooch = 0;
			for(int j = 0;j < 22;j++){
				for(int i = 0;i < 22;i++){
					if(type33[j][i] != 9)
						pooch++;
				}
			}
			if(pooch == 394)
				break;
			}
			if(loser == 1)
			break;
		break;
		}/////////////////////////////////////////////////////////////////////end level 3
		if(loser == 1)
			break;
		if(pooch == 71 && level == 1)
			break;
		if(pooch == 214 && level == 2)
			break;
		if(pooch == 389 && level == 3)
			break;
				if(std == 1){///////////////////////////////////////////////////////////////if press EOF
				printf("%s\n%s\n%s\n","for exit press: '1'","for Save and Exit press: '2'","keep on the game press: '3'");
					scanf("%d",&std);
					if(std == 1){
						fprintf(game,"\d",-1);
						fclose(game);
						return;
					}
					else{
						if(std == 2){
							char savepath[50];
							sprintf(savepath, "%s/savegame.txt",user_name);
							game = fopen(savepath,"w");
					fprintf(game,"%d\n",level);
					if(level == 1){
						for(int j = 0;j < 9;j++){
							for(int i = 0;i < 9;i++){
								fprintf(game,"%u\t",type1[i][j]);
							}
							fprintf(game,"\n");
						}
						for(int j = 0;j < 9;j++){
							for(int i = 0;i < 9;i++){
								fprintf(game,"%u\t",type11[i][j]);
							}
							fprintf(game,"\n");
						}
					}
					else
					{
						if(level == 2)
						{
							for(int j = 0;j < 16;j++){
								for(int i = 0;i < 16;i++){
									fprintf(game,"%u\t",type2[i][j]);
								}
								fprintf(game,"\n");
							}
							for(int j = 0;j < 16;j++){
								for(int i = 0;i < 16;i++){
									fprintf(game,"%u\t",type22[i][j]);
								}
								fprintf(game,"\n");
							}
						}
						else
						{
							for(int j = 0;j < 22;j++){
								for(int i = 0;i < 22;i++){
									fprintf(game,"%u\t",type3[i][j]);
								}
								fprintf(game,"\n");
							}
							for(int j = 0;j < 22;j++){
								for(int i = 0;i < 22;i++){
									fprintf(game,"%u\t",type33[i][j]);
								}
								fprintf(game,"\n");
							}
						}
					}
						fclose(game);
						return;
						}
						else{
							if(std = 3){
							std = 3;
							}
							else{
								std = 4;
								break;
							}
						}
					}
				}//////////////////////////////////////////////////////////////////////////end EOF
				if (loser == 1)
					break;
				if(pooch == 71 && level == 1)
					break;
				if(pooch == 214 && level == 2)
					break;
				if(pooch == 389 && level == 3)
					break;
			}
		}
		///////////////////////////////////////////new game
	else{
		std = 4;
		while(std == 4){
		for(int i = 0;i < 9;i++){
			for(int j = 0;j < 9;j++){
				type11[i][j] = 9;
				type1[i][j] = 0;
			}
		}
		for(int i = 0;i < 16;i++){
			for(int j = 0;j < 16;j++){
				type22[i][j] = 9;
				type2[i][j] = 0;
			}
		}
		for(int i = 0;i < 22;i++){
			for(int j = 0;j < 22;j++){
				type33[i][j] = 9;
				type3[i][j] = 0;
			}
		}
		printf("%s\n%s\n%s\n%s\n%s","please choose the level of the game: "
							,"level 1:  9 * 9  &  10 Bombs"
							,"level 2: 16 * 16 &  42 Bombs"
							,"level 3: 22 * 22 &  95 Bombs"
							,"level : ");
	scanf("%u",&level);
	level = lvl(level);
	srand(time(NULL));
	switch(level){//start bomb
		
	case 1:
		for (int i = 0; i < 10;i++){
			m1 = rand() % 9;
			m2 = rand() % 9;
			if(type1 [m1][m2] != 0){
				i--;
			}
			else{
				type1 [m1][m2] = 1;
			}
		}
		break;
	case 2:
		for (int i = 0; i < 42;i++){
			m1 = rand() % 16;
			m2 = rand() % 16;
			if(type2 [m1][m2] != 0){
				i--;
			}
			else{
				type2 [m1][m2] = 1;
			}
		}
	case 3:
		for (int i = 0; i < 95;i++){
			m1 = rand() % 22;
			m2 = rand() % 22;
			if(type3 [m1][m2] != 0){
				i--;
			}
			else{
				type3 [m1][m2] = 1;
			}
		}
	}//end bomb
	//start game with x & y
		std = 3;
	while(std == 3){
		std = 3;
		clr();
		switch (level){
	case 1://////////////////////////////////////////////////////////////level 1
		color(3);
		printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9\n");
		for(int j = 0;j < 9;j++){
			color(3);
			printf("                  %2d",j+1);
			for(int i = 0;i < 9;i++){
				if (type11[i][j] == 0)
					printf("%c ",str);
				else{
					if(type11[i][j] == 9)
						printf("%c ",str1);
					else{
						if(type11[i][j] == 10){
							color(5);
							printf("%c ",str2);
							color(3);
						}
						else
						{
							color(5);
							printf("%u ",type11[i][j]);
							color(3);
						}
					}
				}
			}
			printf("\n");
		}
		color(7);
		while(!feof(stdin)){
			printf("%s\n%s","please Enter Coordinates","Enter x: ");
			scanf("%d",&x);
			while(!feof(stdin)){
				if(x > 0 && x < 10)
					break;
				else{
					printf("%s\n%s","please Enter right Coordinates!!!","Enter x again: ");
					scanf("%d",&x);
				}
			}
			if(feof(stdin)){
				std = 1;
				break;
			}
			printf("Enter y: ");
			scanf("%d",&y);
			while(!feof(stdin)){
				if(y > 0 && y < 10)
					break;
				else{
					printf("%s\n%s","please Enter right Coordinates!!!","Enter y again: ");
					scanf("%d",&y);
				}
			}
			if(feof(stdin)){
				std = 1;
				break;
			}
			x--;
			y--;
			clr();
			if(type1[x][y] == 0){
				lvlT1(T,lvl1,type11,type1,x,y,sum);			
				for(int o = 0; o < 81; o++){
					for(int i = 0;i < 9;i++){
						for(int j = 0;j < 9;j++){
							if(type11[i][j] == 0){
								lvlT1(T,lvl1,type11,type1,i,j,sum);
							}
						}
					}
				}
				color(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9\n");
		for(int j = 0;j < 9;j++){
			color(3);
			printf("                  %2d",j+1);
			for(int i = 0;i < 9;i++){
				if (type11[i][j] == 0)
					printf("%c ",str);
				else{
					if(type11[i][j] == 9)
						printf("%c ",str1);
					else{
						if(type11[i][j] == 10){
							color(5);
							printf("%c ",str2);
							color(3);
						}
						else
						{
							color(5);
							printf("%u ",type11[i][j]);
							color(3);
						}
					}
				}
			}
			printf("\n");
		}
		color(7);
			}
			else{
				loser = 1;
				break;
			}
			pooch = 0;
			for(int j = 0;j < 9;j++){
				for(int i = 0;i < 9;i++){
					if(type11[j][i] != 9)
						pooch++;
				}
			}
			if(pooch == 71)
				break;
			if(loser == 1)
				break;
		}
			/////////////////////////////////////////////////end level 1
		break;

	case 2:////////////////////////////////////////////////////start level 2
		color(3);
		printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9 .........\n");
		for(int j = 0;j < 16;j++){
			color(3);
			printf("                  %2d",j+1);
			for(int i = 0;i < 16;i++){
				if (type22[i][j] == 0)
					printf("%c ",str);
				else{
					if(type22[i][j] == 9)
						printf("%c ",str1);
					else{
						if(type22[i][j] == 10){
							color(5);
							printf("%c ",str2);
							color(3);
						}
						else
						{
							color(4);
							printf("%u ",type22[i][j]);
							color(3);
						}
					}
				}
			}
			printf("\n");
		}
		color(7);
		while(!feof(stdin)){
			printf("%s\n%s","please Enter Coordinates","Enter x: ");
			scanf("%d",&x);
			while(!feof(stdin)){
				if(x > 0 && x < 17)
					break;
				else{
					printf("%s\n%s","please Enter right Coordinates!!!","Enter x again: ");
					scanf("%d",&x);
				}
			}
			if(feof(stdin)){
				std = 1;
				break;
			}
			printf("Enter y: ");
			scanf("%d",&y);
			while(!feof(stdin)){
				if(y > 0 && y < 17)
					break;
				else{
					printf("%s\n%s","please Enter right Coordinates!!!","Enter y again : ");
					scanf("%d",&y);
				}
			}
			if(feof(stdin)){
				std = 1;
				break;
			}
			x--;
			y--;
			clr();
			if(type2[x][y] == 0)
			{
				lvlT2(T2,lvl2,type22,type2,x,y,sum);
			
				for(int o = 0; o < 81; o++){
					for(int i = 0;i < 16;i++){
						for(int j = 0;j < 16;j++){
							if(type22[i][j] == 0){
								lvlT2(T2,lvl2,type22,type2,i,j,sum);
							}
						}
					}
				}
				color(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9 ........\n");
		for(int j = 0;j < 16;j++){
			color(3);
			printf("                  %2d",j+1);
			for(int i = 0;i < 16;i++){
				if (type22[i][j] == 0)
					printf("%c ",str);
				else{
					if(type22[i][j] == 9)
						printf("%c ",str1);
					else{
						if(type22[i][j] == 10){
							color(5);
							printf("%c ",str2);
							color(3);
						}
						else
						{
							color(4);
							printf("%u ",type22[i][j]);
							color(3);
						}
					}
				}
			}
			printf("\n");
		}
		color(7);
	}
	else{
		loser = 1;
		break;
	}
	pooch = 0;
	for(int j = 0;j < 16;j++){
		for(int i = 0;i < 16;i++){
			if(type11[j][i] != 9)
				pooch++;
		}
	}
	if(pooch == 214)
		break;
	if(loser == 1)
		break;
	}
		break;///////////////////////////////////////////////////////////end level 2



	case 3://////////////////////////////////////////////////////////////level 3
		color(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9 ..............\n");
				for(int j = 0;j < 22;j++){
					color(3);
					printf("                  %2d",j+1);
					for(int i = 0;i < 22;i++){
						if (type33[i][j] == 0)
							printf("%c ",str);
						else{
							if(type33[i][j] == 9)
								printf("%c ",str1);
							else{
								if(type33[i][j] == 10){
									color(5);
									printf("%c ",str2);
									color(3);
								}
								else
								{
									color(4);
									printf("%u ",type33[i][j]);
									color(3);
								}
							}
						}
					}
					printf("\n");
				}
				color(7);

		while(!feof(stdin)){
			printf("%s\n%s","please Enter Coordinates","Enter x: ");
			scanf("%d",&x);
			while(!feof(stdin)){
				if(x > 0 && x < 23)
					break;
				else{
					printf("%s\n%s","please Enter right Coordinates!!!","Enter x again: ");
					scanf("%d",&x);
				}
			}
			if(feof(stdin)){
				std = 1;
				break;
			}
			printf("Enter y: ");
			scanf("%d",&y);
			while(!feof(stdin)){
				if(y > 0 && y < 23)
					break;
				else{
					printf("%s\n%s","please Enter right Coordinates!!!","Enter y again : ");
					scanf("%d",&y);
				}
			}
			if(feof(stdin)){
				std = 1;
				break;
			}
			x--;
			y--;
			clr();
			if(type3[x][y] == 0)
			{
				lvlT3(T3,lvl3,type33,type3,x,y,sum);

				for(int o = 0; o < 81; o++){
					for(int i = 0;i < 22;i++){
						for(int j = 0;j < 22;j++){
							if(type33[i][j] == 0){
								lvlT3(T3,lvl3,type33,type3,i,j,sum);
							}
						}
					}
				}
				color(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9 ..............\n");
				for(int j = 0;j < 22;j++){
					color(3);
					printf("                  %2d",j+1);
					for(int i = 0;i < 22;i++){
						if (type33[i][j] == 0)
							printf("%c ",str);
						else{
							if(type33[i][j] == 9)
								printf("%c ",str1);
							else{
								if(type33[i][j] == 10){
									color(5);
									printf("%c ",str2);
									color(3);
								}
								else
								{
									color(4);
									printf("%u ",type33[i][j]);
									color(3);
								}
							}
						}
					}
					printf("\n");
				}
				color(7);
			}
			else
			{
				loser = 1;
				break;
			}
					pooch = 0;
			for(int j = 0;j < 22;j++){
				for(int i = 0;i < 22;i++){
					if(type33[j][i] != 9)
						pooch++;
				}
			}
			if(pooch == 389)
				break;
			if(loser == 1)
				break;
			}
		break;
		}/////////////////////////////////////////////////////////////////////end level 3
		if (loser == 1)
				break;
		if(pooch == 71)
				break;
		if(pooch == 214)
				break;
		if(pooch == 389)
				break;



		if(std == 1){///////////////////////////////////////////////////////////////if press EOF
		printf("%s\n%s\n%s\n","for Exit press '1'","for Save and Exit press '2'","keep on game press '3'");
			scanf("%d",&std);
			if(std == 1)
				return;
			else{
				if(std == 2){///////////////////////////////////////save
					char savepath[50];
					sprintf(savepath, "%s/savegame.txt",user_name);
					game = fopen(savepath,"w");
					fprintf(game,"%d\n",level);
					if(level == 1){
						for(int j = 0;j < 9;j++){
							for(int i = 0;i < 9;i++){
								fprintf(game,"%u\t",type1[i][j]);
							}
							fprintf(game,"\n");
						}
						for(int j = 0;j < 9;j++){
							for(int i = 0;i < 9;i++){
								fprintf(game,"%u\t",type11[i][j]);
							}
							fprintf(game,"\n");
						}
					}
					else
					{
						if(level == 2)
						{
							for(int j = 0;j < 16;j++){
								for(int i = 0;i < 16;i++){
									fprintf(game,"%u\t",type2[i][j]);
								}
								fprintf(game,"\n");
							}
							for(int j = 0;j < 16;j++){
								for(int i = 0;i < 16;i++){
									fprintf(game,"%u\t",type22[i][j]);
								}
								fprintf(game,"\n");
							}
						}
						else
						{
							for(int j = 0;j < 22;j++){
								for(int i = 0;i < 22;i++){
									fprintf(game,"%u\t",type3[i][j]);
								}
								fprintf(game,"\n");
							}
							for(int j = 0;j < 22;j++){
								for(int i = 0;i < 22;i++){
									fprintf(game,"%u\t",type33[i][j]);
								}
								fprintf(game,"\n");
							}
						}
					}
					fclose(game);
					return;
				}
				else{
					if(std = 3){
					std = 3;
					}
					else{
						std = 4;
						break;
					}
				}
			}
		}//////////////////////////////////////////////////////////////////////////end EOF
		if (loser == 1)
			break;
		if(pooch == 71 && level == 1)
				break;
		if(pooch == 214 && level == 2)
				break;
		if(pooch == 389 && level == 3)
				break;
	}
		if (loser == 1)
					break;
		if(pooch == 71 && level == 1)
				break;
		if(pooch == 214 && level == 2)
				break;
		if(pooch == 389 && level == 3)
				break;
	}
	}
	
	

		if(loser == 0){/////////////////////////////////////////////////////////////////////if you win
		clr();
		printf("                                YOU WIN\n");
		if(level == 1){
			for(int j = 0;j < 9;j++){		
				for(int i = 0;i < 9;i++){
					if (type1[i][j] == 1){
						type11[i][j] = 10;
					}
				}
			}
			color(3);
			printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9\n");
			for(int j = 0;j < 9;j++){
				color(3);
				printf("                  %2d",j+1);
				for(int i = 0;i < 9;i++){
					if (type11[i][j] == 0)
						printf("%c ",str);
					else{
						if(type11[i][j] == 9)
							printf("%c ",str1);
						else{
							if(type11[i][j] == 10){
								color(4);
								printf("%c ",str2);
								color(3);
							}
							else
							{
								color(5);
								printf("%u ",type11[i][j]);
								color(3);
							}
						}
					}
				}
				printf("\n");
			}
		}
		else{
			if(level == 2){
				for(int j = 0;j < 16;j++){	
					for(int i = 0;i < 16;i++){
						if (type2[i][j] == 1){
							type22[i][j] = 10;
						}
					}
				}
				color(3);	              
				printf("\n\n\n\n\n                      1 2 3 4 5 6 7 8 9..........\n");
				for(int j = 0;j < 16;j++){
					color(3);
					printf("                  %2d",j+1);
					for(int i = 0;i < 16;i++){
						if (type11[i][j] == 0)
							printf("%c ",str);
						else{
							if(type11[i][j] == 9)
								printf("%c ",str1);
							else{
								if(type11[i][j] == 10){
									color(4);
									printf("%c ",str2);
									color(3);
								}
								else
								{
									color(5);
									printf("%u ",type11[i][j]);
									color(3);
								}
							}
						}
					}
					printf("\n");
				}
				color(7);
			}
			else{
				for(int j = 0;j < 22;j++){
					for(int i = 0;i < 22;i++){
						if (type3[i][j] == 1){
							type33[i][j] = 10;
						}
					}
				}
				color(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9 ..............\n");
				for(int j = 0;j < 22;j++){
					color(3);
					printf("                  %2d",j+1);
					for(int i = 0;i < 22;i++){
						if (type33[i][j] == 0)
							printf("%c ",str);
						else{
							if(type33[i][j] == 9)
								printf("%c ",str1);
							else{
								if(type33[i][j] == 10){
									color(4);
									printf("%c ",str2);
									color(3);
								}
								else
								{
								color(5);
								printf("%u ",type33[i][j]);
								color(3);
								}
							}
						}
					}
					printf("\n");
				}
				color(7);
			}
		}
	}///////////////////////////////////////////////////////////////////////end you win

	else{//////////////////////////////////////////////////////////////////if you lose
		clr();
		printf("                               YOU LOSE");
		if(level == 1){
			for(int j = 0;j < 9;j++){		
				for(int i = 0;i < 9;i++){
					if (type1[i][j] == 1){
						type11[i][j] = 10;
					}
				}
			}
			
			char savepath[50];
		sprintf(savepath, "%s/savegame.txt",user_name);
		game = fopen(savepath,"w");
				fprintf(game,"%d",-1);
				fclose(game);
			color(3);
			printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9\n");
			for(int j = 0;j < 9;j++){
				color(3);
				printf("                  %2d",j+1);
				for(int i = 0;i < 9;i++){
					if (type11[i][j] == 0)
						printf("%c ",str);
					else{
						if(type11[i][j] == 9)
							printf("%c ",str1);
						else{
							if(type11[i][j] == 10){
								color(5);
								printf("%c ",str2);
								color(3);
							}
							else
							{
								color(4);
								printf("%u ",type11[i][j]);
								color(3);
							}
						}
					}
				}
				printf("\n");
			}
			color(7);
		}
		else{
			if(level == 2){
				for(int j = 0;j < 16;j++){	
					for(int i = 0;i < 16;i++){
						if (type2[i][j] == 1){
							type22[i][j] = 10;
						}
					}
				}
				char savepath[50];
		sprintf(savepath, "%s/savegame.txt",user_name);
		game = fopen(savepath,"w");
				fprintf(game,"%d",-1);
				fclose(game);
				color(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9..........\n");
				for(int j = 0;j < 16;j++){
					color(3);
					printf("                  %2d",j+1);
					for(int i = 0;i < 16;i++){
						if (type22[i][j] == 0)
							printf("%c ",str);
						else{
							if(type22[i][j] == 9)
								printf("%c ",str1);
							else{
								if(type22[i][j] == 10){
									color(5);
									printf("%c ",str2);
									color(3);
								}
								else
								{
									color(4);
									printf("%u ",type22[i][j]);
									color(3);
								}
							}
						}					
					}
					printf("\n");
				}
				color(7);
			}
			else{
				for(int j = 0;j < 22;j++){	
					for(int i = 0;i < 22;i++){
						if (type3[i][j] == 1){
							type33[i][j] = 10;
						}
					}
				}
				char savepath[50];
		sprintf(savepath, "%s/savegame.txt",user_name);
		game = fopen(savepath,"w");
				fprintf(game,"%d",-1);
				fclose(game);
				color(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9 ..............\n");
				for(int j = 0;j < 22;j++){
					color(3);
					printf("                  %2d",j+1);
					for(int i = 0;i < 22;i++){
						if (type33[i][j] == 0)
							printf("%c ",str);
						else{
							if(type33[i][j] == 9)
								printf("%c ",str1);
							else{
								if(type33[i][j] == 10){
									color(5);
									printf("%c ",str2);
									color(3);
								}
								else
								{
									color(4);
									printf("%u ",type33[i][j]);
									color(3);
								}
							}
						}
					}
					printf("\n");
				}
				color(7);
			}
		}
	}
}

int lvl (unsigned int level)
{
	
	if(level != 1 && level != 2 && level != 3){
		printf("%s\n%s","you intered wrong number!!!"
					   ,"please choose again: ");
		scanf("%u",&level);
		return lvl (level);
	}
	else{
		return level;
	}
}

int lvl1 (unsigned int type11[9][9],unsigned int type1[9][9],int x, int y,int sum)
{
	sum = 0;
	if(type1[x][y] == 0){
		for(int j = -1; j < 2; j++){
			for(int i = -1; i < 2; i++){
				if(x+i < 9 && y+j < 9 && x+i > -1 && y+j > -1){
					if(x+i != x || y+j != y){
					sum = sum + type1[x+i][y+j];
					}
				}
			}		
		}
		type11[x][y] = sum;
		if(type11[x][y] == 0){
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

void T (int lvl1(unsigned int type11[9][9],unsigned int type1[9][9],int x, int y,int sum),unsigned int type11[9][9],unsigned int type1[9][9],int x, int y,int sum){
	if(lvl1 (type11,type1,x,y,sum) == 0){
		for(int k = -1; k < 2; k++){
			for(int l = -1; l < 2; l++){
				if(x+l < 9 && y+k < 9 && x+l > -1 && y+k > -1){
					if(x+l != x || y+k != y){
					lvl1(type11,type1,x+l,y+k,sum);
					}
				}
			}
		}
	}
}

void lvlT1(void T (int lvl1(unsigned int type11[9][9],unsigned int type1[9][9],int x, int y,int sum),unsigned int type11[9][9],unsigned int type1[9][9],int x, int y,int sum),int lvl1(unsigned int type11[9][9],unsigned int type1[9][9],int x, int y,int sum),unsigned int type11[9][9],unsigned int type1[9][9],int x, int y,int sum){
	if(lvl1 (type11,type1,x,y,sum) == 0){
		for(int k = -1; k < 2; k++){
			for(int l = -1; l < 2; l++){
				if(x+l < 9 && y+k < 9 && x+l > -1 && y+k > -1){
					if(x+l != x || y+k != y){
						if(lvl1(type11,type1,x+l,y+k,sum)==0){
							T (lvl1,type11,type1,x+l,y+k,sum);
						}
					}
				}
			}
		}
	}
}

int lvl2 (unsigned int type22[16][16],unsigned int type2[16][16],int x, int y,int sum)
{
	sum = 0;
	if(type2[x][y] == 0){
		for(int j = -1; j < 2; j++){
			for(int i = -1; i < 2; i++){
				if(x+i < 16 && y+j < 16 && x+i > -1 && y+j > -1){
					if(x+i != x || y+j != y){
					sum = sum + type2[x+i][y+j];
					}
				}
			}		
		}
		type22[x][y] = sum;
		if(type22[x][y] == 0){
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

void T2 (int lvl2(unsigned int type22[16][16],unsigned int type2[16][16],int x, int y,int sum),unsigned int type22[16][16],unsigned int type2[16][16],int x, int y,int sum)
{
	if(lvl2 (type22,type2,x,y,sum) == 0){
		for(int k = -1; k < 2; k++){
			for(int l = -1; l < 2; l++){
				if(x+l < 9 && y+k < 9 && x+l > -1 && y+k > -1){
					if(x+l != x || y+k != y){
					lvl2(type22,type2,x+l,y+k,sum);
					}
				}
			}
		}
	}
}

void lvlT2(void T2 (int lvl2(unsigned int type22[16][16],unsigned int type2[16][16],int x, int y,int sum),unsigned int type22[16][16],unsigned int type2[16][16],int x, int y,int sum),int lvl2(unsigned int type22[16][16],unsigned int type2[16][16],int x, int y,int sum),unsigned int type22[16][16],unsigned int type2[16][16],int x, int y,int sum)
{
	if(lvl2 (type22,type2,x,y,sum) == 0){
		for(int k = -1; k < 2; k++){
			for(int l = -1; l < 2; l++){
				if(x+l < 16 && y+k < 16 && x+l > -1 && y+k > -1){
					if(x+l != x || y+k != y){
						if(lvl2(type22,type2,x+l,y+k,sum)==0){
							T2 (lvl2,type22,type2,x+l,y+k,sum);
						}
					}
				}
			}
		}
	}
}

int lvl3 (unsigned int type33[22][22],unsigned int type3[22][22],int x, int y,int sum)
{
	sum = 0;
	if(type3[x][y] == 0){
		for(int j = -1; j < 2; j++){
			for(int i = -1; i < 2; i++){
				if(x+i < 22 && y+j < 22 && x+i > -1 && y+j > -1){
					if(x+i != x || y+j != y){
					sum = sum + type3[x+i][y+j];
					}
				}
			}		
		}
		type33[x][y] = sum;
		if(type33[x][y] == 0){
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

void T3 (int lvl3(unsigned int type33[22][22],unsigned int type3[22][22],int x, int y,int sum),unsigned int type33[22][22],unsigned int type3[22][22],int x, int y,int sum)
{
	if(lvl3 (type33,type3,x,y,sum) == 0){
		for(int k = -1; k < 2; k++){
			for(int l = -1; l < 2; l++){
				if(x+l < 22 && y+k < 22 && x+l > -1 && y+k > -1){
					if(x+l != x || y+k != y){
						lvl3(type33,type3,x+l,y+k,sum);
					}
				}
			}
		}
	}
}

void lvlT3(void T3 (int lvl3(unsigned int type33[22][22],unsigned int type3[22][22],int x, int y,int sum),unsigned int type33[22][22],unsigned int type3[22][22],int x, int y,int sum),int lvl3(unsigned int type33[22][22],unsigned int type3[22][22],int x, int y,int sum),unsigned int type33[22][22],unsigned int type3[22][22],int x, int y,int sum)
{
	if(lvl3 (type33,type3,x,y,sum) == 0){
		for(int k = -1; k < 2; k++){
			for(int l = -1; l < 2; l++){
				if(x+l < 22 && y+k < 22 && x+l > -1 && y+k > -1){
					if(x+l != x || y+k != y){
						if(lvl3(type33,type3,x+l,y+k,sum)==0){
							T3 (lvl3,type33,type3,x+l,y+k,sum);
						}
					}
				}
			}
		}
	}
}
//end game---------------------------------------------------------------

int login(int type_v, char * username_e) {
	struct tm *t;
	time_t rawtime;
	time(&rawtime);
	t = localtime(&rawtime);
	 today = (t->tm_year%100)*10000 + (t->tm_mon + 1)*100 + t->tm_mday;
	static char username[25], password[30], password_e[30] = { 0 }, name[20], c;
	int use_deadline, a_level, found = 0;
	int pos = 0;
	FILE *login = fopen("users.pj", "r");
	if (!type_v) {
		printf("Please enter your username(25 characters maximum)\n enter <exit> to exit\n");
		scanf("%s", username_e);
		if (!strcmp("exit", username_e)) {
			exit_value = 1;
			fclose(login);
			return 0;
		}
	}
		while (!feof(login)) {
			fscanf(login, "%s %s %s %d %d", username, name, password, &use_deadline, &a_level);
			if (!strcmp(username, username_e)) {
				found = 1;
				while(!user_level){
				printf("Please enter password(30 characters maximum)\n enter <exit> to exit\n");
				pos = 0;
				do {
					c = getch();

					if (isprint(c))
					{
						password_e[pos++] = c;
						printf("%c", '*');
					}
					else if (c == 8 && pos)
					{
						password_e[pos--] = '\0';
						printf("%s", "\b \b");
					}
				} while (c != 13);
				printf("\n");
				if (!strcmp("exit", password_e)) {
					exit_value = 1;
					fclose(login);
					return 0;
				}
				if (!strcmp(password, password_e)) {

					if (today < use_deadline) {
						if (a_level)
							user_level = 1;
						strcpy(user_name, username);
						sprintf(path,"/root/%s",user_name);
						strcpy(curdir,user_name);
						fclose(login);
						return 1;
					}
					else{
						printf("your account has expired\n");
						fclose(login);
						return 0;
					}
				}
				else{
					printf("Password is incorrect\n");
				}
			}
				if (user_level) {
					if (!a_level)
						user_level = 0;
					strcpy(user_name, username_e);
					strcpy(curdir,username);
					fclose(login);
					sprintf(path,"/root/%s",user_name);
					return 1 ;
				}
		}
	}
		if (!found) {
			printf("username not found\n");
			fclose(login);
			return 0;
		}
		fclose(login);
}


void su(char *command) {
	char username_e[25], command2[30];
	sscanf(command, "%s %s", command2, username_e);
	login(1, username_e);
}

void create_user(void) {
	static char c, tmp[30], user[200], username[25], hispath[30];
	long int ntmp, tmp1, tmp2, tmp3;
	int pos = 0;
	printf("enter username(25 characters maximum)\n");
	scanf("%s", tmp);
	strcpy(username,tmp);	
	strcat(user, tmp);
	strcat(user, " ");
	printf("enter name(20 characters maximum)\n");
	scanf("%s", tmp);
	strcat(user, tmp);
	strcat(user, " ");
	printf("enter password(30 characters maximum)\n");
	do {
		c = getch();

		if (isprint(c))
		{
			tmp[pos++] = c;
			printf("%c", '*');
		}
		else if (c == 8 && pos)
		{
			tmp[pos--] = '\0';
			printf("%s", "\b \b");
		}
	} while (c != 13);
	strcat(user, tmp);
	int true_v = 0;
		while (!true_v) {
			printf("\nenter users deadline date << year/month/day >> all in 2 digits\n");
			scanf("%d/%d/%d", &tmp1, &tmp2, &tmp3);
			ntmp = tmp1 * 10000 + tmp2 * 100 + tmp3;
			true_v = 1;
			if (tmp2 > 12 || tmp3>31 || ntmp < today) {
				printf("invalid data");
				true_v = 0;
			}
		}
	FILE *userfile = fopen("users.pj", "a");
	fprintf(userfile, "\n%s %d %d\n", user, ntmp, 0);
	mkdir(username);
	char lsname[50];
	sprintf(lsname,"%s/%s.ls",username,username);
	FILE *ls=fopen(lsname,"w");
	fclose(ls);
	ls=fopen("root.ls","a+");
	fprintf(ls,"%s\t",username);
	sprintf(hispath, "%s/history.txt", username);
	FILE *his = fopen(hispath, "w+");
	fclose(his);
	fclose(ls);
	fclose(userfile);
}

void passwd(char *username_e) {
	static char username[25], password[30], name[20], password_e[30] = { 0 }, c;
	int use_deadline, a_level;
	int pos = 0, found = 0;
	FILE *users = fopen("users.pj", "r+");
	fseek(users, 0, SEEK_SET);
	while (!feof(users)) {
		fscanf(users, "%s %s %s %d %d", username, name, password, &use_deadline, &a_level);
		if (!strcmp(username, username_e)) {
			found = 1;
			while (!user_level) {
				printf("Please enter old password(30 characters maximum)\n enter <back> to exit\n");
				do {
					c = getch();

					if (isprint(c))
					{
						password_e[pos++] = c;
						printf("%c", '*');
					}
					else if (c == 8 && pos)
					{
						password_e[pos--] = '\0';
						printf("%s", "\b \b");
					}
				} while (c != 13);
				if (!strcmp("back", password_e)) {
					fclose(users);
					return;
				}
				if (!strcmp(password, password_e)){
					fclose(users);
					pos = 0 ;
					break;
				}
				else{
					printf("password in incorrect\n");
					pos = 0 ;
				}
			}
			printf("Please enter new password(30 characters maximum)\n");
			pos = 0 ;
			do {
				c = getch();

				if (isprint(c))
				{
					password_e[pos++] = c;
					printf("%c", '*');
				}
				else if (c == 8 && pos)
				{
					password_e[pos--] = '\0';
					printf("%s", "\b \b");
				}
			} while (c != 13);
			int len = -strlen(password) - 9;
			fseek(users, len, SEEK_CUR);
			fprintf(users, "%s", password_e);
			fclose(users);
			return ;
		}
	}
	if (!found) {
		printf("username not found\n");
		fclose(users);
		return ;
	}
}
void passwd_l(char *date, char *username_e) {
	static char username[25], password[30], name[20];
	int use_deadline, a_level;
	int found = 0;
	int tmp1, tmp2, tmp3, ntmp = 0;
		FILE *userfile = fopen("users.pj", "r+");
		fseek(userfile, 0, SEEK_SET);
	while (!feof(userfile)) {
		fscanf(userfile, "%s %s %s %d %d", username, name, password, &use_deadline, &a_level);
		if (!strcmp(username, username_e)){
			found = 1;
			fseek(userfile, -8, SEEK_CUR);
				tmp1 = strtol(date, 0, 10);
				tmp2 = strtol(date + 3, 0, 10);
				tmp3 = strtol(date + 6, 0, 10);
				ntmp = tmp1 * 10000 + tmp2 * 100 + tmp3;
				if (tmp2 > 12 || tmp3 > 31 || ntmp < today){
					printf("invalid date\n");
					return;
				}
			fprintf(userfile, "%d", ntmp);
			printf("Done!\n");
			fclose(userfile);
			return;
		}
	}
	if(!found) {
			printf("username not found\n");
			fclose(userfile);
			return;
	}
	fclose(userfile);
	printf("%d\n", found);
}


int main() {
	static char hispath[30];
	color(15);
	while(!login(0,user_name)){
		if (exit_value)
			return 0;
	}
	clr();
	char *command=(char*)malloc(500); //string that holds the input command
	sprintf(hispath, "%s/history.txt", user_name);
	FILE *his = fopen(hispath, "w+");//file that saves the commands entered by user
	char freebuffer[2];
	fgets(freebuffer,2,stdin);
	//string that holds absolute path of the pwd
	while (1) {
		color(10);
		printf("%s @ %s  ",user_name,curdir);
		color(15);
		printf(">> ");
		fgets(command, 500, stdin);//entering the command
		command = (char*)realloc(command, strlen(command) * sizeof(char) + 5);//returning extra memory to OS
		for (int ch = 0; command[ch] != '\n'; ch++)
			command[ch] = tolower(command[ch]);//makes the commands not case-sensitive
		//--------------------- exit command -----------------------
		if (!strcmp(command, "exit\n")) {
			fclose(his);
			return 0;
		}
		//--------------------- time command -----------------------
		else if (!strcmp(command, "time\n")) {
			struct tm *t;
			time_t rawtime;
			time(&rawtime);
			t = localtime(&rawtime);//saving details of current time in struct
			printf("The local time of system is %d:%d:%d\n", t->tm_hour, t->tm_min, t->tm_sec);
			fprintf(his, "   *time\n");
			continue;
		}
		//------------------ history command ------------------------
		else if (!strcmp(command, "history\n")) {
			char *hiscom = (char*)malloc(500);
			fprintf(his, "   *history\n");
			puts("");
			fseek(his, 0, SEEK_SET);
			fgets(hiscom, 500, his);
			while (!feof(his)) {
				printf("%s", hiscom);
				fgets(hiscom, 500, his);
			}//showing the contents of history file
			puts("");
			free(hiscom);
			continue;
		}
		//------------------- cal command ----------------------------
		else if (!strcmp(command, "cal\n")) {
			puts("");
			showcal();
			fprintf(his, "   *cal\n");
			puts("");
			continue;
		}
		//--------------------- clear command -------------------------
		else if (!strcmp(command, "clear\n")) {
			clr();
			fprintf(his, "   *clear\n");
			continue;
		}
		//---------------- make directory command ----------------------
		else if(!strncmp(command, "mkdir ",6)){
			command[strlen(command)-1]='\0';//terminating '\n' character
			struct stat st={0};//struct for checking directory existence
			char *lsname=(char*)malloc(500);
			char *curlsname=(char*)malloc(500);
			//determining current directory ls file name
			if (!user_level && command[6] == '/' && strncmp(&command[7], user_name, strlen(user_name))){
				printf("access denied\n");
				continue;
			}
			if(!strcmp(curdir,"root"))
				strcpy(curlsname,"root.ls");
			else
				sprintf(curlsname,"%s/%s.ls",&path[6],curdir);
			if(command[6]=='/'){ //for absouloute paths
				if(stat(&command[7],&st) == -1){
					mkdir(&command[7]);
					lsname=strcat(&command[7],".ls");
					FILE *ls=fopen(lsname,"a+");
					fprintf(ls,"%s\t",&command[7]);//writing in ls file
					fclose(ls);
				}
				else
					printf("The directory already exists.\n");
			}
			
			else if(stat(&command[6],&st) == -1){ //for relative paths
				if (strcmp(curdir,"root")){
					char *dname=(char*)malloc(500);//string that holsds directory name
					sprintf(dname,"%s/%s",&path[6],&command[6]);
					mkdir(dname);
					free(dname);
					sprintf(lsname,"%s/%s/%s.ls",&path[6],&command[6],&command[6]);
				}
				else {
					mkdir(&command[6]);
					sprintf(lsname,"%s/%s.ls",&command[6],&command[6]);
				}
				//changing ls file
				FILE *ls=fopen(lsname,"a+");
				FILE *curls=fopen(curlsname,"a+");
				fprintf(curls,"%s\t",&command[6]);
				fclose(curls);
				fclose(ls);
			}
			else
				printf("The directory already exists.\n");
			free(lsname);
			free(curlsname);
			fprintf(his, "   *mkdir %s\n",&command[6]);
			continue;
		}
		//----------------------- pwd command --------------------------
		else if(!strcmp(command,"pwd\n")){
			printf("%s\n",path);
			fprintf(his, "   *pwd\n");
			continue;
		}
		//--------------------- ls (-a) command -----------------------
		else if(!strncmp(command,"ls",2)){
			char *lsname=(char*)malloc(500);
			if(!strcmp(curdir,"root")) //determining the ls file name
				strcpy(lsname,"root.ls");
			else
				sprintf(lsname,"%s/%s.ls",&path[6],curdir);
			//printing the contents of ls file
			FILE *ls=fopen(lsname,"a+");
			fseek(ls,0,SEEK_SET);
			char *lstemp=(char*)malloc(20);
			fscanf(ls,"%20s",lstemp);
			while(!feof(ls)){
				if (lstemp[0]!='.' || !strcmp(&command[2]," -a\n")) //checking hidden files
					printf("%s\t",lstemp);
				fscanf(ls,"%20s",lstemp);
			}
			puts("");
			free(lstemp);
			free(lsname);
			fclose(ls);
			fprintf(his, "   *%s",command);
			continue;
		}
		//----------------- cd command --------------------------------
		else if(!strncmp(command,"cd ",3)){
			command[strlen(command)-1]='\0'; //terminating '\n' character
			struct stat st={0};
			if (!user_level && command[3] == '/' && strncmp(&command[4], user_name, strlen(user_name))){
				printf("access denied\n");
				continue;
			}
			if(!strcmp(&command[3],"..")){ // command "cd .."
				if(!strcmp(curdir, user_name) && !user_level ){
					printf("access denied\n");
					continue;
				}
				char* temp=(char*)malloc(500);
				sprintf(temp,path);
				path[strlen(path)-strlen(curdir)-1]='\0'; //terminating the current dir from pwd
				sprintf(curdir,predir(temp,curdir));//changing current directory to previous directory
				free(temp);
				fprintf(his, "   *cd ..\n");
			}
			
			else if(command[3]=='/'){ // command "cd abspath"
				if(stat(&command[4],&st) != -1){
					strcat(path,&command[3]);
					char *temp=(char*)malloc(500);
					sprintf(temp,"%s/t",&command[3]);
					sprintf(curdir,predir(temp,"t"));//determining and changing the current directory
					free(temp);
					fprintf(his, "   *cd %s\n",&command[4]);
				} 
				else
					printf("No such diretory!\n");
			}
			
			else { // command "cd dirname"
				char *dname=(char*)malloc(500);
				if(!strcmp(curdir,"root"))//determining directory name
					strcpy(dname,&command[3]);
				else
					sprintf(dname,"%s/%s",&path[6],&command[3]); 
					
				if(stat(dname,&st) != -1){
					sprintf(curdir,&command[3]);
					sprintf(path,"%s/%s",path,curdir); // adding dirname to pwd
					fprintf(his, "   *cd %s\n",&command[3]);
				} 
				else
					printf("No such diretory!\n");
				free(dname);
			}
			continue;
		}
		//-------------------- > and >> command -------------------------
		else if(strchr(command,'>')!=NULL){
			struct stat st={0};
			FILE *file,*detfile;//main file and .det file
			command[strlen(command)-1]='\0'; //terminating '\n' character
			if(*(strchr(command,'>')+1)=='>'){ // >> command
				char* part1=strtok(command,">>");
				char* part2=strtok(NULL,">> ");//tokenizing two parts of the command
				if (!user_level && part1[0] == '/' && strncmp(&part1[1], user_name, strlen(user_name))){
				printf("access denied\n");
				continue;
			}
			if (!user_level && part2[0] == '/' && strncmp(&part2[1], user_name, strlen(user_name))){
				printf("access denied\n");
				continue;
			}
				part1[strlen(part1)-1]='\0';
				char *fname=(char*)malloc(500);//determining file name
				char *f1name=(char*)malloc(500);
				if (part2[0]=='/'){
					sprintf(fname,&part2[1]);
				}//checking for absoloute path
				else if (strcmp(curdir,"root"))
					sprintf(fname,"%s/%s",&path[6],part2);
				else sprintf(fname,"%s",part2);
				if (part1[0]=='/'){
					sprintf(f1name,&part1[1]);
				}//checking for absoloute path
				else if (strcmp(curdir,"root"))
					sprintf(f1name,"%s/%s",&path[6],part1);
				else sprintf(f1name,"%s",part1);
				//ls file change
				if(stat(fname,&st)==-1){
					char *lsname=(char*)malloc(500);
					char *temp=(char*)malloc(50);
					if (part2[0]=='/'){
						sprintf(temp,"%s/t",part2);
						sprintf(temp,"%s",predir(temp,"t"));
						sprintf(part2,temp);
					}
					else if(!strcmp(curdir,"root"))
						strcpy(lsname,"root.ls");
					else
						sprintf(lsname,"%s/%s.ls",&path[6],curdir);
					FILE *ls=fopen(lsname,"a+");
					fprintf(ls,"%s\t",part2);
					free(temp);
					free(lsname);
					fclose(ls);	
				}
				//file change
				if (stat(f1name,&st)!=-1){//if part 1 is an existing file
					char *buffer=(char*)malloc(2000);
					FILE *fp1=fopen(f1name,"a+");
					file=fopen(fname,"a+");
					fgets(buffer,2000,fp1);
					fprintf(file,buffer);
					while(!feof(fp1)){
						fgets(buffer,2000,fp1);
						fprintf(file,buffer);
					}
					fclose(file);
					fclose(fp1);
					free(buffer);
				}
				else {//if part 1 is a string
					file=fopen(fname,"a+");
					fprintf(file,part1);
					fclose(file);
				}
				//details file
				char* detname=(char*)malloc(20);
				sprintf(detname,"%s.det",fname);
				detfile=fopen(detname,"w+");
				stat(fname,&st);//saving the stat of file in struct
				fprintf(detfile,"Generator: %s\nPath: %s\nSize: %d Bytes\n",user_name,path,st.st_size);
				fprintf(detfile,"Generation time: %sLast accsess time: %sLast modification time: %s",ctime(&st.st_ctime),ctime(&st.st_atime),ctime(&st.st_mtime));
				fclose(detfile);
				free (detname);
				free(fname);
				free(f1name);
				fprintf(his, "   *%s >> %s\n",part1,part2);
				
			}
			else { // > command
				char *part1=strtok(command,">");
				char *part2=strtok(NULL,"> ");//tokenizing two parts of the commands
				if (!user_level && part1[0] == '/' && strncmp(&part1[1], user_name, strlen(user_name))){
				printf("access denied\n");
				continue;
			}
			if (!user_level && part2[0] == '/' && strncmp(&part2[1], user_name, strlen(user_name))){
				printf("access denied\n");
				continue;
			}
				part1[strlen(part1)-1]='\0';
				char *fname=(char*)malloc(500);//determining file name
				char *f1name=(char*)malloc(500);
				if (part2[0]=='/'){
					sprintf(fname,&part2[1]);
				}//checking for absoloute path
				else if (strcmp(curdir,"root"))
					sprintf(fname,"%s/%s",&path[6],part2);
				else sprintf(fname,"%s",part2);
				if (part1[0]=='/'){
					sprintf(f1name,&part1[1]);
				}//checking for absoloute path
				else if (strcmp(curdir,"root"))
					sprintf(f1name,"%s/%s",&path[6],part1);
				else sprintf(f1name,"%s",part1);
				//ls file change
				if(stat(fname,&st)==-1){
					char *lsname=(char*)malloc(500);
					char *temp=(char*)malloc(50);
					if (part2[0]=='/'){
						sprintf(temp,"%s/t",part2);
						sprintf(temp,"%s",predir(temp,"t"));
						sprintf(part2,temp);
					}
					else if(!strcmp(curdir,"root"))
						strcpy(lsname,"root.ls");
					else
						sprintf(lsname,"%s/%s.ls",&path[6],curdir);
					FILE *ls=fopen(lsname,"a+");
					fprintf(ls,"%s\t",part2);
					free(temp);
					free(lsname);
					fclose(ls);	
				}
				//file change
				if (stat(f1name,&st)!=-1){//if part 1 is an existing file
					char *buffer=(char*)malloc(2000);
					FILE *fp1=fopen(f1name,"a+");
					file=fopen(fname,"w+");
					fgets(buffer,2000,fp1);
					fprintf(file,buffer);
					while(!feof(fp1)){
						fgets(buffer,2000,fp1);
						fprintf(file,buffer);
					}
					fclose(file);
					fclose(fp1);
					free(buffer);
				}
				else {//if part 1 is a string
					file=fopen(fname,"w+");
					fprintf(file,part1);
					fclose(file);
				}
				//details file
				char* detname=(char*)malloc(20);
				sprintf(detname,"%s.det",fname);
				detfile=fopen(detname,"w+");
				stat(fname,&st);//saving the stat of file in struct
				fprintf(detfile,"Generator: %s\nPath: %s\nSize: %d Bytes\n",user_name,path,st.st_size);
				fprintf(detfile,"Generation time: %sLast accsess time: %sLast modification time: %s",ctime(&st.st_ctime),ctime(&st.st_atime),ctime(&st.st_mtime));
				fclose(detfile);
				free (detname);
				free(fname);
				free(f1name);
				fprintf(his, "   *%s > %s\n",part1,part2);
			}
			continue;
		}
		//------------------- exif command ----------------------------
		else if (!strncmp(command,"exif ",5)){
			command[strlen(command)-1]='\0'; //terminating '\n' character
				if (!user_level && command[5] == '/' && strncmp(&command[6], user_name, strlen(user_name))){
				printf("access denied\n");
				continue;
			}
			char *dettemp=(char*)malloc(500);
			char *detname=(char*)malloc(50);//determining the name od .det file
			if (command[5]=='/') sprintf(detname,"%s.det",&command[6]);
			else if (strcmp(curdir,"root"))
					sprintf(detname,"%s/%s.det",&path[6],&command[5]);
			else sprintf(detname,"%s.det",&command[5]);
			FILE *det=fopen(detname,"r");
			rewind(det);
			if(det==NULL){//checking existence of det file (actually the main file)
				puts("No such file!");
				continue;
			}
			else {//printing the .det file
				fgets(dettemp,500,det);
				while(!feof(det)){
					printf("%s",dettemp);
					fgets(dettemp,500,det);
				}
			}
			free(detname);
			fclose(det);
			free(dettemp);
			fprintf(his, "   *%s\n",command);
			continue;
		}
		//------------------ cat command ----------------------------
		else if (!strncmp(command,"cat ",4)){
			command[strlen(command)-1]='\0'; //terminating '\n' character
				if (!user_level && command[4] == '/' && strncmp(&command[5], user_name, strlen(user_name))){
				printf("access denied\n");
				continue;
			}
			char *fname=(char*)malloc(50);
			char *ftemp=(char*)malloc(200);
			if (command[4]=='/') sprintf(fname,"%s",&command[5]);//determining the file name
			else if (strcmp(curdir,"root"))
					sprintf(fname,"%s/%s",&path[6],&command[4]);
			else sprintf(fname,"%s",&command[4]);
			FILE *file=fopen(fname,"r");
			if(file!=NULL){//checking file exixtence and printing it
				fgets(ftemp,200,file);
				puts(ftemp);
				while(!feof(file)){
					fgets(ftemp,200,file);
					puts(ftemp);
				}
				fclose(file);
			}
			else puts("No such file!");
			free(fname);
			free(ftemp);
			fprintf(his, "   *%s\n",command);
			continue;
		}
		//------------------ rm -r command ---------------------------
		else if (!strncmp(command,"rm -r ",6)){
			command[strlen(command)-1]='\0'; //terminating '\n' character
				if (!user_level && command[6] == '/' && strncmp(&command[7], user_name, strlen(user_name))){
				printf("access denied\n");
				continue;
			}
			struct stat st={0};
			char *name=(char*)malloc(50);
			char *lsname=(char*)malloc(50);
			if (command[6]=='/') sprintf(name,"%s",&command[7]);//determining directory name
			else if (strcmp(curdir,"root"))
					sprintf(name,"%s/%s",&path[6],&command[6]);
			else sprintf(name,"%s",&command[6]);
			if(stat(name,&st)!=-1 && fopen(name,"r")==NULL){//checking that the entry is an existing directory
		 		deldir(name,&command[6]);//a recursive function for deleting folders
		 		//ls file change
				if(!strcmp(curdir,"root"))//determining ls file name
					strcpy(lsname,"root.ls");
				else
					sprintf(lsname,"%s/%s.ls",&path[6],curdir);
				FILE *ls=fopen(lsname,"r+");
				char *ftemp=(char*)malloc(20);
				while(!feof(ls)){// deleting directory name from the ls file
					fscanf(ls,"%s",ftemp);
					if(!strcmp(ftemp,&command[6])){
						fseek(ls,-strlen(&command[6]),SEEK_CUR);
						for(int i=0;i<strlen(&command[6]);i++)
							fputc(' ',ls);
						break;
					}
				}
				free(ftemp);
				fclose(ls);
				free(lsname);
			}
			else puts("No such directory!");
			free(name);
			fprintf(his, "   *%s\n",command);
			continue;
		}
		//--------------------- rm command ---------------------------
		else if (!strncmp(command,"rm ",3)){
			command[strlen(command)-1]='\0'; //terminating '\n' character
				if (!user_level && command[3] == '/' && strncmp(&command[4], user_name, strlen(user_name))){
				printf("access denied\n");
				continue;
			}
			char *name=(char*)malloc(50);
			char *detname=(char*)malloc(50);
			char *lsname=(char*)malloc(50);
			if (command[3]=='/') sprintf(name,"%s",&command[4]);//determining file name
			else if (strcmp(curdir,"root"))
					sprintf(name,"%s/%s",&path[6],&command[3]);
			else sprintf(name,"%s",&command[3]);
			sprintf(detname,"%s.det",name);//determining .det file name
			FILE *file=fopen(name,"r");
			if(file!=NULL){//checking file existence and removing it
				fclose(file);
		 		remove(name);
		 		remove(detname);
		 		//ls file change
				if(!strcmp(curdir,"root"))//determining ls file name
					strcpy(lsname,"root.ls");
				else
					sprintf(lsname,"%s/%s.ls",&path[6],curdir);
				FILE *ls=fopen(lsname,"r+");
				char *ftemp=(char*)malloc(20);
				while(!feof(ls)){//deleting file name from ls file
					fscanf(ls,"%s",ftemp);
					if(!strcmp(ftemp,&command[3])){
						fseek(ls,-strlen(&command[3]),SEEK_CUR);
						for(int i=0;i<strlen(&command[3]);i++)
							fputc(' ',ls);
						break;
					}
				}
				free(ftemp);
				fclose(ls);
				free(lsname);
			}
			else puts("No such file!");
			free(detname);
			free(name);
			fprintf(his, "   *%s\n",command);
			continue;
		}
		//-------------------- cp command -------------------------
		else if (!strncmp(command,"cp ",3)){
			command[strlen(command)-1]='\0'; //terminating '\n' character
			strtok(command," ");
			char *part1=strtok(NULL," "), *part2=strtok(NULL," ");
			if (!user_level && part1[0] == '/' && strncmp(&part1[1], user_name, strlen(user_name))){
				printf("access denied\n");
				continue;
			}
			if (!user_level && part2[0] == '/' && strncmp(&part2[1], user_name, strlen(user_name))){
				printf("access denied\n");
				continue;
			}
			char *file1=(char*)malloc(100), *file2=(char*)malloc(100);
			//determining file 1 name
			if (part1[0]=='/') sprintf(file1,"%s",&part1[1]);
			else if (strcmp(curdir,"root"))
					sprintf(file1,"%s/%s",&path[6],part1);
			else sprintf(file1,"%s",part1);
			//determining file 2 name
			if (part2[0]=='/') sprintf(file2,"%s",&part2[1]);
			else if (strcmp(curdir,"root"))
					sprintf(file2,"%s/%s",&path[6],part2);
			else sprintf(file2,"%s",part2);
			FILE *f1=fopen(file1,"r"), *f2=fopen(file2,"w");
			if (f1!=NULL){
				//copying file 1 to file 2
				while(!feof(f1)){
					char *buffer=(char*)malloc(1000);
					fgets(buffer,1000,f1);
					fprintf(f2,"%s\n",buffer);
					free(buffer);
				}
				//creating det file
				struct stat st={0};
				char* detname=(char*)malloc(20);
				sprintf(detname,"%s.det",file2);
				FILE* detfile=fopen(detname,"w+");
				stat(file2,&st);//saving the stat of file in struct
				fprintf(detfile,"Generator: %s\nPath: %s\nSize: %d Bytes\n",user_name,path,st.st_size);
				fprintf(detfile,"Generation time: %sLast accsess time: %sLast modification time: %s",ctime(&st.st_ctime),ctime(&st.st_atime),ctime(&st.st_mtime));
				fclose(detfile);
				free(detname);
				//changing ls file
				char *lsname=(char*)malloc(500);
				if(part2[0]=='/'){ //for paths
					char *temp=(char*)malloc(50);
					sprintf(temp,"%s/t",part2);
					sprintf(temp,"%s",predir(temp,"t"));
				//	char* temp2=strstr(part2,temp);
					sprintf(temp,"%s.ls",predir(part2,temp));
					sprintf(lsname,"%s/%s",&part2[1],temp);
					sprintf(part2,temp);
					free(temp);
				}
				else if(!strcmp(curdir,"root"))
					strcpy(lsname,"root.ls");
				else
					sprintf(lsname,"%s/%s.ls",&path[6],curdir);
				FILE *ls=fopen(lsname,"a+");
				fprintf(ls,"%s\t",part2);
				free(lsname);
				fclose(ls);	
			}
			else puts("No such file!");
			fclose(f1);
			fclose(f2);
			free(file1);
			free(file2);
			fprintf(his, "   *%s\n",command);
			continue;
		}
		//-------------------- mv command --------------------------
		else if (!strncmp(command,"mv ",3)){
			command[strlen(command)-1]='\0'; //terminating '\n' character
			strtok(command," ");
			char *part1=strtok(NULL," "), *part2=strtok(NULL," ");
			if (!user_level && part1[0] == '/' && strncmp(&part1[1], user_name, strlen(user_name))){
				printf("access denied\n");
				continue;
			}
			if (!user_level && part2[0] == '/' && strncmp(&part2[1], user_name, strlen(user_name))){
				printf("access denied\n");
				continue;
			}
			char *file1=(char*)malloc(100), *file2=(char*)malloc(100);
			//file 1
			if (part1[0]=='/') sprintf(file1,"%s",&part1[1]);
			else if (strcmp(curdir,"root"))
					sprintf(file1,"%s/%s",&path[6],part1);
			else sprintf(file1,"%s",part1);
			//file 2
			if (part2[0]=='/') sprintf(file2,"%s",&part2[1]);
			else if (strcmp(curdir,"root") && user_level==0)
					sprintf(file2,"%s/%s",&path[6],part2);
			else sprintf(file2,"%s",part2);
			FILE *f1=fopen(file1,"r"), *f2=fopen(file2,"w");
			if (f1!=NULL){
				//copying file 1 to file 2
				while(!feof(f1)){
					char *buffer=(char*)malloc(1000);
					fgets(buffer,1000,f1);
					fprintf(f2,"%s\n",buffer);
					free(buffer);
				}
				//creating det file
				struct stat st={0};
				char* detname=(char*)malloc(20);
				sprintf(detname,"%s.det",file2);
				FILE* detfile=fopen(detname,"w+");
				stat(file2,&st);//saving the stat of file in struct
				fprintf(detfile,"Generator: %s\nPath: %s\nSize: %d Bytes\n",user_name,path,st.st_size);
				fprintf(detfile,"Generation time: %sLast accsess time: %sLast modification time: %s",ctime(&st.st_ctime),ctime(&st.st_atime),ctime(&st.st_mtime));
				fclose(detfile);
				free(detname);
				//changing ls file
				char *lsname=(char*)malloc(500);
				if(part2[0]=='/'){ //for paths
					char *temp=(char*)malloc(50);
					sprintf(temp,"%s/t",part2);
					sprintf(temp,"%s",predir(temp,"t"));
					char* temp2=strstr(part2,temp);
					sprintf(temp,"%s.ls",predir(part2,temp2));
					sprintf(lsname,"%s/%s",&part2[1],temp);
					sprintf(part2,temp2);
					free(temp);
				}
				else if(!strcmp(curdir,"root") && user_level==1)
					strcpy(lsname,"root.ls");
				else
					sprintf(lsname,"%s/%s.ls",&path[6],curdir);
				FILE *ls=fopen(lsname,"a+");
				fprintf(ls,"%s\t",part2);
				fclose(ls);
				//deleting file 1
				sprintf(detname,"%s.det",file1);
				fclose(f1);
		 		remove(file1);
		 		remove(detname);
		 		//ls change
		 		if(part1[0]=='/'){ //for paths
					char *temp=(char*)malloc(50);
					sprintf(temp,"%s/t",part1);
					sprintf(temp,"%s",predir(temp,"t"));
					char* temp2=strstr(part1,temp);
					sprintf(temp,"%s.ls",predir(part1,temp2));
					sprintf(lsname,"%s/%s",&part1[1],temp);
					sprintf(part1,temp2);
					free(temp);
				}
				else if(!strcmp(curdir,"root") && user_level==1)
					strcpy(lsname,"root.ls");
				else
					sprintf(lsname,"%s/%s.ls",&path[6],curdir);
				ls=fopen(lsname,"r+");
				char *ftemp=(char*)malloc(50);
				while(!feof(ls)){
					fscanf(ls,"%50s",ftemp);
					if(!strcmp(ftemp,&command[3])){
						fseek(ls,-strlen(&command[3]),SEEK_CUR);
						for(int i=0;i<strlen(&command[3]);i++)
							fputc(' ',ls);
						break;
					}
				}
				free(ftemp);
				fclose(ls);
				free(lsname);
				free(detname);
			}
			else puts("No such file!");
			fclose(f2);
			free(file1);
			free(file2);
			fprintf(his, "   *%s\n",command);
			continue;
		}
		//-------------------- wc command ---------------------------
		else if(!strncmp(command,"wc ",3)){
			command[strlen(command)-1]='\0'; //terminating '\n' character
			if (!user_level && command[5] == '/' && strncmp(&command[6], user_name, strlen(user_name))){
				printf("access denied\n");
				continue;
			}
			struct stat st={0};
			char *fname=(char*)malloc(50);//determining file name
			if (command[3]=='/') sprintf(fname,"%s",&command[4]);
			else if (strcmp(curdir,"root") && user_level==0)
					sprintf(fname,"%s/%s",&path[6],&command[3]);
			else sprintf(fname,"%s",&command[3]);
			FILE *file=fopen(fname,"r");
			unsigned int chars=0, pars=0, words=0;
			char *buffer=(char*)malloc(500);
			if(file!=NULL){
				while(!feof(file)){
					fgets(buffer,500,file);
					pars++;//number of paragraphs
					chars+=strlen(buffer);//number of characters
					words++;
					for(int i=0;i<strlen(buffer);i++)
						if(buffer[i]==' ')
							words++;//number of words
				}
				printf("Number of characters:%d\nNumber of words:%d\nNumber of paragraphs:%d\n",chars,words,pars);
			}
			else puts("No such file!");
			free(fname);
			free(buffer);
			fprintf(his, "   *%s\n",command);
			continue;
		}
			//------------------- su command ----------------------------
		else if (!strncmp(command,"su ",3)){
			su(command);
			continue;
		}
		//-------------------create user command ----------------------
		else if (!strcmp(command,"create user\n")){
			if(!user_level){
				printf("access denied\n");
				continue ;
			}
			create_user();
			char simple[2];
			fgets(simple, 2, stdin);
			continue;
		}
		//------------------- passwd -l command ----------------------------
		else if (!strncmp(command,"passwd -l",9)){
			if(!user_level){
				printf("access denied\n");
				continue ;
			}
			char username_e[25], command2[30], date[10], command3[30];
			sscanf(command, "%s %s %s %s", command2, command3, date, username_e);
			passwd_l(date, username_e);
			continue;
		}
		//------------------- passwd [username] command ----------------------------
		else if (!strncmp(command,"passwd ",7)){
			if(!user_level){
				printf("access denied\n");
				continue ;
			}
			char username_e[25], command2[30];
			sscanf(command, "%s %s", command2, username_e);
			passwd(username_e);
			continue;
		}
		//--------------------------game command------------------------------------
		else if(!strcmp(command,"game\n")){
			game();
			char simple[2];
			fgets(simple, 2, stdin);
			continue;
		}
		else printf("Wrong command!\n");
	}
	return 0;
}
