#ifndef PLAYER_H
#define PLAYER_H




#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"




class Player
{
   // Construct the remaining declaration from the project manual.




   // Only some sample members are included here




   // You will include more data members and member functions to complete your design.




   public:
       enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state




       Player(GameMechs* thisGMRef);
       ~Player();




       void getPlayerPos(objPos &returnPos); // Upgrade this in iteration 3.
       void updatePlayerDir();
       void movePlayer();




   private:
       objPos playerPos;   // Upgrade this in iteration 3.      
       enum Dir myDir;




       // Need a reference to the Main Game Mechanisms
       GameMechs* mainGameMechsRef;
};




#endif


objPos.h 

#ifndef OBJPOS_H
#define OBJPOS_H




class objPos
{
   public:
       int x;
       int y;
       char symbol;




       objPos();
       objPos(objPos &o); // copy constructor
       objPos(int xPos, int yPos, char sym);




       void setObjPos(objPos o);      
       void setObjPos(int xPos, int yPos, char sym);
       void getObjPos(objPos &returnPos);
       char getSymbol();




       bool isPosEqual(const objPos* refPos);
     
       char getSymbolIfPosEqual(const objPos* refPos);
};




#endif


