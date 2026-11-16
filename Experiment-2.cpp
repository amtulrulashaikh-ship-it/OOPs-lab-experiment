#include <iostream>
#include <string>
using namespace std;
class BankAccount
{
protected:
    string holderName;
    long accountNumber;
    float balance;
public:
    void getDetails()
    {
        cout << "Enter Account Holder Name: ";
        cin >> holderName;

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Bank Balance: ";
        cin >> balance;
    }
    void displayDetails()
    {
        cout << "\n--- Account Details ---" << endl;
        cout << "Account Holder: " << holderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Bank Balance: " << balance << endl;
    }
};
class SavingsAccount : public BankAccount
{
private:
    float depositAmount;
public:
    void deposit()
    {
        cout << "Enter Deposit Amount: ";
        cin >> depositAmount;
        balance = balance + depositAmount;
    }
    void displayBalance()
    {
        cout << "Bank Balance After Deposit: "
             << balance << endl;
    }
};
int main()
{
    SavingsAccount account;
    account.getDetails();
    account.displayDetails();
    account.deposit();
    account.displayBalance();
    return 0;
}
