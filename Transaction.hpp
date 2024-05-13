#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <string>

// Transaction class to handle individual financial records
class Transaction {
private:
    std::string date;
    double amount;
    std::string description;
    std::string category;

public:
    Transaction(std::string date, double amount, std::string description, std::string category);
    
    std::string getDate() const;
    double getAmount() const;
    std::string getDescription() const;
    std::string getCategory() const;

    void print() const;
};

#endif // TRANSACTION_HPP
