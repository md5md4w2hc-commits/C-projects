#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>

struct Student
{
    std::string name;
    int M_marks;
    int P_marks;
    int C_marks;
};

int MarksCheck(int& a)
{
    if(a < 0 || a > 100)
    {
        std::cout << "Error : Invalid marks \n";
        return -1;
    }
    else
    {
        return a;
    }
}

void MathsTopper(const std::vector<Student> &list)
{
    if (list.empty()) {
        std::cout << "No student data available.\n";
        return;
    }

    std::cout << "Mathematics - " << '\n';
    std::cout << "NAME : " << list[0].name << '\n';
    std::cout << "MARKS IN MATHS : " << list[0].M_marks << '\n' << '\n';
}

void PhysicsTopper(const std::vector<Student> &list)
{
    if (list.empty()) {
        std::cout << "No student data available.\n";
        return;
    }

    std::cout << "Physics - " << '\n';
    std::cout << "NAME : " << list[0].name << '\n';
    std::cout << "MARKS IN PHYSICS : " << list[0].P_marks << '\n' << '\n';
}

void ChemistryTopper(const std::vector<Student> &list)
{
    if (list.empty()) {
        std::cout << "No student data available.\n";
        return;
    }

    std::cout << "Chemistry - " << '\n';
    std::cout << "NAME : " << list[0].name << '\n';
    std::cout << "MARKS IN CHEMISTRY : " << list[0].C_marks << '\n' << '\n';
}

std::tuple< std::string  , int , int , int > Input()
{
    std::cout << "Enter the name of the student \n";
    std::string name;
    std::cin >> name ;
    
    std::cout << "Enter the Maths marks of the student \n";
    int Mmarks;
    std::cin >> Mmarks ;
    
    std::cout << "Enter the Physics marks of the student \n";
    int Pmarks;
    std::cin >> Pmarks ;

    std::cout << "Enter the Chemistry marks of the student \n";
    int Cmarks;
    std::cin >> Cmarks ;

    return { name , Mmarks , Pmarks , Cmarks };
}

void sorting_Maths(std::vector<Student> &list)
{
    std::sort(list.begin() , list.end() , [](const Student &a ,const Student &b){return a.M_marks > b.M_marks;});
}

void sorting_Physics(std::vector<Student> &list)
{
    std::sort(list.begin() , list.end() , [](const Student &a ,const Student &b){return a.P_marks > b.P_marks;});
}

void sorting_Chemistry(std::vector<Student> &list)
{
    std::sort(list.begin() , list.end() , [](const Student &a ,const Student &b){return a.C_marks > b.C_marks;});
}

void showValue(const std::vector<Student> &list)
{
    std::cout << "-------------The list-------------" << '\n' << '\n';
    
   for(const Student &p : list)
   {
       std::cout << "Name: " << p.name << '\n';
       std::cout << "Maths marks : " << p.M_marks << '\n';
       std::cout << "Physics marks : " << p.P_marks << '\n';
       std::cout << "Chemistry marks : " << p.C_marks << '\n' << '\n';
   }
}

int main()
{
    std::vector<Student> student;
    
    char keepGoing = 'y';
    
    while(keepGoing == 'y' || keepGoing == 'Y')
    {
        auto [userName , MathsMarks , PhysicsMarks , ChemistryMarks] = Input();
       
        student.push_back({userName , MarksCheck(MathsMarks) , MarksCheck(PhysicsMarks) , MarksCheck(ChemistryMarks)});
        
        std::cout << "\nDo you want to enter another student? (y/n): ";
        std::cin >> keepGoing;
    }
   
    std::cout << "Which subject list you want to see in Descending Order : ";
    std::string input;
    std::cin >> input;
    
    if(input == "Maths" || input == "maths" || input == "Mathematics" || input == "mathematics" || input == "math" || input == "Math" || input == "MATHS" || input == "MATHEMATICS" || input == "MATHEMATIC" || input == "MATHS")
    {
        sorting_Maths(student);
        showValue(student);
    }
    else if(input == "Physics" || input == "physics" || input == "PHYSICS")
    {
        sorting_Physics(student);
        showValue(student);
    }
    else if(input == "Chemistry" || input == "chemistry" || input == "CHEMISTRY")
    {
        sorting_Chemistry(student);
        showValue(student);
    }
    else
    {
        std::cout << "ERROR : INVALID SUBJECT \n";
    }
    
    std::cout << "----------TOPPER LIST----------" << '\n' << '\n';
    sorting_Maths(student);
    MathsTopper(student);
    sorting_Physics(student);
    PhysicsTopper(student);
    sorting_Chemistry(student);
    ChemistryTopper(student);
    
    
    std::cin.get();
}
