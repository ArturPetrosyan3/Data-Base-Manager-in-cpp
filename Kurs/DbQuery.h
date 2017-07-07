#pragma once
#include "CheckField.h"
#include "String.h"
class DbQuery
{
private:
	checkField object;
	bool InsertInto();
	bool DeleteFrome();
	bool SelectFrom();
	MyString GetSeperateValue(MyString value,int i) ;
	MyString QueryString;
public:
	DbQuery(void);
	~DbQuery(void);
	bool prepare(MyString query);
	void BindValue(MyString ValueToBeReplaced, MyString Value);
};

