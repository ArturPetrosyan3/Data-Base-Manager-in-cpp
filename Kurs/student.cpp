#include "student.h"


istream& operator >>(istream &input, Student& student) {
    input   >> student.firstname
            >> student.lastname
            >> student.age
			>> student.group;
    return input;
}

ostream& operator <<(ostream &output, const Student& student) {
    output  << "First Name:	" << student.firstname << "\n"
            << "Last Name:	" << student.lastname << "\n"
            << "Age:	" << student.age << "\n"
			<< "Group:	"  << student.group << "\n";
    return output;
}