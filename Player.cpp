
#include "Player.h"
#include "MacUILib.h"
#include "Food.h"
#include "objPosArrayList.h"








Player::Player(GameMechs* thisGMRef, Food* myFood)
{
   mainGameMechsRef = thisGMRef;
   myDir = STOP;
   myObject = myFood;





   objPos tempPos;



   // more actions to be included
   tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,
                       mainGameMechsRef->getBoardSizeY()/2,
                       '*');




   //need heap member
   playerPosList = new objPosArrayList();
   playerPosList->insertHead(tempPos);

   //DEBUG PURPOSE
//    playerPosList->insertHead(tempPos);
//    playerPosList->insertHead(tempPos);
//    playerPosList->insertHead(tempPos);
//    playerPosList->insertHead(tempPos);
   
}




Player::~Player()
{
   // delete any heap members here
   //delete [] playerPosList;
   delete playerPosList;
}




objPosArrayList* Player::getPlayerPos()
{
   // return the reference to the playerPos arrray list
   //returnPos.setObjPos(playerPos.x,playerPos.y,playerPos.symbol);

   return playerPosList;
}




void Player::updatePlayerDir()
{
   // GameMechs* mainGameMechsRef;
   // PPA3 input processing logic  
   char input = mainGameMechsRef->getInput();




   switch(input)
   {
       case 27:
           mainGameMechsRef->setExitTrue();
           break;
       case 'w':
       case 'W':
           if(myDir != DOWN && myDir != UP)
           {
               myDir = UP;
           }
           break;
       case 'a':
       case 'A':
           if(myDir != RIGHT && myDir != LEFT)
           {
               myDir = LEFT;
           }
           break;
       case 's':
       case 'S':
           if(myDir != UP && myDir != DOWN)
           {
               myDir = DOWN;
           }
           break;
       case 'd':
       case 'D':
           if(myDir != LEFT && myDir != RIGHT)
           {
               myDir = RIGHT;
           }
           break;
       default:
           break;
   }
}




void Player::movePlayer()
{
   // PPA3 Finite State Machine logic
   int x = mainGameMechsRef->getBoardSizeX();
   int y = mainGameMechsRef->getBoardSizeY();
   objPos currHead;
   objPos foodPos;
   
   
   playerPosList->getHeadElement(currHead);
   myObject->getFoodPos(foodPos);


   switch(myDir)
   {
       case UP:
           currHead.y--;
           if (currHead.y <= 0)
           {
               currHead.y = y -2;
           }
           break;
     
     
       case LEFT:
           currHead.x--;
           if (currHead.x <= 0)
           {
               currHead.x = x -2;
           }
           break;
       case DOWN:
           currHead.y++;
           if (currHead.y >= y -1)
           {
               currHead.y = 1;
           }
           break;




       case RIGHT:
           currHead.x++;
           if (currHead.x >= x -1)
           {
               currHead.x = 1;
           }
           break;
       default:
           break;
   }

   if(currHead.isPosEqual(&foodPos))
   {
        playerPosList->insertHead(currHead);
        myObject->generateFood(playerPosList);
        //MacUILib_printf("Passed!");

   }
   else
   {
        playerPosList->insertHead(currHead);
        playerPosList->removeTail();
   }

   for(int j = 0; j < playerPosList->getSize(); j++)
   {
        mainGameMechsRef->incrementScore();
   }
    // playerPosList->insertHead(currHead);
    // playerPosList->removeTail();


}


