#include <stdio.h>

int main ()
{
	FILE *file = fopen("file.txt","r");
    char body[10000];
    int i = 0;
    char sample = "";
	if (file == NULL)
	    return 0;
	do
	{
		char c = fgetc(file);
		if (feof(file))
			break ;

        body[i++] = c;
	} while(1);
    body[i] = '\0';

    for (int j=0; j<i; j++){
        if (body[j] == 10 || body[j] == 9 || body[j] == 32)
            body[j] = sample;
    }
    printf(body);
	fclose(file);
    FILE *file2 = fopen("file.txt","r");
    fputs("body", file2);
    fclose(file2);
	return(0);
}
