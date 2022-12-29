#include <stdio.h>

int main (int argc, char *argv[])
{
	FILE *file = fopen(argv[0],"r");
    int bufferLength = 255;
    char buffer[bufferLength]; /* not ISO 90 compatible */


    while(fgets(buffer, bufferLength, file)) {
        int j = 0;
        while (buffer[j] == 10 || buffer[j] == 9 || buffer[j] == 32 || buffer[j] == 13)
            j++;
        if (buffer[j] != 35)
            printf("%s", buffer);
    }
    printf("\n");
    fclose(file);
	return(0);
}

