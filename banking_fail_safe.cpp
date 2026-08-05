#include <iostream>
#include <iomanip>
#include <limits> // Required for std::numeric_limits

void showbalance(double balance);
double deposite();
double withdraw(double balance);

int main()
{
    double balance = 0;
    int choice = 0;
    do
    { 
        std::cout << "\nenter your choice \n";
        std::cout << "1) show balance\n";
        std::cout << "2) deposite money\n";
        std::cout << "3) withdraw money \n";
        std::cout << "4) exit\n";
        std::cin >> choice;
        
        // Check if the input failed (e.g., user entered a character)
        if (std::cin.fail()) 
        {
            std::cin.clear(); // 1. Clear the error state
            
            // 2. Discard the bad input up to the next newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            
            // choice will default to 0, which triggers the 'default' switch case
        }
        else 
        {
            // Good practice: clear the newline character even on successful integer input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch(choice)
        {
            case 1: 
                showbalance(balance);
                break;
            case 2: 
                balance += deposite();
                showbalance(balance);
                break;
            case 3: 
                balance -= withdraw(balance);
                showbalance(balance);
                break;
            case 4: 
                std::cout << "thanks for visiting\n";
                break;
            default:
                std::cout << "invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}

void showbalance(double balance)
{
    std::cout << "your balance is ₹" << std::setprecision(2) << std::fixed << balance << '\n';
}

double deposite()
{
    double amount = 0;
    std::cout << "enter amount to be deposited ₹";
    std::cin >> amount;
    
    // Bonus Tip: You might want to add std::cin.fail() checks here too!
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "thats not a valid amount\n";
        return 0;
    }

    if (amount > 0)
    {
        return amount;
    }
    else 
    {
        std::cout << "thats not a valid amount\n";
        return 0;
    }
}

double withdraw(double balance)
{
    double amount = 0;
    std::cout << "enter the amount to be withdrawn ₹";
    std::cin >> amount;
    
    // Bonus Tip: You might want to add std::cin.fail() checks here too!
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "thats not a valid amount\n";
        return 0;
    }

    if(amount < 0)
    {
        std::cout << "thats not a valid amount\n";
        return 0;
    }
    else if(amount <= balance)
    {
        return amount;
    }
    else
    {
        std::cout << "insufficient funds \n";
        return 0;
    }
}