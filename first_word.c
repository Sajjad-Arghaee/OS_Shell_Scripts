#include <stdio.h> 

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[0], "r");
    char* word;
    if ( file == NULL )
    {
        printf( "Intended file failed to open" ) ;
    }
    else{
        fscanf(file,"%s%*[^\n]",word);
    }
    printf("%s\n", word);
    fclose(file);
    return(0);
}
