#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
<<<<<<< HEAD
#include "Food.h"

=======
>>>>>>> 9326ca0dedc180c54a65b7726c964f6cd51bf2ab

using namespace std;


<<<<<<< HEAD


#define DELAY_CONST 100000




=======
#define DELAY_CONST 100000


>>>>>>> 9326ca0dedc180c54a65b7726c964f6cd51bf2ab
//Global Variables
GameMechs *myGM;
Player *myPlayer;
objPos myPos;
<<<<<<< HEAD
Food *myFood;




bool exitFlag;
=======


>>>>>>> 9326ca0dedc180c54a65b7726c964f6cd51bf2ab


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);






<<<<<<< HEAD






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



=======
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
>>>>>>> 9326ca0dedc180c54a65b7726c964f6cd51bf2ab


}

void Initialize(void)
{
   MacUILib_init();
   MacUILib_clearScreen();

<<<<<<< HEAD
   //score = 0;


   myGM = new GameMechs(30,15); //new heap
   myPlayer = new Player(myGM); //new heap
   myFood = new Food(myGM); //new heap

   srand(time(NULL));

   objPos tempPos;
   myPlayer->getPlayerPos(tempPos);
   myFood->generateFood(tempPos);

   //think about when to generate the new food...

   // remember generateFood() requires player reference. You will need to provide
   // it after player object is instantiated
=======

    myGM = new GameMechs(26,16); //new heap
    myPlayer = new Player(myGM); //new heap
>>>>>>> 9326ca0dedc180c54a65b7726c964f6cd51bf2ab
}


void GetInput(void)
{
<<<<<<< HEAD
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

   objPos tempPos;
   myPlayer->getPlayerPos(tempPos); //get the player pos.

   objPos foodPos;
   myFood->getFoodPos(foodPos);

   if(tempPos.isPosEqual(&foodPos))
   {
        myFood->generateFood(tempPos);
        myGM->incrementScore();
   }



   
//    objPos blockOff;
//    myFood->generateFood(blockOff);
//    //myFood->getFoodPos();


    myGM -> clearInput();
   
}




void DrawScreen(void)
{
   MacUILib_clearScreen();   
   int y, x;




   objPos tempPos;
   myPlayer->getPlayerPos(tempPos); //get the player pos.

   objPos foodPos;
   myFood->getFoodPos(foodPos);
   
   MacUILib_printf("Controls: 'w' = Up,'a' = Left, 's' = Down, 'd' = Right\nPress ESC to exit game\n");

   for(y = 0; y < myGM -> getBoardSizeY(); y++)
   {
       for(x = 0; x < myGM -> getBoardSizeX(); x++)
       {
           char printChar = ' ';


           if(y == 0 || x == 0 || x == myGM -> getBoardSizeX() - 1|| y == myGM -> getBoardSizeY() - 1)
           {
               printChar = '#';
           }
           else if(y == tempPos.y && x == tempPos.x)
           {
              printChar = tempPos.symbol;
             
           }
           else if(y == foodPos.y && x == foodPos.x)
           {
              printChar = foodPos.symbol;
           }
           MacUILib_printf("%c", printChar);
       }
       MacUILib_printf("\n");
   }

   MacUILib_printf("BoardSize: %dx%d\nPlayer Pos: <%d, %d>\nCharacter: %c\nScore: %d\n",
                   myGM->getBoardSizeX(), myGM->getBoardSizeY(),
                   tempPos.x, tempPos.y, tempPos.symbol, myGM->getScore());
=======
   myGM -> getInput();
}


void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    myGM -> clearInput();
}


void DrawScreen(void)
{
    MacUILib_clearScreen();    
 
    int y, x;


    objPos tempPos;
    myPlayer->getPlayerPos(tempPos); //get the player pos.


   MacUILib_printf("BoardSize: %dx%d, Player Pos: <%d, %d>, Character: %c\n", 
                    myGM->getBoardSizeX(), myGM->getBoardSizeY(),
                    tempPos.x, tempPos.y, tempPos.symbol);

    for(y = 0; y < myGM -> getBoardSizeY(); y++)
    {
        for(x = 0; x < myGM -> getBoardSizeX(); x++)
        {
            char printChar = ' ';

            if(y == 0 || x == 0 || x == myGM -> getBoardSizeX() - 1|| y == myGM -> getBoardSizeY() - 1)
            {
                printChar = '#';
            }
            else if(y == tempPos.y && x == tempPos.x)
            {
               printChar = tempPos.symbol;
               
            }
            MacUILib_printf("%c", printChar);
        }
        MacUILib_printf("\n");
    }
>>>>>>> 9326ca0dedc180c54a65b7726c964f6cd51bf2ab


}


void LoopDelay(void)
{
   MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

<<<<<<< HEAD
void CleanUp(void)
{
   MacUILib_clearScreen();   
   MacUILib_uninit();




   delete myGM;
   delete myPlayer;
   delete myFood;
=======



void CleanUp(void)
{
    MacUILib_clearScreen();    
 
    MacUILib_uninit();


    delete myGM;
    delete myPlayer;
>>>>>>> 9326ca0dedc180c54a65b7726c964f6cd51bf2ab
}


