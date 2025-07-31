#ifndef HELP
#define HELP

#include <stdio.h>

void help()
{
    printf("Usage:\n");
    printf("afsedit [flag/filename] [flag/filename]\n");
    printf("a flag is required\n");
    printf("\n");
    printf("flags:\n");
    printf("--help - prints this text\n");
    printf("--meta - for editing metatada\n");
}

#endif
