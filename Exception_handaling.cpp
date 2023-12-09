#include <iostream>
#include <string.h>
using namespace std;

class User
{
 int age;
 int vehicle;
 int income;
 char city[100];
 public:
  void get_age(int a)
  {
   age = a;
   try
   {
    if (age < 18 || age > 55)
    throw(age);
   }
   catch (int age)
   {
    cout << age << " is Invalid..!" << '\n';
   }
  }

  void get_income(int f)
  {
   income = f;
   try
   {
    if (income < 50000 || income > 100000)
    throw(income);
   }
   catch (int income)
   {
    cout << "..Invalid Income..!";
   }
  }

  void get_veh(int ch)
  {
   try
   {
    if (ch == 1)
    throw(ch);
   }
   catch (int ch)
   {
    cout << "\nYou Must have 4-Wheeler\n";
   }
  }

  void get_city(char *c)
  {
   char *a = "PUNE";
   char *b = "PUNE";
   try
   {
    if ((strcmp(c, a)) || (strcmp(c, b)) || (strcmp(c, "BANGALORE")) || (strcmp(c,"AMRAVATI")))
    throw(c);
    else
    cout << "\nCity Is INVALID";
   }
   catch (char c)
   {
    cout << "\nVALID City: " << c << endl;
   }
  }
};

int main()
{
 int ch;
 char *city;
 string c;
 User u;
 cout << "\nEnter Age: ";
 cin >> ch;
 u.get_age(ch);
 cout << "\nEnter Income: ";
 cin >> ch;
 u.get_income(ch);
 cout << "\nChoose Vwhicle Type:\n1. Two-Wheeler\n2.Four-Wheeler\n";
 cin >> ch;
 u.get_veh(ch);
 int n = c.length();
 cout << "\nEnter Your City (ALL CAPS): ";
 cin >> city;
 u.get_city(city);
 return 0;
}
