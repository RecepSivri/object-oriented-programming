//HW08_121044038_Recep_Sivri
//
//  Directory.cpp
//  Created on 19/12/2015
//  Description:
//  Directory  File for HW08_121044038_Recep_Sivri which Directory implementation file.

#include"File.h"
#include"Directory.h"
#include"TextFile.h"
#include"Executable.h"
namespace HW08RecepSivri
{

    bool Directory::cp(  File *object)
    {
        object->makePath(path());
        elements.push_back(object);
        return true;
    }
    void Directory::ls()
    {
        int i;
        for(i=0;i<elements.size();++i)
        {
            cout<<elements[i]->getFileName()<<"   ";
        }
        cout<<endl;
    }
    void Directory::ls(string command)
    {
        int i;
        Directory *dirObj;
        TextFile *textObj;
        Executable *execObj;
        if(command.compare("-a")==0)
        {
            cout<<". .. ";
            for(i=0;i<elements.size();++i)
            {
                cout<<elements[i]->getFileName()<<"   ";
            }
        }
        if(command.compare("-R")==0)
        {
            cout<<path()<<":\n";
            for(i=0;i<elements.size();++i)
            {
                    cout<<elements[i]->getFileName()<<" ";
                        FindDirectories(elements[i]);
            }

        }
        if(command.compare("-l")==0)
        {
            for(i=0;i<elements.size();++i)
            {
                    cout<<elements[i]->getFileName()<<" ";
                    textObj=dynamic_cast<TextFile*>(elements[i]);
                    execObj=dynamic_cast<Executable*>(elements[i]);
                    dirObj=dynamic_cast<Directory*>(elements[i]);
                    if(textObj)
                        cout<<"-rw-rw-r-- ";
                    if(execObj)
                        cout<<"-rwxrwxr-x ";
                    if(dirObj)
                        cout<<"drwxrwxr-x ";
                    cout<<elements[i]->getOwner()<<" ";
                    cout<<elements[i]->getSize()<<" ";
                    cout<<elements[i]->getLastModification()<<" "<<endl;
            }
        }
        if(command.compare("-Rl")==0 || command.compare("-lR")==0)
        {
            cout<<"\n\n"<<path()<<"\n\n";
            for(i=0;i<elements.size();++i)
                    FindDirectoriesForL(elements[i]);
        }
        if(command.compare("-al")==0 || command.compare("-la")==0)
        {
            cout<<"."<<" "<<"drwxrwxr-x ";
            cout<<elements[0]->getOwner()<<" ";
            cout<<elements[0]->getSize()<<" ";
            cout<<elements[0]->getLastModification()<<" "<<endl;
            cout<<".."<<" "<<"drwxrwxr-x ";
            cout<<elements[0]->getOwner()<<" ";
            cout<<elements[0]->getSize()<<" ";
            cout<<elements[0]->getLastModification()<<" "<<endl;
            for(i=0;i<elements.size();++i)
            {
                cout<<elements[i]->getFileName()<<" ";
                textObj=dynamic_cast<TextFile*>(elements[i]);
                execObj=dynamic_cast<Executable*>(elements[i]);
                dirObj=dynamic_cast<Directory*>(elements[i]);
                if(textObj)
                        cout<<"-rw-rw-r-- ";
                if(execObj)
                        cout<<"-rwxrwxr-x ";
                if(dirObj)
                        cout<<"drwxrwxr-x ";
                cout<<elements[i]->getOwner()<<" ";
                cout<<elements[i]->getSize()<<" ";
                cout<<elements[i]->getLastModification()<<" "<<endl;
            }
        }
        if(command.compare("-aR")==0 || command.compare("-Ra")==0)
        {
            cout<<path()<<":\n";
            for(i=0;i<elements.size();++i)
            {
                    if(i==0)
                        cout<<". "<<".. ";
                    cout<<elements[i]->getFileName()<<" ";
                        FindDirectoriesForA(elements[i]);
            }

        }
        cout<<endl;
    }
    void Directory::makePath(string str)
    {
        int i;
        string str2;
        str2=str+"/"+path();
        setPathName(str2);
        for(i=0;i<elements.size();++i)
        {
            str2=elements[i]->path();
            str2=str+"/"+str2;
            elements[i]->setPathName(str2);
        }
    }
    File& Directory::cd(string str)
    {
        int i;
        Directory *dir;
        for(i=0;i<elements.size();++i)
        {
            dir=dynamic_cast<Directory*>(elements[i]);
            if(dir)
            {
                if(elements[i]->getFileName().compare(str)==0)
                {
                    return *elements[i];
                }
            }
        }
        cout<<" no directory "<<str<<" in "<<this->getFileName()<<"!"<<endl;
        return *this;
    }
    void Directory::FindDirectories(File* obj)
    {
        int i;
        Directory *dirObj;
        Directory *dirObj2;
        dirObj=dynamic_cast<Directory*>(obj);
        if(dirObj)
            cout<<"\n"<<obj->path()<<":\n";
        if(dirObj==NULL)
            cout<<"";
        else
        for(i=0;i<dirObj->elements.size();++i)
        {
                cout<<dirObj->elements[i]->getFileName()<<" ";
            FindDirectories(dirObj->elements[i]);
        }
    }
    void Directory::FindDirectoriesForL(File* obj)
    {
        int i;
        Directory *dirObj;
        Directory *dirObj2;
        TextFile *textObj;
        Executable *execObj;
        dirObj=dynamic_cast<Directory*>(obj);
        textObj=dynamic_cast<TextFile*>(obj);
        execObj=dynamic_cast<Executable*>(obj);
        dirObj2=dynamic_cast<Directory*>(obj);
        if(dirObj2)
        {
            cout<<dirObj->getFileName()<<" ";
            cout<<"drwxrwxr-x  ";
            cout<<dirObj->getOwner()<<" ";
            cout<<dirObj->getSize()<<" ";
            cout<<dirObj->getLastModification()<<" "<<endl;
        }
        if(textObj)
        {
            cout<<textObj->getFileName()<<" ";
            cout<<"-rw-rw-r-- ";
            cout<<textObj->getOwner()<<" ";
            cout<<textObj->getSize()<<" ";
            cout<<textObj->getLastModification()<<" "<<endl;
        }
        else
        if(execObj)
        {
            cout<<execObj->getFileName()<<" ";
            cout<<"-rwxrwxr-x  ";
            cout<<execObj->getOwner()<<" ";
            cout<<execObj->getSize()<<" ";
            cout<<execObj->getLastModification()<<" "<<endl;
        }
        else
        if(dirObj)
        {
            cout<<"\n\n"<<dirObj->path()<<"\n\n";
            for(i=0;i<dirObj->elements.size();++i)
            {
                FindDirectoriesForL(dirObj->elements[i]);
            }
        }

    }
    void Directory::FindDirectoriesForA(File* obj)
    {
        int i;
        Directory *dirObj;
        Directory *dirObj2;
        dirObj=dynamic_cast<Directory*>(obj);
        if(dirObj)
            cout<<"\n\n"<<obj->path()<<":\n\n"<<". "<<".. ";
        if(dirObj==NULL)
            cout<<"";
        else
        {

            for(i=0;i<dirObj->elements.size();++i)
            {
                cout<<dirObj->elements[i]->getFileName()<<" ";
                FindDirectoriesForA(dirObj->elements[i]);
            }
        }

    }
}

