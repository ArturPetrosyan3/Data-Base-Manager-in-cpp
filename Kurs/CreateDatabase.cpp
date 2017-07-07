#include "CreateDatabase.h"
#include "createFiled.h"

CreateDatabase::CreateDatabase(MyString DataBaseName,MyString Password,MyString RepeatPassword) {
	dname = DataBaseName;
	password = Password;
	repassword = RepeatPassword;
	Create(DataBaseName,Password,RepeatPassword);
}
CreateDatabase::~CreateDatabase(){}





MyString CreateDatabase::Create(MyString DataBaseName,MyString Password,MyString RepeatPassword)
{
	dname = DataBaseName;
	password = Password;
	repassword = RepeatPassword;
    fstream fpinfo;

    fpinfo.open("db.txt",ios::out|ios::app);
	if ((password!="\0" )&&(password!=repassword))
        cout <<"Passwords do not match!"<< endl;
    else if (password==repassword){
		char *dbname = new char[dname.get_length() + 1];
		strcpy(dbname, dname.tochar(dname));
		if (mkdir(dbname)==-1){
			
			return "Exest";
		} else {
			int len = strlen(dbname);
			MyString str="";
			MyString str1;
			str1 = str + len;
			cout << str1;
			char *size = new char[str1.get_length() + 1];
			strcpy(size, str1.tochar(str1));
			fpinfo.write(size,strlen(size));
			fpinfo.write(dbname,strlen(dbname));
			if(password!=""){
				char *dpassword = new char[dname.get_length() + 1];
				strcpy(dpassword, password.tochar(password));
				chdir(dbname);
				out=1;
				fstream pwd;
				pwd.open("password.pwd",ios::out|ios::app);
				pwd.write(dpassword,strlen(dpassword));  
			}
			if(password!="\0")
				cout << "database and Password saved" << endl;
			else 
				cout << "database saved"<< endl;
			chdir(dbname);
			out=1;
			
		}
    }
    fpinfo.close();
    fpinfo.close();
	return dname;
}

bool CreateDatabase::CreateTable (MyString DataBaseName,MyString TableName) {
			char *TableName_local = new char[TableName.get_length() + 1];
			strcpy(TableName_local, TableName.tochar(TableName));

			char *path = new char[dname.get_length() + 1];
			strcpy(path, dname.tochar(dname));

			int a =chdir(path);
			fstream db;
			db.open("info.db",ios::app|ios::out);
			if(!db)
				cout << "warning file is not opend!" <<endl;
			if(TableName!=""){
				db.write(TableName_local,strlen(TableName_local));
				db.write(".",1);
				db.close();
				createFiled *field = new createFiled();
				field->cwdDbTable(dname,TableName);
			}			
			return true;
}
MyString CreateDatabase::Open(MyString DataBaseName) {
	char *PathToTabels = new char[DataBaseName.get_length() + 1];
	strcpy(PathToTabels, DataBaseName.tochar(DataBaseName));
	chdir(PathToTabels);
	return DataBaseName;
}

bool CreateDatabase::CreateColumn(MyString DataBaseName,MyString TableName, MyString FildName, MyString FildType, MyString FildLength) {
	fild.InsertFild(DataBaseName, TableName, FildName,FildType, FildLength);
	return true;
}
