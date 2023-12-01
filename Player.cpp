#include "Player.h"
#include "MacUILib.h"
<<<<<<< HEAD


=======
>>>>>>> 9326ca0dedc180c54a65b7726c964f6cd51bf2ab


Player::Player(GameMechs* thisGMRef)
{
   mainGameMechsRef = thisGMRef;
   myDir = STOP;

<<<<<<< HEAD



   // more actions to be included
   playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,
                       mainGameMechsRef->getBoardSizeY()/2,
                       '+');


   //need heap member
}
=======
>>>>>>> 9326ca0dedc180c54a65b7726c964f6cd51bf2ab

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,
                        mainGameMechsRef->getBoardSizeY()/2,
                        '*');

    //need heap member
}

Player::~Player()
{
   // delete any heap members here
}


void Player::getPlayerPos(objPos &returnPos)
{
<<<<<<< HEAD
   // return the reference to the playerPos arrray list
   returnPos.setObjPos(playerPos.x,playerPos.y,playerPos.symbol);
=======
    // return the reference to the playerPos arrray list
    returnPos.setObjPos(playerPos.x,playerPos.y,playerPos.symbol);
>>>>>>> 9326ca0dedc180c54a65b7726c964f6cd51bf2ab
}


void Player::updatePlayerDir()
{
<<<<<<< HEAD
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
=======
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
>>>>>>> 9326ca0dedc180c54a65b7726c964f6cd51bf2ab
}


void Player::movePlayer()
{
<<<<<<< HEAD
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


=======
    // PPA3 Finite State Machine logic
    int x = mainGameMechsRef->getBoardSizeX();
    int y = mainGameMechsRef->getBoardSizeY();

    switch(myDir)
    { 
        case UP:
            playerPos.x--;
            if (playerPos.x <= 0)
            {
                playerPos.x = x -2;
            }
            break;
        
        
        case LEFT: 
            playerPos.y--;
            if (playerPos.y <= 0)
            {
                playerPos.y = y -2;
            }
            break;
        case DOWN: 
            playerPos.x++;
            if (playerPos.x >= x -1)
            {
                playerPos.x = 1;
            }
            break;

        case RIGHT:
            playerPos.y++;
            if (playerPos.y >= y -1)
            {
                playerPos.y = 1;
            }
            break;
        default:
            break;
    }

}
>>>>>>> 9326ca0dedc180c54a65b7726c964f6cd51bf2ab
