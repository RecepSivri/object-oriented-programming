//HW08_121044038_Recep_Sivri
//
//  Directory.h
//  Created on 19/12/2015
//  Description:
//    Directory File for HW08_121044038_Recep_Sivri which Directory header file.
#ifndef DIRECTORY_H_INCLUDED
#define DIRECTORY_H_INCLUDED
#include"File.h"
#include<vector>

using namespace std;

namespace HW08RecepSivri
{
    class Directory:public File
    {
        public:
            Directory(string Filename,string ownerOfFile,int SizeOfFile,string Lmodification):File(Filename,//constructors for Directory Class.
            ownerOfFile, SizeOfFile,Lmodification){}
            Directory(string Filename,string ownerOfFile,int SizeOfFile):File(Filename,
            ownerOfFile,SizeOfFile){}
            Directory(string Filename,string ownerOfFile):File(Filename,
            ownerOfFile){}
            Directory(string NameDirectory):File(NameDirectory){}
            Directory():File(){}
            void FindDirectories(File* obj);//for ls function with -R argument.
            void FindDirectoriesForL(File* obj);//for ls function with -R and -l arguments.
            void FindDirectoriesForA(File* obj);//for ls function with -R and -a arguments.
            //virtual functions for polymorphism.
            virtual void makePath(string str);//virtual functions for create path
            virtual bool cp(  File* object);//cp functions for Directory classes.
            virtual void ls();//ls functions for Directory classes.
            virtual void ls(string command);//ls functions for Directory classes.
            virtual File& cd(string str);//cd function for Directory.
            private:
            vector<File*> elements;// for directory members.
    };
}
#endif // DIRECTORY_H_INCLUDED



