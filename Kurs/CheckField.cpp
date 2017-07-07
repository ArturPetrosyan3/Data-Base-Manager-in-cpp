#include "CheckField.h"


MyString a;
MyString startMsg;
StartEnd check_1;
int EPos, end_pos;  
int table_row_count =0;
int selectite;

MyString table_name;
MyString TableNameOP="";
MyString FildName_As="";


checkField::checkField() {
	Edit=0,
    //end_pos=0,
    SHOW=0,
    NEXT=0,
    now=0,
    //EPos=0,
    start=1,            
    field_index=0,
    total_field=0,
    index=0,           
    Xpos=30,
    Ypos=10,
    data_length=0,     
    add_record=0,
    delete_record=0,   
    save_record=0;      

}

checkField::~checkField(){}



MyString checkField::check(MyString tn)
{
    char *character = new char;
    MyString table_design;
    ifstream file;
	MyString temp;
	MyString text = "", FildName = "",FildType = "", FildLength = "";
	temp=tn;
    table_design=temp+=".info";
	char *TableDesign = new char[table_design.get_length() + 1];
	strcpy(TableDesign, table_design.tochar(table_design));
    file.open(TableDesign);
    int is = file.tellg();
	int row=0,j=0,point=0,FildCount=0;
    if(is==-1){
        cout << "file absent" <<endl;
    }
    else{
		while(!file.eof()){
            file.read(character,1);
			if (character[0] == '\n' && !file.eof()) {
				//FildCount++;
				WriteData(tn,FildName,FildType,FildLength);
				point = 0;
				text = "";
			}
			if(character[0] == '.'){
				point++;
			}
			if (point == 2) {
				row=1;
				FildName  = GetFildName(row,text);
				point++;
			}
			if (point == 4) {
				row=1;
				FildType  = GetFildName(row,text);
				point++;
			}
			if (point == 6) {
				row=1;
				FildLength  = GetFildName(row,text);
			}

            if(!(strcmp(character,"\n")) || file.eof()){
                    field_index=0;
            }
            else{
				character[1] = '\0';
                text+=character;
            }
        }
    }
	char *TableName_ToChar = new char[tn.get_length() + 1];
	strcpy(TableName_ToChar, tn.tochar(tn));
	fstream fpinfo;
	fpinfo.open(TableName_ToChar,ios::out|ios::app);
	fpinfo.write("<",1);
	fpinfo.write("\n",1);
	fpinfo.close();
    file.close();
	return text;
}


void checkField::InsertItem(MyString table_name, MyString fildname, MyString value) {
	TableNameOP = table_name;
	FildNameAsInput = "";
	FildNameAsInput = value;
	FildValueAsInput = "";
	FildValueAsInput = fildname;
	char *TableNameInternal = new char[table_name.get_length() + 1];
	strcpy(TableNameInternal, table_name.tochar(TableNameOP));

	checkField ob;
	MyString row = "",temp = "",temp2 = "";
	fstream file,buffer;
	buffer.open(TableNameInternal,ios::out|ios::app);
	GetFildName(table_name);
	temp2 = FildName_As;
	if (fildname == temp2) {
		for (int i = 0; i< value.get_length();) { 
			temp = GetSeperateValue(value,i);
			if (temp != "")	{
				int temp_Len = temp.get_length();
				char str[10];  
				itoa(temp_Len, str, 10);
				buffer.write(str,strlen(str));
				buffer.write("<",1);
				char *FildToChar = new char[temp.get_length() + 1];
				strcpy(FildToChar, temp.tochar(temp));
				buffer.write(FildToChar,strlen(FildToChar));
				//buffer.write("<",1);
				i+=temp.get_length();
			} else {
				i++;
			}
		}
	buffer.write("<",1);
	buffer.write("\n",1);
	}
	FildName_As = "";
	buffer.close();
}

MyString checkField::GetSeperateValue(MyString value,int i) {
	MyString temp = "";
	char *take = new char;
	int j =0;
	for (;i<value.get_length();i++) {
			if (value[i] != ',') {
				take[j++] = value[i];
			} else {
				break;
			}
	}
	take[j] = '\0';
	temp = take;
	return temp;
}

