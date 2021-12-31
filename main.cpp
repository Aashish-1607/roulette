#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int makeChoice(){
    int option;
    cout << "Types of Bets you can make: " << endl;
    cout << "1. It will be an Odd/Even number (2x Winnings)" << endl;
    cout << "2. It will be in a range of a dozen (3x Winnings)" << endl;
    cout << "3. It will be a particular number (10x Winnings)" << endl;
    cout << "4. It will land on 0 (15x Winnings)" << endl;
    cout << "Make a choice of bet: ";
    cin >> option;
    return option;  
}

int makeGuess(int option){
    int guess;
    system("cls");
    switch (option){
    case 1:
        cout << "Will it be odd(1) or even(0): ";
        cin >> guess; 
        break;
    case 2:
        cout << "Will it be lower dozen(0), middle dozen(1), or upper dozen(2): ";
        cin >> guess;
        break;
    case 3:
        cout << "Guess the number: ";
        cin >> guess;
        break;
    case 4:
        return 0;
    default:
        break;
    }
    return guess;
}

void playGame(){
    string playerName;
    int balance, bettingAmount, dice;
    char choice;
    srand(time(0)); // "Seed" the random generator
    cout << "\n\nWhat's your Name : ";
    getline(cin, playerName);
    cout << "\n\nEnter the starting balance to play game : $";
    cin >> balance;
    do{
        system("cls");
        cout << "\n\nYour current balance is $ " << balance << "\n";
        do{
            cout << "Enter amount to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > balance)
                cout << "Betting amount can't be more than current balance!\n";
        }while(bettingAmount > balance);
        int option = makeChoice();
        int guess = makeGuess(option);
        dice = rand()%37;
        switch(option){
            case 1:
                if(dice%2 == guess){
                    cout << "\n\nYou are in luck!! You have won Rs." << bettingAmount*2;
                    balance += bettingAmount*2;
                }
                else{
                    cout << "Oops, better luck next time !! You lost $ "<< bettingAmount <<"\n";
                    balance -= bettingAmount;
                }
                break;
            case 2:
                if((dice!=0) && (dice/12 == guess || (dice%12==0 && dice/12 == guess+1))){
                    cout << "\n\nYou are in luck!! You have won Rs." << bettingAmount*3;
                    balance += bettingAmount*3;
                }
                else{
                    cout << "Oops, better luck next time !! You lost $ "<< bettingAmount <<"\n";
                    balance -= bettingAmount;
                }
                break;
            case 3:
                if(dice == guess){
                    cout << "\n\nYou are in luck!! You have won Rs." << bettingAmount*10;
                    balance += bettingAmount*10;
                }
                else{
                    cout << "Oops, better luck next time !! You lost $ "<< bettingAmount <<"\n";
                    balance -= bettingAmount;
                }
                break;
            case 4:
                if(dice == 0){
                    cout << "\n\nYou are in luck!! You have won Rs." << bettingAmount*15;
                    balance += bettingAmount*15;
                }
                else{
                    cout << "Oops, better luck next time !! You lost $ "<< bettingAmount <<"\n";
                    balance -= bettingAmount;
                }
                break;
            default:
                break;
        }
        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<playerName<<", You have balance of $ " << balance << "\n";
        if(balance == 0){
            cout << "You have no more money left to play :(( ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is $ " << balance << "\n\n";
}

int main(){
    system("cls");
    cout << "Roulette o Hajimeru!\n" << endl;
    playGame();
    return 0;
}