#ifndef FILESYS
#define FILESYS

#include "types.h"

struct fileMetaStructure
{
    uint16 perm; //         word 1
    uint32 creationTime; // word 2-3
    uint32 modifyTime; //   word 4-5

    uint32 ptr[109]; //     word 6-222

    int8 name [64]; //      word 223-255
};

struct fileMetaStructure defFileMetaStructure();

getFileData(uint32 ptr);

#endif