MyString checkField::GetFildName(MyString tn) {
	char *character = new char;
    MyString table_design;
    ifstream file;
	MyString temp;
	MyString text = "", FildName = "",FildType = "", FildLength = "";
	temp=tn;
    table_design=temp+=".info";
	char *TableDesign = new char[table_design.get_length() + 1];
	strcpy(TableDesign, table_design.tochar(table_design));
    file.open(TableDesign);
	if(!file)
		cout << "Warning ";
    int is = file.tellg();
	int row=0,j=0,point=0,FildCount=0,field_index;
    if(is==-1){
        cout << "file absent" <<endl;
    }
    else{
		while(!file.eof()){
            file.read(character,1);
			if (character[0] == '\n')
				FildCount++;
			if (character[0] == '\n' && !file.eof()) {
				 FildName_As += FildName;
				// if (!file.eof())
					FildName_As += ",";
				point = 0;
				text = "";
			}
			if(character[0] == '.'){
				point++;
			}
			if (point == 2) {
				row=1;
				FildName  = GetFildName(row,text);
				point++;
			}
			if(!(strcmp(character,"\n")) || file.eof()){
                    field_index=0;
            }
            else{
				character[1] = '\0';
                text+=character;
            }
		}
	}
	file.close();
	return "def";
}


//bool checkField::InsertItemHelper(MyString fildname) {
//
//}

bool checkField::addItem(MyString tn, MyString fildname, MyString value) {
	check(tn);
	return true;
}

MyString checkField::GetFildName(MyString tn,MyString fildname,MyString FildItemName,int mode,int SelectDelete) {
	char *character = new char;
    MyString table_design;
    ifstream file;
	MyString temp;
	MyString text = "", FildName = "",FildType = "", FildLength = "";
	temp=tn;
    table_design=temp+=".info";
	char *TableDesign = new char[table_design.get_length() + 1];
	strcpy(TableDesign, table_design.tochar(table_design));
    file.open(TableDesign);
	if(!file)
		cout << "Warning ";
    int is = file.tellg();
	int row=0,j=0,point=0,FildCount=0,field_index;
    if(is==-1){
        cout << "file absent" <<endl;
    }
    else{
		while(!file.eof()){
            file.read(character,1);
			if (character[0] == '\n')
				FildCount++;
			if (character[0] == '\n' && !file.eof()) {
				IsFildExest(tn,FildName,FildCount,fildname,FildItemName,mode,SelectDelete);
				//return FildName;
				point = 0;
				text = "";
			}
			if(character[0] == '.'){
				point++;
			}
			if (point == 2) {
				row=1;
				FildName  = GetFildName(row,text);
				point++;
			}
			if(!(strcmp(character,"\n")) || file.eof()){
                    field_index=0;
            }
            else{
				character[1] = '\0';
                text+=character;
            }
		}
	}
	file.close();
	return "def";
}

bool checkField::RemoveItem(MyString tablename, MyString fildname, MyString FildItemName,int SelectDelete) {
	if (GetFildName(tablename,fildname,FildItemName,0,SelectDelete)) {
		return true;
	} else
		return false;
}

MyString checkField::TeturnFildName(MyString fild) {
	return fild;
}

bool checkField::IsFildExest(MyString tablename, MyString FildName,int FildCount,MyString fildnameAsImput,MyString FildItemName, int select,int SelectDelete ) {
	if (FildName == fildnameAsImput) {
		checkField ob;
		MyString temp = "",temp1="";
			TableNameOP = tablename;
			int len=GetTableLenght(tablename);
			for (size_t i=0;i<len;i++)  {
				 len=GetTableLenght(tablename);
				 temp = ob[i];
				 fstream fpinfo;
				 fpinfo.open("temp.info",ios::out);
				 char *row = new char[temp.get_length() + 1];
				strcpy(row, temp.tochar(temp));
				fpinfo.write(row,strlen(row));
				fpinfo.write("\n",1);
				fpinfo.close();
				temp1= ob[FildCount];
				 if (SelectDelete == 1) {
					 if (temp1 == FildItemName) {
						 if (select != 1) {
								RenoveHelper(tablename,temp);
								if (i != 0) {
									i--;
								}
								i--;
						 } else if (select == 1) {
							 selectite =1;
							 SelectHelper(tablename,SelectDelete);
							 i++;
						 }
					 }
				 } else if (SelectDelete == 2) {
					 if (temp1 != FildItemName) {
						 if (select != 1) {
								RenoveHelper(tablename,temp);
								if (i != 0) {
									i--;
								}
								i--;
						 } else if (select == 1) {
							 selectite =1;
							 SelectHelper(tablename,SelectDelete);
							 i++;
						 }
					 }
				 }
			}

	} else {
		return false;
	}

}

