//HW08_121044038_Recep_Sivri
//
//  Executable.cpp
//  Created on 19/12/2015
//  Description:
//  Executable  File for HW08_121044038_Recep_Sivri which Executable implementation file.
#include"Executable.h"
namespace HW08RecepSivri
{
    void Executable::makePath(string str)
    {
        setPathName(str+"/"+path());
    }
    void Executable::ls()
    {
        cout<<getFileName()<<endl;
    }
    void Executable::ls(string command)
    {
        if(command.compare("-a")==0)
            cout<<getFileName()<<endl;
        if(command.compare("-R")==0)
            cout<<getFileName()<<endl;
        if(command.compare("-l")==0)
        {
            cout<<getFileName()<<" ";
            cout<<"-rwxrwxr-x ";
            cout<<getOwner()<<" ";
            cout<<getSize()<<" ";
            cout<<getLastModification()<<" "<<endl;
        }
        if(command.compare("-Rl")==0 || command.compare("-lR")==0)
        {
            cout<<getFileName()<<" ";
            cout<<"-rwxrwxr-x ";
            cout<<getOwner()<<" ";
            cout<<getSize()<<" ";
            cout<<getLastModification()<<" "<<endl;
        }
        if(command.compare("-al")==0 || command.compare("-la")==0)
        {
            cout<<getFileName()<<" ";
            cout<<"-rwxrwxr-x ";
            cout<<getOwner()<<" ";
            cout<<getSize()<<" ";
            cout<<getLastModification()<<" "<<endl;
        }
        if(command.compare("-aR")==0 || command.compare("-Ra")==0)
            cout<<getFileName()<<endl;

    }
    bool Executable::cp(  File* object)
    {
        return false;
    }
    File& Executable::cd(string str)
    {
        cout<<"you cannot use cd command in Executable File!"<<endl;
    }
    void Executable::setCompilerType(string compiler)
    {
        compilerType=compiler;
    }
}

