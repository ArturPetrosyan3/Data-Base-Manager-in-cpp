#include "CreateDatabase.h"
#include "CheckField.h"
#include "SelectDbTable.h"
#include "createFiled.h"
#include "student.h"
#include "DbQuery.h"

void main ()
{

	CreateDatabase db;
	if ("Exest" != db.Create("University","a","a")) {
		db.CreateTable("University","Students");
		db.CreateColumn("University","Students","Name","CHAR","20");
		db.CreateColumn("University","Students","Surename","CHAR","20");
		db.CreateColumn("University","Students","Age","INT","20");
		db.CreateColumn("University","Students","Group","CHAR","20");

		db.CreateTable("University","Lecturer");
		db.CreateColumn("University","Lecturer","Name","CHAR","20");
		db.CreateColumn("University","Lecturer","Surename","CHAR","20");
		db.CreateColumn("University","Lecturer","Departament","CHAR","20");
		//077 57 30 79
	} else {
		cout << "Database already exists "<< endl;
	}

	db.Open("University");
	/*Student stud;
	cin >> stud;
	DbQuery query;
	query.prepare("INSERT INTO Students (Name,Surename,Age,Group,) [:name,:surename,:age,:group]");
	query.BindValue(":name", stud.firstname);
	query.BindValue(":surename", stud.lastname);
	query.BindValue(":age", stud.age);
	query.BindValue(":group", stud.group);

	cin >> stud;
	query.prepare("INSERT INTO Students (Name,Surename,Age,Group,) [:name,:surename,:age,:group]");
	query.BindValue(":name", stud.firstname);
	query.BindValue(":surename", stud.lastname);
	query.BindValue(":age", stud.age);
	query.BindValue(":group", stud.group);*/




	DbQuery query;
	cout << "All table Students";cout << endl;
	query.prepare("SHOW ALL Students");
	cout << endl;
	
	
	cout << "Select Students";cout << endl;
	MyString select = "Gevorgyan";
	query.prepare("SELECT FROM Students WHERE (Surename) == [:Surename]");
	query.BindValue(":Surename",select);
	cout << endl;



	cout << "delete Students";cout << endl;
	MyString forDelete = "aramyan";
	query.prepare("DELETE FROM Students WHERE (Surename) == [:Surename]");
	query.BindValue(":Surename",forDelete);
	cout << endl;cout << endl;

	cout << "All table Students";cout << endl;
	query.prepare("SHOW ALL Students");
	cout << endl;cout << endl;

	cout << "All table Lecturer";cout << endl;
	query.prepare("SHOW ALL Lecturer");
	cout << endl;

	cout << "Select Lecturer";cout << endl;
	query.prepare("SELECT FROM Lecturer WHERE (Surename) == [Alaverdyan]");
	cout << endl;cout << endl;
	
	cout << "delete Lecturer";cout << endl;
	query.prepare("DELETE FROM Lecturer WHERE (Surename) == [Arzumanyan]");
	cout << endl;

	cout << "All table Lecturer";cout << endl;
	query.prepare("SHOW ALL Lecturer");
	cout << endl;

}