#include "DbQuery.h"


DbQuery::DbQuery(void)
{
}


DbQuery::~DbQuery(void)
{
}

void DbQuery::BindValue(MyString ValueToBeReplaced, MyString Value) {
	MyString querytemp = "",query = "";
	int pos = QueryString.find(ValueToBeReplaced);
	int length = ValueToBeReplaced.get_length();
	int SecondPos = pos+length;
	querytemp = QueryString.replace(QueryString,pos-1,SecondPos-1,Value);
	QueryString = querytemp;
	query = QueryString;
	if (!query.find(":")) {
		MyString temp = "", Removed = "", TableName = "", FildNames = "", Values = "";
		if (query.find("INSERT INTO ")) {
			int SelectDelete = 0;
			Removed = query.remove(0,12);
			for (int i = 0; i< query.get_length();) { 
				temp = GetSeperateValue(Removed,i);
				if (temp == "==")
					SelectDelete = 1;
				if (temp == "!=")
					SelectDelete = 2;
				if (temp != "")	{
					if (!temp.find(")") && !temp.find("]") && temp != "WHERE" && temp != "==" && temp != "!=") {
						TableName = temp;
					} else if (temp.find(")")) {
						FildNames = temp.remove(0,1);
						FildNames = FildNames.remove(FildNames.get_length()-1,FildNames.get_length());
					} else if (temp.find("]")) {
						Values = temp.remove(0,1);
						Values = Values.remove(Values.get_length()-1,Values.get_length());
					}
					i+=temp.get_length();
				} else {
					i++;
				}
			}
		object.InsertItem(TableName,FildNames,Values);
		} else if (query.find("SELECT FROM ")) {
			int SelectDelete = 0;
			Removed = query.remove(0,12);
			for (int i = 0; i< query.get_length();) { 
				temp = GetSeperateValue(Removed,i);
				if (temp == "==")
					SelectDelete = 1;
				if (temp == "!=")
					SelectDelete = 2;
				if (temp != "")	{
					if (!temp.find(")") && !temp.find("]") && temp != "WHERE" && temp != "==" && temp != "!=") {
						TableName = temp;
					} else if (temp.find(")")) {
						FildNames = temp.remove(0,1);
						FildNames = FildNames.remove(FildNames.get_length()-1,FildNames.get_length());
					} else if (temp.find("]")) {
						Values = temp.remove(0,1);
						Values = Values.remove(Values.get_length()-1,Values.get_length());
					}
					i+=temp.get_length();
				} else {
					i++;
				}
			}
			object.SelectItem(TableName,FildNames,Values,1,SelectDelete);
		} else if (query.find("DELETE FROM ")) {
			int SelectDelete = 0;
			Removed = query.remove(0,12);
			for (int i = 0; i< query.get_length();) { 
				temp = GetSeperateValue(Removed,i);
				if (temp == "==")
					SelectDelete = 1;
				if (temp == "!=")
					SelectDelete = 2;
				if (temp != "")	{
					if (!temp.find(")") && !temp.find("]") && temp != "WHERE" && temp != "==" && temp != "!=") {
						TableName = temp;
					} else if (temp.find(")")) {
						FildNames = temp.remove(0,1);
						FildNames = FildNames.remove(FildNames.get_length()-1,FildNames.get_length());
					} else if (temp.find("]")) {
						Values = temp.remove(0,1);
						Values = Values.remove(Values.get_length()-1,Values.get_length());
					}
					i+=temp.get_length();
				} else {
					i++;
				}
			} 
			object.RemoveItem(TableName,FildNames,Values,SelectDelete);
		} 
	}

}

bool DbQuery::prepare(MyString query) {
	QueryString = "";
	QueryString = query;
	MyString temp = "", Removed = "", TableName = "", FildNames = "", Values = "";
	if (query.find("SHOW ALL ")) {
			int SelectDelete = 0;
			Removed = query.remove(0,9);
			for (int i = 0; i< query.get_length();) { 
				temp = GetSeperateValue(Removed,i);
				if (temp == "==")
					SelectDelete = 1;
				if (temp == "!=")
					SelectDelete = 2;
				if (temp != "")	{
					if (!temp.find(")") && !temp.find("]") && temp != "WHERE" && temp != "==" && temp != "!=") {
						TableName = temp;
					} else if (temp.find(")")) {
						FildNames = temp.remove(0,1);
						FildNames = FildNames.remove(FildNames.get_length()-1,FildNames.get_length());
					} else if (temp.find("]")) {
						Values = temp.remove(0,1);
						Values = Values.remove(Values.get_length()-1,Values.get_length());
					}
					i+=temp.get_length();
				} else {
					i++;
				}
			} 
			object.ShowRecords(TableName,"def", -1,"def");
		}


	return true;

}

MyString DbQuery::GetSeperateValue(MyString value,int i) {
	MyString temp ="";
	char *take = new char[10000];
	int j =0;
	for (;i<value.get_length();i++) {
			if (value[i] != ' ') {
				take[j++] = value[i];
			} else {
				break;
			}
	}
	take[j] = '\0';
	temp = take;
	return temp;
}