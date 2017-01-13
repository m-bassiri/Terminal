#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <conio.h>
#include "projhead.h"

int main() {
	char *command=(char*)malloc(500); //string that holds the input command
	FILE *his = fopen("history.txt", "w+");//file that saves the commands entered by user
	char path[500]="/users/mohammad/root";//string that holds absolute path of the pwd
	char curdir[30]="root", curuser[30]="mohammad"; //current directory & user
	while (1) {
		color(10);
		printf("%s @ %s  ",curuser,curdir);
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
			}
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
			struct stat st={0};
			char *lsname=(char*)malloc(500);
			char *curlsname=(char*)malloc(500);
			if(!strcmp(curdir,"root"))
				strcpy(curlsname,"root.ls");
			else
				sprintf(curlsname,"%s/%s.ls",&path[21],curdir);
			if(command[6]=='/'){ //for absouloute paths
				if(stat(&command[7],&st) == -1){
					mkdir(&command[7]);
					lsname=strcat(&command[7],".ls");
					FILE *ls=fopen(lsname,"a+");
					fprintf(ls,"%s\t",&command[7]);
					fclose(ls);
				}
				else
					printf("The directory already exists.\n");
			}
			
			else if(stat(&command[6],&st) == -1){ //for relative paths
				if (strcmp(curdir,"root")){
					char *dname=(char*)malloc(500);
					sprintf(dname,"%s/%s",&path[21],&command[6]);
					mkdir(dname);
					free(dname);
					sprintf(lsname,"%s/%s/%s.ls",&path[21],&command[6],&command[6]);
				}
				else {
					mkdir(&command[6]);
					sprintf(lsname,"%s/%s.ls",&command[6],&command[6]);
				}
				
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
		//--------------------- ls command -----------------------------
		else if(!strcmp(command,"ls\n")){
			char *lsname=(char*)malloc(500);
			if(!strcmp(curdir,"root"))
				strcpy(lsname,"root.ls");
			else
				sprintf(lsname,"%s/%s.ls",&path[21],curdir);
			FILE *ls=fopen(lsname,"a+");
			fseek(ls,0,SEEK_SET);
			char *lstemp=(char*)malloc(20);
			fscanf(ls,"%20s",lstemp);
			while(!feof(ls)){
				printf("%s\t",lstemp);
				fscanf(ls,"%20s",lstemp);
			}
			puts("");
			free(lstemp);
			free(lsname);
			fclose(ls);
			fprintf(his, "   *ls\n");
			continue;
		}
		//----------------- cd command --------------------------------
		else if(!strncmp(command,"cd ",3)){
			command[strlen(command)-1]='\0'; //terminating '\n' character
			struct stat st={0};
			if(!strcmp(&command[3],"..")){ // command "cd .."
				char* temp=(char*)malloc(500);
				sprintf(temp,path);
				path[strlen(path)-strlen(curdir)-1]='\0'; //terminating the current dir from pwd
				sprintf(curdir,predir(temp,curdir));
				free(temp);
				fprintf(his, "   *cd ..\n");
			}
			
			else if(command[3]=='/'){ // command "cd abspath"
				if(stat(&command[4],&st) != -1){
					strcat(path,&command[3]);
					char *temp=(char*)malloc(500);
					sprintf(temp,"%s/t",&command[3]);
					sprintf(curdir,predir(temp,"t"));
					free(temp);
					fprintf(his, "   *cd %s\n",&command[4]);
				} 
				else
					printf("No such diretory!\n");
			}
			
			else { // command "cd dirname"
				char *dname=(char*)malloc(500);
				if(!strcmp(curdir,"root"))
					strcpy(dname,&command[3]);
				else
					sprintf(dname,"%s/%s",&path[21],&command[3]); 
					
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
		
		else printf("Wrong command!\n");
	}
	return 0;
}
