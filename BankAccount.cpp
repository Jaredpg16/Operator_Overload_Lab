//
// Created by Jared Peralta on 2/26/26.
//
#include "BankAccount.h"
#include <iostream>
#include <limits>

using namespace std;

BankAccount::BankAccount() : accountNumber("0000"), accountHolderName("Unknown"), balance(0.0){}
BankAccount::BankAccount(string accNum, string accName, double startBal)
    :accountNumber(accNum), accountHolderName(accName),balance(startBal){}

BankAccount::BankAccount(const BankAccount& other) {
    accountNumber = other.accountNumber;
    accountHolderName = other.accountHolderName;
    balance = other.balance;

}

BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this != &other) {
        accountNumber = other.accountNumber;
        accountHolderName = other.accountHolderName;
        balance = other.balance;

    }
    return *this;
}
BankAccount::~BankAccount(){}

string BankAccount::getAccountNumber() const {return accountNumber;}
string BankAccount::getAccountHolderName() const {return accountHolderName;}
double BankAccount::getBalance() const {return balance;}
void BankAccount::setAccountHolderName(string newName) {accountHolderName = newName;}

BankAccount& BankAccount::operator+=(double amount) {
    if (amount > 0) {
        balance += amount;
        cout<< "Deposit successful. New Balance: $" << balance << endl;
    }else {
        cout << "Invalid deposit amount." << endl;
    }
    return *this;
}
BankAccount& BankAccount::operator-=(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout<< "Withdraw successful. New Balance: $" << balance << endl;
    }else if (amount > balance) {
        cout << "Insufficient funds. Current balance is $" << balance << endl;
    }else {
        cout << "Invalid deposit amount." << endl;
    }
    return *this;
}
bool BankAccount::operator==(const BankAccount& other) const {
    return accountNumber == other.accountNumber;
}
bool BankAccount::operator<(const BankAccount& other) const {
    return balance < other.balance;
}
bool BankAccount::operator>(const BankAccount& other)const {
    return balance > other.balance;
}

void BankAccount::printAccount(const BankAccount& account) {
    cout<< "\nAccount number: " << account.getAccountNumber() << endl;
    cout << "Name: " << account.getAccountHolderName() << endl;
    cout << "Balance: $" << account.getBalance() << endl;
}
BankAccount BankAccount::createAccountFromInput() {
    string num, name;
    double bal;

    cout << "Enter account number: ";
    cin >> num;
    cout << "Enter account holder name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    cout << "Enter Starting Balance: ";
    cin >> bal;
    while (cin.fail() || bal < 0 ) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Try again: ";
        cin >> bal;
    }
    return BankAccount(num, name, bal);
}

