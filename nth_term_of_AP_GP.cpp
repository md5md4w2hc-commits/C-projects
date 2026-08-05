#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
char userinput()
{
    cout<<"which series ? (1 for AP and 2 for GP) \n";
    char series;
    cin>>series;
    return series;
}
int main()
{
    double a;
    int n;
    double d;
     cout<<"which term ?\n";
    cin>>n;
    cout<<"first term ?\n";
    cin>>a;
    cout <<"common difference or ratio ?\n";
    cin>>d;
    char t=userinput();
    if (t=='1')
    {
        cout<<"n'th term of AP will be \n";
        double q=a+(n-1)*d;
        cout<<q<<'\n';
    }
    else if(t=='2')
    {
        cout<<"n'th term of GP will be \n";
        double w=pow(d,n-1);
        double q=a*w;
        cout<<q<<'\n';
    }
    else 
    {
        cout <<"invalid input";
    }
    return 0;
}