#include <stdio.h>
#include <string.h>

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

    if (buffer[strlen(buffer)-1] != 10)
        printf("\n");
    fclose(file);
	return(0);
}
