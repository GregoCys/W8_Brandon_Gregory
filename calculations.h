#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

// Structs
struct MPG {
    std::string carName;
    std::string tripName;
    float gasUsed;
    float milesDriven;
    float mpg;
};

struct SimplePay {
    std::string empName;
    float hourlyRate;
    float hoursWorked;
    float pay;
};

// Function Prototypes
std::string readString(const std::string& prompt);
float readFloat(const std::string& prompt);
void updateMPG(MPG* mpg);
void updatePAY(SimplePay* sp);
void calcMPG(MPG* mpg);
void calcSimplePay(SimplePay* sp);
void saveMPG(const std::vector<MPG>& mpgData);
void saveSimplePay(const std::vector<SimplePay>& spData);
void viewMPGFile();
void viewSimplePayFile();
void clearData(std::vector<SimplePay>& spData, std::vector<MPG>& mpgData);

// Basic Math Operations Prototypes
float bg_add(float a, float b);
float bg_sub(float a, float b);
float bg_mult(float a, float b);
float bg_div(float a, float b);

#endif
