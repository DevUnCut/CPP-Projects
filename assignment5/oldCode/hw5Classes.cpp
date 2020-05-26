#include <iostream>
//#include <string.h>
#include <cstring>
using namespace std;

class Person {
    string firstName;
    string lastName;
    char dob[10];

    protected:
	string addr;

    public:
	Person () = delete;
	void changeName(string aName_) {
	    cout << "changing name\n";
	    firstName = aName_;
	}
	Person (Person &a) {
	    cout << "Person copy constructor !" << endl;
	    firstName = a.firstName;
	    lastName = a.lastName;
	    strcpy(dob, a.dob);
	    addr = a.addr;
	}
	Person(string firstName_) {cout << "1 param constructor !" << endl;
	    firstName = firstName_;}
	Person(string firstName_, string lastName_) {
		cout << "2 param constructor !" << endl;
		firstName = firstName_;
	    	lastName = lastName_;
	}
	Person(string firstName_, string lastName_, string birthDate,
	      string address) {
	    cout << "4 param constructor !" << endl;
	    firstName = firstName_;
	    lastName = lastName_;
//	    dob = birthDate.data();
	    strncpy(dob, birthDate.c_str(), sizeof(dob));
	    addr = address;
	}

	void printPersonInfo() {
	    cout << firstName + " " + lastName << endl;
	    cout << "Born on this date of: " << dob << endl;
	    cout << "Lives on the address of: " << addr << endl;
	}
};

class Org {
    string companyName;
    string missionStatement;
    string aboutUs;

    protected:
	Person CEO;
	int numOfEmployees;
	long annualBudget;
	long annualDebt;
	Person employee;

    public:
	// lets make some constructors to create a CEO
	Org (string nameOfCEO) : CEO(nameOfCEO), employee(CEO) {
	    cout << "Org constructor called !" << endl;
	}
	Person & getEmployee() {
	    return employee;
	}
	void changeEmployeeName(Person &p, string aName) 
	{ // a test to make sure copy function works
	  // so that employee number 1 can reference the CEO
	    p.changeName(aName);
	}
	void printEmployeeInfo() {
	    cout << "My employee's name is: ";
	    employee.printPersonInfo();
	}
	void printCEOinfo() {
	   cout << "My company CEO is: ";
	   CEO.printPersonInfo();
	}
};

int main() {
    Person aPerson("Johnathan", "Torres", "07/17/1998", "117 W. 3rd St.");
    aPerson.printPersonInfo();
    Org anOrg("John");
    anOrg.printCEOinfo();
    anOrg.printEmployeeInfo();
    anOrg.changeEmployeeName(anOrg.getEmployee(), "JOHNATHAN");

	// after name change
    anOrg.printEmployeeInfo();
    anOrg.printCEOinfo();
}
