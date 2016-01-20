//HW08_121044038_Recep_Sivri
//
//  File.h
//  Created on 19/12/2015
//  Description:
//    File.h File for HW08_121044038_Recep_Sivri which File header file(base class).
#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include <iostream>
using namespace std;
namespace HW08RecepSivri
{
    class File
    {
    public:
        File(string Filename,string ownerOfFile,int SizeOfFile,string Lmodification):Name(Filename),owner(ownerOfFile)
        ,Size(SizeOfFile),LastModificaiton(Lmodification),pathName(Filename){}
        File(string Filename,string ownerOfFile,int SizeOfFile):Name(Filename),owner(ownerOfFile)
        ,Size(SizeOfFile),LastModificaiton("\0"),pathName(Filename){}
        File(string Filename,string ownerOfFile):Name(Filename),owner(ownerOfFile),LastModificaiton("\0"),Size(0),pathName(Filename){}
        File(string Filename):Name(Filename),owner("\0"),LastModificaiton("\0"),Size(0),pathName(Filename){}
        File( ):Name("\0"),owner("\0"),LastModificaiton("\0"),Size(0),pathName(Name){}
        void setFileName(string Filename);
        void setOwner(string ownerOfFile);
        void setSize(int SizeOfFile);
        void setLastModification(string Lmodification);
        string getFileName()const{return Name;}
        string getOwner()const{return owner;}
        int getSize()const{return Size;}
        string getLastModification()const{return LastModificaiton;}
        string path()const{return pathName;}
        void setPathName(string str){pathName=str;}//sets Filename.
        // Pure virtual functions.
        virtual void makePath(string str)=0;//updates pathName
        virtual bool cp(  File* object)=0;//copies file or directory to directories.
        virtual void ls()=0;//ls function like in linux.
        virtual void ls(string command)=0;//ls function with arguments(-a , -l or -R...)
        virtual File& cd(string str)=0;//cd function for classes.
    private:
        string pathName;// path name for classes.
        string Name;// file or directory name for classes.
        string owner;//user name for classes.
        int Size;//size for directory or files.
        string LastModificaiton;//date for files or directories.

    };
}
#endif // FILE_H_INCLUDED



