#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_

#include "account.h"
#include "checking_account.h"
#include "savings_account.h"
#include "trust_account.h"
#include <vector>

// TODO: use generics (polymorphism?) to make these functions shorter
void display(const std::vector<Account> &accounts);
void display(const std::vector<SavingsAccount> &accounts);
void display(const std::vector<CheckingAccount> &accounts);
void display(const std::vector<TrustAccount> &accounts);
void deposit(std::vector<Account> &accounts, double amount);
void deposit(std::vector<SavingsAccount> &accounts, double amount);
void deposit(std::vector<CheckingAccount> &accounts, double amount);
void deposit(std::vector<TrustAccount> &accounts, double amount);
void withdraw(std::vector<Account> &accounts, double amount);
void withdraw(std::vector<SavingsAccount> &accounts, double amount);
void withdraw(std::vector<CheckingAccount> &accounts, double amount);
void withdraw(std::vector<TrustAccount> &accounts, double amount);

#endif
