#include <iostream>
#include <cmath>
#include <ctime>
int choice();
int dice();
double deposite();
double upperlimit();
double lowerlimit();
double userdicenumber();
int main()
{
    srand(time(NULL));
    std::cout<<"welcome to the gmabling game\n";
    std::cout<<"in this game 3 dice will be thrown\n";
    std::cout<<"you have to tell whether the sum of the faces will be greater than a number of your choice or not\n";
    std::cout<<"if you win you will get 10% of your balance ...if you lose the house will get 10% of your deposite\n";
    std::cout<<"if you guess exactly matches the sum of dice the house will get 5% of you deposite\n";
    std::cout<<"enter the amount you want to deposite to play the game : ₹";
    double balance= deposite();
    if(balance>0)
    {
    std::cout<<"your balnce is ₹";
    std::cout<<balance<<'\n';
    double housebalance = 1000000;
    int ch=choice();
    
    if(ch==1)
    {
        int i=0;
        double r=upperlimit();
        if(r>0)
        {
        double p=lowerlimit();
        if(p>0&&p<r)
        {
        double d=userdicenumber();
        if(d>0)
        {
        double totalwon=0;
        double totallost=0;
        while(balance>=p&&balance<=r)
        {
            int x=dice();
            std::cout << "\n[ The dice rolled a sum of: " << x << " ]\n";
            int y=d;
            double s =balance*0.1;
            double h= balance*0.05;
            if(x>y)
            {
                double w= balance + s;
                housebalance=housebalance-s;
                balance = w;
                std::cout<<"you won ₹"<<s<<'\n';
               totalwon=totalwon+s;
                i=i+1;
            }
            else if(y>x)
            {
                double w=balance-s;
                housebalance=housebalance+s;
                balance = w;
                std::cout<<"you lost ₹"<<s<<'\n';
                totallost=totallost+s;
                i=i+1;
            }
            else
            {
                double w = balance-h;
                 housebalance=housebalance+h;
                 balance = w;
                 std::cout<<"you lost ₹"<<s<<'\n';
                 totallost=totallost+h;
                 i=i+1;
            }
            }
        std::cout<<"amount you won : ₹"<<totalwon<<'\n';
        std::cout<<"amount you lost : ₹"<<totallost<<'\n';
        std::cout<<"your balance is : ₹"<<balance<<'\n';
        std::cout<<"house balance is : ₹"<<housebalance<<'\n';
        std::cout<<"number of game played is "<<i<<'\n';  
        }
        else{
            std::cout<<"invalid\n";
          
        }
    }
        else
        {
             std::cout<<"invalid\n";
        }
        }   
        else
        {
            std::cout<<"invalid\n";
        }
        
    }
    else if(ch==2)
    {
         int i=0;
        double totalwon=0;
        double totallost=0;
        double p=lowerlimit();
        if(p>0)
        {
        while(balance>=p)
        {
            int y=userdicenumber();
            if(y>0)
            {
            int x=dice();
            std::cout << "\n[ The dice rolled a sum of: " << x << " ]\n";
            double s =balance*0.1;
            double h= balance*0.05;
            if(x>y)
            {
                balance= balance + s;
                housebalance=housebalance-s;
                
                std::cout<<"you won ₹"<<s<<'\n';
                totalwon=totalwon+s;
                i=i+1;
            }
            else if(y>x)
            {
                balance=balance-s;
                housebalance=housebalance+s;
        
                std::cout<<"you lost ₹"<<s<<'\n';
                totallost=totallost+s;
                i=i+1;
            }
            else
            {
                double w = balance-h;
                 housebalance=housebalance+h;
                 balance = w;
                 std::cout<<"you lost ₹"<<s<<'\n';
                 totallost=totallost+h;
                 i=i+1;
            }
            int manual_choice;
            std::cout<<"enter 1 to continue playing or 2 to  withdraw now\n";
            std::cin>>manual_choice;
            if(manual_choice==2)
            {
                std::cout<<"manually withdrawing....\n:";
                break;
            }
            else if(manual_choice==1)
            {
                std::cout<<"set the dice number\n";
               
            }
            else
            {
                std::cout<<"invalid choice\n";
            }
        }
        else
        {
            std::cout<<"invalid\n";
        }
        } 
        std::cout<<"\n--- GAME OVER ---\n";
        std::cout<<"Amount you won : ₹"<<totalwon<<'\n';
        std::cout<<"Amount you lost : ₹"<<totallost<<'\n';
        std::cout<<"Your final balance is : ₹"<<balance<<'\n';
        std::cout<<"House balance is : ₹"<<housebalance<<'\n';
        std::cout<<"Number of games played is "<<i<<'\n'; 
    }
    else{
        std::cout<<"invalid\n";
    }
    }
    else
    {
        std::cout<<"invalid output\n";
    }
    return 0;
   }
   else
   {
    std::cout<<"invalid\n";
   }
}
int choice()
{
    std::cout<<"choose for 1 for automated or 2 for manual withdrawer\n";
    int choice;
    std::cin>>choice;
    return choice;
}
int dice()
{
   
    int l=rand()%6+1;
    int n=rand()%6+1;
    int m=rand()%6+1;
    int r=l+m+n;
    return r;
}
double deposite()
{
    double amt;
    std::cin>>amt;
    if(amt>0)
    {
        return amt;

    }
    else 
    {
        
        return 0;
    }
    
}
double upperlimit()
{
    std::cout<<"input the upper limit : ₹";
    double u;
    std::cin>>u;
    if(u>0)
    {
        return u;
    }
    else
    {
        return 0;
    }
}
double lowerlimit()
{
    std::cout<<"input the lower limit : ₹";
    double l;
    std::cin>>l;
    if(l>=0)
    {
        return l;
    }
    else
    {
        return 0;
    }
}
double userdicenumber()
{
    std::cout<<"pick a number you think will lesser than the sum of faces of dice\n";
    std::cout<<"it should be between 10 and 13\n";
    double o;
    std::cin>>o;
    if(o>=10&&o<=13)
    {
    return o;
    }
    else
    {
        return 0;
    }
}
