/**
 * File: main.cpp
 * Developer: Hytham Abdelkarim
 * Email: abdelkarimh@student.vvc.edu
 * Description : This program should print out a bank statement .
**/
#include <iostream>
#include <string>
#include <vector>

class Bank
{
   public:
      Bank();
      void print();
      void get_interest(int day);
      double add_balance(double a); 
      double average_daily(double average, int day); 
      
      double get_average();      
      void set_previous_day(int a); 
   private:
      double total_balance;
      double interest_rate;
      double total_interest;
      int previous_day;
      double the_average;
};

Bank::Bank()
{
   total_balance = 0.0;
   interest_rate= 1.005; 
}

void Bank::print() 
{
   std::cout << "Interest is: " << total_interest << std::endl;
   std::cout << "Current balance is: " << total_balance << std::endl;
   std::cout << "Average daily Balance is: " << the_average << std::endl;
}

void Bank::set_previous_day(int a) 
{
   previous_day = a;
}

void Bank::get_interest(int day) 
{
     
   
    
    int i = (day / 30) * 30;

    if( i > previous_day && i < day);
    total_balance *= interest_rate;
    
    total_interest = total_balance * (interest_rate - 1); 
}

double Bank::add_balance(double a) 
{
   total_balance = total_balance + a; 
}

double Bank::average_daily(double average, int day) 
{
   double total_average = 0.0;  
   
   int i = (day / 30) * 30;
  
   if( i > previous_day && i < day);
     total_average += average;
  
   the_average = total_average / 30.0;
  
}

double Bank::get_average()
{
   return the_average; 
}


class Transaction
{
   public:
      Transaction();
      void read();
      void print() const; 
      int get_day();
      double get_amount();
                
   private:
      int day;
      double amount;
      std::string description;
};

Transaction::Transaction()
{
   day = 0;
   amount = 0.0;
}

void Transaction::read()
{
   std::cout << " Enter day, amount, and description: " << std::endl;
   std::cin >> day;
   std::cin >> amount;
   std::cin.ignore();
   std::getline(std::cin, description);
}

void Transaction::print() const
{
   std::cout << "Day: " << day << std::endl;
   std::cout << "Amount: " << amount << std::endl;
   std::cout << "Description: " << description << std::endl;
}

int Transaction::get_day()
{
   return day;
}

double Transaction::get_amount()
{
   return amount;
}

void print_transactions(const std::vector<Transaction> t)
{
   for(int i = 0; i < t.size();i++)
      t[i].print();
}

int main()
{
   Bank b;
   
   std::vector<Transaction> transaction;
   bool more = true;
   while(more)
   {
      Transaction t;
      
      double temp_addtobal = 0.0;
      int day;
      
      t.read();
      
      temp_addtobal = t.get_amount();
      b.add_balance(temp_addtobal);
      
      day = t.get_day();
      b.get_interest(day); 
      
      b.average_daily(temp_addtobal, day);
      b.set_previous_day(t.get_day());
      transaction.push_back(t);
      b.print();
      std::cout << "Enter another Transaction? y or n" << std::endl;
      char response;
      std::cin >> response;      
      if(response != 'y' && response != 'Y')
         more = false;
      
    }

    print_transactions(transaction);
    b.print();

return 0;
}

