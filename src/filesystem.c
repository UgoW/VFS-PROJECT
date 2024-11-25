#include "filesystem.h"

void init_file_system(FileSystem *fs){
    fs->files = (File *)malloc(sizeof(File) * 10);
    fs->size = 0;
    fs->capacity = 10;
};

void add_file(FileSystem *fs, File file){
    if(fs->size == fs->capacity){
        fs->capacity *= 2;
        fs->files = (File *)realloc(fs->files, sizeof(File) * fs->capacity);
    }
    fs->files[fs->size] = file;
    fs->size++;
};

void remove_file(FileSystem *fs, char *name){
    int i;
    for(i = 0; i < fs->size; i++){
        if(strcmp(fs->files[i].name, name) == 0){
            free_file(&fs->files[i]);
            fs->size--;
            for(; i < fs->size; i++){
                fs->files[i] = fs->files[i + 1];
            }
            break;
        }
    }
};

void print_file_system(FileSystem *fs){
    int i;
    for(i = 0; i < fs->size; i++){
        print_file(fs->files[i]);
    }
};

void free_file_system(FileSystem *fs){
    int i;
    for(i = 0; i < fs->size; i++){
        free_file(&fs->files[i]);
    }
    free(fs->files);
};

