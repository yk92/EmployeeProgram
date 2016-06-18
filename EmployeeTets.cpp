#include <iostream>
#include "Employee.h"

using namespace std;
using namespace Records;

int main() {

	cout << "testing the Employee class." << endl;
	
	Employee emp;
	
	emp.setFirstName("Yuval");
	emp.setLastName("Klein");
	emp.setEmployeeNumber(13);
	emp.setSalary(134000);
	emp.promote();
	emp.promote(5050);
	emp.hire();
	emp.display();
	
	return 0;
}