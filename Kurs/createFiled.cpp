#include "createFiled.h"


createFiled::createFiled () {
	
}

createFiled::~createFiled()
{
}



void createFiled::showFields(){
	cout << "Input Fild Name!	";
	cin >> FildName;
	
	cout << "Input Fild Type!	";
	cin >> FildType;
	
	cout << "Input Fild Lenght !	";
	cin >> FildLenght;
}

void createFiled::AddField( MyString table_name)  
{
    int checkvalue=check();
    if (checkvalue==0)
	{   
		save(table_name);
	}  
}




void createFiled::InsertFild(MyString db_name,MyString table_name, MyString fildname, MyString fildtype, MyString fildlength ) {
	CheckNames(db_name,table_name);
	FildName = fildname;
	FildType = fildtype;
	FildLenght = fildlength;
	AddField(table_name);
}


MyString createFiled::CheckNames(MyString db_name, MyString tn)
{
    char *character = new char;
	table_name = tn;
	dname = db_name;
    ifstream file;
	MyString temp;
	MyString text = "";
	temp=tn;
	char *path = new char[db_name.get_length() + 1];
	strcpy(path, db_name.tochar(db_name));
	chdir(path);
    table_design=temp+=".info";
	char *TableDesign = new char[table_design.get_length() + 1];
	strcpy(TableDesign, table_design.tochar(table_design));
	//showFields();
	return text;
}

MyString createFiled::WriteData(MyString tn,MyString FildName,MyString FildType,MyString FildLength) {
	this->FildLenght = FildLength;
	this->FildType = FildType;
	this->FildName = FildName;
	return "";
}


MyString createFiled::GetFildName(int row,MyString temp) {
	if (row) {
		int pos =  temp.find(".");	
		MyString temp1 ="";
		temp1 = temp.remove(0,pos);
		cout <<"temp1"<< temp1 <<endl;
		return temp1;
	} else {
		return "";
	}
}


int createFiled::check()
{
    int pos;
    pos=0;
	int length=FildName.get_length();
    int cint=0,check=0;
     if(FildType=="LONGTEXT")
		FildLenght = "5";
	 if ((int)FildLenght==INT_MAX)
            check=3;    
    if(FildType=="")
            check=2;
            
    fstream fp2tabledesign;
	char *TableDesign = new char[table_design.get_length() + 1];
	strcpy(TableDesign, table_design.tochar(table_design));
        
                
  for (int i=0;i<length;i++)
            {
                char a;
				a=FildName.at(i);
                if (a=='.'||a==' '|| a=='#')
                {
                       check=1;
                        break;
                }
            }
    
        return check;
}
   
void createFiled::save(MyString table_name)
{
        fstream info;
		
        int cint=0;
        int check=1;
		char *TableDesign = new char[table_design.get_length() + 1];
		strcpy(TableDesign, table_design.tochar(table_design));

        info.open(TableDesign,ios::out|ios::app);// save in table_name.info
        info.write("member",6);
        info.write(".",1);

		char *filedname = new char[FildName.get_length() + 1];
		strcpy(filedname, FildName.tochar(FildName));


		int len = strlen(filedname);
        info.write(filedname,strlen(filedname));
        info.write(".",1);

		char *filedtype = new char[FildType.get_length() + 1];
		strcpy(filedtype, FildType.tochar(FildType));

        info.write(filedtype,strlen(filedtype));
		char *fildlenght = new char[FildLenght.get_length() + 1];
		strcpy(fildlenght, FildLenght.tochar(FildLenght));
        if(FildType!="LONGTEXT")
        {
			info.write(".",1);
			info.write(fildlenght,strlen(fildlenght));
		}
		info.write(".",1);
        info.write("\n",1);
        info.close();
        fstream table;
		char *tablename = new char[table_name.get_length() + 1];
		strcpy(tablename, table_name.tochar(table_name));
        table.open(tablename,ios::out);
}



void createFiled::cwdDbTable(MyString dname,MyString table_name) {

	char *TN = new char[table_name.get_length() + 1];
	strcpy(TN, table_name.tochar(table_name));

	char *DN = new char[dname.get_length() + 1];
	strcpy(DN, dname.tochar(dname));
	MyString temp;
	temp=table_name;
    table_design=temp+=".info";
   // chdir(wd);
    chdir(DN);
	fstream info;

		char *TabName = new char[table_name.get_length() + 1];
		strcpy(TabName, table_name.tochar(table_name));
        info.open(TabName,ios::out|ios::app);
		info.close();
	//FildName = "";
	//FildType = "CHAR";
	//FildLenght = "0";
	//showFields();
	//AddField(table_name);
	chdir("..");
}




