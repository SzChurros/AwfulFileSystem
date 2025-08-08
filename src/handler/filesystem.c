#include "filesystem.h"

struct fileMetaStructure defFileMetaStructure()
{
    struct fileMetaStructure ret;

    ret.perm = 0;
    ret.creationTime = 0;
    ret.modifyTime = 0;

    for (int i = 0; i < 109; i++)
    {
        ret.ptr[i] = 0;
    }

    for (int i = 0; i < 64; i++)
    {
        ret.name = 0;
    }

    return ret;
}