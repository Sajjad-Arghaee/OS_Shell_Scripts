#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <limits.h>

#define MAX_LENGTH 1000

int count(char string[], char ch);

int main()
{
    char currentPath[PATH_MAX];
    getcwd(currentPath, sizeof(currentPath));
    
    while (1){
        char command[MAX_LENGTH] ;
        printf("%s> ",currentPath);
        fgets(command, MAX_LENGTH, stdin);

        if(!strcmp("exit\n", command)){
            break ;
        }else{
            char* token = strtok(command, " ") ;

            pid_t pid;
            pid = fork();

            if (pid < 0) {
                fprintf(stderr, "Fork Failed");
            } else if (pid == 0) {
                if (!strcmp("ls\n",command)){
                    execlp("/home/yosef/Desktop/OS/ls",currentPath,NULL);
                }else if(!strcmp("pwd\n", command)){
                    execlp("/home/yosef/Desktop/OS/pwd",currentPath,NULL);
                }else if(!strcmp("cd", token)){
                    token = strtok(NULL, " ") ;
                    if(!strcmp("..\n", token)){
                        if(count(currentPath, '/') > 1){
                            int currentPathLength = strlen(currentPath) ;
                            int i ;
                            for(i=currentPathLength-1; i >= 0; i--){
                                if(currentPath[i] == '/'){
                                    break ;
                                }
                            }
                            char newAddress[i-1] ;
                            for(int j=i-1; j>=0; j--){
                                newAddress[j] = currentPath[j];
                            }
                            printf("%s\n",newAddress) ;
                            // strcpy(currentPath, newAddress) ;

                        }
                        return 0 ;
                    }else{
                        execlp("/home/yosef/Desktop/OS/cd",token,currentPath,NULL);
                    }
                }else{
                    printf("%s: command not found\n", strtok(command, "\n"));
                    return 0 ;
                }
            } else {
                if (!strcmp("cd", token)){
                    int wstatus;
                    waitpid(pid, &wstatus, 0);
                    int return_value = WEXITSTATUS(wstatus);
                    if(return_value == 2){
                        strcat(currentPath,"/");
                        token = strtok(NULL, " ") ;
                        token = strtok(token,"\n") ;
                        strcat(currentPath, token) ; 
                    }else if(return_value == 1){
                        token = strtok(NULL, " ") ;
                        token = strtok(token,"\n") ;
                        strcpy(currentPath, token) ;
                    }
                }else{
                    wait(NULL);
                }
            }
        }

    }

    return 0;
}

int count(char string[], char ch){
    int n = strlen(string) ;
    int c = 0 ;
    for(int i=0 ; i <= n-1 ; i++){
        if(string[i] == ch){
            c++ ;
        }
    }
    return c ;
}