//HW08_121044038_Recep_Sivri
//
//  TextFile.h
//  Created on 19/12/2015
//  Description:
//    TextFile File for HW08_121044038_Recep_Sivri which TextFile header file.
#ifndef TEXTFILE_H_INCLUDED
#define TEXTFILE_H_INCLUDED
#include"File.h"
namespace HW08RecepSivri
{
    class TextFile:public File
    {
        public:
            TextFile(string Filename,string ownerOfFile,int SizeOfFile,string Lmodification,string type):File(Filename,//constructors for TextFile class.
            ownerOfFile, SizeOfFile,Lmodification),TextFileType(type){}
            TextFile(string Filename,string ownerOfFile,int SizeOfFile,string Lmodification):File(Filename,
            ownerOfFile, SizeOfFile,Lmodification){}
            TextFile(string Filename,string ownerOfFile,int SizeOfFile):File(Filename,
            ownerOfFile,SizeOfFile){}
            TextFile(string Filename,string ownerOfFile):File(Filename,
            ownerOfFile){}
            TextFile(string NameDirectory):File(NameDirectory){}
            TextFile():File(){}
            string getType()const{return TextFileType;}//returns TextFile Type.
            void setType(string str);//sets TextFile class.
            virtual bool cp(  File* object);//cp for TextFile class.
            virtual void makePath(string str);//updates path for TextFile class.
            virtual void ls();//ls function like in linux.
            virtual void ls(string command);//ls function like in linux with arguments( -l,-a or -R).
            virtual File& cd(string str);//cd function for TextFile class.
        private:
            string TextFileType;//type of Textfile.
            string PathName;//name of path.
    };


}
#endif // TEXTFILE_H_INCLUDED
