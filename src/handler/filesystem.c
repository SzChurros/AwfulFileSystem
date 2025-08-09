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

void defFileMetaStructure(struct *folderMetaStructure ptr)
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

