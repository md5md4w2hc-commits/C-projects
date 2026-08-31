#include <iostream>
#include <tuple>
#include <string>
#include <cmath>
#include <vector>

int MarksCheck(int& a)
{
    if(a < 0 || a > 100)
    {
        std::cout << "Error : Invalid marks" << std::endl;
        return -1;
    }
    else
    {
        return a;
    }
}

void Output(int* a , int* b , int* c)
{
    if(*a >= 0 && *b >= 0 && *c>= 0)
    {
        std::cout << "Maths marks of student is " << *a << std::endl;
        std::cout << "Physics marks of student is " << *b << std::endl;
        std::cout << "Chemistry marks of student is " << *c << std::endl;
    }
}

std::tuple< std::string  , int , int , int > Input()
{
    std::cout << "Enter the name of the student" << std::endl;
    std::string name;
    std::cin >> name ;
    
    std::cout << "Enter the Maths marks of the student" << std::endl;
    int Mmarks;
    std::cin >> Mmarks ;
    
    std::cout << "Enter the Physics marks of the student" << std::endl;
    int Pmarks;
    std::cin >> Pmarks ;

    std::cout << "Enter the Chemistry marks of the student" << std::endl;
    int Cmarks;
    std::cin >> Cmarks ;

    return { name , Mmarks , Pmarks , Cmarks };
}

int main()
{
    std::vector<int> M_list;
    std::vector<int> P_list;
    std::vector<int> C_list;
    std::vector<std::string> names;
    
    char keepGoing = 'y';
    
    while(keepGoing == 'y' || keepGoing == 'Y')
    {
        auto [userName , MathsMarks , PhysicsMarks , ChemistryMarks] = Input();
        
        names.push_back(userName);
        M_list.push_back(MarksCheck(MathsMarks));
        P_list.push_back(MarksCheck(PhysicsMarks));
        C_list.push_back(MarksCheck(ChemistryMarks));
        
        std::cout << "\nDo you want to enter another student? (y/n): ";
        std::cin >> keepGoing;
    }
    std::cout << "\n--- Final List of Maths Marks ---" << std::endl;
        for (int i = 0; i < names.size(); i++)
        {
            std::cout << "Student " << (i + 1) << " name: " << names[i] << std::endl;
        }
        for (int i = 0; i < M_list.size(); i++)
        {
            std::cout << "Student " << (i + 1) << " scored: " << M_list[i] << std::endl;
            std::cout << "Student " << (i + 1) << " scored: " << P_list[i] << std::endl;
            std::cout << "Student " << (i + 1) << " scored: " << C_list[i] << std::endl;
        }
    
    std::cin.get();
}
