#include <stdio.h>

int main (int argc, char *argv[])
{
	FILE *file = fopen(argv[0],"r");
    int bufferLength = 255;
    char buffer[bufferLength];
    int count = 1;


    while(fgets(buffer, bufferLength, file) && count <= 10) {
        printf(buffer);
        count++;
    }
    fclose(file);
	return(0);
}
