#ifndef FOOD_H_INCLUDED
#define FOOD_H_INCLUDED

#define w 25
#define h 25

///FOOD CLASS DEFINITION AND IMPLEMENTATION


class Food{
private:
COORD foodPos;
public:

    Food(){
        spawnFood();

    }

    void spawnFood(){
        srand(time(0));
        foodPos.X = rand() % w;
        foodPos.Y = rand() % h;
    }

    COORD getFoodPos(){
    return foodPos;
    }

};


#endif // FOOD_H_INCLUDED
