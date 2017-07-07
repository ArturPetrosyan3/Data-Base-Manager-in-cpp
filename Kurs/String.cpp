#include "String.h"

MyString::MyString ()
{
    length = 1;
    str = '\0';
}

MyString::MyString (const char *c)
{
    from_c_str (c);
}

MyString::MyString (const MyString& t)
{
    from_c_str (t.str);
}

MyString::~MyString ()
{
    delete[] str;
}
char*  MyString::tochar (MyString str) {
	char temp[100];
	int j=0;
	for (int i=0;i<str.get_length();i++) {
		temp[j++]=str[i];
	}
	temp[j] = '\0';
	return temp;
}

MyString& MyString::operator= (const MyString& t)
{
    from_c_str (t.str);

    return *this;
}

MyString MyString::replace(MyString str,size_t pos, size_t lenght, MyString Value) {
	MyString temp = "",temp2 = "";
	temp = str.remove(pos,lenght);
	for (int i = 0; i<Value.get_length();i++) {
		temp2  = temp.insert(pos++,Value[i]);
		temp = temp2;

	}
	return temp;
}
MyString& MyString::operator= (const char *c)
{
    from_c_str (c);
    return *this;
}

//MyString MyString::operator+ (const MyString& t) const
//{
//    return (MyString(str) += t.str);
//}

MyString operator+ (const MyString& str,const int& a)
{
	  
	int radix = 10; 
	char buffer[20]; 
	char *p;  
	p = itoa(a,buffer,radix);
	MyString ob = "aaaaaaaaaa";
	for (int i=0;i<10;i++)
		ob[i] = p[i];
    return (ob += MyString(str));
}
MyString operator+ (const int& a,const MyString& str)
{  
	int radix = 10; 
	char buffer[20]; 
	char *p;  
	p = itoa(a,buffer,radix);
	MyString ob = "aaaaaaaaaa";
	for (int i=0;i<10;i++)
		ob[i] = p[i];
	MyString k = str;
    return (ob += k);
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
    MyString ts = lhs;
    return ts += rhs;
}

MyString operator+(const MyString& lhs, const char * rhs) {
	MyString ts = lhs;
    return ts += rhs;
}

bool operator== (const MyString& t, char *c)
{
    return (strcmp(t.str, c) == 0);
}

bool operator== (const MyString& t, const MyString& t1)
{
    return (strcmp(t.str, t1.str) == 0);
}

bool operator!= (const MyString& t, char *c)
{
    return !(operator== (t, c));
}

bool operator!= (const MyString& t, const MyString& t1)
{
    return !(operator== (t, t1.str));
}

//MyString& MyString::operator+= (const MyString& t)
//{
//    length = strlen (str) + strlen (t.str) + 1;
//    char *newStr = new char[length];
//    strcpy (newStr, str);
//    strcat (newStr, t.str);
//    strcpy (str, newStr);
//    str[length-1] = '\0';
//    delete[] newStr;
//
//    return *this;
//}

MyString& MyString::operator+=(const MyString& rhs)
{
    int sz = strlen(this->str) + strlen(rhs.str);
    char* ts = new char[sz+1];
    for (int i = 0; i < strlen(this->str); i++)
        ts[i] = this->str[i];
    for (int ii = strlen(this->str), j = 0; ii <= sz; ii++, j++)
        ts[ii] = rhs.str[j];
    delete this->str;
    this->str = ts;
    return *this;
}

char& MyString::operator[] (size_t i)
{
    return str[i];
}

const char& MyString::operator[] (size_t i) const
{
    return str[i];
}

char& MyString::at (size_t i)
{
    if (str != NULL && i >= 0 && i < length)
    {
        return str[i];
    }
    else
    {
        throw std::exception ("wrong index");
    }
}

const char& MyString::at (size_t i) const
{
    if (str != NULL && i >= 0 && i < length)
    {
        return str[i];
    }
    else
    {
        throw std::exception ("wrong index");
    }
}

