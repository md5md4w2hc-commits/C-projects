#include <iostream>
#include <cmath>



int main()
{
    double axis[11];
    double ordinate[11];

    axis[0] = 0;
    axis[1] = 1;
    axis[2] = 2;
    axis[3] = 3;
    axis[4] = 4;
    axis[5] = 5;
    axis[6] = 6;
    axis[7] = 7;
    axis[8] = 8;
    axis[9] = 9;
    axis[10] = 10;
    
    ordinate[0] = 0;
    ordinate[1] = 1;
    ordinate[2] = 2;
    ordinate[3] = 3;
    ordinate[4] = 4;
    ordinate[5] = 5;
    ordinate[6] = 6;
    ordinate[7] = 7;
    ordinate[8] = 8;
    ordinate[9] = 9;
    ordinate[10] = 10;
    
    double a;
    double b;

    std::cout<<"enter the x co-ordinate of your location\n";
    std::cin>>a;
    
    std::cout<<"enter the y co-ordinate of your location\n";
    std::cin>>b;


    for(double x : axis)
    {
        double k = a;
        
        if (k == x)
        {
            int z  = round(k);
            std::cout<<axis[z]<<'\n';
            break;

        }
        
        else 
        {
           
        }
    }

    for(double y : ordinate)
    {
        double l = b;
        
        if (l == y)
        {
            int w  = round(l);
            std::cout<<axis[w]<<'\n';
            break;
            
        }
        
        else 
        {
          
        }

    }
  
}
