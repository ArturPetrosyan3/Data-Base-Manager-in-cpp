

#ifndef MyString_H
#define MyString_H
 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
using namespace std;

class MyString
{
    private:
        size_t length;
        char *str;

    public:
        MyString ();
        MyString (const char *c);
        MyString (const MyString& t);
        ~MyString ();

        MyString& operator= (const MyString& t);
        MyString& operator= (const char *c);
		operator int();
		friend MyString operator+(const MyString& lhs, const MyString& rhs);
		friend MyString operator+(const MyString& lhs, const char * rhs);
		friend MyString MyString::operator+ (const MyString& lhs,const int& t);
		friend MyString MyString::operator+ (const int& t,const MyString& lhs);
		MyString& operator+=(const MyString& rhs);
        char& operator[] (size_t i);
        const char& operator[] (size_t i) const;
		char*  tochar (MyString str);

        char& at (size_t i);
        const char& at (size_t i) const;
        void get_input (std::istream& in);
        size_t get_length () const;
        void from_c_str (const char *other);
		MyString substr(size_t first, size_t last);
		MyString remove(size_t first, size_t last);
		MyString insert (size_t i,const char& c);
		bool find(const MyString& str, const char* ch);
		size_t find(const MyString& str,int i=0);
		size_t find(const char* str);
		bool find(const char* str,int pos);
		MyString replace(MyString str, size_t pos, size_t lenght, MyString Value);
		

        friend std::ostream& operator<< (std::ostream& out, const MyString& t);
        friend std::istream& operator>> (std::istream& in, MyString& obj);
        friend bool operator== (const MyString& t, char *c);
        friend bool operator== (const MyString& t, const MyString& t1);
        friend bool operator!= (const MyString& t, char *c);
        friend bool operator!= (const MyString& t, const MyString& t1);
};
#endif