void MyString::get_input (std::istream& in)
{
    while (true)
    {
        char c = in.get ();

        if (c == '\n')
        {
            break;
        }

        if (length == 0)
        {
            length = 2;
        }
        else
        {
            ++length;
        }

        char* newStr = new char[length];
        if (str != NULL)
        {
            strcpy (newStr, str);
        }
        newStr[length-2] = c;
        newStr[length-1] = '\0';

        delete[] str;

        str = newStr;
    }
}

size_t MyString::get_length () const
{
    return (length - 1);
}

void MyString::from_c_str (const char *c)
{
    length = strlen (c) +1;
	char *a = new char[length];
    str = new char[length];
    strcpy (str, c);
}

std::ostream& operator<< (std::ostream& out, const MyString& t)
{
    out << t.str;
    return out;
}

std::istream& operator>>(std::istream& is, MyString& obj)
{
    char BUFF[2048];
 
    is.getline(BUFF, sizeof BUFF);
    obj = BUFF;
 
    return is;
}

 MyString::operator int() {
	int a = atoi(str);
	return a;
}

 MyString MyString::substr(size_t first, size_t last) {
	 if ((first > 0 && last <=  this->get_length() ) && ( first <= last && last >= first)  ) {
		 char temp[1000];
		 int j =0;
		 for (int i = first;i<=last;i++) {
			 temp[j] = this->str[i];
			 j++;
		 }
		 temp[j] = '\0';
		 return MyString(temp);
	 } else {
		 throw std::exception ("wrong index");
	 }
 }
 MyString MyString::remove(size_t first, size_t last) {
	 int len = this->get_length();
	 if ((first >= 0 && last <=  this->get_length() ) && ( first <= last && last >= first)  ) {
		 char temp[1000];
		 int j =0;
		 for (int i = 0;i<this->get_length(); i++) {
			 if (i>=first && i<last)
				 continue;
			 temp[j] = this->str[i];
			 j++;
		 }
		 temp[j] = '\0';
		 return MyString(temp);
	 } else {
		 throw std::exception ("wrong index");
	 }
 }
 MyString MyString::insert(size_t pos,const char& c) {
	int  size = this->get_length();
	if (pos > 0 && pos <= this->get_length()) {
		char *temp = new char[this->get_length() +1];
		int i = 0;
		int j = 0;
		for (i ; i < pos; i++)
			temp[i] = this->str[i]; 
		temp[i] = c;
		for (j=i; j < this->get_length()+1; j++)
			temp[j+1] = this->str[j];
		temp[j] = '\0';
		str = new char[length +1];
		strcpy (str, temp);
		return MyString(str);
	} else {
		throw std::exception ("wrong index");
	}
 }

 size_t MyString::find(const MyString& str, int i) {
	 if (i >= 0 && i <= this->get_length()) {
		 int find_lengt = str.get_length();
		 int find_lengt_1 =find_lengt;
		 int t =0;
		 int c = 0;
		 int b = 0;
		 for (i; i<this->get_length(); i++) {
			 while (find_lengt) {
				if (this->str[i] == str.str[t] ) {
					t++;
					i++;
					if (t == find_lengt_1) {
						c = i+1;
						c-= find_lengt_1;
						b = t;
					} 
				} 
				find_lengt--;
			 }
			 t=0;
			 find_lengt =str.get_length();
		 }
		 if (b == find_lengt) {
			return c;
		} else {
			return INT_MAX;
		}
	 } else {
		 throw std::exception ("wrong index");
	 }
 }

 bool MyString::find(const MyString& str1, const char* ch) {
	int find_lengt = str1.get_length();
	str = new char[find_lengt];
	this->length = find_lengt;
	int i = 0;
	for (i; i< find_lengt; i++)
		this->str[i] = str1.str[i];
	this->str[i] = '\0';
	MyString temp = ch;
	if (find(temp) != INT_MAX) {
		return 1;
	} else {
		return 0;
	}
 }
 size_t MyString::find(const char* ch) {
	MyString temp = ch;
	if (find(temp) != INT_MAX) {
		return find(temp);
	} else {
		return 0;
	}
 }

 bool MyString::find(const char* str,int pos) {
	MyString temp = str;
	if (find(temp,pos) != INT_MAX) {
		return 1;
	} else {
		return 0;
	}
 }