//HW08_121044038_Recep_Sivri
//
//  Executable.h
//  Created on 19/12/2015
//  Description:
//    Executable File for HW08_121044038_Recep_Sivri which Executable header file.
#ifndef EXECUTABLE_H_INCLUDED
#define EXECUTABLE_H_INCLUDED
#include"File.h"
using namespace std;
namespace HW08RecepSivri
{
    class Executable:public File
    {
        public:
            Executable(string Filename,string ownerOfFile,int SizeOfFile,string Lmodification,string compiler):File(Filename,//constructors for Executable Class.
            ownerOfFile, SizeOfFile,Lmodification),compilerType(compiler){}
           Executable(string Filename,string ownerOfFile,int SizeOfFile,string Lmodification):File(Filename,
            ownerOfFile, SizeOfFile,Lmodification){}
            Executable(string Filename,string ownerOfFile,int SizeOfFile):File(Filename,
            ownerOfFile,SizeOfFile){}
            Executable(string Filename,string ownerOfFile):File(Filename,
            ownerOfFile){}
            Executable(string NameDirectory):File(NameDirectory){}
            Executable():File(){}
            string getCompilerType()const{return compilerType;}//gets compiler type.
            void setCompilerType(string compiler);//sets compiler type.
            virtual void makePath(string str);//makes path.
            virtual bool cp(  File* object);//copies file or directory to directory
            virtual void ls();// ls function for Executable class.
            virtual void ls(string command);// ls function with arguments for Executable class.
            virtual File& cd(string str);// cd function for Executable class.
        private:
            string compilerType;//compiler type for Executable File.
    };
}


#endif // EXECUTABLE_H_INCLUDED
