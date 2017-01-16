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


int lvl (unsigned int level);

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
	char str = 153;
	char str1 = 223;
	char str2 = 233;
	int std;
	int m1, m2, x, y;	
	int pooch = 0;
	unsigned int wrong = 0;
	unsigned int level;
	unsigned int type1 [9][9]={};
	unsigned int type11[9][9]={};

	for(int i = 0;i < 9;i++){
		for(int j = 0;j < 9;j++){
			type11[i][j] = 9;
		}
	}

	unsigned int type2 [16][16]={};
	unsigned int type22[16][16]={};
	
	for(int i = 0;i < 16;i++){
		for(int j = 0;j < 16;j++){
			type22[i][j] = 9;
		}
	}
	unsigned int type3 [22][22]={};
	unsigned int type33[22][22]={};
	
	for(int i = 0;i < 22;i++){
		for(int j = 0;j < 22;j++){
			type33[i][j] = 9;
		}
	}//end ...............................................

	printf("%s\n%s\n%s\n%s\n%s","please choose level of game: "
							,"level 1: 9 * 9"
							,"level 2: 16 * 16"
							,"level 3: 22 * 22"
							,"level : ");
	scanf("%u",&level);

	level = lvl(level);
	
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
		for (int i = 0; i < 40;i++){
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
		for (int i = 0; i < 90;i++){
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
	clr();
	std = 0;
	switch (level){
	case 1:
		printf("\n\n\n\n\n\n");
		for(int j = 0;j < 9;j++){
			printf("                    ");
			for(int i = 0;i < 9;i++){
				if (type11[i][j] == 0)
					printf("%c ",str);
				else{
					if(type11[i][j] == 9)
						printf("%c ",str1);
					else
					{
						printf("%u ",type11[i][j]);
					}
				}
			}
			printf("\n");
		}
		while(!feof(stdin)){
			printf("%s\n%s","please inter Coordinate","inter x: ");
			scanf("%d",&x);
			while(!feof(stdin)){
				if(x > 0 && x < 10)
					break;
				else{
					printf("%s\n%s","please inter right Coordinate!!!","inter x again : ");
					scanf("%d",&x);
				}
			}
			if(feof(stdin)){
				std = 1;
				break;
			}
			printf("inter y: ");
			scanf("%d",&y);
			while(!feof(stdin)){
				if(y > 0 && y < 10)
					break;
				else{
					printf("%s\n%s","please inter right Coordinate!!!","inter y again : ");
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
				printf("\n\n\n\n\n\n");
				for(int j = 0;j < 9;j++){
					printf("                    ");
					for(int i = 0;i < 9;i++){
						if (type11[i][j] == 0)
							printf("%c ",str);
						else{
							if(type11[i][j] == 9)
								printf("%c ",str1);
							else
							{
								printf("%u ",type11[i][j]);
							}
						}
					}
					printf("\n");
					
				}
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
		}
		break;
	case 2:
		printf("\n\n\n\n\n\n");
		for(int j = 0;j < 16;j++){
			printf("                    ");
					for(int i = 0;i < 16;i++){
						if (type22[i][j] == 0)
							printf("%c ",str);
						else{
							if(type22[i][j] == 9)
								printf("%c ",str1);
							else
							{
								printf("%u ",type22[i][j]);
							}
						}
					}
					printf("\n");
		
				}
		while(!feof(stdin)){
			printf("%s\n%s","please inter Coordinate","inter x: ");
			scanf("%d",&x);
			while(!feof(stdin)){
				if(x > 0 && x < 17)
					break;
				else{
					printf("%s\n%s","please inter right Coordinate!!!","inter x again : ");
					scanf("%d",&x);
				}
			}
			if(feof(stdin)){
				std = 1;
				break;
			}
			printf("inter y: ");
			scanf("%d",&y);
			while(!feof(stdin)){
				if(y > 0 && y < 17)
					break;
				else{
					printf("%s\n%s","please inter right Coordinate!!!","inter y again : ");
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
			if(type1[x][y] == 0)
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
				printf("\n\n\n\n\n\n");
				for(int j = 0;j < 16;j++){
					printf("                    ");
					for(int i = 0;i < 16;i++){
						if (type22[i][j] == 0)
							printf("%c ",str);
						else{
							if(type22[i][j] == 9)
								printf("%c ",str1);
							else
							{
								printf("%u ",type22[j][i]);
							}
						}
					}
					printf("\n");
		
				}
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
			if(pooch == 216)
				break;
		}
		break;
	case 3:
		printf("\n\n\n\n\n\n");
		for(int j = 0;j < 22;j++){
			printf("                    ");
			for(int i = 0;i < 22;i++){
				if (type33[i][j] == 0)
					printf("%c ",str);
				else{
					if(type33[i][j] == 9)
						printf("%c ",str1);
					else
					{
						printf("%u ",type33[i][j]);
					}
				}
			}
			printf("\n");	
		}

		while(!feof(stdin)){
			printf("%s\n%s","please inter Coordinate","inter x: ");
			scanf("%d",&x);
			while(!feof(stdin)){
				if(x > 0 && x < 23)
					break;
				else{
					printf("%s\n%s","please inter right Coordinate!!!","inter x again : ");
					scanf("%d",&x);
				}
			}
			if(feof(stdin)){
				std = 1;
				break;
			}
			printf("inter y: ");
			scanf("%d",&y);
			while(!feof(stdin)){
				if(y > 0 && y < 23)
					break;
				else{
					printf("%s\n%s","please inter right Coordinate!!!","inter y again : ");
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
				printf("\n\n\n\n\n\n");
				for(int j = 0;j < 22;j++){
					printf("                    ");
					for(int i = 0;i < 22;i++){
						if (type33[i][j] == 0)
							printf("%c ",str);
						else{
							if(type33[i][j] == 9)
								printf("%c ",str1);
							else
							{
								printf("%u ",type33[i][j]);
							}
						}
					}
					printf("\n");	
				}
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
		break;
		}
	if(std == 1){
		printf("%s\n%s\n%s\n","for exit press '1'","for seve and play later press '2'","keep on game press '3'");
			scanf("%d",&std);
			if(std == 1)
				return 0;
			else{
				if(std == 2){

				}
				else{

				}
			}

	}
	else{
	if(loser == 0){
		printf("                                you win\n");
if(level == 1){
		for(int j = 0;j < 9;j++){
		
		for(int i = 0;i < 9;i++){
				if (type1[i][j] == 1){
					type11[i][j] = 10;
				}
			}
		}
		printf("\n\n\n\n\n\n");
		for(int j = 0;j < 9;j++){
			setColor(3);
			printf("                    ");
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
							printf("%u ",type11[i][j]);
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
		printf("\n\n\n\n\n\n");
			for(int j = 0;j < 16;j++){
				setColor(3);
				printf("                    ");
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
										printf("%u ",type22[i][j]);
									}
								}
						}
						
					}
					printf("\n");
			}
		}
		else{
			for(int j = 0;j < 22;j++){
		
				for(int i = 0;i < 22;i++){
					if (type3[i][j] == 1){
						type33[i][j] = 10;
					}
				}
			}
			printf("\n\n\n\n\n\n");
			for(int j = 0;j < 22;j++){
				setColor(3);
				printf("                    ");
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
							printf("%u ",type33[i][j]);
							}
						}
					}
				}
				printf("\n");
			}
		}
	}
	}
	else{
		printf("                                you lose");
	if(level == 1){
		for(int j = 0;j < 9;j++){
		
		for(int i = 0;i < 9;i++){
				if (type1[i][j] == 1){
					type11[i][j] = 10;
				}
			}
		}
		printf("\n\n\n\n\n\n");
		for(int j = 0;j < 9;j++){
			setColor(3);
			printf("                    ");
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
							printf("%u ",type11[i][j]);
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
		printf("\n\n\n\n\n\n");
			for(int j = 0;j < 16;j++){
				setColor(3);
				printf("                    ");
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
										printf("%u ",type22[i][j]);
									}
								}
						}
						
					}
					printf("\n");
			}
		}
		else{
			for(int j = 0;j < 22;j++){
		
				for(int i = 0;i < 22;i++){
					if (type3[i][j] == 1){
						type33[i][j] = 10;
					}
				}
			}
			printf("\n\n\n\n\n\n");
			for(int j = 0;j < 22;j++){
				setColor(3);
				printf("                    ");
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
							printf("%u ",type33[i][j]);
							}
						}
					}
				}
				printf("\n");
			}
		}
	}
	}
	}
	system("pause");
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
