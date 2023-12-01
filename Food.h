#ifndef FOOD_H
#define FOOD_H


#include <cstdlib> //provides srand() an rand()
#include <ctime> //provides time() (can be replaced with time.h)


#include "objPos.h"
#include "objPosArrayList.h"


#include "GameMechs.h"


using namespace std;


class Food
{
    private:
        objPos foodPos;
        GameMechs* mainGameMechsRef;
        objPosArrayList *playerPosList;
    public:
        Food(GameMechs *thisGMRef);
        ~Food();

        objPosArrayList* generateFood(objPosArrayList* playerPosList);
        //void generateFood(objPos blockOff);
        void getFoodPos(objPos &returnPos);
};


#endif
