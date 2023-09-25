#include <iostream>
#include "calculations.h"

using namespace std;

// Basic Math Operations
float bg_add(float a, float b) { return a + b; }
float bg_sub(float a, float b) { return a - b; }
float bg_mult(float a, float b) { return a * b; }
float bg_div(float a, float b) {
    if (b == 0.0) {
        cout << "Cannot divide by zero. Enter the numbers again." << endl;
        return -1;
    }
    return a / b;
}

// Function to print calculation results
void print_result(char operation, float a, float b, float result) {
    cout << a << " " << operation << " " << b << " = " << result << endl;
}

// Function to clear data for new data
void clearData(vector<SimplePay>& spData, vector<MPG>& mpgData) {
    spData.clear();
    mpgData.clear();
}

// Function to read a string input from the user
string readString(const string& prompt) {
    cout << prompt;
    string input;
    getline(cin, input);
    return input;
}

// Function to read a float input from the user
float readFloat(const string& prompt) {
    cout << prompt;
    float value;
    cin >> value;
    cin.ignore();
    return value;
}

// Function to update MPG
void updateMPG(MPG* mpg) {
    mpg->mpg = bg_div(mpg->milesDriven, mpg->gasUsed);
}

// Function to update Pay
void updatePAY(SimplePay* sp) {
    sp->pay = bg_mult(sp->hourlyRate, sp->hoursWorked);
}

// Function to handle MPG calculations
void calcMPG(MPG* mpg) {
    mpg->carName = readString("Enter Car Name: ");
    mpg->tripName = readString("Enter Trip Name: ");
    mpg->gasUsed = readFloat("Enter Gas Used: ");
    mpg->milesDriven = readFloat("Enter Miles Driven: ");
    updateMPG(mpg);
    
    cout << "Car Name: " << mpg->carName << ", Trip Name: " << mpg->tripName 
         << ", Miles Driven: " << mpg->milesDriven << ", Gas Used: " << mpg->gasUsed
         << ", Calculated MPG: " << mpg->mpg << endl;
}

// Function to handle Simple Pay calculations
void calcSimplePay(SimplePay* sp) {
    sp->empName = readString("Enter Employee Name: ");
    sp->hourlyRate = readFloat("Enter Hourly Rate: ");
    sp->hoursWorked = readFloat("Enter Hours Worked: ");
    updatePAY(sp);
    
    cout << "Employee Name: " << sp->empName << ", Hours Worked: " << sp->hoursWorked
         << ", Hourly Rate: $" << sp->hourlyRate << ", Calculated Pay: $" << sp->pay << endl;
}

// Function to save MPG calculations to a file
void saveMPG(const vector<MPG>& mpgData) {
    ofstream file("mpg_results.txt", ios::app);
    
    if (!file.is_open()) {
        cout << "Error: Could not open file." << endl;
        return;
    }

    for (const auto& mpg : mpgData) {
        file << mpg.carName << "|" << mpg.tripName << "|" << mpg.gasUsed 
             << "|" << mpg.milesDriven << "|" << mpg.mpg << endl;
    }
    
    file.close();
    
    cout << "Success: MPG data has been saved to mpg_results.txt." << endl;
}

// Function to save Simple Pay calculations to a file
void saveSimplePay(const vector<SimplePay>& spData) {
    ofstream file("spc_results.txt", ios::app);

    if (!file.is_open()) {
        cout << "Could not open file for writing." << endl;
        return;
    }

    for (const auto& sp : spData) {
        file << sp.empName << "|" << sp.hourlyRate << "|" << sp.hoursWorked << "|" << sp.pay << endl;
    }

    file.close();

    cout << "Simple Pay data saved." << endl;
}

// Function to view saved MPG data from the file
void viewMPGFile() {
    ifstream file("mpg_results.txt");
    
    string line;
    if (!file.is_open()) {
        cout << "Could not open file." << endl;
        return;
    }
    
    cout << "\nMPG Data:" << endl;
    
    while (getline(file, line)) {
        cout << line << endl;
    }
    
    file.close();
}

// Function to view saved Simple Pay data from the file
void viewSimplePayFile() {
    ifstream file("spc_results.txt");
    
    string line;
    if (!file.is_open()) {
        cout << "Could not open file for reading." << endl;
        return;
    }
    
    cout << "\nSimple Pay Data:" << endl;
    
    while (getline(file, line)) {
        cout << line << endl;
    }
    
    file.close();
}
