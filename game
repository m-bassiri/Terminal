#include <stdio.h>
#include <Windows.h>
#include <time.h>

int adad (int typ11[7][7],int type1[7][7],int x, int y,int n1,int sum);

int main ()
{
	srand(time(NULL));
	int x, y;
	int loser = 0;
	int sum1 = 0;
	int sum = 0;
	int n,s,bomb,m1,m2,n1;	
	unsigned int wrong = 0;
	unsigned int type, level;
	int type1 [7][7]={};
	int type11[7][7]={};

	for(int j = 0;j < 7;j++){
		for(int v = 0;v < 7;v++){
			type11[j][v] = 9;
		}
	}
	unsigned int type2 [11][11]={};
	int type22[11][11]={};
	
	for(int j = 0;j < 11;j++){
		for(int v = 0;v < 11;v++){
			type22[j][v] = 9;
		}
	}
	unsigned int type3 [15][15]={};
	int type33[15][15]={};
	
	for(int j = 0;j < 15;j++){
		for(int v = 0;v < 15;v++){
			type33[j][v] = 9;
		}
	}

	printf("%s\n%s\n%s\n%s\n%s","please choose type of game: "
							,"type 1: 7 * 7"
							,"type 2: 11 * 11"
							,"type 3: 15 * 15"
							,"type : ");
	scanf("%u",&type);

	if(type == 1){
		n = 7 * 7;
		n1 = 7;
	}
	else{
		if(type == 2){
			n = 11 * 11;
			n1 = 11;
		}
		else{
			if(type == 3){
				n = 15 * 15;
				n1 = 15;
			}
			else{	
				while(wrong != 1){
					printf("%s\n%s","you intered wrong number!!!"
									,"please choose again: ");
					scanf("%u",&type);
					if(type == 1 || type == 2 || type == 3)
						wrong = 1;
				}
			}
		}
	}
	wrong = 0;
	printf("%s\n%s\n%s\n%s\n%s","please choose level of game:"
							,"level esey   = 1"
						    ,"level normal = 2"
						    ,"level hard   = 3"
							,"level : ");
	scanf("%u",&level);
	if(level == 1)
		s = 6;
	else{
		if(level == 2)
			s = 5;
		else{
			if(level == 3)
				s = 4;
			else{	
				while(wrong != 1){
					printf("%s\n%s","you intered wrong number!!!"
									,"please choose again: ");
					scanf("%u",&level);
					if(level == 1 || level == 2 || level == 3)
						wrong = 1;
				}
			}
		}
	}//end first part

	bomb = n / s;
	if(type == 1){
		for (int i = 0; i < bomb;i++){
			m1 = rand() % n1;
			m2 = rand() % n1;
			if(type1 [m1][m2] == 0)
				type1 [m1][m2] = 1;
			else{
				i--;
			}
		}
	}
	else{
		if(type == 2){
			for (int i = 0; i < bomb;i++){
				m1 = rand() % n1;
				m2 = rand() % n1;
				if(type2 [m1][m2] == 0)
					type2 [m1][m2] = 1;
				else{
					i--;
				}
			}
		}
		else{
			for (int i = 0; i < bomb;i++){
				m1 = rand() % n1;
				m2 = rand() % n1;
				if(type3 [m1][m2] == 0)
					type3 [m1][m2] = 1;
				else{
					i--;
				}
			}
		}
	}
	for(int j = 0;j < n1;j++){
		for(int v = 0;v < n1;v++){
			printf("%u ",type1[j][v]);
		}
		printf("\n");
	}
	//start game with x & y
	while(!feof(stdin)){
		printf("%s\n%s ","please inter moghtasat","inter x: ");
		scanf("%d",&x);
		printf("inter y: ");
		scanf("%d",&y);
		x--;
		y--;
		if(type1[x][y] == 1)//age too ghone bomb bood
		{
			loser = 1;
			break;
		}

		else//age to ghone bomb nabod
		{
			adad (type11,type1,x,y,n1,sum);
		}
		for(int i = 0;i < n1;i++){
			for(int j = 0;j < n1;j++){
				if(type11[i][j] == 9){
					sum1++;
				}
			}
		}
		if(sum1 == bomb)
			break;
		for(int j = 0;j < n1;j++){
			for(int v = 0;v < n1;v++){
				printf("%u ",type11[j][v]);
			}
			printf("\n");
		}
	}
	if(loser == 1)
		printf("you lose\n");
	else
		printf("you win\n");
		
		
}//تابعی که مخنصات یه خونه که بمب توش نیست رو میگیره و اگه عدد بود چاپ میکنه و اگه پوچ بود اونو با 0 نشون میده و میره سراغ خونه های اطرافش

int adad (int type11[7],int type1[7][7],int x, int y,int n1,int sum)//این تابع رو برای جدول 7*7 درست کردم فعلا
{
	sum = 0;
	if(type1[x][y] == 0){
		for(int i = -1; i < 2; i++){
			for(int j = -1; j < 2; j++){
				if(x+i < 7 && y+j < 7 && x+i > 0 && y+j > 0){
					sum = sum + type1[x+i][y+j];
				}
			}
		}
		if(sum == 0){
			type11[x][y] = 0;
			for(int i = -1; i < 2; i++){
				for(int j = -1; j < 2; j++){
					if(x+i < 7 && y+j < 7 && x+i > 0 && y+j > 0)
					return adad (type11,type1,x+i,y+j,n1,sum);
				}
			}
		}
		else{
			type11[x][y] = sum;
		}
	}
}
