# BankAccount Class

A C++ class for a banking system

## Data Dictionary

| Attribute           | Data Type     | Description                                       |
|---------------------|---------------|---------------------------------------------------|
| `accountNumber`     | `std::string` | a unique identifier for the person's bank account |
| `accountHolderName` | `std::string` | The full name of the person's account             |
| `balance`           | `double`      | the current balance                               |

## Methods List

| Method Signature                                                        | Return Type   | Description                                       |
|-------------------------------------------------------------------------|---------------|---------------------------------------------------|
| `BankAccount()`                                                         | (Constructor)  | Default constructor.                             |
| `BankAccount(std::string accNum, std::string accName, double startBal)` | (Constructor)  | Parameterized constructor.                       |
| `BankAccount(const BankAccount& other)`                                 | (Constructor)  | Copy constructor                                 |
| `operator=(const BankAccount& other)                                    | `BankAccount&' | Copy assignment operator                         |
| `~BankAccount()`                                                        | (Destructor)   | Destructor                                       |
| `getAccountNumber() const`                                              | `std::string`  | Gets the account number.                         |
| `getAccountHolderName() const`                                          | `std::string`  | Gets the account holder name.                    |
| `getBalance() const`                                                    | `double`       | Gets the current balance.                        |
| `setAccountHolderName(std::string newName)`                             | `void`         | Updates the account holder name.                 |
| `operator+=(double amount)`                                             | `BankAccount&` | Adds funds.                                      |
| `operator-=(double amount)`                                             | `BankAccount&` | Subtracts funds.                                 |
| `operator==(const BankAccount& other) const`                            | `bool`         | Compares accounts by account number.             |
| `operator<(const BankAccount& other) const`                             | `bool`         | Checks if this balance is less than another.     |
| `operator>(const BankAccount& other) const`                             | `bool`         | Checks if this balance is greater than another.  |
| `static printAccount(const BankAccount& account)`                       | `void`         | Static utility to print account details.         |
| `static createAccountFromInput()`                                       | `BankAccount`  | Static utility to prompt user & create account.  |
