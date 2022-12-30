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


    while(fgets(buffer, bufferLength, file)) {
        int j = 0;
        while (buffer[j] == 10 || buffer[j] == 9 || buffer[j] == 32 || buffer[j] == 13)
            j++;
        if (buffer[j] != 35)
            printf("%s", buffer);
    }
    if (buffer[strlen(buffer)-1] != 10)
        printf("\n");
    fclose(file);
	return(0);
}



