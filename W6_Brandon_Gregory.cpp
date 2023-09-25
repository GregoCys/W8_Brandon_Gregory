////////////////////////////////////////
// Brandon Gregory                    //
// CSCI140 C001 Summer 2023           //
// Instructor name: Dr. Frank Appiah  //
// Week #: Week 8                     //
// Date completed: 09/25/2023         //
////////////////////////////////////////
//                                    //
// How-to Instructions in README.txt  //
//                                    //
////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include "calculations.h"

void print_result(char op, float num1, float num2, float result);

int main() {

    char selection;
    float num1, num2, result;
    std::string name;
    std::vector<MPG> mpgData;
    std::vector<SimplePay> spData;

    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cin.ignore();

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1) Add\n" << "2) Subtract\n" << "3) Multiply\n" << "4) Divide\n";
        std::cout << "5) Calc MPG\n" << "6) Calc Simple Pay\n";
        std::cout << "7) Save MPG to file\n" << "8) Save Simple Pay Calc to file\n";
        std::cout << "9) View MPG file\n" << "v) View Simple Calc file\n" << "q) Exit\n";
        std::cout << "Choose: ";

        std::cin >> selection;
        std::cin.ignore();

        if (selection >= '1' && selection <= '4') {
            std::cout << "Enter two numbers: ";
            std::cin >> num1 >> num2;
            std::cin.ignore();
        }

        switch (selection) {
            case '1' :
                result = bg_add(num1, num2);
                print_result('+', num1, num2, result);
                break;
            case '2' :
                result = bg_sub(num1, num2);
                print_result('-', num1, num2, result);
                break;
            case '3' :
                result = bg_mult(num1, num2);
                print_result('*', num1, num2, result);
                break;
            case '4' :
                if (num2 == 0) {
                    std::cout << "Cannot divide by zero. Enter the second number again: ";
                    std::cin >> num2;
                    std::cin.ignore();
                    continue;
                }
                result = bg_div(num1, num2);
                print_result('/', num1, num2, result);
                break;
            case '5':
                {
                    MPG newMPG;
                    calcMPG(&newMPG);
                    mpgData.push_back(newMPG);
                }
                break;
            case '6':
                {
                    SimplePay newSP;
                    calcSimplePay(&newSP);
                    spData.push_back(newSP);
                }
                break;
            case '7':
                saveMPG(mpgData);
                break;
            case '8':
                saveSimplePay(spData);
                break;
            case '9':
                viewMPGFile();
                break;
            case 'v':
                viewSimplePayFile();
                break;
            case 'q':
                std::cout << name << ", thank you for using my application.\n";
                std::cout << "Press any key to close...";
                std::cin.get();
                exit(0);
            default:
                std::cout << "Invalid option\n";
        }

    } while(1);

    return 0;
}
