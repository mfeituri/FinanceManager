#ifndef TRANSACTIONMANAGER_HPP
#define TRANSACTIONMANAGER_HPP

#include "Transaction.hpp"
#include <vector>

// Manages a collection of transactions
class TransactionManager {
private:
    std::vector<Transaction> transactions;

public:
    void addTransaction(const Transaction& transaction);
    void listTransactions() const;
    double calculateBalance() const;
    void saveTransactions(const std::string& filename) const;
    void loadTransactions(const std::string& filename);
};

#endif 
