#include "arithmetic.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printMenu() {
    cout << "\n=== Arithmetic Calculator (RPN) ===\n";
    cout << "1. Calculate expression\n";
    cout << "2. Set variable value\n";
    cout << "3. Get variable value\n";
    cout << "4. Show predefined variables\n";
    cout << "5. Show expression in RPN\n";
    cout << "6. Show supported operations\n";
    cout << "7. Exit\n";
    cout << "Choice: ";
}

void calculateExpression(ArithmeticCalculator& calc) {
    string expression;
    cout << "Enter expression: ";
    cin.ignore();
    getline(cin, expression);

    try {
        double result = calc.calculate(expression);
        cout << "Result: " << result << endl;
    }
    catch (const ParseException& e) {
        cout << "Error at position " << e.getPosition() << ": " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void setVariable(ArithmeticCalculator& calc) {
    string name;
    double value;

    cout << "Enter variable name: ";
    cin >> name;
    cout << "Enter variable value: ";
    cin >> value;

    calc.setVariable(name, value);
    cout << "Variable '" << name << "' set to " << value << endl;
}

void getVariable(ArithmeticCalculator& calc) {
    string name;
    cout << "Enter variable name: ";
    cin >> name;

    try {
        double value = calc.getVariable(name);
        cout << name << " = " << value << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void showPredefinedVariables() {
    cout << "\nPredefined variables:\n";
    cout << "pi = 3.14159...\n";
    cout << "e = 2.71828...\n";
}

void showRPN(ArithmeticCalculator& calc) {
    string expression;
    cout << "Enter expression: ";
    cin.ignore();
    getline(cin, expression);

    try {
        size_t errorPos = 0;
        if (!calc.isValidExpression(expression)) {
            cout << "Invalid expression at position" << errorPos << "!" << endl;
            return;
        }

        vector<string> rpn = calc.toRPN(expression);
        cout << "RPN: ";
        for (const string& token : rpn) {
            cout << token << " ";
        }
        cout << endl;

        double result = calc.calculateRPN(rpn);
        cout << "Result from RPN: " << result << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void showSupportedOperations() {
    cout << "\nSupported operations:\n";
    cout << "Arithmetic: +, -, *, /, ^ (power)\n";
    cout << "Comparison: <, >, <=, >=, ==, !=\n";
    cout << "Functions: sin, cos, tan, asin, acos, atan, sqrt, log, log10, exp, abs, floor, ceil, round\n";
    cout << "Variables: any letter or underscore starting identifier\n";
    cout << "Examples:\n";
    cout << "  sin(pi/2) + cos(0) = 2\n";
    cout << "  x = 5, y = 3, x + y = 8\n";
    cout << "  sqrt(16) * 2 = 8\n";
}

int main() {
    ArithmeticCalculator calculator;
    int choice;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            calculateExpression(calculator);
            break;
        case 2:
            setVariable(calculator);
            break;
        case 3:
            getVariable(calculator);
            break;
        case 4:
            showPredefinedVariables();
            break;
        case 5:
            showRPN(calculator);
            break;
        case 6:
            showSupportedOperations();
            break;
        case 7:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}