#include <stdio.h>

int main (int argc, char *argv[])
{
	FILE *file = fopen(argv[0],"r");
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
