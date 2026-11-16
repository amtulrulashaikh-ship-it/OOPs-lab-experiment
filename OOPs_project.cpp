#include <iostream>
#include <vector>
using namespace std;
// ================= EXPENSE CLASS =================
class Expense
{
private:
    string category;
    string description;
    string date;
    double amount;
public:
    // Constructor
    Expense(string c, string d, string dt, double a)
    {
        category = c;
        description = d;
        date = dt;
        amount = a;
    }
    // Display expense
    void display(int no)
    {
        cout << no << ". "
             << category << " | "
             << description << " | "
             << date << " | Rs."
             << amount << endl;
    }
    string getCategory()
    {
        return category;
    }
    double getAmount()
    {
        return amount;
    }
};
// ================= EXPENSE MANAGER =================
class ExpenseManager
{
private:
    vector<Expense> expenses;
    double budget;
public:
    ExpenseManager()
    {
        budget = 0;
    }
    // Set budget
    void setBudget()
    {
        cout << "Enter budget: Rs.";
        cin >> budget;
        cout << "Budget set successfully!\n";
    }
    // Add expense
    void addExpense()
    {
        string category, description, date;
        double amount;
        cout << "Enter category: ";
        cin >> category;
        cout << "Enter description: ";
        cin >> description;
        cout << "Enter date: ";
        cin >> date;
        cout << "Enter amount: Rs.";
        cin >> amount;
        if (amount <= 0)
        {
            cout << "Invalid amount!\n";
            return;
        }
        expenses.push_back(
            Expense(category, description, date, amount)
        );
        cout << "Expense added successfully!\n";
    }
    // Show expenses
    void showExpenses()
    {
        if (expenses.empty())
        {
            cout << "No expenses found.\n";
            return;
        }
        cout << "\n----- EXPENSES -----\n";
        for (int i = 0; i < expenses.size(); i++)        {
            expenses[i].display(i + 1);
        }
    }
    // Calculate total
    double totalExpense()
    {
        double total = 0;
        for (Expense e : expenses)
            total += e.getAmount();
        return total;
    }
    // Search category
    void searchCategory()
    {
        string category;
        bool found = false;
        cout << "Enter category: ";
        cin >> category;
        for (int i = 0; i < expenses.size(); i++)
        {
            if (expenses[i].getCategory() == category)
            {
                expenses[i].display(i + 1);
                found = true;
            }
        }
        if (!found)
            cout << "No expense found.\n";
    }
    // Delete expense
    void deleteExpense()
    {
        int no;
        showExpenses();
        if (expenses.empty())
            return;
        cout << "Enter expense number: ";
        cin >> no;
        if (no < 1 || no > expenses.size())
        {
            cout << "Invalid number!\n";
            return;
        }
        expenses.erase(expenses.begin() + no - 1);
       cout << "Expense deleted successfully!\n";
    }
    // Show budget
    void showBudget()
    {
        double total = totalExpense();
       cout << "\nBudget: Rs." << budget << endl;
        cout << "Total Expense: Rs." << total << endl;
        cout << "Remaining: Rs." << budget - total << endl;
        if (total > budget)
            cout << "Warning: Budget exceeded!\n";
    }
};
// ================= MAIN =================
int main()
{
    ExpenseManager manager;
    int choice;
    do
    {
        cout << "\n============================\n";
        cout << "   EXPENSE MANAGEMENT SYSTEM\n";
        cout << "============================\n";
        cout << "1. Set Budget\n";
        cout << "2. Add Expense\n";
        cout << "3. Show Expenses\n";
        cout << "4. Search Category\n";
        cout << "5. Delete Expense\n";
        cout << "6. Show Total\n";
        cout << "7. Show Budget\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            manager.setBudget();
            break;
        case 2:
            manager.addExpense();
            break;
        case 3:
            manager.showExpenses();
            break;
        case 4:
            manager.searchCategory();
            break;
        case 5:
            manager.deleteExpense();
            break;
        case 6:
            cout << "Total Expense: Rs."
                 << manager.totalExpense() << endl;
            break;
        case 7:
            manager.showBudget();
            break;
        case 8:
            cout << "Thank you!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 8);
    return 0;
}
