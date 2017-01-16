#include <stdio.h>
#include <Windows.h>
#include <time.h>

void setColor(int ForgC)
{
    WORD wColor;
    //We will need this handle to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
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
	for (int j = 0; j < 100; j++)
		printf("                                                                             \n");//prints 10000 space characters
	pos(0, 0);//sets the cursor position in the top of the console
}


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

int main ()
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
	game = fopen("savegame.txt","r+");
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
			game = fopen("savegame.txt","w");
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
		game = fopen("savegame.txt","r+");
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
		setColor(3);
		printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9\n");
		for(int j = 0;j < 9;j++){
			setColor(3);
			printf("                  %2d",j+1);
			for(int i = 0;i < 9;i++){
				if (type11[i][j] == 0)
					printf("%c ",str);
				else{
					if(type11[i][j] == 9)
						printf("%c ",str1);
					else{
						if(type11[i][j] == 10){
							setColor(5);
							printf("%c ",str2);
							setColor(3);
						}
						else
						{
							setColor(5);
							printf("%u ",type11[i][j]);
							setColor(3);
						}
					}
				}
			}
			printf("\n");
		}
		setColor(7);
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
				setColor(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9\n");
		for(int j = 0;j < 9;j++){
			setColor(3);
			printf("                  %2d",j+1);
			for(int i = 0;i < 9;i++){
				if (type11[i][j] == 0)
					printf("%c ",str);
				else{
					if(type11[i][j] == 9)
						printf("%c ",str1);
					else{
						if(type11[i][j] == 10){
							setColor(5);
							printf("%c ",str2);
							setColor(3);
						}
						else
						{
							setColor(5);
							printf("%u ",type11[i][j]);
							setColor(3);
						}
					}
				}
			}
			printf("\n");
		}
		setColor(7);
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
		setColor(3);
		printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9 .........\n");
		for(int j = 0;j < 16;j++){
			setColor(3);
			printf("                  %2d",j+1);
			for(int i = 0;i < 16;i++){
				if (type22[i][j] == 0)
					printf("%c ",str);
				else{
					if(type22[i][j] == 9)
						printf("%c ",str1);
					else{
						if(type22[i][j] == 10){
							setColor(5);
							printf("%c ",str2);
							setColor(3);
						}
						else
						{
							setColor(4);
							printf("%u ",type22[i][j]);
							setColor(3);
						}
					}
				}
			}
			printf("\n");
		}
		setColor(7);
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
				setColor(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9 ........\n");
		for(int j = 0;j < 16;j++){
			setColor(3);
			printf("                  %2d",j+1);
			for(int i = 0;i < 16;i++){
				if (type22[i][j] == 0)
					printf("%c ",str);
				else{
					if(type22[i][j] == 9)
						printf("%c ",str1);
					else{
						if(type22[i][j] == 10){
							setColor(5);
							printf("%c ",str2);
							setColor(3);
						}
						else
						{
							setColor(4);
							printf("%u ",type22[i][j]);
							setColor(3);
						}
					}
				}
			}
			printf("\n");
		}
		setColor(7);
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
		setColor(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9 ..............\n");
				for(int j = 0;j < 22;j++){
					setColor(3);
					printf("                  %2d",j+1);
					for(int i = 0;i < 22;i++){
						if (type33[i][j] == 0)
							printf("%c ",str);
						else{
							if(type33[i][j] == 9)
								printf("%c ",str1);
							else{
								if(type33[i][j] == 10){
									setColor(5);
									printf("%c ",str2);
									setColor(3);
								}
								else
								{
									setColor(4);
									printf("%u ",type33[i][j]);
									setColor(3);
								}
							}
						}
					}
					printf("\n");
				}
				setColor(7);

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
				setColor(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9 ..............\n");
				for(int j = 0;j < 22;j++){
					setColor(3);
					printf("                  %2d",j+1);
					for(int i = 0;i < 22;i++){
						if (type33[i][j] == 0)
							printf("%c ",str);
						else{
							if(type33[i][j] == 9)
								printf("%c ",str1);
							else{
								if(type33[i][j] == 10){
									setColor(5);
									printf("%c ",str2);
									setColor(3);
								}
								else
								{
									setColor(4);
									printf("%u ",type33[i][j]);
									setColor(3);
								}
							}
						}
					}
					printf("\n");
				}
				setColor(7);
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
				printf("%s\n%s\n%s\n","for exit press: '1'","for Seve and Exit press: '2'","keep on the game press: '3'");
					scanf("%d",&std);
					if(std == 1){
						fprintf(game,"\d",-1);
						fclose(game);
						return 0;
					}
					else{
						if(std == 2){
							game = fopen("savegame.txt","w");
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
						return 0;
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
		setColor(3);
		printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9\n");
		for(int j = 0;j < 9;j++){
			setColor(3);
			printf("                  %2d",j+1);
			for(int i = 0;i < 9;i++){
				if (type11[i][j] == 0)
					printf("%c ",str);
				else{
					if(type11[i][j] == 9)
						printf("%c ",str1);
					else{
						if(type11[i][j] == 10){
							setColor(5);
							printf("%c ",str2);
							setColor(3);
						}
						else
						{
							setColor(5);
							printf("%u ",type11[i][j]);
							setColor(3);
						}
					}
				}
			}
			printf("\n");
		}
		setColor(7);
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
				setColor(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9\n");
		for(int j = 0;j < 9;j++){
			setColor(3);
			printf("                  %2d",j+1);
			for(int i = 0;i < 9;i++){
				if (type11[i][j] == 0)
					printf("%c ",str);
				else{
					if(type11[i][j] == 9)
						printf("%c ",str1);
					else{
						if(type11[i][j] == 10){
							setColor(5);
							printf("%c ",str2);
							setColor(3);
						}
						else
						{
							setColor(5);
							printf("%u ",type11[i][j]);
							setColor(3);
						}
					}
				}
			}
			printf("\n");
		}
		setColor(7);
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
		setColor(3);
		printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9 .........\n");
		for(int j = 0;j < 16;j++){
			setColor(3);
			printf("                  %2d",j+1);
			for(int i = 0;i < 16;i++){
				if (type22[i][j] == 0)
					printf("%c ",str);
				else{
					if(type22[i][j] == 9)
						printf("%c ",str1);
					else{
						if(type22[i][j] == 10){
							setColor(5);
							printf("%c ",str2);
							setColor(3);
						}
						else
						{
							setColor(4);
							printf("%u ",type22[i][j]);
							setColor(3);
						}
					}
				}
			}
			printf("\n");
		}
		setColor(7);
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
				setColor(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9 ........\n");
		for(int j = 0;j < 16;j++){
			setColor(3);
			printf("                  %2d",j+1);
			for(int i = 0;i < 16;i++){
				if (type22[i][j] == 0)
					printf("%c ",str);
				else{
					if(type22[i][j] == 9)
						printf("%c ",str1);
					else{
						if(type22[i][j] == 10){
							setColor(5);
							printf("%c ",str2);
							setColor(3);
						}
						else
						{
							setColor(4);
							printf("%u ",type22[i][j]);
							setColor(3);
						}
					}
				}
			}
			printf("\n");
		}
		setColor(7);
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
		setColor(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9 ..............\n");
				for(int j = 0;j < 22;j++){
					setColor(3);
					printf("                  %2d",j+1);
					for(int i = 0;i < 22;i++){
						if (type33[i][j] == 0)
							printf("%c ",str);
						else{
							if(type33[i][j] == 9)
								printf("%c ",str1);
							else{
								if(type33[i][j] == 10){
									setColor(5);
									printf("%c ",str2);
									setColor(3);
								}
								else
								{
									setColor(4);
									printf("%u ",type33[i][j]);
									setColor(3);
								}
							}
						}
					}
					printf("\n");
				}
				setColor(7);

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
				setColor(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9 ..............\n");
				for(int j = 0;j < 22;j++){
					setColor(3);
					printf("                  %2d",j+1);
					for(int i = 0;i < 22;i++){
						if (type33[i][j] == 0)
							printf("%c ",str);
						else{
							if(type33[i][j] == 9)
								printf("%c ",str1);
							else{
								if(type33[i][j] == 10){
									setColor(5);
									printf("%c ",str2);
									setColor(3);
								}
								else
								{
									setColor(4);
									printf("%u ",type33[i][j]);
									setColor(3);
								}
							}
						}
					}
					printf("\n");
				}
				setColor(7);
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
		printf("%s\n%s\n%s\n","for Exit press '1'","for Seve and Exit press '2'","keep on game press '3'");
			scanf("%d",&std);
			if(std == 1)
				return 0;
			else{
				if(std == 2){///////////////////////////////////////seve
					game = fopen("savegame.txt","w");
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
					return 0;
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
			setColor(3);
			printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9\n");
			for(int j = 0;j < 9;j++){
				setColor(3);
				printf("                  %2d",j+1);
				for(int i = 0;i < 9;i++){
					if (type11[i][j] == 0)
						printf("%c ",str);
					else{
						if(type11[i][j] == 9)
							printf("%c ",str1);
						else{
							if(type11[i][j] == 10){
								setColor(4);
								printf("%c ",str2);
								setColor(3);
							}
							else
							{
								setColor(5);
								printf("%u ",type11[i][j]);
								setColor(3);
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
				setColor(3);	              
				printf("\n\n\n\n\n                      1 2 3 4 5 6 7 8 9..........\n");
				for(int j = 0;j < 16;j++){
					setColor(3);
					printf("                  %2d",j+1);
					for(int i = 0;i < 16;i++){
						if (type11[i][j] == 0)
							printf("%c ",str);
						else{
							if(type11[i][j] == 9)
								printf("%c ",str1);
							else{
								if(type11[i][j] == 10){
									setColor(4);
									printf("%c ",str2);
									setColor(3);
								}
								else
								{
									setColor(5);
									printf("%u ",type11[i][j]);
									setColor(3);
								}
							}
						}
					}
					printf("\n");
				}
				setColor(7);
			}
			else{
				for(int j = 0;j < 22;j++){
					for(int i = 0;i < 22;i++){
						if (type3[i][j] == 1){
							type33[i][j] = 10;
						}
					}
				}
				setColor(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9 ..............\n");
				for(int j = 0;j < 22;j++){
					setColor(3);
					printf("                  %2d",j+1);
					for(int i = 0;i < 22;i++){
						if (type33[i][j] == 0)
							printf("%c ",str);
						else{
							if(type33[i][j] == 9)
								printf("%c ",str1);
							else{
								if(type33[i][j] == 10){
									setColor(4);
									printf("%c ",str2);
									setColor(3);
								}
								else
								{
								setColor(5);
								printf("%u ",type33[i][j]);
								setColor(3);
								}
							}
						}
					}
					printf("\n");
				}
				setColor(7);
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
			
			game = fopen("savegame.txt","w");
				fprintf(game,"%d",-1);
				fclose(game);
			setColor(3);
			printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9\n");
			for(int j = 0;j < 9;j++){
				setColor(3);
				printf("                  %2d",j+1);
				for(int i = 0;i < 9;i++){
					if (type11[i][j] == 0)
						printf("%c ",str);
					else{
						if(type11[i][j] == 9)
							printf("%c ",str1);
						else{
							if(type11[i][j] == 10){
								setColor(5);
								printf("%c ",str2);
								setColor(3);
							}
							else
							{
								setColor(4);
								printf("%u ",type11[i][j]);
								setColor(3);
							}
						}
					}
				}
				printf("\n");
			}
			setColor(7);
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
				game = fopen("savegame.txt","w");
				fprintf(game,"%d",-1);
				fclose(game);
				setColor(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9..........\n");
				for(int j = 0;j < 16;j++){
					setColor(3);
					printf("                  %2d",j+1);
					for(int i = 0;i < 16;i++){
						if (type22[i][j] == 0)
							printf("%c ",str);
						else{
							if(type22[i][j] == 9)
								printf("%c ",str1);
							else{
								if(type22[i][j] == 10){
									setColor(5);
									printf("%c ",str2);
									setColor(3);
								}
								else
								{
									setColor(4);
									printf("%u ",type22[i][j]);
									setColor(3);
								}
							}
						}					
					}
					printf("\n");
				}
				setColor(7);
			}
			else{
				for(int j = 0;j < 22;j++){	
					for(int i = 0;i < 22;i++){
						if (type3[i][j] == 1){
							type33[i][j] = 10;
						}
					}
				}
				game = fopen("savegame.txt","w");
				fprintf(game,"%d",-1);
				fclose(game);
				setColor(3);
				printf("\n\n\n\n\n                    1 2 3 4 5 6 7 8 9 ..............\n");
				for(int j = 0;j < 22;j++){
					setColor(3);
					printf("                  %2d",j+1);
					for(int i = 0;i < 22;i++){
						if (type33[i][j] == 0)
							printf("%c ",str);
						else{
							if(type33[i][j] == 9)
								printf("%c ",str1);
							else{
								if(type33[i][j] == 10){
									setColor(5);
									printf("%c ",str2);
									setColor(3);
								}
								else
								{
									setColor(4);
									printf("%u ",type33[i][j]);
									setColor(3);
								}
							}
						}
					}
					printf("\n");
				}
				setColor(7);
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
