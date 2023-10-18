#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#define w 25
#define h 25

///SNAKE CLASS DEFINITION AND IMPLEMENTATION


class Snake{
private:
    COORD snakePos;
    int snakeLength, snakeVelocity;
    char snakeDirection;
    vector<COORD> body;
public:

    Snake( COORD _snakePos, int _snakeVelocity){
        snakePos = _snakePos;
        snakeVelocity = _snakeVelocity;
        snakeLength = 1;
        snakeDirection = 'S';
        body.push_back(snakePos);
    }

    COORD getSnakePos (){
    return snakePos;
    }

    char getSnakeDirection (){
    return snakeDirection;
    }

    vector<COORD> getSnakeBody(){
    return body;
    }


    void changeDirection( char newdirection){
    snakeDirection = newdirection;
    }

    void moveSnake (){
        switch(snakeDirection){
        case 'U':
            snakePos.Y -= snakeVelocity;
            Sleep(30);
            break;
        case 'D':
            snakePos.Y += snakeVelocity;
            Sleep(30);
            break;
        case 'L':
            snakePos.X -= snakeVelocity;
            break;
        case 'R':
            snakePos.X += snakeVelocity;
            break;
    }
    body.push_back(snakePos);
    if(body.size() > snakeLength)
        body.erase(body.begin());
    }

    void increaseTailLength(){
    snakeLength++;
    }

    bool canEat(COORD foodpos){
        bool eat = false;
        if((snakePos.X == foodpos.X) && (snakePos.Y == foodpos.Y))
                eat = true;

    return eat;
    }

    bool canCrash(){
         if( (snakePos.X >= w) || (snakePos.X <0) || (snakePos.Y >=h) || (snakePos.Y < 0) )
            return true;

        for(int i = 0; i <snakeLength - 1; i++){
        if((snakePos.X == body[i].X) && (snakePos.Y == body[i].Y))
         return true;
    }

        return false;
    }

};


#endif // SNAKE_H_INCLUDED
