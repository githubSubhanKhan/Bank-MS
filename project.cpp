#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <limits>

using namespace std;

struct date_of_birth {
    int day;
    int month;
    int year;

    // Function to print the Date of Birth in readable format
    void print() const {
        cout << setfill('0') << setw(2) << day << '/'<< setfill('0') << setw(2) << month << '/'<< year << endl;
    }

    void input() {
        string dateStr;
        while (true) {
            cout << "Enter date of birth (DD/MM/YYYY): ";
            getline(cin, dateStr);

            istringstream dateStream(dateStr);
            char delimiter1, delimiter2;

            if (dateStream >> day >> delimiter1 >> month >> delimiter2 >> year 
                && delimiter1 == '/' && delimiter2 == '/'
                && day >= 1 && day <= 31 && month >= 1 && month <= 12) {
                break; // Exit if input is valid
            }

            cout << "Invalid date format. Please try again.\n";
        }
    }
};

class BankAccount {
    private:
        string full_name;
        date_of_birth dob;
    
    public:
        void inputDetails() {
            cout << "Enter Full Name: ";
            getline(cin, full_name);
            dob.input();
        }

        void outputDetails() {
            cout << "Full Name: " << full_name << endl;
            dob.print();
        }
};

int main() {
    BankAccount account;
    account.inputDetails();
    cout << "Account Details" << endl;
    account.outputDetails();
    return 0;
}