#include "Player.h"
#include "MacUILib.h"




Player::Player(GameMechs* thisGMRef)
{
   mainGameMechsRef = thisGMRef;
   myDir = STOP;




   // more actions to be included
   playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,
                       mainGameMechsRef->getBoardSizeY()/2,
                       '+');


   //need heap member
}


Player::~Player()
{
   // delete any heap members here
}


void Player::getPlayerPos(objPos &returnPos)
{
   // return the reference to the playerPos arrray list
   returnPos.setObjPos(playerPos.x,playerPos.y,playerPos.symbol);
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

   switch(myDir)
   {
       case UP:
           playerPos.y--;
           if (playerPos.y <= 0)
           {
               playerPos.y = y -2;
           }
           break;
      
      
       case LEFT:
           playerPos.x--;
           if (playerPos.x <= 0)
           {
               playerPos.x = x -2;
           }
           break;
       case DOWN:
           playerPos.y++;
           if (playerPos.y >= y -1)
           {
               playerPos.y = 1;
           }
           break;


       case RIGHT:
           playerPos.x++;
           if (playerPos.x >= x -1)
           {
               playerPos.x = 1;
           }
           break;
       default:
           break;
   }


   
   


}


