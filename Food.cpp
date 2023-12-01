#include "Food.h"
#include "MacUILib.h"
#include "GameMechs.h"
#include "objPos.h"


#include <iostream>
#include "Player.h"


GameMechs* snakeFood;
Player* playerDir;


Food::Food(GameMechs *thisGMRef)
{
    //constructor
    foodPos.setObjPos(-1, -1, 'o'); //initialize foodPos outside of the game board (so to not be displayed)
    mainGameMechsRef = thisGMRef;
}


Food::~Food()
{
    //destructor


}


void Food::generateFood(objPos blockOff)
{
    //generate food from PPA3
    //generate random x and y coord, and make sure they are NOT boarder or blockOff pos
    //check x and y against 0 and boardSize X /Y
    //remember, in objPos class you have an isPosEqual() method. Use this insead of
    //comparing element by element for your convenience


    int x, y;


    do
    {
        srand(time(NULL));


        foodPos.x = (rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1);
        foodPos.y = (rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1);
       
    }
    while(foodPos.isPosEqual(&blockOff));


    // playerDir->getPlayerPos(blockOff);


    // int rep = 1;


    // while(rep)
    // {
    //     rep = 0;
    //     int item_x = (rand() % (snakeFood->getBoardSizeX() - 2)) + 1;
    //     int item_y = (rand() % (snakeFood->getBoardSizeY() - 2)) + 1;
       
    //     foodPos.setObjPos(item_x, item_y, 'o');


    //     if(foodPos.isPosEqual(&blockOff) || item_x == 0 || item_y == 0 || item_x == snakeFood->getBoardSizeX() - 1 || item_y == snakeFood->getBoardSizeY() - 1)
    //     {
    //         rep = 1;
    //     }


    // }
}


void Food::getFoodPos(objPos &returnPos)
{
    returnPos = foodPos;
}


