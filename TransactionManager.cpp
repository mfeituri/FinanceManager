#include "TransactionManager.hpp"
#include <fstream>

void TransactionManager::addTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
}

void TransactionManager::listTransactions() const {
    for (const auto& transaction : transactions) {
        transaction.print();
    }
}

double TransactionManager::calculateBalance() const {
    double balance = 0.0;
    for (const auto& transaction : transactions) {
        balance += transaction.getAmount();
    }
    return balance;
}

void TransactionManager::saveTransactions(const std::string& filename) const {
    std::ofstream file(filename);
    for (const auto& transaction : transactions) {
        file << transaction.getDate() << ","
             << transaction.getAmount() << ","
             << transaction.getDescription() << ","
             << transaction.getCategory() << std::endl;
    }
    file.close();
}

void TransactionManager::loadTransactions(const std::string& filename) {
    std::ifstream file(filename);
    std::string date, description, category, amountStr;
    double amount;
    while (file.good()) {
        getline(file, date, ',');
        getline(file, amountStr, ',');
        amount = std::stod(amountStr);
        getline(file, description, ',');
        getline(file, category);
        if (!date.empty()) {
            transactions.emplace_back(date, amount, description, category);
        }
    }
    file.close();
}
