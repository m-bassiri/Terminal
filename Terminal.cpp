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
		//-------------------- > and >> command -------------------------
		else if(strchr(command,'>')!=NULL){
			struct stat st={0};
			FILE *file,*detfile;
			command[strlen(command)-1]='\0'; //terminating '\n' character
			if(*(strchr(command,'>')+1)=='>'){ // >> command
				char* part1=strtok(command,">>");
				char* part2=strtok(NULL,">> ");
				part1[strlen(part1)-1]='\0';
				if (part2[0]=='/') part2++;
				if (part1[0]=='/') part1++;
				char *fname=(char*)malloc(500);
				if (strcmp(curdir,"root"))
					sprintf(fname,"%s/%s",&path[21],part2);
				else sprintf(fname,"%s",part2);
				//ls change
				if(stat(fname,&st)==-1){
					char *lsname=(char*)malloc(500);
					if(!strcmp(curdir,"root"))
						strcpy(lsname,"root.ls");
					else
						sprintf(lsname,"%s/%s.ls",&path[21],curdir);
					FILE *ls=fopen(lsname,"a+");
					fprintf(ls,"%s\t",part2);
					free(lsname);
					fclose(ls);	
				}
				//file change
				if (stat(part1,&st)!=-1){
					char *buffer=(char*)malloc(2000);
					FILE *fp1=fopen(part1,"a+");
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
				else {
				file=fopen(fname,"a+");
				fprintf(file,part1);
				fclose(file);
				}
				//details file
				char* detname=(char*)malloc(20);
				sprintf(detname,"%s.det",fname);
				detfile=fopen(detname,"w+");
				stat(fname,&st);//saving the stat of file in struct
				fprintf(detfile,"Generator: %s\nPath: %s\nSize: %d Bytes\n",curuser,path,st.st_size);
				fprintf(detfile,"Generation time: %sLast accsess time: %sLast modification time: %s",ctime(&st.st_ctime),ctime(&st.st_atime),ctime(&st.st_mtime));
				fclose(detfile);
				free (detname);
				free(fname);
				fprintf(his, "   *%s >> %s\n",part1,part2);
				
			}
			else { // > command
				char *part1=strtok(command,">");
				char *part2=strtok(NULL,"> ");
				part1[strlen(part1)-1]='\0';
				if (part2[0]=='/') part2++;
				if (part1[0]=='/') part1++;
				char *fname=(char*)malloc(500);
				if (strcmp(curdir,"root"))
					sprintf(fname,"%s/%s",&path[21],part2);
				else sprintf(fname,"%s",part2);
				//ls change
				if(stat(fname,&st)==-1){
					char *lsname=(char*)malloc(500);
					if(!strcmp(curdir,"root"))
						strcpy(lsname,"root.ls");
					else
						sprintf(lsname,"%s/%s.ls",&path[21],curdir);
					FILE *ls=fopen(lsname,"a+");
					fprintf(ls,"%s\t",part2);
					free(lsname);
					fclose(ls);	
				}
				//file change
				if (stat(part1,&st)!=-1){
					char *buffer=(char*)malloc(2000);
					FILE *fp1=fopen(part1,"a+");
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
				else {
				file=fopen(fname,"w+");
				fprintf(file,part1);
				fclose(file);
				}
				//details file
				char* detname=(char*)malloc(20);
				sprintf(detname,"%s.det",fname);
				detfile=fopen(detname,"w+");
				stat(fname,&st);//saving the stat of file in struct
				fprintf(detfile,"Generator: %s\nPath: %s\nSize: %d Bytes\n",curuser,path,st.st_size);
				fprintf(detfile,"Generation time: %sLast accsess time: %sLast modification time: %s",ctime(&st.st_ctime),ctime(&st.st_atime),ctime(&st.st_mtime));
				fclose(detfile);
				free (detname);
				free(fname);
				fprintf(his, "   *%s > %s\n",part1,part2);
			}
			continue;
		}
		//------------------- exif command ----------------------------
		else if (!strncmp(command,"exif ",5)){
			command[strlen(command)-1]='\0'; //terminating '\n' character
			char *dettemp=(char*)malloc(500);
			char *detname=(char*)malloc(50);
			if (command[5]=='/') sprintf(detname,"%s.det",&command[6]);
			else if (strcmp(curdir,"root"))
					sprintf(detname,"%s/%s.det",&path[21],&command[5]);
			else sprintf(detname,"%s.det",&command[5]);
			FILE *det=fopen(detname,"r");
			rewind(det);
			if(det==NULL){
				puts("No such file!");
				continue;
			}
			else {
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
			char *fname=(char*)malloc(50);
			char *ftemp=(char*)malloc(200);
			if (command[4]=='/') sprintf(fname,"%s",&command[5]);
			else if (strcmp(curdir,"root"))
					sprintf(fname,"%s/%s",&path[21],&command[4]);
			else sprintf(fname,"%s",&command[4]);
			FILE *file=fopen(fname,"r");
			fgets(ftemp,200,file);
			puts(ftemp);
			while(!feof(file)){
				fgets(ftemp,200,file);
				puts(ftemp);
			}
			fclose(file);
			free(fname);
			free(ftemp);
			fprintf(his, "   *%s\n",command);
			continue;
		}
		//------------------ rm -r command ---------------------------
		else if (!strncmp(command,"rm -r ",6)){
			command[strlen(command)-1]='\0'; //terminating '\n' character
			struct stat st={0};
			char *name=(char*)malloc(50);
			char *lsname=(char*)malloc(50);
			if (command[6]=='/') sprintf(name,"%s",&command[7]);
			else if (strcmp(curdir,"root"))
					sprintf(name,"%s/%s",&path[21],&command[6]);
			else sprintf(name,"%s",&command[6]);
			if(stat(name,&st)!=-1 && fopen(name,"r")==NULL){
		 		deldir(name,&command[6]);
		 		//ls change
				if(!strcmp(curdir,"root"))
					strcpy(lsname,"root.ls");
				else
					sprintf(lsname,"%s/%s.ls",&path[21],curdir);
				FILE *ls=fopen(lsname,"r+");
				char *ftemp=(char*)malloc(20);
				while(!feof(ls)){
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
			char *name=(char*)malloc(50);
			char *detname=(char*)malloc(50);
			char *lsname=(char*)malloc(50);
			if (command[3]=='/') sprintf(name,"%s",&command[4]);
			else if (strcmp(curdir,"root"))
					sprintf(name,"%s/%s",&path[21],&command[3]);
			else sprintf(name,"%s",&command[3]);
			sprintf(detname,"%s.det",name);
			FILE *file=fopen(name,"r");
			if(file!=NULL){
				fclose(file);
		 		remove(name);
		 		remove(detname);
		 		//ls change
				if(!strcmp(curdir,"root"))
					strcpy(lsname,"root.ls");
				else
					sprintf(lsname,"%s/%s.ls",&path[21],curdir);
				FILE *ls=fopen(lsname,"r+");
				char *ftemp=(char*)malloc(20);
				while(!feof(ls)){
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
			char *file1=(char*)malloc(100), *file2=(char*)malloc(100);
			//file 1
			if (part1[0]=='/') sprintf(file1,"%s",&part1[1]);
			else if (strcmp(curdir,"root"))
					sprintf(file1,"%s/%s",&path[21],part1);
			else sprintf(file1,"%s",part1);
			//file 2
			if (part2[0]=='/') sprintf(file2,"%s",&part2[1]);
			else if (strcmp(curdir,"root"))
					sprintf(file2,"%s/%s",&path[21],part2);
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
				fprintf(detfile,"Generator: %s\nPath: %s\nSize: %d Bytes\n",curuser,path,st.st_size);
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
				else if(!strcmp(curdir,"root"))
					strcpy(lsname,"root.ls");
				else
					sprintf(lsname,"%s/%s.ls",&path[21],curdir);
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
			char *file1=(char*)malloc(100), *file2=(char*)malloc(100);
			//file 1
			if (part1[0]=='/') sprintf(file1,"%s",&part1[1]);
			else if (strcmp(curdir,"root"))
					sprintf(file1,"%s/%s",&path[21],part1);
			else sprintf(file1,"%s",part1);
			//file 2
			if (part2[0]=='/') sprintf(file2,"%s",&part2[1]);
			else if (strcmp(curdir,"root"))
					sprintf(file2,"%s/%s",&path[21],part2);
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
				fprintf(detfile,"Generator: %s\nPath: %s\nSize: %d Bytes\n",curuser,path,st.st_size);
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
				else if(!strcmp(curdir,"root"))
					strcpy(lsname,"root.ls");
				else
					sprintf(lsname,"%s/%s.ls",&path[21],curdir);
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
				else if(!strcmp(curdir,"root"))
					strcpy(lsname,"root.ls");
				else
					sprintf(lsname,"%s/%s.ls",&path[21],curdir);
				ls=fopen(lsname,"r+");
				char *ftemp=(char*)malloc(20);
				while(!feof(ls)){
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
				free(detname);
			}
			else puts("No such file!");
			fclose(f2);
			free(file1);
			free(file2);
			fprintf(his, "   *%s\n",command);
			continue;
		}
		//-----
		else printf("Wrong command!\n");
	}
	return 0;
}
