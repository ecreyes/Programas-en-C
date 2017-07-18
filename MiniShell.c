#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // para fork
#include <sys/types.h> //para wait
#include <sys/wait.h> //para wait
#include <string.h> //para strtok

int main(void)
{   
	while(1){
		printf(">");
		char input[1024];
		char *string[256];
		char inputDos[1024];
		char *stringDos[256];            
		char delimit[]=" \t\r\n\v\f"; 
		int i = 0;
		int amp = 0;
		int Dos = 0;
		if(fgets(input, sizeof input, stdin))                             
		{
			strcpy(inputDos,input);
			if(strcmp(input,"exit\n")==0){
				break;
			}
			if(input[strlen(input)-2]==38){
			  input[strlen(input)-2]='\0';
			  amp = 1;
			}                                            
		  string[i]=strtok(input,delimit);
		  while(string[i]!=NULL)                    
		  {
			i++;
			string[i]=strtok(NULL,delimit);
		  }
		}
		i = 0;
		if(string[0][strlen(string[0])-1] == 38){
			inputDos[strlen(string[0])-1]=' ';
			stringDos[i]=strtok(inputDos,delimit);
			while(stringDos[i]!=NULL){
				i++;
				stringDos[i]=strtok(NULL,delimit);
			  }
			amp = 1;
			Dos = 1;
		}
		int pid;
		pid = fork();
		if(pid == -1){
			perror("error\n");
			exit(1);
		}
		if (pid == 0){
			if(Dos == 0){
				execvp(string[0],string);
				perror("error execvp\n");
			}
			else{
				execvp(stringDos[0],stringDos);
				perror("error execvp\n");
			}
			exit(0);
		}
		else{
			if(amp == 0){
			  waitpid(pid,NULL,0);
			}
		}
	}
  return 0;
}

