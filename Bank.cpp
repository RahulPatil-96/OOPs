#include<bits/stdc++.h>
using namespace std;

class acc_holder_info
{
 protected:
  string name,pan_no,ph_no,acc_no;
  int age;
  char g;
 public:
  int balance=0,withdraw,deposit;

  void get_info()
  {
   cout<<"Enter name: ";
   cin>>name;
   cout<<"Enter Account no: ";
   cin>>acc_no;
   cout<<"Enter Pan no: ";
   cin>>pan_no;
   cout<<"Enter Phone no: ";
   cin>>ph_no;
   cout<<"Enter your age: ";
   cin>>age;
  }
 };

class operation : public acc_holder_info
{
 public:
  void deposit(int d)
  {
   balance=balance+d;
  }

  void withdraw (int w)
  {
   if(balance == 0 || w > balance )
    cout<<"Insufficient balance"<<endl;
  
   else if(balance - w < 100)
   { 
     cout<<"balance:"<<balance<<endl;
     cout<<"w:"<<w<<endl;
     int f = 100 - (balance - w);
     cout<<"f: "<<f<<endl;
     w -= f;
     cout<<"w: "<<w<<endl;
     balance = balance - w;
     // cout<<"b: "<<balance<<endl;
     cout<<"Minimum bal 100 is required"<<endl;
     cout<<"Hence amount withdraw is Rs:"<<w<<endl;
   }
  
  else
   balance=balance-w;
  }
};

class display: public operation
{
 public :
  void bal()
  {
  cout<<"Your balance is: "<<balance<<endl;
  }

  void info()
  {
  cout<<"Your info is: \n";
  cout<<"Name:"<<name<<endl;
  cout<<"Acc no: "<<acc_no<<endl;
  if(age<18)
   cout<<"Your acc is of Minor Type"<<endl;
  
  else
   cout<<"Your acc is Major Type"<<endl;
  
  cout<<"Balance: "<<balance;
  } 
};

int main()
{
 int ch,c=1,w,d;
 display d1;
 d1.get_info();

 while(c)
 {
  cout<<"\n 1.Check Balance\n 2.Withdraw\n 3.Deposit\n 4.Personal info\n 5.Exit\n";
  cin>>ch;
  switch(ch)
  {
   case 1:
    d1.bal();
    break;
    
   case 2:
    cout<<"Enter amount to be withdraw: ";
    cin>>w;
    d1.withdraw(w);
    break;

   case 3:
    cout<<"Enter amount to be deposited: ";
    cin>>d;
    d1.deposit(d);
    break;

   case 4:
    d1.info();
    break;
    case 5:
    c=0;
    break;
  }
 }
return 0;
}
