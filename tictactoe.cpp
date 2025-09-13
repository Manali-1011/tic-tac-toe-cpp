#include<iostream>
using namespace std;
int currentplayer;
char currentmarker;
char arr[3][3]={{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
void grid(){
    cout<<" "<< arr[0][0]<<" | "<< arr[0][1]<<" | "<<arr[0][2]<<" "<<endl;
    cout<<"---+---+---"<<endl;
    cout<<" "<< arr[1][0]<<" | "<<arr[1][1]<<" | "<<arr[1][2]<<" "<<endl;
    cout<<"---+---+---"<<endl;
    cout<<" "<< arr[2][0]<<" | "<<arr[2][1]<<" | "<<arr[2][2]<<" "<<endl;
}
bool marker(int slot){
    int row=(slot - 1)/3;
    int cln=(slot - 1)%3;
    if(arr[row][cln]!='X' && arr[row][cln]!='O'){
        arr[row][cln]=currentmarker;
        return true;
    }
    else return false;
}
int winner(){
    for(int i=0; i<3; i++){
        if(arr[i][0]==arr[i][1] && arr[i][0]==arr[i][2]){
            return currentplayer;
        }
        if(arr[0][i]==arr[1][i] && arr[0][i]==arr[2][i]){
            return currentplayer;
        }
    }
    if(arr[0][0]==arr[1][1]&& arr[1][1]==arr[2][2]){
        return currentplayer;
    }
    if(arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0]){
        return currentplayer;
    }
    return 0;
}
void swapPlayerAndMarker(){
    if(currentmarker=='X'){
        currentmarker='O';
    }
    else{
        currentmarker='X';
    }
    if(currentplayer==1){
        currentplayer=2;
    }
    else{
        currentplayer=1;
    }

}
void game(){
    cout<<"Welcome to Tic Tac Toe! "<<endl;
    char player1, player2;
    cout<<"Player 1 enter your symbol: X or O"<<endl;
    cin>> player1;
    if(player1=='X') player2='O';
    else player2='X';

    currentplayer=1;
    currentmarker=player1;
    grid();
    int playerwon;
    for(int i=0; i<9; i++){
        int slot;
        cout<<"Its player"<< currentplayer<< "'s turn, enter your slot";
        cin>> slot;
        if(slot <0 || slot >9){
            cout<<"Invalid slot, try again"<<endl;
            i--;
            continue;
        }
        if(marker(slot)==false){
            cout<<"Invalid slot, try again"<<endl;
            i--;
            continue;
        }
        grid();
        playerwon= winner();
        if(playerwon==1){
            cout<<"Player1 wins the game."<< endl<<"CONGRATULATIONS!!!"<<endl;
            break;
        }
        else if(playerwon==2){
            cout<<"Player2 wins the game."<<endl<<"CONGRATULATIONS!!!"<<endl;
            break;
        }
        swapPlayerAndMarker();
        if(i==8 && playerwon==0){
            cout<<"Its a tie!";
            break;
        }
    }
}
int main(){
    game();
    return 0;
}