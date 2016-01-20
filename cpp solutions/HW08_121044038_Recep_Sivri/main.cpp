//HW08_121044038_Recep_Sivri
//
//  main.cpp
//  Created on 19/12/2015
//  Description:
//    main File for HW08_121044038_Recep_Sivri which contains tests.

#include"File.h"
#include"Executable.h"
#include"Directory.h"
#include"TextFile.h"
using namespace std;
using namespace HW08RecepSivri;
int main()
{
    //Definitions Classes for testings.
    Executable file1("C++","Recep",123,"01 11 2015");
    TextFile Tfile("deneme","Sivri",213,"01 12 2015");
    Directory dir1("dir1","Sivri",12,"03 11 2014");
    Directory dir2("dir2","Sivri",14,"04 01 2014");
    Directory dir3("dir3","Sivri",17,"05 10 2014");
    Directory dir4("dir4","Sivri",19,"07 09 2015");
    Directory dir5("dir5","Sivri",20,"15 06 2013");
    Directory dir6("dir6","Sivri",123,"15 08 2014");
    Executable file2("java","Sivri",125,"05 12 2014");
    Executable file3("mips","Sivri",15,"08 12 2014");
    Executable file4("lisp","Sivri",25,"25 12 2014");
    Executable file5("verilog","Sivri",55,"15 12 2014");
    TextFile Tfile2("deneme2","Recep",22,"12 12 2015");
    TextFile Tfile3("deneme3","Recep",225,"17 12 2015");
    TextFile Tfile4("deneme4","Recep",224,"18 12 2015");
    TextFile Tfile5("deneme5","Recep",124,"28 12 2015");

    //Tests for cp function
    cout<<"------------------------Testing For cp Function---------------------------"<<endl;
    if(!dir1.cp(&Tfile))
        cout<<"1.invalid copy processing!"<<endl;
    if(!dir4.cp(&file1))
        cout<<"2.invalid copy processing!"<<endl;
    if(!dir4.cp(&Tfile3))
        cout<<"2.invalid copy processing!"<<endl;
    if(!dir3.cp(&file2))
        cout<<"3.invalid copy processing!"<<endl;
    if(!dir2.cp(&Tfile2))
        cout<<"4.invalid copy processing!"<<endl;
    if(!dir1.cp(&dir2))
        cout<<"5.invalid copy processing!"<<endl;
    if(!dir2.cp(&dir3))
        cout<<"6.invalid copy processing!"<<endl;
    if(!dir3.cp(&dir4))
        cout<<"7.invalid copy processing!"<<endl;
    if(!Tfile2.cp(&file1))
        cout<<"8.invalid copy processing!"<<endl;
    if(!dir4.cp(&dir5))
        cout<<"9.invalid copy processing!"<<endl;
    if(!file1.cp(&dir5))
        cout<<"10.invalid copy processing!"<<endl;
    if(!dir5.cp(&file4))
        cout<<"11.invalid copy processing!"<<endl;
    if(!dir5.cp(&dir6))
        cout<<"12.invalid copy processing!"<<endl;
    if(!dir6.cp(&Tfile4))
        cout<<"13.invalid copy processing!"<<endl;
    if(!dir6.cp(&file3))
        cout<<"14.invalid copy processing!"<<endl;
    if(!dir6.cp(&file5))
        cout<<"15.invalid copy processing!"<<endl;
    if(!dir6.cp(&Tfile5))
        cout<<"16.invalid copy proecessing!"<<endl;

    //Testing for ls function.
    cout<<"------------------------Testing For ls() Function---------------------------"<<endl;
    cout<<"---Testing ls() with no parameter:----";
    cout<<endl<<"From dir1:"<<endl;
    dir1.ls();
    cout<<endl<<"From dir2:"<<endl;
    dir2.ls();
    cout<<endl<<"From dir3:"<<endl;
    dir3.ls();
    cout<<endl<<"for C++ Executable File:"<<endl;
    file1.ls();
    cout<<endl<<"for deneme Text File:"<<endl;
    Tfile.ls();
    cout<<"---Testing ls() with -a parameter:----";
    cout<<endl<<"From dir1:"<<endl;
    dir1.ls("-a");
    cout<<endl<<"From dir2:"<<endl;
    dir2.ls("-a");
    cout<<endl<<"From dir3:"<<endl;
    dir3.ls("-a");
    cout<<endl<<"for C++ Executable File:"<<endl;
    file1.ls("-a");
    cout<<endl<<"for deneme Text File:"<<endl;
    Tfile.ls("-a");

    cout<<endl<<"----Testing ls() with -l parameter:----";
    cout<<endl<<"From dir1:"<<endl;
    dir1.ls("-l");
    cout<<endl<<"From dir4:"<<endl;
    dir4.ls("-l");
    cout<<endl<<"From dir6:"<<endl;
    dir6.ls("-l");
    cout<<endl<<"for java Executable File:"<<endl;
    file2.ls("-l");
    cout<<endl<<"for deneme2 Text File:"<<endl;
    Tfile2.ls("-l");

    cout<<endl<<"---Testing ls() with -R parameter:---";
    cout<<endl<<"From dir3:"<<endl;
    dir3.ls("-R");
    cout<<endl<<"From dir4:"<<endl;
    dir4.ls("-R");
    cout<<endl<<"From dir5:"<<endl;
    dir5.ls("-R");
    cout<<endl<<"for java Executable File:"<<endl;
    file2.ls("-R");
    cout<<endl<<"for deneme2 Text File:"<<endl;
    Tfile2.ls("-R");

    cout<<endl<<endl<<"----Testing ls() with -Rl or -lR parameter:----";
    cout<<endl<<"From dir2:"<<endl;
    dir2.ls("-Rl");
    cout<<endl<<"From dir3:"<<endl;
    dir3.ls("-lR");
    cout<<endl<<"From dir5:"<<endl;
    dir5.ls("-Rl");
    cout<<endl<<"for mips Executable File:"<<endl;
    file3.ls("-Rl");
    cout<<endl<<"for deneme3 Text File:"<<endl;
    Tfile3.ls("-lR");

    cout<<endl<<endl<<"---Testing ls() with -Ra or -aR parameter:----";
    cout<<endl<<"From dir2:"<<endl;
    dir2.ls("-Ra");
    cout<<endl<<"From dir3:"<<endl;
    dir3.ls("-aR");
    cout<<endl<<"From dir5:"<<endl;
    dir5.ls("-Ra");
    cout<<endl<<"for mips Executable File:"<<endl;
    file3.ls("-Ra");
    cout<<endl<<"for deneme3 Text File:"<<endl;
    Tfile3.ls("-aR");

    cout<<endl<<endl<<"---Testing ls() with -la or -al parameter:---";
    cout<<endl<<"From dir2:"<<endl;
    dir2.ls("-la");
    cout<<endl<<"From dir3:"<<endl;
    dir3.ls("-al");
    cout<<endl<<"From dir5:"<<endl;
    dir5.ls("-la");
    cout<<endl<<"for mips Executable File:"<<endl;
    file3.ls("-la");
    cout<<endl<<"for deneme3 Text File:"<<endl;
    Tfile3.ls("-al");
    //Testing for cd function.
    cout<<"------------------------Testing For cd() Function---------------------------"<<endl;
    cout<<"----for Dir2 in Dir1:----"<<endl;
        dir1.cd("dir2");
    cout<<"----for deneme in Dir1:----"<<endl;
        dir1.cd("deneme");
    cout<<"----Testing cd() with TextFile:----"<<endl;
        Tfile2.cd("dir2");
    cout<<"----Testing cd() with Executable File:----"<<endl;
        file2.cd("dir2");

    //Testing for path function.
   cout<<"------------------------Testing For path() Function---------------------------"<<endl;
   cout<<"----for Dir6----"<<endl;
   cout<<dir6.path()<<endl;
   cout<<"----for Dir4----"<<endl;
   cout<<dir4.path()<<endl;
   cout<<"----for java Executable File----"<<endl;
   cout<<file2.path()<<endl;
   cout<<"----for deneme4 Text File----"<<endl;
   cout<<Tfile4.path()<<endl;
    return 0;
}
