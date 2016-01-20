//HW08_121044038_Recep_Sivri
//
//  TextFile.cpp
//  Created on 19/12/2015
//  Description:
//  TextFile  File for HW08_121044038_Recep_Sivri which TextFile implementation file.
#include"TextFile.h"

namespace HW08RecepSivri
{
    void TextFile::makePath(string str)
    {
        setPathName(str+"/"+path());
    }
    void TextFile::ls()
    {
        cout<<getFileName()<<endl;
    }
    void TextFile::ls(string command)
    {
        if(command.compare("-a")==0)
            cout<<getFileName()<<endl;
        if(command.compare("-R")==0)
            cout<<getFileName()<<endl;
        if(command.compare("-l")==0)
        {
            cout<<getFileName()<<" ";
            cout<<"-rw-rw-r-- ";
            cout<<getOwner()<<" ";
            cout<<getSize()<<" ";
            cout<<getLastModification()<<" "<<endl;
        }
        if(command.compare("-Rl")==0 || command.compare("-lR")==0)
        {
            cout<<getFileName()<<" ";
            cout<<"-rw-rw-r-- ";
            cout<<getOwner()<<" ";
            cout<<getSize()<<" ";
            cout<<getLastModification()<<" "<<endl;
        }
        if(command.compare("-al")==0 || command.compare("-la")==0)
        {
            cout<<getFileName()<<" ";
            cout<<"-rw-rw-r-- ";
            cout<<getOwner()<<" ";
            cout<<getSize()<<" ";
            cout<<getLastModification()<<" "<<endl;
        }
        if(command.compare("-aR")==0 || command.compare("-Ra")==0)
            cout<<getFileName()<<endl;
    }
    bool TextFile::cp(  File* object)
    {
        return false;
    }
    File& TextFile::cd(string str)
    {
        cout<<"you cannot use cd command in Text File!"<<endl;
    }
    void TextFile::setType(string str)
    {
        PathName=str;
    }
}

