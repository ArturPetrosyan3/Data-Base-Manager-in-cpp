#pragma once

#include "String.h"
#include <iostream>
#include<fstream>
#include <sys/stat.h>
#include <direct.h>
using namespace std;
class createFiled
{
	public:
		createFiled ();
		~createFiled();
		void AddField(MyString);
        void table(MyString);
		void showFields();
		void save(MyString );
		int check();
		void cwdDbTable(MyString,MyString);
		MyString CheckNames(MyString,MyString);
		MyString GetFildName(int row,MyString temp);
		MyString WriteData(MyString tn,MyString FildName,MyString FildType,MyString FildLength);
		void InsertFild(MyString,MyString,MyString fildname="", MyString fildtype="CHAR", MyString fildlength="0");
		char* operator[] (size_t i) ;
	private:
	    MyString table_name,table_design,current_wd,dname;
		MyString FildName,FildType,FildLenght;
		int i;
};