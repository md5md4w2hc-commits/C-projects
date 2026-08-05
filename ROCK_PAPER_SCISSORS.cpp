#include <iostream>
#include <ctime>
char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player,char computer);

int main()
{
    char player;
    char computer;

    player=getUserChoice();
    std::cout<<"your choice is \n";
    showChoice(player);

    computer=getComputerChoice();
    std::cout<<"computer's choice is \n";
    showChoice(computer);

    chooseWinner(player,computer);




    return 0;
}
char getUserChoice()
{
    char player;
    std::cout<<"rock paper scirssors game\n";
    std::cout<<"choose one\n";

    do
    {
         std::cout<<"'r' for rocks\n";
         std::cout<<"'p' for papers\n";
         std::cout<<"'s' for scissors\n";
         std::cin>>player;
    }while(player !='r' && player != 'p' && player != 's');

    return player;
}
char getComputerChoice()
{
    srand(time(0));
    int num =rand()%3+1;
    switch(num)
    {
        case 1:
        return 'r';
        case 2:
        return 'p';
        case 3:
        return 's';

    }
     
     return 0;

}
void showChoice(char choice)
{
    switch(choice)
    {
        case 'r':
        std::cout<<"rock\n";
        break;
        case 'p':
        std::cout<<"paper\n";
        break;
        case 's':
        std::cout<<"scissors\n";
        break;

    }
}
void chooseWinner(char player,char computer)
{
    switch(player)
    {
        case 'r':
         if(computer == 'r')
         {
            std::cout<<"it's a tie\n";
         }
         else if(computer == 'p')
         {
            std::cout<<"you loose\n";
         }
         else
         {
            std::cout<<"you won\n";
         }
         break;


         case 'p':
         if(computer == 'p')
         {
            std::cout<<"it's a tie\n";
         }
         else if(computer == 's')
         {
            std::cout<<"you loose\n";
         }
         else
         {
            std::cout<<"you won\n";
         }
         break;


         case 's':
         if(computer == 's')
         {
            std::cout<<"it's a tie\n";
         }
         else if(computer == 'r')
         {
            std::cout<<"you loose\n";
         }
         else
         {
            std::cout<<"you won\n";
         }
         break;



        
    }
    

}