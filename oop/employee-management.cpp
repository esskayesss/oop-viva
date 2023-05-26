#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Employee{
    private:
        string name;
        int age;
        float salary;

    public:
        Employee(string name, int age, float salary){
            this->name = name;
            this->age = age;
            this->salary = salary;
        }

        void display(){
            cout << "Employee:\n" << "Name: " << this->name << "\nAge: " << this->age << "\nSalary: " << this->salary << endl;
        }
};

class Employees{
    private:
        vector<Employee> employees;

    public:
        void add_employee(string name, int age, float salary){
            Employee new_record(name, age, salary);
            employees.push_back(new_record);
        }

        void add_employee_interactive(){
            string name;
            int age;
            float salary;
            cout << "employee creation in progress...\n" << "enter the name: ";
            cin.ignore();
            getline(cin, name);
            cout << "enter the age: ";
            cin >> age;
            cout << "enter the salary: ";
            cin >> salary;
            Employee new_record(name, age, salary);
            employees.push_back(new_record);
        }

        void print_roster(){
            for(Employee emp: employees)
                emp.display();
        }
};

void print_menu(){
    cout << "employees management menu\n" << "1. add a new employee\n" << "2. print all records\n" << "input q to quit\n" << "enter the choice: ";
}

void driver(){
    Employees manager;
    char choice;
    while(choice != 'q'){
        print_menu();
        cin >> choice;
        choice = tolower(choice);
        switch(choice){
            case '1':
                manager.add_employee_interactive();
                break;
            case '2':
                manager.print_roster();
                break;
            case 'q':
            case 'Q':
                cout << "thanks for using our program.\n";
                exit(1);
            default:
                cout << "invalid choice!\n";
                break;
        }
    }
}


int main(){
    driver();
}
