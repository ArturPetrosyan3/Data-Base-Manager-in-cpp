 #include "SelectDbTable.h"

selectDbTable::selectDbTable(){}
selectDbTable::~selectDbTable(){}

MyString selectDbTable::getDbName()
{
    fstream fp2dbinfo;
    fp2dbinfo.open("db.txt",ios::in);
	if (!fp2dbinfo)
		cout << "Warning File is not opened!";
    fp2dbinfo.seekg(0,ios::beg);
	int length=0,integer=0;
	MyString file_input = "";
	char *character=new char;
	char temp[100];
	int j=0;
	temp[j++] = '|';
   while(1)
	{
			if(fp2dbinfo.eof())
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
                for(int i=0;i<length;i++)
                {
                    fp2dbinfo.read(character,1);
                    temp[j++] = character[0];
                }
				length = 0;
				temp[j++] = '|';
			}    
	}
   temp[j] = '\0';
   file_input = temp;
   return file_input;
}

MyString selectDbTable::getTableName(MyString str)
{
	char *PathToTabels = new char[str.get_length() + 1];
	strcpy(PathToTabels, str.tochar(str));
	chdir(PathToTabels);
    MyString file_input;
   fstream fp2tableinfo;
   fp2tableinfo.open("info.db",ios::in);
	if (!fp2tableinfo)
	cout << "Warning File is not opened!";
	char *character=new char;
	int lenght =1;
	char temp[100];
	int j=0;
	temp[j++] = '|';
   while(1)
	{
			if(fp2tableinfo.eof())
			{
				break;
			}    
           fp2tableinfo.read(character,1);                       // get character from file
            if (character[0] != '.')
            {  
                lenght=0;
				temp[j++] = character[0];
				
            } else {  
				temp[j] = '|';
				j++;
			}
	}
 
   temp[j] = '\0';
   file_input = temp;
   return file_input;

}             
  