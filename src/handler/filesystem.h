#ifndef FILESYS
#define FILESYS

#include "types.h"

struct fileMetaStructure
{
    uint16 perm; //         word 1
    uint32 creationTime; // word 2-3
    uint32 modifyTime; //   word 4-5

    uint32 ptr[117]; //     word 6-238

    int8 name [32]; //      word 239-255
};

struct folderMetaStructure
{
    uint32 creationTime; // word 2-3
    uint32 modifyTime; //   word 4-5

    uint32 ptr[117]; //     word 6-238

    int8 name [32]; //      word 239-255
};

struct sector
{
    uint16 dat[256];
};

void defFileMetaStructure(struct *fileMetaStructure ptr);
void defFolderMetaStructure(struct *folderMetaStructure ptr);

void getFileData(struct *sector sect, struct *fileMetaStructure ptr);
void getFolderData(struct *sector sect, struct *folderMetaStructure ptr);

#endif