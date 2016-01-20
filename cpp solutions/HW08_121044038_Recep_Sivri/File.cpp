//HW08_121044038_Recep_Sivri
//
//  File.cpp
//  Created on 19/12/2015
//  Description:
//  File  File for HW08_121044038_Recep_Sivri which File implementation file.
#include"File.h"
namespace HW08RecepSivri
{
    void File::setFileName(string Filename)
    {
        Name=Filename;
    }
    void File::setOwner(string ownerOfFile)
    {
        owner=ownerOfFile;
    }
    void File::setSize(int SizeOfFile)
    {
        Size=SizeOfFile;
    }
    void File::setLastModification(string Lmodification)
    {
        LastModificaiton=Lmodification;
    }
}

