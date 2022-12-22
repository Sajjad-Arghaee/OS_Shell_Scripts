#include <dirent.h> 
#include <stdio.h> 
#include <string.h>

int main(int argc, char *argv[]) {
    DIR *d;
    struct dirent *dir;
    int strSize = strlen(argv[0]) ;
    char addr[strSize-1] ;
    for(int i=0; i <= strSize-1; i++){
        addr[i] = argv[0][i] ;
    }

    char* addrTok = strtok(addr, "\n");
    strcpy(addr,addrTok);
    for(int i=strSize; i < strlen(addr) ; i++){
        addr[i] = '\0' ;
    }
    strcat(argv[1],"/");
    strcat(argv[1],addr);
    d = opendir(argv[1]);
    if (d) {
        return 2;
    }
    d = opendir(addr);
    if(d){
        return 1;
    }
    printf("No such file or directory\n") ;
    
    return(-1);
}
