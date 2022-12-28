#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
// still have to work
int main()  
{     
    FILE *file = fopen("file.txt", "r");
    char word[1024];
    fscanf(file, "%1023s", word);
    puts(word);
    
    fclose(file);  
      
    return 0;  
}  
