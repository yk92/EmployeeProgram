#pragma once
#include <iostream>
#include <vector>
#include "Employee.h"

namespace Records {

	const int kFirstEmployeeNumber = 1000;
	
	class Database {
		
		public:
			
			Database();
			
			Employee& addEmployee(const std::string& firstName,
								  const std::string& lastName);
			Employee& getEmployee(int employeeNumber);
			Employee& getEmployee(const std::string& firstName,
								  const std::string& lastName);
			
			void displayAll() const; //All employees current and former
			void displayCurrent() const; //only current employees
			void displayFormer() const; //all former employees
			
		private:
			
			std::vector<Employee> mEmployees;
			int mNextEmployeeNumber;
	
	};
}