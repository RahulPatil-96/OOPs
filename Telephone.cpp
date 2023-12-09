#include <bits/stdc++.h>
using namespace std;

class telephone
{
 public:
  string name;
  string phone_no;

  void get_data()
  {
   cout << endl;
   cin.ignore();
   cout << "Enter the Name:";
   getline(cin, name);
   cout << "\nEnter Phone Number:";
   cin >> phone_no;
  }
};

int main()
{
 telephone t[100];
 int ans, ch;
 static int count = 0;
 fstream f;
 string search_name, search_phone;
 int choice;
 do
 {
  cout << "\t\t*Menu*" << endl;
  cout << "\nEnter:\n1.To Enter Details\n2.To Show Details\n3.To Search \n";
  cout << "Enter your choice :";
  cin >> ch;
  switch (ch)
  {
   case 1:
    f.open("sample1.txt", ios::app);
    t[count].get_data();
    f.write(reinterpret_cast<char *>(&t[count]), sizeof(t[count]));
    count++;
    break;

   case 2:
    f.open("sample1.txt");
    cout << "\n\t*Telephone List*"<< "\n\n\tName\t\tphone Number";
    cout << endl;
    for (int i = 0; i < count; i++)
    {
     f.read(reinterpret_cast<char *>(&t[i]), sizeof(t[i]));
     cout << "\t" << t[i].name << "\t\t" << t[i].phone_no;
     cout << endl;
    }
    break;

   case 3:
    cout << "\n1.Search By Name" << endl<< "2.Search by Phone Number" << endl;
    cout << "Enter Your Choice:";
    cin >> choice;
    switch (choice)
    {
     case 1:
      cout << "\n*Search By Name*" << endl;
      cout << "\nEnter the name to Search:";
      cin.ignore();
      getline(cin, search_name);
      for (int i = 0; i < count; i++)
      {
       f.read(reinterpret_cast<char *>(&t[i]), sizeof(t[i]));
       if (search_name == t[i].name)
       {
        cout << t[i].name << "\t" << t[i].phone_no << endl;
        break;
       }
      }
      break;

    case 2:
     cout << "\n*Search By Phone Number*" << endl;
     cout << "\nEnter the Phone Number to Search:";
     cin >> search_phone;
     for (int i = 0; i < count; i++)
     {
      f.read(reinterpret_cast<char *>(&t[i]), sizeof(t[i]));
      if (search_phone == t[i].name)
      {
       cout << t[i].name << "\t" << t[i].phone_no;
       cout << endl;
       break;
      }
     }
     break;

    default:
     cout << "\nInvalid Choice Please Enter Valid Choice\n";
   }
   break;

   default:
    cout << "\nInvalid Choice Please Enter Valid choice\n";
  }
  cout << "\nDo you Want to continue:\n1.Yes\n2.No\n";
  cin >> ans;
 } while (ans == 1);
 f.close();
 return 0;
}
