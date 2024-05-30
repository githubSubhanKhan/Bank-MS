#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Account {
private:
    string account_holder_name;
    int account_number;
    double balance;

public:
    Account(int acc_num, const string& name, double bal);

    void deposit(double amount);

    void withdraw(double amount);

    void display_account_details() const;

    int get_account_number() const;

    ~Account();
};

class Bank {
private:
    vector<Account*> accounts;

public:
    void add_account(Account* acc);

    void remove_account(int account_number);

    Account* find_account(int account_number);

    void display_all_accounts() const;

    ~Bank();
};

// Account function definitions
Account::Account(int acc_num, const string& name, double bal) : account_number(acc_num), account_holder_name(name), balance(bal) {}

void Account::deposit(double amount) {
    balance += amount;
}

void Account::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
    } else {
        cout << "Insufficient Balance!" << endl;
    }
}

void Account::display_account_details() const {
    cout << "Account Holder Name: " << account_holder_name << endl;
    cout << "Account Number: " << account_number << endl;
    cout << "Balance: " << balance << endl;
}

int Account::get_account_number() const {
    return account_number;
}

Account::~Account() {}

// Bank function definitions
void Bank::add_account(Account* acc) {
    accounts.push_back(acc);
}

void Bank::remove_account(int account_number) {
    auto it = find_if(accounts.begin(), accounts.end(), [&](Account* acc) {
        return acc->get_account_number() == account_number; 
    });

    if (it != accounts.end()) {
        delete *it;
        *it = nullptr;  // Set to nullptr after deletion
        accounts.erase(it); // Erase the deleted account
    } else {
        cout << "Account Not Found!" << endl;
    }
}

Account* Bank::find_account(int account_number) {
    auto it = find_if(accounts.begin(), accounts.end(), [&](Account* acc) {
        return acc->get_account_number() == account_number;
    });

    if (it != accounts.end()) {
        return *it;
    } else {
        cout << "Account Not Found!" << endl;
        return nullptr;
    }
}

void Bank::display_all_accounts() const {
    for (const auto& acc : accounts) {
        acc->display_account_details();
        cout << "----------------------------------" << endl;
    }
}

Bank::~Bank() {
    for (auto acc : accounts) {
        delete acc;
    }
    accounts.clear();
}

int main() {
    Bank bank;

    Account* account1 = new Account(101, "Subhan Khan", 1000.0);

    bank.add_account(account1);
    bank.display_all_accounts();

    account1->deposit(500.0);

    bank.display_all_accounts();

    account1->withdraw(1000.0);

    bank.display_all_accounts();

    bank.remove_account(101);

    bank.display_all_accounts();

    return 0;
}
