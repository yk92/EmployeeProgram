#include <iostream>
#include <stdexcept>
#include <exception>
#include "Database.h"

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database &db);
void doFire(Database &db);
void doPromote(Database &db);
void doDemote(Database &db);

int main() {
	
	Database employeeDB;
	bool done = false;
	
	while (!done) {
		
		int selection = displayMenu();
		
		switch (selection) {
			
			case 1:
				doHire(employeeDB);
				break;
			case 2:
				doFire(employeeDB);
				break;
			case 3:
				doPromote(employeeDB);
				break;
			case 4:
				doDemote(employeeDB);
				break;
			case 5:
				employeeDB.displayAll();
				break;
			case 6:
				employeeDB.displayCurrent();
				break;
			case 7:
				employeeDB.displayFormer();
				break;
			case 0:
				done = true;
				break;
			default:
				cerr << "Unknown command." << endl;
				break;
			}
	}
	
	return 0;
}

//displayMenu assumes user will not enter bad input

//** TODO: Make function better protected against bad input **

int displayMenu() {
	
	int selection = 0;
	
	cout << endl;
	cout << "Employee Database" << endl;
	cout << "-----------------" << endl;
	cout << "1) Hire a new employee" << endl;
	cout << "2) Fire an employee" << endl;
	cout << "3) Promote an employee" << endl;
	cout << "4) Demote an employee" << endl;
	cout << "5) Display all employees" << endl;
	cout << "6) Display current employees" << endl;
	cout << "7) Display former employees" << endl;
	cout << "0) Quit Program" << endl;
	cout << endl;
	cout << "----> ";
	cin >> selection;
	
	return selection;
}

void doHire(Database& db) {

	string firstName;
	string lastName;
	
	cout << "First name? ";
	cin >> firstName;
	cout << "Last Name? ";
	cin >> lastName;
	
	try {
		
		db.addEmployee(firstName, lastName);
	}
	
	catch(const std::exception& exception) {
		
		cerr << "Unable to add new employee: " << exception.what() << endl; 
	}
}

void doFire(Database& db) {
	
	int employeeNumber;
	cout << "Employee number? ";
	cin >> employeeNumber;
	
	try {
		
		Employee& emp = db.getEmployee(employeeNumber);
		emp.fire();
		cout << "Employee " << employeeNumber << " terminated!" << endl;
	}
	
	catch(const std::exception& exception){
		
		cerr << "Unable to terminate employee: " << exception.what() << endl;
	}
}

void doPromote(Database& db) {
	
	int employeeNumber;
	int raiseAmount;
	
	cout << "Employee number? ";
	cin >> employeeNumber;
	cout << "How much of a raise? ";
	cin >> raiseAmount;
	
	try {
		
		Employee& emp = db.getEmployee(employeeNumber);
		emp.promote(raiseAmount);
	}
	
	catch(const std::exception& exception) {
		cerr << "Could not promote employee: " << exception.what() << endl;
	}
}

void doDemote(Database& db) {

	int employeeNumber;
	
	cout << "Employee number? ";
	cin >> employeeNumber;
	
	try {
		
		Employee& emp = db.getEmployee(employeeNumber);
		emp.demote();
	}
	
	catch(const std::exception& exception) {
		cerr << "Unable to demote: " << exception.what() << endl;
	}
}
	