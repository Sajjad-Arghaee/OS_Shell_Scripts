#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
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

    int bufferLength = 255;
    char buffer[bufferLength];
    int count = 0;


    while(fgets(buffer, bufferLength, file)) {
        count++;
    }
    printf("%d\n", count);
    fclose(file);
	return(0);
}

