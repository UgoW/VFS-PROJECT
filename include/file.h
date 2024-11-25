#include <stdio.h>
#include <stdlib.h>

typedef struct File
{
    char *name;
    char *path;
    char *content;
    int size;
    char *date;
}File;

void init_file(File *file, char *name, char *path, char *content, int size, char *date);
void print_file(File file);
void free_file(File *file);
