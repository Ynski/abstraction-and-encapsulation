//Program by Ayen Brinas
#include <iostream>
using namespace std;


class Account {
private:
   double balance;


public:
   Account(double initialBalance) : balance(initialBalance) {}


   void deposit(double amount) {
       balance += amount;
       cout << "Deposited: " << amount<< endl;
   }


   virtual void withdraw(double amount) { 
       if (amount <= balance) {
           balance -= amount;
           cout << "Withdrawn: " << amount<< endl;
       } else {
           cout << "Insufficient balance." << endl;
       }
   }


   void checkBalance() const {
       cout << "Balance: " << balance << endl;
   }


   double getBalance() const {
       return balance;
   }


   void setBalance(double newBalance) {
       balance = newBalance;
   }
};


class SavingsAccount : public Account {
public:
   SavingsAccount(double initialBalance) : Account(initialBalance) {}


   void withdraw(double amount) { 
       if (getBalance() - amount >= 1000) {
           Account::withdraw(amount);
       } else {
           cout << "Withdrawal Error! Minimum balance is 1000." << endl;
       }
   }
};


int main() {
   int accountType;
   double initialBalance;


cout<<endl;
cout<<"Welcome to Ynski Banking App"<<endl;
   cout << "1: Savings Account\n2: Current Account"<<endl;
   cout<<"Input here: ";
   cin >> accountType;
   cout<<endl;


   cout << "Enter Initial Balance: ";
   cin >> initialBalance;


   Account* account;


   if (accountType == 1) {
       account = new SavingsAccount(initialBalance);
   } else {
       account = new Account(initialBalance);
   }


   int action;
   double amount;


   do {
       cout << "\n1: Deposit\n2: Withdraw\n3: Check Balance\n4: Exit\n";
       cout<<"Input here: ";
       cin >> action;


       if (action == 1) {
           cout << "Enter deposit amount: ";
           cin >> amount;
           account->deposit(amount);
       } else if (action == 2) {
           cout << "Enter withdraw amount: ";
           cin >> amount;
           account->withdraw(amount);
       } else if (action == 3) {
           account->checkBalance();
       }
   } while (action != 4);


   delete account;
   return 0;
}
