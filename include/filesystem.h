#include "file.h"

typedef struct FileSystem{
    File *files;
    int size;
    int capacity;
}FileSystem;

void init_file_system(FileSystem *fs);
void add_file(FileSystem *fs, File file);
void remove_file(FileSystem *fs, char *name);
void print_file_system(FileSystem *fs);
void free_file_system(FileSystem *fs);
