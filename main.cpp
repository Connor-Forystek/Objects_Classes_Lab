//Connor Forystek
//September 15, 2025
// Purpose: Create a Bank Account system to simulate basic banking operations
//Assignment: Lab Activities: Objects and Classes 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

//This section holds everything that is associated with the BankAccount class
class BankAccount {
    private:
        string accountNumber;
        string accountHolderName;
        double balance;
    public:
    BankAccount(string accountNumber, string accountHolderName, double balance) {}
    BankAccount();
    string name;
    string number;

    //This section allows the user to get the account number
    string getAccountNumber() const {
        return number;
    }
    //This section allows the user to get the account holder name
    string getAccountHolderName() const {
        return name;
    }
    //This section allows the user to get the balance
    double getBalance() const {
        return balance;
    }
    //This section allows the user to change the current holder name for the account
    void setAccountHolderName(string accountHolderName) {
        name = accountHolderName;
    }
    //This section allows the user to change the current account number
    void setAccountNumber(string accountNumber) {
        number = accountNumber;
    }
    //This section allows the user to deposit a certain amount into the account
    void deposit(double amount) {
        balance += amount;
    }
    //This section allows the user to withdraw a certain amount into the account
    void withdraw(double amount) {
        balance -= amount;
    }



};
//This section is the default constructor for the BankAccount class and holds the default value for the private variables
BankAccount::BankAccount() {
    balance = 0;
    number = "Unknown";
    name = "Unknown";
}

//This section displays the menu and makes sure that only digits are inputted
int displayMenu() {
    cout << "Option 1: Change Account Holder Name" << endl;
    cout << "Option 2: Deposit Amount" << endl;
    cout << "Option 3: Withdraw Amount" << endl;
    cout << "Option 4: Display Balance" << endl;
    cout << "Option 5: Display Account Number" << endl;
    cout << "Option 6: Display Account Holder Name" << endl;
    cout << "Option 7: Change Account Number" << endl;
    cout << "Option 8: Quit" << endl;

    int choice;
    cin >> choice;
    while (choice == 0) {
        cout << "That is an invalid input. Clearing your input" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout <<"Invalid choice" << endl;
        cout <<"Enter another choice between 1 and 8" << endl;
        cout << "Option 1: Change Account Holder Name" << endl;
        cout << "Option 2: Deposit Amount" << endl;
        cout << "Option 3: Withdraw Amount" << endl;
        cout << "Option 4: Display Balance" << endl;
        cout << "Option 5: Display Account Number" << endl;
        cout << "Option 6: Display Account Holder Name" << endl;
        cout << "Option 7: Change Account Number" << endl;
        cout << "Option 8: Quit" << endl;
        cin >> choice;
    }
    return choice;
}
int main() {
    //This section is where the vector account is initialized
    vector<BankAccount> account;
    BankAccount currentAccount;
    int input;
    string currentAccountNumber;
    double balanceChange = 0;
    string currentAccountHolderName;
    bool hasData = false;
    //This section is the loop that activates and runs the menu
    do {
        input = displayMenu();
        switch (input) {
            //This case calls the section in the BankAccount class to change the account holder name
            case 1:
                cout << "Please enter new Account Holder Name" << endl;
                cin >> currentAccountHolderName;
                currentAccount.setAccountHolderName(currentAccountHolderName);
                account.push_back(currentAccount);
                cout << "Account Holder Name Changed" << endl;
                break;
            //This case calls the section in the BankAccount class to deposit an amount of money into the bank account and states that there is a balance
            case 2:
                cout << "How much money are you depositing today?" << endl;
                cin >> balanceChange;
                currentAccount.deposit(balanceChange);
                cout << "You have deposited $" << balanceChange << endl;
                hasData = true;
                break;
            //This section makes asks to make sure that there is a balance first then allows the user to withdraw if it is less than or equal to the current balance
            case 3:
                if (hasData == false) {
                    std::cout << "Please Enter A Balance First" << std::endl;
                    break;
                }
                cout << "How much money are you withdrawing today?" << endl;
                cin >> balanceChange;
                if (balanceChange > currentAccount.getBalance()) {
                    cout << "You are trying to withdraw an amount of money that you do not own. Please try again." << endl;
                    break;
                }
                currentAccount.withdraw(balanceChange);
                cout << "You have withdrawn $" << balanceChange << endl;
                break;
            //This section allows the user to check what the account's balance is
            case 4:
                cout << "Your account's balance is: " << currentAccount.getBalance() << endl;
                break;
            //This section allows the user to check what the account number is
            case 5:
                cout << "Your account's number is: " << currentAccount.getAccountNumber() << endl;
                break;
            //This section allows the user to check what the account's holder name is
            case 6:
                cout << "Your account's holder name is: " << currentAccount.getAccountHolderName() << endl;
                break;
            //This section allows the user to input a new account number and change it
            case 7:
                cout << "Please enter new Account Number" << endl;
                cin >> currentAccountNumber;
                currentAccount.setAccountNumber(currentAccountNumber);
                account.push_back(currentAccount);
                cout << "Account Number Changed" << endl;
                break;
            case 8:
                //This section exits the code when 8 is received
                cout << "Exiting The Banking Program." << endl;
                cout << "Goodbye!" << endl;
                break;
            default:
                //This section makes sure that the input is between 1-8
                cout << "That is an invalid choice. Please choose 1-8" << endl;
                break;
        }

    }while (input != 8); //This section ends the do / while loop when 8 is inputted

    return 0;
}