int checkField::GetTableLenght(MyString table_name) {
	char *TableName_ToChar = new char[table_name.get_length() + 1];
	strcpy(TableName_ToChar, table_name.tochar(table_name));
	int numLines = 0;
	ifstream in(TableName_ToChar);
	while ( in.good() )
	{
		std::string line;
		std::getline(in, line);
		if (line != "")
			++numLines;
	}

	return numLines;
}

bool checkField::RenoveHelper(MyString tablename,MyString fild) {
	fstream fpinfo;
	fpinfo.open("buffer",ios::out|ios::app);
	if (!fpinfo)
		cout << "warning";
	TableNameOP = tablename;
	checkField ob;
	MyString temp = "";
	int len = GetTableLenght(tablename);
	for (size_t i=0;i<len;i++) {
		temp = ob[i];
		if (temp != fild) {
			char *row = new char[temp.get_length() + 1];
			strcpy(row, temp.tochar(temp));
			fpinfo.write(row,strlen(row));
			fpinfo.write("\n",1);
		}
	}
	char *table_name = new char[tablename.get_length() + 1];
	strcpy(table_name, tablename.tochar(tablename));
	fpinfo.close();
	if (remove( table_name) != 0) 
		cout << "warning";
	int result= rename( "buffer" , table_name );
	if ( result == 0 )
		puts ( "File successfully renamed" );
	else
		perror( "Error renaming file" );
	return true;
}

MyString checkField::TableName(MyString tablename) {
	TableNameOP = tablename;
	return TableNameOP;
}

MyString checkField::operator[] (size_t i) {
	MyString tn="";
	char *TableName = new char[TableNameOP.get_length() + 1];
	strcpy(TableName, TableNameOP.tochar(TableNameOP));
	fstream fp2dbinfo;
    fp2dbinfo.open(TableName,ios::in);
	if (!fp2dbinfo)
		cout << "Warning File is not opened!";
    fp2dbinfo.seekg(0,ios::beg);
	int length=0,integer=0,row=0,ChakertCount=0;
	int toprint = 0;
	int forWhile = 1;
	MyString file_input = "", FildName = "",Index = "";
	char *character=new char;
	char temp[100];
	int j=0,flag=0;
	int tbname = 0;
   while(forWhile)
	{
			if(fp2dbinfo.eof() && character[0] == '\n' )
			{
				break;
			}
           fp2dbinfo.read(character,1);  
		   if ( character[0] == '\n') {
			   tbname++;
				continue;
		   }
		   if (tbname != i) {
			   if (character[0] != '\n')
				   continue;
		   } else 
				temp[j++] = character[0];
		   
	}
   temp[j] = '\0';
   fp2dbinfo.close();
   return temp;
}

MyString checkField::SelectHelper(MyString tablename, int SelectDelete) {
	ShowRecords(tablename,"def", -1,"def",1,SelectDelete);
	return "";
}

MyString checkField::SelectItem(MyString tablename, MyString fildname, MyString FildItemName,int mode,int SelectDelete) {
	GetFildName(tablename,fildname,FildItemName,mode,SelectDelete);
	return "";
}

