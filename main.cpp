#include <iostream>
#include "BankAccount.h"
#include <vector>
#include <limits>

using namespace std;

int main() {
    vector<BankAccount> accounts;
    int choice;

    do {
        cout << "Menu" << endl;
        cout << "1. Create account" << endl;
        cout << "2. Deposit Funds" << endl;
        cout << "3. Withdraw Funds" << endl;
        cout << "4. Display All Accounts" << endl;
        cout << "5. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        while (cin.fail() || choice <1 || choice > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout <<"Invalid input. Try again: ";
            cin >> choice;
        }
        if (choice == 1) {
            BankAccount newAcc = BankAccount ::createAccountFromInput();
            accounts.push_back(newAcc);
            cout << "Account created" << endl;
        } else if (choice == 2) {
            string searchNum;
            double amount;
            bool found = false;

            cout << "Enter Account Number to deposit into: ";
            cin >> searchNum;

            BankAccount dummy(searchNum, "",0);

            for (auto& acc : accounts) {
                if (acc == dummy) {
                    found = true;
                    cout << "Enter deposist amount: ";
                    cin >> amount;
                    while (cin.fail() || amount <= 0) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Try again: ";
                        cin >> amount;
                    }
                    acc += amount;
                    break;
                }
            }
            if (!found) cout << "Account not found" << endl;
        }else if (choice == 3) {
            string searchNum;
            double amount;
            bool found = false;

            cout << "Enter Account Number to withdraw from: ";
            cin >> searchNum;

            BankAccount dummy(searchNum, "",0);

            for (auto& acc : accounts){
                if (acc == dummy) {
                    found = true;
                    cout << "Enter withdraw amount: ";
                    cin >> amount;
                    while (cin.fail() || amount <= 0) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Try again: ";
                        cin >> amount;
                    }
                    acc -= amount;
                    break;
                }
            }
            if (!found) cout << "Account not found" << endl;
        } else if (choice == 4) {
            if (accounts.empty()) {
                cout << "No accounts to display." << endl;
            } else {
                for (const auto& acc : accounts) {
                    BankAccount::printAccount(acc);

                }
            }
        } else if (choice == 5) {
            cout << "Exiting..." << endl;
        }
    } while (choice != 5);

    return 0;
}