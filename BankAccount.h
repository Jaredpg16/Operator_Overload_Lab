//
// Created by Jared Peralta on 2/26/26.
//

#ifndef OPERATOR_OVERLOAD_LAB_BANKACCOUNT_H
#define OPERATOR_OVERLOAD_LAB_BANKACCOUNT_H
#include <iostream>
#include <string>



class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    BankAccount();
    BankAccount(std::string accNum, std::string accName, double startBal);

    BankAccount(const BankAccount &other);
    BankAccount &operator=(const BankAccount &other);
    ~BankAccount();

    std::string getAccountNumber() const;
    std::string getAccountHolderName() const;
    double getBalance() const;
    void setAccountHolderName(std::string newName);
    BankAccount& operator+=(double amount);
    BankAccount& operator-=(double amount);

    bool operator ==(const BankAccount &other) const;
    bool operator <(const BankAccount &other) const;
    bool operator >(const BankAccount &other) const;

    static void printAccount(const BankAccount& account);

    static BankAccount createAccountFromInput();
};


#endif //OPERATOR_OVERLOAD_LAB_BANKACCOUNT_H