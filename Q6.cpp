#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int empID;

public:
    virtual void getData() {
        cout << "Enter Employee ID: ";
        cin >> empID;
    }

    virtual void displayData() {
        cout << "Employee ID: " << empID << endl;
    }
};

class Admin : public Person {
protected:
    string name;
    float monthlyIncome;

public:
    void getData() override {
        Person::getData();
        cout << "Enter Admin Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    void displayData() override {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        cout << "Annual Bonus: " << bonus() << endl;
    }

    float bonus() {
        return monthlyIncome * 12 * 0.05f;
    }
};

class Accounts : public Person {
protected:
    string name;
    float monthlyIncome;

public:
    void getData() override {
        Person::getData();
        cout << "Enter Accounts Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    void displayData() override {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        cout << "Annual Bonus: " << bonus() << endl;
    }

    float bonus() {
        return monthlyIncome * 12 * 0.05f;
    }
};

int main() {
    Admin adminEmp;
    Accounts accountsEmp;

    cout << "--- Enter Admin Employee Details ---\n";
    adminEmp.getData();

    cout << "\n--- Enter Accounts Employee Details ---\n";
    accountsEmp.getData();

    cout << "\n--- Admin Employee Information ---\n";
    adminEmp.displayData();

    cout << "\n--- Accounts Employee Information ---\n";
    accountsEmp.displayData();

    return 0;
}
