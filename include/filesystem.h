#include "file.h"

typedef struct FileSystem{
    File *files;
    int size;
    int capacity;

}FileSystem;