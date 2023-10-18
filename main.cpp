#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>

using namespace std;

#include "snake.h"
#include "food.h"


#define w 25
#define h 25

int score;
bool gameOver;

Snake snake({w / 2, h / 2,}, 1);
Food food;



///INICIALIZACION DE VARIABLES
void init(){
    system("cls");

    score = 0;

    gameOver = false;
}

///RENDERIZAR PANTALLA
void render(){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    for(int i = 0; i < w + 2; i++){
            cout<<"#";
    }
    cout<<endl;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(j == 0)
                cout<<"#";

            if(j == snake.getSnakePos().X && i == snake.getSnakePos().Y)
                cout<<"O";
             else  if(j == food.getFoodPos().X && i == food.getFoodPos().Y)
                cout<<"*";
            else{
                bool printTail = false;

                for(int k = 0; k< snake.getSnakeBody().size(); k++){
                        if((snake.getSnakeBody()[k].X == j) && (snake.getSnakeBody()[k].Y == i)){
                            cout<<"o";
                            printTail = true;
                        }
                }
                if(!printTail)
                cout<<" ";
                }


            if(j == w - 1)
                cout<<"#";

        }
        cout<<endl;
    }

    for(int i = 0; i < h + 2; i++){
            cout<<"#";
    }

    cout<<endl<<endl;
    cout<<"YOUR SCORE: "<<score<<endl;
}

void input(){

    if(_kbhit()){
        switch(_getch()){
        case 'w' :if(snake.getSnakeDirection() != 'D')
            snake.changeDirection('U');
            break;
        case 'W' :if(snake.getSnakeDirection() != 'D')
            snake.changeDirection('U');
            break;
        case 's': if(snake.getSnakeDirection() != 'U')
            snake.changeDirection('D');
            break;
        case 'S': if(snake.getSnakeDirection() != 'U')
            snake.changeDirection('D');
            break;
        case 'a': if(snake.getSnakeDirection() != 'R')
            snake.changeDirection('L');
            break;
        case 'A' : if(snake.getSnakeDirection() != 'R')
            snake.changeDirection('L');
            break;
        case 'd': if(snake.getSnakeDirection() != 'L')
            snake.changeDirection('R');
            break;
        case 'D': if(snake.getSnakeDirection() != 'L')
            snake.changeDirection('R');
            break;
        case 'q': gameOver = true;
            break;
        case 'Q': gameOver = true;
            break;
        }
    }
    snake.moveSnake();
}



void game(){

    if(snake.canCrash()){
       gameOver = true;
    }

    if(snake.canEat(food.getFoodPos())){
        score += 10;
        food.spawnFood();
        snake.increaseTailLength();
    }

}

int main(){
    srand(time(0));

    init();
    while(!gameOver){
        render();
        Sleep(65);
        input();
        game();

    }

    cout<<"GAME OVER!"<<endl;
}

