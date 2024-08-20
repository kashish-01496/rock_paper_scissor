#include<bits/stdc++.h>
using namespace std;

char getComputerMove(){
    srand(time(NULL));
    int comp = rand() % 3;
    char comp_move;
    if(comp == 0)       comp_move = 'r'; 
    else if(comp == 1)  comp_move = 'p'; 
    else                comp_move = 's'; 
    return comp_move;
}

int getResult(char inp,char comp_move){
    int result;
    if(comp_move==inp)                                          result =  0;
    else if(comp_move == 'r' && inp == 'p')                     result = -1;
    else if(comp_move == 'r' && inp == 's')                     result =  1;
    else if(comp_move == 'p' && inp == 'r')                     result =  1;
    else if(comp_move == 'p' && inp == 's')                     result = -1;
    else if(comp_move == 's' && inp == 'r')                     result = -1;
    else if(comp_move == 's' && inp == 'p')                     result =  1;
    return result;
}
void getMove(char c){
    switch (c){
        case 'r': cout<<"Rock\n";    return;
        case 'p': cout<<"Paper\n";   return;
        case 's': cout<<"Scissor\n"; return;
    }
}
void displayMove(char inp,char comp_move){
    cout<<"Your move : ";
    getMove(inp);
    cout<<"Computer Move : ";
    getMove(comp_move);
}


int main(){
    cout<<"\t\t\t\t\t\t-----Welcome to Rock Paper Scissor Game-----\n";
    cout<<"\t\t\t\t\t\t-----Enter 'r' for Rock , 'p' for Paper , 'S' for Scissor \n";
    cout<<"\t\t\t\t\t\t\tLet's Start!!\n";

    char inp;
    cout<<"Enter your move(r,p,s):\t";
    
    // Taking input from user
    while(1){
        cin>>inp;
        if(inp =='p' || inp == 's'|| inp == 'r')    break;
        else           cout<<"Invalid move!\n";
    }

    // Computer move
    char comp_move = getComputerMove();

    // Getting Results
    int res = getResult(inp,comp_move);
    if(res==0)      cout<<"Draw\n";
    else if(res==1) cout<<"Oops! You lost\n";
    else            cout<<"Congrats!!, you win\n";

    // Displaying moves of both Player and Computer
    displayMove(inp,comp_move);

    return 0;
}