#pragma once

#include "String.h"
#include <iostream>
#include<fstream>
#include<cstring>
#include <sys/stat.h>
#include <direct.h>
using namespace std;




class StartEnd{
    public:
        int table_name;
        int START;
        int END;
        StartEnd(){
            START=1;
            END=0;
        }
};



class checkField
{	
	public:
		checkField();
		~checkField();
		MyString table,table_info,table_name,dname;
		void setTableName(MyString);
		int checklongtext(int []);
		void Next(MyString,MyString);
		void ShowRecords(MyString,MyString,int,MyString,int sellect = 0,int SelectDelete=0);
		void ShowColumns(MyString );
		MyString GetFildName(MyString,MyString,MyString,int mode,int SelectDelete);
		bool IsFildExest(MyString,MyString,int ,MyString, MyString,int select = 0,int SelectDelete =0);
		bool RemoveItem(MyString, MyString,MyString,int SelectDelete);
		MyString operator[] (size_t i);
		MyString operator[] (int i);
		bool RenoveHelper(MyString tablename,MyString fild);
		int GetTableLenght(MyString table_name);
		MyString SelectHelper(MyString tablename,int SelectDelete);
		MyString SelectItem(MyString tablename, MyString fildname, MyString FildItemName,int mode,int SelectDelete);
		MyString TeturnFildName(MyString fild);
		MyString GetFildName(MyString tn);
		MyString GetSeperateValue(MyString value,int i);
        
int SHOW,             
    NOW,              
    start,            
    field_index,
    total_field,
    PPos1,            
    PREVIOUS,         
    NEXT,             
    now,              
    index,            
    IPos,             
    PPos,             
    CPos,             
//    EPos,           
    Xpos,
    Ypos,
    data_length,      
    editing_pos,      
    Edit,             
    add_record,       
    delete_record,    
    save_record;      	
		StartEnd readTableforlist(int);
		
	public:
		MyString check(MyString);
		StartEnd readTable(int index);
		void addRecord(MyString,MyString,MyString,MyString);
		MyString ReadTableInfo(MyString );
		MyString GetFildName(int ,MyString ) ;
		bool WriteData(MyString,MyString ,MyString ,MyString );
		bool addItem(MyString tn, MyString fildname, MyString value );
		MyString TableName(MyString );
		void InsertItem(MyString table_name, MyString fildname, MyString value);
private:
	MyString FildNameAsInput;
	MyString FildValueAsInput;
};