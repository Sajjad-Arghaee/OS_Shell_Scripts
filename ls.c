#include <dirent.h> 
#include <stdio.h> 
#include <string.h>

int main(int argc, char *argv[]) {
  DIR *d;
  struct dirent *dir;
  d = opendir(argv[0]);
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0){
        printf("%s\t", dir->d_name);
      }
    }
    printf("\n");
    closedir(d);
  }
  return(0);
}