#include <stdio.h>
#include <unistd.h> 

int main(int argc, char *argv[]) {
    FILE *file;
    if(access(argv[0], F_OK)==0){
        file = fopen(argv[0], "r") ;
    }else{
        if(access(argv[1], F_OK)==0){
            file = fopen(argv[1], "r");
        }else{
            fprintf(stderr, "No such file\n");
        }
    }
    char* word;
    if ( file == NULL )
    {
        // printf( "Intended file failed to open" ) ;
    }
    else{
        fscanf(file,"%s%*[^\n]",word);
    }
    printf("%s\n", word);
    fclose(file);
    return(0);
}

