#include <iostream>
#include <cstring>
using namespace std;

class Person {
// a class's defualt member visibility is private
    string firstName;
    string lastName;
    char dob[11];
    int age;
    protected:
	string addr;
    public:
	Person(string aName) {
	    firstName = aName;
	}
	Person(string aName, string lastName_) {
	    firstName = aName; lastName = lastName_;
	}
	Person(string aName, string lastName_, string addr_, const char dob_[11]
		,int age_)
	 : firstName {aName}, lastName {lastName_}, addr {addr_}, age {age_} {
	    strncpy(dob, dob_, sizeof(dob));	
	}
	void setName(string aName) {
	    cout << "Changing first name !\n";
	    firstName = aName;
	}
	void setName(string aName, string lastName_) {
	    cout << "Changing first & last names !\n";
	    firstName = aName; lastName = lastName_;
	}
	void setAddr(string newAddr) {
	    cout << "Changing " + firstName + "'s address\n";
	    addr = newAddr;
	}
	void setDOB(const char dob_[11]) {
	    strncpy(dob, dob_, sizeof(dob));
	}
	void setAge(int age_) { age = age_; }
	void getPersonName() {
	  // this will print the first & last names of the person
	    if (lastName != "" && firstName != "")
                cout << firstName + " " + lastName + "\n";
	    else if (firstName != "" && lastName == "")
	        cout << firstName + "\n";
	}
	void getPersonInfo() {
	    cout << firstName + "'s date of birth is: " << dob << endl;
	    cout << firstName + "'s age is: " << age << endl;
	    cout << firstName + " lives at the address of: " << addr << endl;
	}
};

class Org {
    char estDate[11];
    string companyName;
    string missionStatement;
    string aboutUs;

    protected:
	Person CEO;
	long annualBudget;
	long annualDebt;
	int numOfEmployees;

    public:
	Org(string companyName_) : CEO("The CEO") {
	    companyName = companyName_;
	}
	Org(string companyName_, string CEOname, int numOfEmployees_) :
	  CEO(CEOname) {
	    companyName = companyName_;
	    numOfEmployees = numOfEmployees_;
	}
	Org(string companyName_, string CEOfirstName,string CEOlastName,
	   int numOfEmployees_, long companyBudget, long companyDebts,
	   string estDate_) : CEO(CEOfirstName, CEOlastName)
	{
	    companyName = companyName_;
	    numOfEmployees = numOfEmployees_;
	    annualBudget = companyBudget;
	    annualDebt = companyDebts;
	    strncpy(estDate, estDate_.c_str(), sizeof(estDate));
	    cout << "Enter your company's mission statement: ";
	    getline(cin, missionStatement);
	    cout << "Tell us a bit about your company: ";
	    getline(cin, aboutUs);
	}
	void getCompanyInfo() {
	    cout << "This company's name is: " << companyName << endl;
	    cout << companyName + "'s CEO is: "; CEO.getPersonName();
	    cout << companyName + " was established on: " + estDate << endl;
	    cout << companyName + " has an annual budget of: " << annualBudget
		<< endl;
	    cout << companyName + " has an annual debt of: " << annualDebt
		<< endl;
            if ( missionStatement != "" && aboutUs != "")
                getStatements();
            else if (missionStatement == "" && aboutUs != "")
                cout << companyName + " is all about: " << aboutUs << endl;
	    else if (missionStatement != "" && aboutUs == "")
		cout << companyName + "'s mission statement is: "
		    << missionStatement << endl;
	    if (numOfEmployees != 0) {
		cout << companyName + " has: " << numOfEmployees
		  << " employees !\n";
	    }
	}
	void getStatements() {

	// this method does not check to see if companyName & missionStatement
	// member variables are null we will still get "" an empty string
	// printing
	    cout << companyName + "'s mission statement is: "
		<< missionStatement << endl;
	    cout << companyName + " is all about: " << aboutUs << endl;
	}
	void setCompanyName(string orgName) {
	    companyName = orgName;
	}
	void setEstDate(const char est[11]) {
	    strncpy(estDate, est, sizeof(estDate));
	}
	void setStatements(string mission, string aboutUs_) {
	    missionStatement = mission;
	    aboutUs = aboutUs_;
	}
	void setCompanyFunds(long companyBudget, long companyDebt) {
	    annualBudget = companyBudget;
	    annualDebt = companyDebt;
	}
	void setNumOfEmployees(int numOfEmp) { numOfEmployees = numOfEmp;}
	void setCEOname(string firstName, string lastName) {
	    CEO.setName(firstName, lastName);
	}
};
int main () {
    Person aPerson("Johnathan", "Torres", "117 W 3rd st.", "07/17/1998", 21);
    aPerson.getPersonName();
    aPerson.getPersonInfo();
    cout << "\n";

    aPerson.setName("John");
    aPerson.getPersonName();
    aPerson.getPersonInfo();
    cout << "\n";

    aPerson.setName("Alejandro", "Gonzales");
    aPerson.getPersonName();
    aPerson.getPersonInfo();
    cout << "\n";

    Org firstOrg("John's Organization");
    firstOrg.getCompanyInfo();
    cout << "Explicit method call to get mission & about us statements\n";
    firstOrg.getStatements();
    cout << "\n";

    firstOrg.setEstDate("07/17/1998");
    firstOrg.setStatements("Provide tomorrow's solutions for todays problems",
	"With more than 21 years of expierence and contracts spanning from the U.S to Mexico we're the place to go to !");
    firstOrg.setCompanyFunds(700000000000, 650000000);
    firstOrg.setNumOfEmployees(50);
    firstOrg.setCEOname("Johnathan", "Torres");
    firstOrg.getCompanyInfo();
    cout << endl;

    cout << "Creating a secondOrg\n";
    Org secondOrg("TheOrganization", "Johnathan", "Torres", 50,
	95000000, 7250000, "07/17/1998");
    secondOrg.getCompanyInfo();
    cout << endl;
    // our company grew gained new employees and a new CEO
    secondOrg.setCompanyFunds(100000000, 950000000);
    secondOrg.setNumOfEmployees(250);
    secondOrg.setCEOname("Jennifer", "Medina");
    // now lets compare the output from both Org objects
    cout << "firstOrg info bellow\n";
    firstOrg.getCompanyInfo();
    cout << endl;
    cout << "secondOrg info bellow\n";
    secondOrg.getCompanyInfo();
    cout << endl;
    
    cout << "Creating another Person object !" << endl;
    Person anotherPerson("Johnathan", "Torres");
    anotherPerson.getPersonName();
    anotherPerson.getPersonInfo();
    cout << endl;
    cout << "Adding additional info to anotherPerson\n";
    anotherPerson.setDOB("07/17/1998");
    anotherPerson.setAge(21);
    anotherPerson.setAddr("403 Sherwood");
    cout << endl;

    // lets compare the output from both Person objects
    cout << "aPerson info is as follows bellow: \n";
    aPerson.getPersonName();
    aPerson.getPersonInfo();
    cout << endl;
    cout << "anotherPerson info is as follows bellow: \n";
    anotherPerson.getPersonName();
    anotherPerson.getPersonInfo();
    cout << endl;
    
    return 0;
}
