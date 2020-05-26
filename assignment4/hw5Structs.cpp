#include <iostream>
using namespace std;

/*
    we can also at a further date use fileIO by including the necessary header
    files which are #include <fstream>  which is file stream, so we're able to
    read/write to file OR we can use #include <ofstream> to simply write to a
    file OR #include <ifstream> to read from a file.

    once a file has been created we can write to that file in the JSON
    file format, simply put JSON just stand for JavaScript Object Notation,
    there's nothing special about these files, the only thing about them is
    the information stored in these files are followed by strict syntax rules
    provided by the JSON language and is used by NoSql databases which use
    documents opposed to the use of TABLES and COLUMNS that are found in SQL
    databases
*/

struct Person {
    string firstName;
    string lastName;
    string address;
    char sex[2];
};

struct Org {
    string companyName;
    Person CEO;
    Person employee;
    string companyLocation;
    string missionStatement;
    string aboutUs;
    long annualDues;
    long annualBudget;
};

void printOrgInfo(Org anOrg) {
    cout << "anOrg companyName is: " << anOrg.companyName << endl;
    cout << anOrg.companyName << "s CEO is: " <<  anOrg.CEO.firstName
        << " " << anOrg.CEO.lastName << endl;
    cout << anOrg.companyName << "'s mission is: " << anOrg.missionStatement
	<< endl;
    cout << "Here's a little about us: " << anOrg.aboutUs << endl;
}

int main() {
    Org defaultOrg {{},{},{}};
    printOrgInfo(defaultOrg);
    cout << endl;

    defaultOrg = {"My Company",{"Johnathan", "Torres", "117 W 3rd St.", "M"},
	{},"Hanford, CA", "Mission Statement", "About Us", 0, 0};
    printOrgInfo(defaultOrg);
    cout << endl;

    Org anotherOrg {"R & D Labs inc.",{"Johnathan", "Torres", "117 W 3rd St.",
	"M"}, {}, "San Francisco, CA",
	"We strive on pushing todays boundarys for tomorrws future",
	"Starting as a small company in electronics, quickly gaining traction as the place to go !", 0,0};
    printOrgInfo(anotherOrg);
    return 0;
}