MyString checkField::operator[] (int i) {
	MyString tn="";
	char *TableName = new char[TableNameOP.get_length() + 1];
	strcpy(TableName, TableNameOP.tochar(TableNameOP));
	fstream fp2dbinfo;
    fp2dbinfo.open("temp.info",ios::in);
	if (!fp2dbinfo)
		cout << "Warning File is not opened!";
    fp2dbinfo.seekg(0,ios::beg);
	int length=0,integer=0,row=0,ChakertCount=0;
	int toprint = 0;
	int forWhile = 1;
	MyString file_input = "", FildName = "",Index = "" , ReturnValue ="";
	char *character=new char;
	char temp[100];
	int j=0,flag=0;
   while(forWhile)
	{
			if(fp2dbinfo.eof() && character[0] == '\n' )
			{
				break;
			}
           fp2dbinfo.read(character,1);  
		   if ( character[0] == '\n') {
				toprint = 0;
				continue;
		   }
		   if (character[0] == '<' && toprint != 0) {
			   ChakertCount++;
			   temp[j] = '\0';
			   j=0;
			   toprint =0;
				if (ChakertCount == i) {
					ReturnValue +=temp;
					return ReturnValue;
				} else {
					continue;
				}
		   }
		   if (character[0] == '>' || character[0] == '<') {
				continue;
		   }
		   
            if((integer = ((int)*character-48))<10)
            {  
				
                length=length*10+integer;
            }
            else if(length)
            {   
				toprint = 1;
               fp2dbinfo.seekg(-1,ios::cur);
                for(int i=0;i<length;i++)
                {
                    fp2dbinfo.read(character,1);
                    temp[j++] = character[0];
                }
				length = 0;
			} 
	}
   fp2dbinfo.close();
  // temp[j] = '\0';
   file_input = temp;
}

void checkField::addRecord(MyString TableName,MyString FildName,MyString FildType,MyString FildLength){
	char *TableName_ToChar = new char[TableName.get_length() + 1];
	strcpy(TableName_ToChar, TableName.tochar(TableName));

	int FildLength_InFile = (int)FildLength;
	char *FildName_Input = new char[FildLength_InFile];
	cout << "Input "<< FildName << "=";
	//if (InsertItemHelper(FildName))
	cin >>FildName_Input;
	
	fstream fpinfo;
	fpinfo.open(TableName_ToChar,ios::out|ios::app);
	if (!fpinfo)
		cout << "Warning File is not opened!";
	char buffer[100];
	//itoa (numLines,buffer,10);
	//fpinfo.write(buffer,strlen(buffer));
	
	int FildLEngth_InFile = strlen(FildName_Input);
	itoa (FildLEngth_InFile,buffer,10);
	fpinfo.write(buffer,strlen(buffer));
	fpinfo.write("<",1);
	fpinfo.write(FildName_Input,strlen(FildName_Input));
	fpinfo.close();
}

bool checkField::WriteData(MyString TableName, MyString FildName,MyString FildType,MyString FildLength) {
	char *TableName_ToChar = new char[TableName.get_length() + 1];
	strcpy(TableName_ToChar, TableName.tochar(TableName));
	addRecord(TableName,FildName,FildType,FildLength);
	return true;
}

MyString checkField::ReadTableInfo(MyString tablename) {
	tablename+=".info";
	char *TableName = new char[tablename.get_length() + 1];
	strcpy(TableName, tablename.tochar(tablename));
	fstream fp2dbinfo;
    fp2dbinfo.open(TableName,ios::in);
	if (!fp2dbinfo)
		cout << "Warning File is not opened!";
    fp2dbinfo.seekg(0,ios::beg);
	int length=0,integer=0,row=0;
	MyString file_input = "", FildName = "";
	char *character=new char;
	char temp[100];
	int j=0;
   while(1)
	{
			if(fp2dbinfo.eof() && character[0] == '\n' )
			{
				break;
			}    
           fp2dbinfo.read(character,1);                       // get character from file
            if((integer = ((int)*character-48))<10)
            {  
                length=length*10+integer;
            }
            else if(length)
            {   
               fp2dbinfo.seekg(-1,ios::cur);
               // file_input.erase();
                for(int i=0;i<length;i++)
                {
                    fp2dbinfo.read(character,1);
                    temp[j++] = character[0];
                }
				length = 0;
			} 

			
	}
   temp[j] = '\0';
   file_input = temp;
   fp2dbinfo.close();
   return file_input;
}

