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
