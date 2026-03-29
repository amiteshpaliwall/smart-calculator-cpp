/*
SMART CALCULATOR v1.0
Features:
+ - * / ^ sqrt %
History (last 5 calculations)
Exception handling
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// ---------- HISTORY STRUCT ----------
struct Calculation {
    double a, b, result;
    char op;
};

Calculation history[5];
int historyIndex = 0;

// ---------- SAVE HISTORY ----------
void saveHistory(double a, double b, char op, double result) {
    history[historyIndex % 5] = {a, b, result, op};
    historyIndex++;
}

// ---------- SHOW HISTORY ----------
void showHistory() {
    cout << "\nRecent Calculations:\n";
    for (int i = 0; i < 5; i++) {
        if (history[i].op != '\0') {
            cout << history[i].a << " "
                 << history[i].op << " "
                 << history[i].b
                 << " = " << history[i].result << endl;
        }
    }
}

// ---------- OPERATIONS ----------
double divide(double a, double b) {
    if (b == 0)
        throw runtime_error("Division by zero!");
    return a / b;
}

double squareRoot(double a) {
    if (a < 0)
        throw runtime_error("Negative number!");
    return sqrt(a);
}

// ---------- MENU ----------
void showMenu() {
    cout << "\n===== SMART CALCULATOR =====\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Power\n";
    cout << "6. Square Root\n";
    cout << "7. Modulo\n";
    cout << "8. History\n";
    cout << "0. Exit\n";
}

// ---------- MAIN ----------
int main() {

    int choice;
    double a, b, result;

    do {

        showMenu();
        cout << "Enter choice: ";
        cin >> choice;

        try {

            switch (choice) {

            case 1:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                result = a + b;
                saveHistory(a,b,'+',result);
                break;

            case 2:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                result = a - b;
                saveHistory(a,b,'-',result);
                break;

            case 3:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                result = a * b;
                saveHistory(a,b,'*',result);
                break;

            case 4:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                result = divide(a,b);
                saveHistory(a,b,'/',result);
                break;

            case 5:
                cout << "Enter base and power: ";
                cin >> a >> b;
                result = pow(a,b);
                saveHistory(a,b,'^',result);
                break;

            case 6:
                cout << "Enter number: ";
                cin >> a;
                result = squareRoot(a);
                saveHistory(a,0,'√',result);
                break;

            case 7:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                result = fmod(a,b);
                saveHistory(a,b,'%',result);
                break;

            case 8:
                showHistory();
                continue;

            }

            if(choice!=0 && choice!=8)
            cout << "Result = " << fixed << setprecision(4) << result << endl;

        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 0);

    cout << "Goodbye!\n";

}
