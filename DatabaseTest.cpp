#include <iostream>
#include "Database.h"

using namespace std;
using namespace Records;

int main() {

	Database myDB;
	
	Employee& emp1 = myDB.addEmployee("Patrick", "Ewing");
	emp1.fire();
	
	Employee& emp2 = myDB.addEmployee("John", "Starks");
	emp2.setSalary(100000);
	
	Employee& emp3 = myDB.addEmployee("Yuval", "Klein");
	emp3.setSalary(1000);
	emp3.promote();
	
	cout << "All Employees:" << endl << endl;
	myDB.displayAll();
	
	cout << "Current Employees: " << endl << endl;
	myDB.displayCurrent();
	
	cout << "Former Employees: " << endl << endl;
	myDB.displayFormer();
	
	return 0;
}