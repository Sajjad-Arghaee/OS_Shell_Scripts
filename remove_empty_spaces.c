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
    char body[10000];
    int i = 0;
	if (file == NULL)
	    return 0;
	do
	{
		char c = fgetc(file);
		if (feof(file))
			break ;

        body[i++] = c;
	} while(1);

    for (int j=0; j<i; j++){
        if (body[j] == 10 || body[j] == 9 || body[j] == 32 || body[j] == 13)
            body[j] = 0;
    }

    char result[1000];
    int k = 0;
    for (int j=0; j<i; j++)
        if(body[j] != 0)
            result[k++] = body[j];
    
    
    printf("%s\n", result);
	fclose(file);
    // FILE *file2 = fopen(argv[0],"w");
    FILE *file2 ;
    if(access(argv[0], F_OK)==0){
        file2 = fopen(argv[0], "w") ;
    }else{
        if(access(argv[1], F_OK)==0){
            file2 = fopen(argv[1], "w");
        }else{
            fprintf(stderr, "Unable to write\n");
        }
    }
    fputs(result, file2);
    fclose(file2);
	return(0);
}
