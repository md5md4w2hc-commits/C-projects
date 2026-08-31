#include <iostream>
#include <tuple>
#include <string>
#include <cmath>

int MarksInputCheck(int a);

struct Student
{
    std::string name;
    std::string subject;
    int marks;
};

int InputCheck(int a)
{
    if(a <= 0 || a >= 100)
    {
        std::cout << "Enter valid marks /n";
        return -1;
    }
    else
    {
        return a;
    }
}

std::tuple< std::string , std::string , int > Input()
{
    std::cout << "Enter the name of the student \n";
    std::string name;
    std::cin >> name ;
    
    std::cout << "Enter the subject \n";
    std::string subject;
    std::cin >> subject ;
        
    std::cout << "Enter the marks of the student \n";
    int marks;
    std::cin >> marks ;
    
    Student x;
    x.name = name;
    x.subject = subject;
    x.marks = InputCheck(marks);
    
    return { name , subject , marks };
}

int main()
{
    auto [userName , userSubject , userMarks] = Input();
    
    std::cout << userName << " ," << userSubject << " ," << userMarks << std::endl;
    
    
    std::cin.get();
}
