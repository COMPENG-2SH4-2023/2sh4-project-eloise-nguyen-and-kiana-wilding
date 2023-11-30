#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;


#define DELAY_CONST 100000


//Global Variables
GameMechs *myGM;
Player *myPlayer;
objPos myPos;



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


    myGM = new GameMechs(26,16); //new heap
    myPlayer = new Player(myGM); //new heap
}

void GetInput(void)
{
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
}
