#include "Transaction.hpp"
#include <iostream>

Transaction::Transaction(std::string date, double amount, std::string description, std::string category)
    : date(date), amount(amount), description(description), category(category) {}

std::string Transaction::getDate() const { return date; }
double Transaction::getAmount() const { return amount; }
std::string Transaction::getDescription() const { return description; }
std::string Transaction::getCategory() const { return category; }

void Transaction::print() const {
    std::cout << "Date: " << date << ", Amount: $" << amount
              << ", Description: " << description << ", Category: " << category << std::endl;
}
