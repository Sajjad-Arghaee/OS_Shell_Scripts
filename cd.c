#include <dirent.h> 
#include <stdio.h> 
#include <string.h>

int main(int argc, char *argv[]) {
    DIR *d;
    struct dirent *dir;
    int strSize = strlen(argv[0]) ;
    char addr[strSize-1] ;
    for(int i=0; i < strSize-1; i++){
        addr[i] = argv[0][i] ;
    }
    d = opendir(argv[1]);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (!strcmp(dir->d_name, addr)){
                return 2;
            }
        }
    }
    d = opendir(addr);
    if(d){
        return 1;
    }
    printf("No such file or directory\n") ;
    
    return(0);
}