#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_

#include "account.h"
#include <vector>

void display(const std::vector<Account *> &accounts);
void deposit(std::vector<Account *> &accounts, double amount);
void withdraw(std::vector<Account *> &accounts, double amount);

#endif // _ACCOUNT_UTIL_H_
