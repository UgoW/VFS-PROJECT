#include "file.h"

void init_file(File *file, char *name, char *path, char *content, int size, char *date){
    file->name = (char *)malloc(strlen(name) + 1);
    strcpy(file->name, name);
    file->path = (char *)malloc(strlen(path) + 1);
    strcpy(file->path, path);
    file->content = (char *)malloc(strlen(content) + 1);
    strcpy(file->content, content);
    file->size = size;
    file->date = (char *)malloc(strlen(date) + 1);
    strcpy(file->date, date);
};

void print_file(File file){
    printf("Name: %s\n", file.name);
    printf("Path: %s\n", file.path);
    printf("Content: %s\n", file.content);
    printf("Size: %d\n", file.size);
    printf("Date: %s\n", file.date);
};

void free_file(File *file){
    free(file->name);
    free(file->path);
    free(file->content);
    free(file->date);
};