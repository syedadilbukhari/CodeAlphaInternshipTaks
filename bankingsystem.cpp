//#include <iostream>
//#include <string>
//
//using namespace std;
//
//const int MAX_CUSTOMERS = 100;
//const int MAX_ACCOUNTS = 100;
//const int MAX_TRANSACTIONS = 100;
//
//class Customer {
//public:
//    Customer() : Name(""), id("") {}
//    Customer(const string& name, const string& id) : Name(name), id(id) {}
//
//    string getName() const { return Name; }
//    string getId() const { return id; }
//
//private:
//    string Name;
//    string id;
//};
//
//class Transaction {
//public:
//    Transaction() : type(""), Amount(0.0) {}
//    Transaction(const string& type, double amount) : type(type), Amount(amount) {}
//
//    void display() const {
//        cout << "Transaction Type: " << type << ", Amount: " << Amount << endl;
//    }
//
//private:
//    string type;
//    double Amount;
//};
//
//class Account {
//public:
//    Account() : accountNumber(""), balance(0.0), transactionCount(0) {}
//    Account(const string& accountNumber, double balance = 0.0)
//        : accountNumber(accountNumber), balance(balance), transactionCount(0) {}
//
//    string getAccountNumber() const { return accountNumber; }
//    double getBalance() const { return balance; }
//
//    void deposit(double amount);
//    bool withdraw(double amount);
//    void addTransaction(const Transaction& transaction);
//    void displayTransactions() const;
//
//private:
//    string accountNumber;
//    double balance;
//    Transaction transactions[MAX_TRANSACTIONS];
//    int transactionCount;
//};
//
//void Account::deposit(double amount) {
//    balance += amount;
//    cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
//}
//
//bool Account::withdraw(double amount) {
//    if (balance >= amount) {
//        balance -= amount;
//        cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
//        return true;
//    }
//    else {
//        cout << "Insufficient balance!" << endl;
//        return false;
//    }
//}
//
//void Account::addTransaction(const Transaction& transaction) {
//    if (transactionCount < MAX_TRANSACTIONS) {
//        transactions[transactionCount++] = transaction;
//    }
//    else {
//        cout << "Transaction limit reached!" << endl;
//    }
//}
//
//void Account::displayTransactions() const {
//    for (int i = 0; i < transactionCount; ++i) {
//        transactions[i].display();
//    }
//}
//
//class Bank {
//public:
//    Bank() : customerCount(0), accountCount(0) {}
//
//    void addCustomer(const string& name, const string& id);
//    void createAccount(const string& customerId, const string& accountNumber);
//    void deposit(const string& accountNumber, double amount);
//    void withdraw(const string& accountNumber, double amount);
//    void transfer(const string& fromAccount, const string& toAccount, double amount);
//    void viewAccountDetails(const string& accountNumber) const;
//
//private:
//    Customer customers[MAX_CUSTOMERS];
//    Account accounts[MAX_ACCOUNTS];
//    int customerCount;
//    int accountCount;
//
//    int findCustomerIndex(const string& customerId) const;
//    int findAccountIndex(const string& accountNumber) const;
//};
//
//void Bank::addCustomer(const string& name, const string& id) {
//    if (customerCount < MAX_CUSTOMERS) {
//        customers[customerCount++] = Customer(name, id);
//        cout << "Customer added: " << name << endl;
//    }
//    else {
//        cout << "Customer limit reached!" << endl;
//    }
//}
//
//void Bank::createAccount(const string& customerId, const string& accountNumber) {
//    if (findCustomerIndex(customerId) != -1) {
//        if (accountCount < MAX_ACCOUNTS) {
//            accounts[accountCount++] = Account(accountNumber);
//            cout << "Account created: " << accountNumber << endl;
//        }
//        else {
//            cout << "Account limit reached!" << endl;
//        }
//    }
//    else {
//        cout << "Customer ID not found!" << endl;
//    }
//}
//
//void Bank::deposit(const string& accountNumber, double amount) {
//    int index = findAccountIndex(accountNumber);
//    if (index != -1) {
//        accounts[index].deposit(amount);
//        accounts[index].addTransaction(Transaction("Deposit", amount));
//    }
//    else {
//        cout << "Account number not found!" << endl;
//    }
//}
//
//void Bank::withdraw(const string& accountNumber, double amount) {
//    int index = findAccountIndex(accountNumber);
//    if (index != -1) {
//        if (accounts[index].withdraw(amount)) {
//            accounts[index].addTransaction(Transaction("Withdrawal", amount));
//        }
//    }
//    else {
//        cout << "Account number not found!" << endl;
//    }
//}
//
//void Bank::transfer(const string& fromAccount, const string& toAccount, double amount) {
//    int fromIndex = findAccountIndex(fromAccount);
//    int toIndex = findAccountIndex(toAccount);
//    if (fromIndex != -1 && toIndex != -1) {
//        if (accounts[fromIndex].withdraw(amount)) {
//            accounts[toIndex].deposit(amount);
//            accounts[fromIndex].addTransaction(Transaction("Transfer Out", amount));
//            accounts[toIndex].addTransaction(Transaction("Transfer In", amount));
//            cout << "Transferred " << amount << " from " << fromAccount << " to " << toAccount << endl;
//        }
//    }
//    else {
//        cout << "One or both account numbers not found!" << endl;
//    }
//}
//
//void Bank::viewAccountDetails(const string& accountNumber) const {
//    int index = findAccountIndex(accountNumber);
//    if (index != -1) {
//        const Account& account = accounts[index];
//        cout << "Account Number: " << account.getAccountNumber() << ", Balance: " << account.getBalance() << endl;
//        account.displayTransactions();
//    }
//    else {
//        cout << "Account number not found!" << endl;
//    }
//}
//
//int Bank::findCustomerIndex(const string& customerId) const {
//    for (int i = 0; i < customerCount; ++i) {
//        if (customers[i].getId() == customerId) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//int Bank::findAccountIndex(const string& accountNumber) const {
//    for (int i = 0; i < accountCount; ++i) {
//        if (accounts[i].getAccountNumber() == accountNumber) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//int main() {
//    Bank bank;
//    int choice;
//    string name, id, accountNumber, customerId, fromAccount, toAccount;
//    double amount;
//
//    do {
//        cout << "\nBank Menu:\n";
//        cout << "1. Add Customer\n";
//        cout << "2. Create Account\n";
//        cout << "3. Deposit\n";
//        cout << "4. Withdraw\n";
//        cout << "5. Transfer\n";
//        cout << "6. View Account Details\n";
//        cout << "0. Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "Enter customer name: ";
//            cin >> name;
//            cout << "Enter customer ID: ";
//            cin >> id;
//            bank.addCustomer(name, id);
//            break;
//        case 2:
//            cout << "Enter customer ID: ";
//            cin >> customerId;
//            cout << "Enter account number: ";
//            cin >> accountNumber;
//            bank.createAccount(customerId, accountNumber);
//            break;
//        case 3:
//            cout << "Enter account number: ";
//            cin >> accountNumber;
//            cout << "Enter amount to deposit: ";
//            cin >> amount;
//            bank.deposit(accountNumber, amount);
//            break;
//        case 4:
//            cout << "Enter account number: ";
//            cin >> accountNumber;
//            cout << "Enter amount to withdraw: ";
//            cin >> amount;
//            bank.withdraw(accountNumber, amount);
//            break;
//        case 5:
//            cout << "Enter from account number: ";
//            cin >> fromAccount;
//            cout << "Enter to account number: ";
//            cin >> toAccount;
//            cout << "Enter amount to transfer: ";
//            cin >> amount;
//            bank.transfer(fromAccount, toAccount, amount);
//            break;
//        case 6:
//            cout << "Enter account number: ";
//            cin >> accountNumber;
//            bank.viewAccountDetails(accountNumber);
//            break;
//        case 0:
//            cout << "Exiting...\n";
//            break;
//        default:
//            cout << "Invalid choice! try again.\n";
//        }
//    } while (choice != 0);
//
//    return 0;
//}
