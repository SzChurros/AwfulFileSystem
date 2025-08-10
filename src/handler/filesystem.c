#include "filesystem.h"

void defFileMetaStructure(struct *fileMetaStructure ptr)
{
    ptr->perm = 0;
    ptr->creationTime = 0;
    ptr->modifyTime = 0;

    for (int i = 0; i < 117; i++)
    {
        ptr->ptr[i] = 0;
    }

    for (int i = 0; i < 32; i++)
    {
        ret.name = 0;
    }
}

void defFolderMetaStructure(struct *folderMetaStructure ptr)
{
    ptr->creationTime = 0;
    ptr->modifyTime = 0;

    for (int i = 0; i < 117; i++)
    {
        ptr->ptr[i] = 0;
    }

    for (int i = 0; i < 32; i++)
    {
        ptr->name = 0;
    }
}

void getFileData(struct *sector sect, struct *fileMetaStructure ptr)
{
    ptr->perm = sect->dat[1];

    ptr->creationTime = ((uint32_t)sect->dat[3] << 16) | sect->dat[2];

    ptr->updateTime = ((uint32_t)sect->dat[5] << 16) | sect->dat[4];

    for (int i = 0; i < 117)
    {
        ptr->ptr[i] = ((uint32_t)sect->dat[7 + i * 2] << 16) | sect->dat[6 + i * 2];
    }

    for (int i = 0; i < 16)
    {
        ptr->name[i*2] =  & 0xFF;
        ptr->name[i*2+1];
    }
}