#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For formatting output

// Structure to represent a bank account
struct BankAccount {
    int accountNumber;
    std::string accountHolderName;
    double balance;

    // Constructor to initialize an account
    BankAccount(int accNum, std::string name, double initialBalance)
        : accountNumber(accNum), accountHolderName(name), balance(initialBalance) {}

    // Function to display account details
    void displayAccount() const {
        std::cout << std::fixed << std::setprecision(2); // Set precision for balance
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Holder: " << accountHolderName << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
        std::cout << "--------------------------------------" << std::endl;
    }
};

// Global vector to store all bank accounts
std::vector<BankAccount> accounts;
int nextAccountNumber = 1001; // Starting account number

// Function prototypes
void createAccount();
void deposit();
void withdraw();
void displayAccountDetails();
void searchAccount();
void displayAllAccounts();
void showMenu();

int main() {
    int choice;

    do {
        showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                displayAccountDetails();
                break;
            case 5:
                searchAccount();
                break;
            case 6:
                displayAllAccounts();
                break;
            case 7:
                std::cout << "Exiting Bank Management System. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
        std::cout << std::endl; // Add a new line for better readability
    } while (choice != 7);

    return 0;
}

void showMenu() {
    std::cout << "\n========== Bank Management System ==========" << std::endl;
    std::cout << "1. Create New Account" << std::endl;
    std::cout << "2. Deposit Money" << std::endl;
    std::cout << "3. Withdraw Money" << std::endl;
    std::cout << "4. Display Account Details" << std::endl;
    std::cout << "5. Search Account by Number" << std::endl;
    std::cout << "6. Display All Accounts" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "============================================" << std::endl;
}

void createAccount() {
    std::string name;
    double initialBalance;

    std::cin.ignore(); // Consume the newline character left by previous std::cin
    std::cout << "Enter Account Holder Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Initial Balance: $";
    std::cin >> initialBalance;

    if (initialBalance < 0) {
        std::cout << "Initial balance cannot be negative. Account not created." << std::endl;
        return;
    }

    accounts.emplace_back(nextAccountNumber, name, initialBalance);
    std::cout << "Account created successfully!" << std::endl;
    std::cout << "Your Account Number is: " << nextAccountNumber << std::endl;
    nextAccountNumber++;
}

void deposit() {
    int accNum;
    double amount;

    std::cout << "Enter Account Number: ";
    std::cin >> accNum;

    // Find the account
    bool found = false;
    for (auto& account : accounts) {
        if (account.accountNumber == accNum) {
            std::cout << "Enter amount to deposit: $";
            std::cin >> amount;
            if (amount > 0) {
                account.balance += amount;
                std::cout << "Deposit successful! New balance: $" << account.balance << std::endl;
            } else {
                std::cout << "Deposit amount must be positive." << std::endl;
            }
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Account not found with number: " << accNum << std::endl;
    }
}

void withdraw() {
    int accNum;
    double amount;

    std::cout << "Enter Account Number: ";
    std::cin >> accNum;

    // Find the account
    bool found = false;
    for (auto& account : accounts) {
        if (account.accountNumber == accNum) {
            std::cout << "Enter amount to withdraw: $";
            std::cin >> amount;
            if (amount > 0) {
                if (account.balance >= amount) {
                    account.balance -= amount;
                    std::cout << "Withdrawal successful! New balance: $" << account.balance << std::endl;
                } else {
                    std::cout << "Insufficient balance." << std::endl;
                }
            } else {
                std::cout << "Withdrawal amount must be positive." << std::endl;
            }
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Account not found with number: " << accNum << std::endl;
    }
}

void displayAccountDetails() {
    int accNum;
    std::cout << "Enter Account Number: ";
    std::cin >> accNum;

    bool found = false;
    for (const auto& account : accounts) {
        if (account.accountNumber == accNum) {
            account.displayAccount();
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Account not found with number: " << accNum << std::endl;
    }
}

void searchAccount() {
    int accNum;
    std::cout << "Enter Account Number to search: ";
    std::cin >> accNum;

    bool found = false;
    for (const auto& account : accounts) {
        if (account.accountNumber == accNum) {
            std::cout << "Account found!" << std::endl;
            account.displayAccount();
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Account not found with number: " << accNum << std::endl;
    }
}

void displayAllAccounts() {
    if (accounts.empty()) {
        std::cout << "No accounts to display." << std::endl;
        return;
    }
    std::cout << "\n========== All Bank Accounts ==========" << std::endl;
    for (const auto& account : accounts) {
        account.displayAccount();
    }
    std::cout << "=======================================" << std::endl;
}