void checkField::ShowRecords(MyString tablename,MyString DeleteFild = "def",int fildcount =-1,MyString FildItemName = "def",int sellect,int SelectDelete ) {
	if (!sellect)
		ShowColumns(tablename);
	else if (sellect ==1) {
		MyString temp = "";
		temp  = tablename;
		tablename = "temp.info";
		ShowColumns(temp);
	}
	char *TableName = new char[tablename.get_length() + 1];
	strcpy(TableName, tablename.tochar(tablename));
	fstream fp2dbinfo;
    fp2dbinfo.open(TableName,ios::in);
	if (!fp2dbinfo)
		cout << "Warning File is not opened!";
    fp2dbinfo.seekg(0,ios::beg);
	int length=0,integer=0,row=0,ChakertCount=0;
	int toprint = 0;
	int forWhile = 1;
	MyString file_input = "", FildName = "";
	char *character=new char;
	char temp[100],check[2];
	int j=0,flag=0;
   while(forWhile)
	{
			if(fp2dbinfo.eof() && character[0] == '\n' )
			{
				break;
			}
           fp2dbinfo.read(character,1);  

		   if ( character[0] == '\n') {
				check[1] = '\n';
				cout << endl;
				toprint = 0;
				check[0] = '!';
				continue;
		   }
		   if (flag) {
			   if (character[0] != '\n')
				   continue;
			   else
				   flag = 0;
		   }
		   
		   if (character[0] == '<' && toprint != 0) {
			   ChakertCount++;
			   temp[j] = '\0';
			   if (DeleteFild == "def") 
					cout << temp << "\t";
				else if(DeleteFild == "DeleteTrue") {
					if (ChakertCount == fildcount) {
						if(temp != FildItemName ) {
							flag =1;
							ChakertCount=0;
						} else {
							cout <<temp;
						}
					}
				}
			   j=0;
		   }
		   if ( character[0] == '<') {
			   check[0] = '<';
				continue;
		   } else if(check[0] == '<' && (integer = ((int)*character-48))<10) {
			   toprint = 1;
               fp2dbinfo.seekg(-1,ios::cur);
                for(int i=0;i<length;i++)
                {
                    fp2dbinfo.read(character,1);
                    temp[j++] = character[0];
					
                }
				check[0] = '!';
				check[1] != '!';
				length = 0;
				continue;
			   
		   }  else {
			   check[0] = '!';
			   check[1] != '!';
		   }

		   if((integer = ((int)*character-48))<10) {
			   check[0] = '!';
			   check[1] != '!';
                length=length*10+integer;
           } else if(length) {  
				toprint = 1;
               fp2dbinfo.seekg(-1,ios::cur);
                for(int i=0;i<length;i++)
                {
                    fp2dbinfo.read(character,1);
                    temp[j++] = character[0];
                }
				length = 0;
			} 
	}
   temp[j] = '\0';
   file_input = temp;
   fp2dbinfo.close();
}

void checkField::ShowColumns(MyString tn) {
	char *character = new char;
    MyString table_design;
    ifstream file;
	MyString temp;
	MyString text = "", FildName = "",FildType = "", FildLength = "";
	temp=tn;
    table_design=temp+=".info";
	char *TableDesign = new char[table_design.get_length() + 1];
	strcpy(TableDesign, table_design.tochar(table_design));
    file.open(TableDesign);
	if(!file)
		cout << "Warning ";
    int is = file.tellg();
	int row=0,j=0,point=0,FildCount=0;
    if(is==-1){
        cout << "file absent" <<endl;
    }
    else{
		while(!file.eof()){
            file.read(character,1);
			if (character[0] == '\n' && !file.eof()) {
				cout << FildName << "\t";
				point = 0;
				text = "";
			}
			if(character[0] == '.'){
				point++;
			}
			if (point == 2) {
				row=1;
				FildName  = GetFildName(row,text);
				point++;
			}
			if(!(strcmp(character,"\n")) || file.eof()){
                    field_index=0;
            }
            else{
				character[1] = '\0';
                text+=character;
            }
		}
	}
	file.close();
	cout << endl;
}

MyString checkField::GetFildName(int row,MyString temp) {
	if (row) {
		int pos =  temp.find(".");	
		MyString temp1 ="";
		temp1 = temp.remove(0,pos);
		return temp1;
	} else {
		return "";
	}
}

void checkField::Next(MyString dbname,MyString tablename){
    MyString a;
	table_name = tablename;
	dname = dbname;
    NEXT=1;
	EPos = 1100;
    if(SHOW!=EPos){
        SHOW++;
		char *TableName = new char[table_name.get_length() + 1];
	strcpy(TableName, table_name.tochar(table_name));
        ifstream is;
        is.open(TableName);
		if (!is)
			cout <<"Warning file is not opened!";
    }

}