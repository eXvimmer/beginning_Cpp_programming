#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_

#include "account.h"
#include "savings_account.h"
#include <vector>

void display(const std::vector<Account> &accounts);
void display(const std::vector<SavingsAccount> &accounts);
void deposit(std::vector<Account> &accounts, double amount);
void deposit(std::vector<SavingsAccount> &accounts, double amount);
void withdraw(std::vector<Account> &accounts, double amount);
void withdraw(std::vector<SavingsAccount> &accounts, double amount);

#endif
