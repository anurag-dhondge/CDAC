/*
    4. Employee Payroll System with Abstract Classes:
    Select suitable type of inheritance to implement given scenario
    Problem Statement: Design an employee payroll system. Create an abstract class Employee with
    attributes like name and employee ID. Derive concrete classes like Hourly Employee and Salaried
    Employee. Define abstract methods for calculating pay in the base class and implement them in the
    derived classes.
*/

#include <iostream>
using namespace std;

class Employee
{
	protected:
		string name;
		int employeeId;

	public:
		Employee(string employeeName, int id)
		{
			name = employeeName;
			employeeId = id;
		}

		virtual double calculatePay() = 0;

		virtual void display()
		{
			cout << "\nEmployee Name: " << name;
			cout << "\nEmployee ID: " << employeeId;
		}

		virtual ~Employee()
		{
		}
};

class HourlyEmployee : public Employee
{
	private:
		double hoursWorked;
		double hourlyRate;

	public:
		HourlyEmployee(string employeeName, int id,
					   double hours, double rate)
			: Employee(employeeName, id)
		{
			hoursWorked = hours;
			hourlyRate = rate;
		}

		double calculatePay() override
		{
			return hoursWorked * hourlyRate;
		}

		void display() override
		{
			Employee::display();

			cout << "\nEmployee Type: Hourly";
			cout << "\nHours Worked: " << hoursWorked;
			cout << "\nHourly Rate: " << hourlyRate;
			cout << "\nTotal Pay: " << calculatePay();
		}
};

class SalariedEmployee : public Employee
{
	private:
		double monthlySalary;

	public:
		SalariedEmployee(string employeeName, int id,
						 double salary)
			: Employee(employeeName, id)
		{
			monthlySalary = salary;
		}

		double calculatePay() override
		{
			return monthlySalary;
		}

		void display() override
		{
			Employee::display();

			cout << "\nEmployee Type: Salaried";
			cout << "\nMonthly Salary: " << monthlySalary;
			cout << "\nTotal Pay: " << calculatePay();
		}
};

int main()
{
	Employee *employee1;
	Employee *employee2;

	HourlyEmployee hourlyEmployee("Rahul", 101, 160, 200);
	SalariedEmployee salariedEmployee("Amit", 102, 50000);

	employee1 = &hourlyEmployee;
	employee2 = &salariedEmployee;

	cout << "===== HOURLY EMPLOYEE =====";
	employee1->display();

	cout << "\n\n===== SALARIED EMPLOYEE =====";
	employee2->display();

	return 0;
}