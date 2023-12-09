#include <iostream>
using namespace std;

int n = 100;

template <class T>

class Sort
{
 public:
  void sort(T A[])
  {
   T temp;
   for (int i = 0; i < n; i++)
   {
    for (int j = i + 1; j < n; j++)
    {
     if (A[j] < A[i])
     {
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
     }
    }
   }
  }
};

int main()
{
 int ch;
 int a[10];
 float b[10];
 cout << "Enter Size of Array: ";
 cin >> n;
 cout << "\nChoose:\n1:Integer Array\n2:Float Array\n";
 cin >> ch;
 if (ch == 1)
 {
  cout << "\nEnter Array Elements: \n";
  for (int i = 0; i < n; i++)
  cin >> a[i];
  Sort<int> S;
  S.sort(a);
  cout << "\nSorted Array: ";
  for (int i = 0; i < n; i++)
  cout << a[i] << " ";
 }

 if (ch == 2)
 {
  cout << "\nEnter Array Elements: \n";
  for (int i = 0; i < n; i++)
  cin >> b[i];
  Sort<float> ss;
  ss.sort(b);
  cout << "\nSorted Array: ";
  for (int i = 0; i < n; i++)
  cout << b[i] << " ";
 }
 return 0;
}
