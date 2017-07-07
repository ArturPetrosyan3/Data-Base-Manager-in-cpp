#pragma once

#include "String.h"
#include <iostream>
#include<fstream>
#include <sys/stat.h>
#include <direct.h>
using namespace std;

class selectDbTable 
{

		
	public:
		selectDbTable();
		~selectDbTable();
        int out;
		friend class ClassTable;
		MyString getTableName(MyString);
		int nstart;
        void cwd(MyString);
		MyString getDbName();
};