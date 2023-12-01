#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
#include "objPosArrayList.h"




using namespace std;








#define DELAY_CONST 100000








//Global Variables
GameMechs *myGM;
Player *myPlayer;
objPos myPos;
Food *myFood;








bool exitFlag;




void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);
























int main(void)
{




   Initialize();




   while(myGM->getExitFlagStatus() == false)
   {
       GetInput();
       RunLogic();
       DrawScreen();
       LoopDelay();
   }








   CleanUp();








}




void Initialize(void)
{
   MacUILib_init();
   MacUILib_clearScreen();


   //score = 0;




   myGM = new GameMechs(30,15); //new heap
   myPlayer = new Player(myGM); //new heap
   myFood = new Food(myGM); //new heap


   srand(time(NULL));


   //objPos tempPos{-1,-1,'o'};
   myPlayer->getPlayerPos(tempPos);
   myFood->generateFood(tempPos);


   //think about when to generate the new food...


   // remember generateFood() requires player reference. You will need to provide
   // it after player object is instantiated
}




void GetInput(void)
{
  myGM -> getInput();
}








void RunLogic(void)
{
   myPlayer->updatePlayerDir();
   myPlayer->movePlayer();


   
   
//    objPos returnPlayerPos;
//    myPlayer->getPlayerPos(returnPlayerPos)


//    objPos FoodPos;
//    myFood->getFoodPos(FoodPos);


   // objPos tempPos;
   // myPlayer->getPlayerPos(tempPos); //get the player pos.


   // objPos foodPos;
   // myFood->getFoodPos(foodPos);


   // if(tempPos.isPosEqual(&foodPos))
   // {
   //      myFood->generateFood(tempPos);
   //      myGM->incrementScore();
   // }






   
//    objPos blockOff;
//    myFood->generateFood(blockOff);
//    //myFood->getFoodPos();




    myGM -> clearInput();
   
}








void DrawScreen(void)
{
   MacUILib_clearScreen();  
   int y, x;

   objPosArrayList* playerBody = myPlayer->getPlayerPos();
   objPos tempBody;
   bool drawn; 

   // objPos tempPos;
   // myPlayer->getPlayerPos(tempPos); //get the player pos.


   objPos tempFoodPos;
   myFood->getFoodPos(tempFoodPos);
   
   MacUILib_printf("Controls: Press 'w' for Up, Press 'a' for Left, Press 's' for Down, Press 'd' Right\nPress ESC to exit game\n");


   for(y = 0; y < myGM -> getBoardSizeY(); y++)
   {
      for(x = 0; x < myGM -> getBoardSizeX(); x++)
      {
         drawn = false;
         char printChar = ' ';
         for(int k =0; k < playerBody->getSize(); k++)
         {
            playerBody->getElement(tempBody,k);
            if(tempBody.x == x && tempBody.y == y)
            {
               MacUILib_printf("%c",tempBody.symbol);
               drawn= true;
               break;
   
            }
         }

         if(drawn) continue;


         if(y == 0 || x == 0 || x == myGM -> getBoardSizeX() - 1|| y == myGM -> getBoardSizeY() - 1)
         {
            printChar = '#';
         }
         else if(y == tempFoodPos.y && x == tempFoodPos.x)
         {
            printChar =  tempFoodPos.symbol;
         }
         MacUILib_printf("%c", printChar);
      }
      MacUILib_printf("\n");
   }
   

   // MacUILib_printf("BoardSize: %dx%d\nPlayer Pos: <%d, %d>\nCharacter: %c\nScore: %d\n",
   //                 myGM->getBoardSizeX(), myGM->getBoardSizeY(),
   //                 tempPos.x, tempPos.y, tempPos.symbol, myGM->getScore());
   MacUILib_printf("Score: %d\n", myGM->getScore());
   MacUILib_printf("Player positions:\n");
   for(int l =0; l <playerBody->getSize(); l++)
   {
      playerBody->getElement(tempBody,l);
      MacUILib_printf("<%d,%d>",tempBody.x,tempBody.y);
   }

   MacUILib_printf("Food position: <%d,%d>\n",tempFoodPos.x, tempFoodPos.y);
   



}


void LoopDelay(void)
{
   MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
   MacUILib_clearScreen();  
   MacUILib_uninit();








   delete myGM;
   delete myPlayer;
   delete myFood;
}



