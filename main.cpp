#include "TransactionManager.hpp"
#include <iostream>
#include <limits>

using namespace std; 

void displayMenu() {
    cout << "\n=== Finance Manager Menu ===\n";
    cout << "1. Add Transaction\n";
    cout << "2. List Transactions\n";
    cout << "3. Show Balance\n";
    cout << "4. Save Transactions\n";
    cout << "5. Load Transactions\n";
    cout << "6. Exit\n";
    cout << "Select an option: ";
}

int main() {
    TransactionManager manager;
    const string filename = "transactions.txt";
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 6) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        if (choice == 6) break;

        switch (choice) {
            case 1: {
                string date, description, category;
                double amount;
                cout << "Enter date (YYYY-MM-DD): ";
                cin >> date;
                cout << "Enter amount: ";
                cin >> amount;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard newline
                cout << "Enter description: ";
                getline(cin, description);
                cout << "Enter category: ";
                getline(cin, category);
                manager.addTransaction(Transaction(date, amount, description, category));
                break;
            }
            case 2:
                manager.listTransactions();
                break;
            case 3:
                cout << "Current Balance: $" << manager.calculateBalance() << endl;
                break;
            case 4:
                manager.saveTransactions(filename);
                cout << "Transactions saved to file.\n";
                break;
            case 5:
                manager.loadTransactions(filename);
                cout << "Transactions loaded from file.\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
