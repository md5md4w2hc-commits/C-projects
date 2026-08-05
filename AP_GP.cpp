#include <iostream>
#include <cmath>
using namespace std;
char operation()
{
   char t;
   cout<<"enter the operation (1 for AP and 2 for GP) \n";
   cin>>t;
   return t;
}
int main()
{
   char choice = operation();
   if (choice== '1')
   {
   cout<<"enter the first term \n";
   double a;
   cin>>a;
   cout<<"enter common difference \n";
   double d;
   cin>>d;
   cout<<"enter the number of terms \n";
   double n;
   cin>>n;
   double i=0;
   cout<<"the AP will be\n";
   while (i<n)
   {
     double ap = a+d*(i);
      cout<<ap<<'\n';
      i=i+1;
   }
   }
   else if (choice== '2' )
   {
   cout<<"enter the first term for GP\n";
   double a;
   cin>>a;
   cout<<"enter the common ratio for GP\n";
   double r;
   cin>>r;
   cout<<"number of terms for GP\n";
   double n;
   cin>>n;
   double i=0;
   cout<<"GP will be\n";
   while(i<n)
   {
      double f=pow(r,i);
      double gp = a*f;
      cout<<gp<<'\n';
      i=i+1;
   }
   }
   else{
      cout<<"invalid input";
   }
   return 0;
}