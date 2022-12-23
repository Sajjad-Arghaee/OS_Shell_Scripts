#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <limits.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MAX_LENGTH 1000

int count(char string[], char ch);

int main()
{
    char currentPath[PATH_MAX];
    getcwd(currentPath, sizeof(currentPath));
    
    using_history();
    FILE *hfile = fopen("history.txt","a");

    while (1){
        char* command ;
        char header[PATH_MAX+1] ;
        strcpy(header, currentPath);
        strcat(header, "> ");

        command = readline(header) ;
        fprintf(hfile, "%s\n", command) ;

        add_history (command) ;

        if(!strcmp("exit", command)){
            fclose(hfile);
            break ;
        }else{
            char* token = strtok(command, " ") ;

            pid_t pid;
            pid = fork();

            if (pid < 0) {
                fprintf(stderr, "Fork Failed");
            } else if (pid == 0) {
                if (!strcmp("ls",command)){
                    execlp("./ls",currentPath,NULL);
                }else if(!strcmp("pwd", command)){
                    execlp("./pwd",currentPath,NULL);
                }else if(!strcmp("cd", token)){
                    token = strtok(NULL, " ") ;
                    if(!strcmp("..", token)){
                        if(count(currentPath, '/') > 1 && strlen(token) > 1){
                            int currentPathLength = strlen(currentPath) ;
                            int i ;
                            for(i=currentPathLength-1; i >= 0; i--){
                                if(currentPath[i] == '/'){
                                    return i ;
                                }
                            }
                        }
                        return 0 ;
                    }else{
                        execlp("./cd",token,currentPath,NULL);
                    }
                }else if(!strcmp("mkdir", token)){
                    token = strtok(NULL, " ") ;
                    execlp("/bin/mkdir","mkdir",token,NULL) ;
                    return 0 ;
                }else if(!strcmp("touch", token)){
                    token = strtok(NULL, " ") ;
                    execlp("/bin/touch","touch",token,NULL) ;
                    return 0 ;
                }else if(!strcmp("cat", token)){
                    token = strtok(NULL, " ") ;
                    execlp("/bin/cat","cat",token,NULL) ;
                    return 0 ;
                }else if(!strcmp("cp", token)){
                    token = strtok(NULL, " ") ;
                    char* token2 = strtok(NULL, " ") ;
                    execlp("/bin/cp","cp",token,token2,NULL) ;
                    return 0 ;
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
                        if(strcmp(currentPath, "/")){
                            strcat(currentPath,"/");
                        }
                        token = strtok(NULL, " ") ;
                        token = strtok(token,"\n") ;
                        strcat(currentPath, token) ; 
                    }else if(return_value == 1){
                        token = strtok(NULL, " ") ;
                        token = strtok(token,"\n") ;
                        strcpy(currentPath, token) ;
                    }else{
                        if(return_value != 0){
                            char newAddress[return_value-1] ;
                            for(int j=return_value-1; j>=0; j--){
                                newAddress[j] = currentPath[j];
                            }
                            for(int j=return_value; j<=strlen(currentPath)-1; j++){
                                newAddress[j] = '\0';
                            }
                            strcpy(currentPath, newAddress) ;
                        }else{
                            strcpy(currentPath, "/");
                        }
                    }
                }else{
                    wait(NULL);
                    if(!strcmp(token, "cat"))
                        printf("\n");
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