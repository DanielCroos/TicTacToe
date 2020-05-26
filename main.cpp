//
//  main.cpp
//  TicTacToe
//
//  Created by Daniel Croos on 2020-03-18.
//  Copyright © 2020 Daniel Croos. All rights reserved.
//

#include <iostream>

void print_board(char* test);
int place(int counter,char* array, bool* placed);
char check_win(char* array);

class score{
private:
    int win;
    int lost;
    int draw;

public:
    score(){
        win = 0;
        lost = 0;
        draw = 0;
    }
    int get_win();
    void increase_win();
    int get_lost();
    void increase_lost();
    int get_draw();
    void increase_draw();
    void print_score(score other);
};

int score::get_win(){return win;}
void score::increase_win(){win++;}
int score::get_lost(){return lost;}
void score::increase_lost(){lost++;}
int score::get_draw(){return draw;}
void score::increase_draw(){draw++;}

void score::print_score(score other){
    std::cout<<"     P1-P2"<<std::endl<<"Win:  "<<get_win()<<"-"<<other.get_win()<<std::endl;
    std::cout<<"Lost: "<<get_lost()<<"-"<<other.get_lost()<<std::endl;
    std::cout<<"Draw: "<<get_draw()<<std::endl;
}

int main() {
    score p_1{};
    score p_2{};
    
    std::cout<<"Welcome to TIC TAC TOE"<<std::endl;
    
    bool check{1};
    
    while (check){
        char board[9]{0};
        bool taken_spots[9]{0};
        int turn{1};
        
        for(char i{0};i<9;i++){
            board[i] = i + 49;
        }
        
        print_board(board);
        
        std::cout<<"First player (X) & Second player (O)"<<std::endl;
        
        for (int i{0};i<4;i++){
            place(turn,board,taken_spots);
            print_board(board);
            turn++;
        }
        
        while (turn<10){
            place(turn,board,taken_spots);
            print_board(board);
            
            if (check_win(board)=='X'){
                std::cout<<"Player 1 Wins!"<<std::endl;
                p_1.increase_win();
                p_2.increase_lost();
                break;
            }
            else if (check_win(board)=='O'){
                std::cout<<"Player 2 Wins!"<<std::endl;
                p_1.increase_lost();
                p_2.increase_win();
                break;
            }
            else if (turn==9){
                std::cout<<"The Game ends in a Draw"<<std::endl;
                p_1.increase_draw();
                p_2.increase_draw();
            }
            turn++;
        }
        
        p_1.print_score(p_2);
        std::cout<<"Would you like to Play again?"<<std::endl<<"Type Y for Yes or N for No"<<std::endl;
        
        char play{0};
        
        while (play!='Y' || play !='y' || play !='N' || play !='n'){
            std::cin>>play;
            
            if (play=='Y' || play =='y') {
                check=true;
                break;
            }
            
            else if( play =='N' || play =='n') {
                check = false;
                break;
            }
            else std::cout<<"Incorect input please try again"<<std::endl;
        }
    }
    
    return 0;
}

void print_board(char *test){
    std::cout<<std::endl;
    std::cout<<"     |     |     "<<std::endl;
    std::cout<<"  "<<test[0]<<"  |"<<"  "<<test[1]<<"  |"<<"  "<<test[2]<<"  "<<std::endl;
    std::cout<<"_____|_____|_____"<<std::endl;
    std::cout<<"     |     |     "<<std::endl;;
    std::cout<<"  "<<test[3]<<"  |"<<"  "<<test[4]<<"  |"<<"  "<<test[5]<<"  "<<std::endl;
    std::cout<<"_____|_____|_____"<<std::endl;
    std::cout<<"     |     |     "<<std::endl;;
    std::cout<<"  "<<test[6]<<"  |"<<"  "<<test[7]<<"  |"<<"  "<<test[8]<<"  "<<std::endl;
    std::cout<<"     |     |     "<<std::endl<<std::endl;
}

int place(int counter,char* array,bool* placed){
    int placement{0};
    bool is_taken{0};
    
    if (counter%2==1){
        std::cout<<"It is Player 1's turn"<<std::endl;
    }
    else{
        std::cout<<"It is Player 2's turn"<<std::endl;
    }
    
    std::cout<<"Pick a number corresponding to where you want to place "<<std::endl;
    std::cin>>placement;
    
    if(placed[placement-1]==true){
        is_taken=true;
    }
    
    while ((placement>9)||(placement<1)||is_taken){
        std::cout<<"Invalid placement please enter a valid number"<<std::endl;
        std::cin>>placement;
        
        if(placed[placement-1]==true) is_taken=true;
        else is_taken=false;
    }
    
    placed[placement-1]=true;
    
    if (counter%2==1){
        array[placement-1]='X';
    }
    else{
        array[placement-1]='O';
    }
    
    return placement;
}

char check_win(char* array){
    if ((array[0]==array[1]&&array[0]==array[2]) || (array[0]==array[3]&&array[0]==array[6]) || (array[0]==array[4]&&array[0]==array[8]) || (array[1]==array[4]&&array[1]==array[7]) || (array[2]==array[5]&&array[2]==array[8]) || (array[2]==array[4]&&array[2]==array[6]) || (array[3]==array[4]&&array[3]==array[5]) || (array[6]==array[7]&&array[6]==array[8])) {
        
        if ( array[0]== 'X' || array[1]=='X' || array[2]=='X' || array[5]=='X' || array[8]=='X'){
            return 'X';
        }
        else {
            return 'O';
        }
    }
    return '0';
}
