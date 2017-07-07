#pragma once

#include "String.h"
#include <iostream>
#include<fstream>
#include<cstring>
#include <sys/stat.h>
#include <direct.h>
#include "createFiled.h"
using namespace std;
class CreateDatabase
{
	public:
		CreateDatabase() {
			current_wd = "";
			dname = "";
			password = "";
			repassword = "";
		};
		CreateDatabase(MyString DataBaseName,MyString Password,MyString RepeatPassword) ;
		~CreateDatabase();
		MyString Create(MyString DataBaseName,MyString Password,MyString RepeatPassword);
		int out;
		bool CreateTable (MyString DataBaseName,MyString TableName );
		bool CreateColumn(MyString DataBaseName,MyString TableName, MyString FildName, MyString FildType, MyString FildLength);
		MyString Open(MyString DataBaseName);
	private:
		MyString current_wd;
		MyString dname;
		MyString password;
		MyString repassword;
		createFiled fild;
};

class databasestore
{
    private:
        char dname[40];
        char password[40];
    public:
        databasestore(){}
		databasestore(string dname1,string password1)
        {
		}
};
