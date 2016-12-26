#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "projhead.h"

int main() {
	char *command=(char*)malloc(500); //string that holds the input command
	FILE *his = fopen("history.txt", "w+");//file that saves the commands entered by user
	char *relpath, *abspath;//strings that hold relative and absolute path of the pwd
	while (1) {
		printf(">> ");
		fgets(command, 500, stdin);//entering the command
		for (int ch = 0; command[ch] != '\n'; ch++)
			command[ch] = tolower(command[ch]);//makes the commands not case-sensitive
		//--------------------- exit command -----------------------
		if (!strcmp(command, "exit\n")) {
			fclose(his);
			return 0;
			continue;
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
		//---------------------- 
		else printf("Wrong command!\n");
	}
	return 0;
}
