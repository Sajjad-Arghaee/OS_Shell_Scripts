#include <stdio.h> 
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
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
    char* word;
    char saved_words[1000][1000];
    int count_words [1000] = {0};
    int index_saved = 0;
    int word_position = 0;
    if (file == NULL)
    {
        // printf( "Intended file failed to open" ) ;
    }
    else {
        char word[1000];
        while (fscanf(file, "%1000s", word) == 1){
            for (word_position = 0; word_position < index_saved; word_position++){
                if (!strcmp(word, saved_words[word_position]))
                    break;
            }
            if (word_position == index_saved){
                for (int j=0; j<strlen(word); j++)
                    saved_words[index_saved][j] = word[j];
                index_saved++;
            }
            count_words[word_position]++;
            
            
        }
    }

    int max_index = 0;
    for(int i = 1; i < index_saved; i++) {
        if (count_words[i] > count_words[max_index])
            max_index = i;
    }

    printf("result = %s\n", saved_words[max_index]);
    fclose(file);
    return(0);
}

