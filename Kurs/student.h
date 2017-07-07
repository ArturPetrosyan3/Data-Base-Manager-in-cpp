#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "String.h"

#include<iomanip>
 
using namespace std;
 


class Student {
public:
    Student() {}
	friend istream& operator >>(istream &input, Student& student);
    friend ostream& operator <<(ostream &output, const Student& student);
protected:
    //MyString firstname;
    //MyString lastname;
	
private:
	
	int idnum;
public:
	void show_tabular() const;
	int getIDNum() const;
	void display_all();
	void write_student();
	void class_result();
	void display_sp(const char *str, int n);
	void display_sp(const char* filename,MyString & atr,MyString& atrname,int equal);
	void delete_student(const char* filename, MyString & atr,MyString& atrname,int equal);
	MyString firstname;
    MyString lastname;
    MyString age;
	MyString group;
};
