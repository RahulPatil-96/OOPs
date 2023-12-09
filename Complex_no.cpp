#include<iostream>
using namespace std;

class complex
{
 private:
  int real;
  int imag;
 public:
  complex()
  {
   real=0;
   imag=0;
  }

  complex(int r , int i)
  {
   real=r;
   imag=i;
  }

  friend istream &operator>>(istream &in, complex &x)
  {
   cout<<endl;
   cout<<"Enter the real part of complex no:";
   cin>>x.real;
   cout<<"\n";
   cout<<"Enter the Imaginary part of complex no:";
   cin>>x.imag;
   cout<<endl;
  }

  friend ostream &operator<<(ostream &out, complex&x)
  {
  if(x.real==0)
   cout<<x.imag<<"i"<<endl;
  
  else if(x.imag==0)
   cout<<x.real<<endl;

  else if(x.imag==0 && x.real)
   cout<<"0"<<endl;
  
  else
   cout<<" "<<x.real<<"+"<<x.imag<<"i"<<endl;
  
  return out;
  }

  complex operator+ (complex z)
  {
   complex temp;
   temp.real=real+z.real;
   temp.imag=imag+z.imag;
   return temp;
  }

  complex operator* (complex z)
  {
   complex temp;
   temp.real=(real * z.real)-(imag * z.imag);
   temp.imag=(real * z.imag)+(z.real * z.imag);
   return temp;
  }
};

int main()
{
 complex c1,c2,c3,c4;
 cout<<"For First complex Number:"<<endl;
 cin>>c1;
 cout<<"\n First Complex number is :"<<c1<<endl;
 cout<<"For Second complex Number :";
 cin>>c2;
 cout<<endl;
 cout<<"Second Complex number is :"<<c2<<endl;
 c3=c1+c2;
 cout<<"Addition of complex number is :"<<c3<<endl;
 c4=c1*c2;
 cout<<"Multiplication of Complex Number is:"<<c4<<endl;
 return 0;
}
