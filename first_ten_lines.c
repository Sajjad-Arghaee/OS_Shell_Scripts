#include <stdio.h>
#include <string.h>
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
    int count = 1;

    while(fgets(buffer, bufferLength, file) && count <= 10) {
        printf("%s",buffer);
        count++;
    }

    if (buffer[strlen(buffer)-1] != 10)
        printf("\n");
    fclose(file);
	return(0);
}
