#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
int firstPlayerScore=0;
int secondPlayerScore=0;
int computerScore=0;

vector<string> characters={"rock","paper","scissor"};
void displayRules(){
    cout<<"Welocome"<<endl;
    cout<<"Game Rules: "<<endl;
    cout<<"1. you can play with computer and with your friend"<<endl;
    cout<<"The game play until one player get 3 score"<<endl;
    cout<<"A player who get 3 points will win"<<endl;
    cout<<"Rock stronger than Scissor"<<endl;
    cout<<"Scissor stronger than paper"<<endl;
    cout<<"Paper stronger than Rock"<<endl;
    cout<<endl<<endl;
}
string answer1;
string answer2;
void firstPlayerAnswer(){
    cout<<"Enter the characters: ";
    cin>>answer1;
}
void secondPlayerAnswer(){
    cout<<"Enter the character: ";
    cin>>answer2;
}
string computerAnswer(){
    return characters[rand() % characters.size()];
}



int main(){
    srand(static_cast<unsigned int>(time(0)));
    char playAgain='y';
    char againtsWho='c';
    displayRules();
    while(playAgain=='y' || playAgain=='Y'){
        int firstPlayerScore=0;
        int secondPlayerScore=0;
        int computerScore=0;    
        cout<<"With againts computer prees c "<<endl;
        cout<<"With againts with your friends enter others key: ";
        cin>>againtsWho;
        if(againtsWho=='c' || againtsWho=='C'){
            while(computerScore<3 && firstPlayerScore<3){
                int i=0;
                firstPlayerAnswer();
                string compChoice=computerAnswer();
                if((answer1=="rock" && compChoice=="scissor") || (answer1=="scissor" && compChoice=="paper") ||
                (answer1=="paper" && compChoice=="rock")){
                    cout<<"You won the round"<<endl;
                    firstPlayerScore++;
                    cout<<"First Player score: "<<firstPlayerScore<<"  "<<"computer score: "<<computerScore<<endl;
                    i++;
                }
                else if (answer1==compChoice){
                    cout<<"you drew with computer"<<endl;
                    i++;
                    cout<<"First Player: "<<firstPlayerScore<<"  "<<"computer score: "<<computerScore<<endl;
                }
                else{
                    cout<<"Computer won the round"<<endl;
                    i++;
                    computerScore++;
                    cout<<"First Player: "<<firstPlayerScore<<"  "<<"computer score: "<<computerScore<<endl;
                }
            
                
            }
            if(firstPlayerScore>computerScore){
                cout<<"First player won the game"<<endl;
            }
            else{
                cout<<"computer won the game"<<endl;
            }
            

        }
        else{
            while(firstPlayerScore<3 || secondPlayerScore<3){
                firstPlayerAnswer();
                secondPlayerAnswer();
                if((answer1=="rock" && answer2=="scissor") || (answer1=="scissor" && answer2=="paper") ||
                (answer1=="paper" && answer2=="rock")){
                    cout<<"First Player won the round"<<endl;
                    firstPlayerScore++;
                    cout<<"First Player: "<<firstPlayerScore<<"  "<<"second player score: "<<secondPlayerScore<<endl;
                }
                else if (answer1==answer2){
                    cout<<"first player and second player drew"<<endl;
                    cout<<"First Player: "<<firstPlayerScore<<"  "<<"second player score: "<<secondPlayerScore<<endl;
                }
                else{
                    cout<<"Second Player won"<<endl;
                    secondPlayerScore++;
                    cout<<"First Player: "<<firstPlayerScore<<"  "<<"second player score: "<<secondPlayerScore<<endl;
                }
            }
            if(firstPlayerScore>secondPlayerScore){
                cout<<"First player won the game"<<endl;
            }
            else{
                cout<<"Second Player won the game"<<endl;
            }
        }
        
        cout<<"You wanna play again press 'y': ";
        cin>>playAgain;
    }
    
    
    return 0;
}
