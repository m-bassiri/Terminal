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
	char *path=(char*)malloc(500);//string that holds absolute path of the pwd
	path="/users/mohammad";//initializing bsolute path
	FILE *rootls=fopen("mohammad.ls","a+");//a file that contains list of files in the root directory
	while (1) {
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
			t = localtime(&rawtime);
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
			command[strlen(command)-1]='\0';
			struct stat st={0};
			if(stat(&command[6],&st) == -1){
				mkdir(&command[6]);
				fprintf(rootls,strcat(&command[6],"\t"));
			}
			else
				printf("The directory already exists.\n");
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
			char *lstemp=(char*)malloc(2000);
			fseek(rootls,0,SEEK_SET);
			fscanf(rootls,"%s",lstemp);
			while(!feof(rootls)){
				printf("%s\t",lstemp);
				fscanf(rootls,"%s",lstemp);
			}
			puts("");
			free(lstemp);
			fprintf(his, "   *ls\n");
			continue;
		}
		//-----------------
		else printf("Wrong command!\n");
	}
	return 0;
}
