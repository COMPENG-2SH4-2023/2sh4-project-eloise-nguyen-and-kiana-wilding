#include "GameMechs.h"
#include "MacUILib.h"
<<<<<<< HEAD


GameMechs::GameMechs()
{
   //Default game mode


   input = 0; //nothing comes in
   exitFlag = false;
   boardSizeX = 30;
   boardSizeY = 15;
   score = 0;
=======

GameMechs::GameMechs()
{
    //Default game mode 

    input = 0; //nothing comes in 
    exitFlag = false;
    boardSizeX = 30;
    boardSizeY = 15;
>>>>>>> 9326ca0dedc180c54a65b7726c964f6cd51bf2ab
}


GameMechs::GameMechs(int boardX, int boardY)
{
<<<<<<< HEAD
   input = 0; //nothing comes in
   exitFlag = false;
   boardSizeX = boardX;
   boardSizeY = boardY;
   score = 0;
}




=======
    input = 0; //nothing comes in 
    exitFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
}


>>>>>>> 9326ca0dedc180c54a65b7726c964f6cd51bf2ab
// do you need a destructor?

GameMechs::~GameMechs() //Destructor ( we don't need yet until there is a heap member
{
   //maybe myGM???
   //maybe myPlayer???
}


GameMechs::~GameMechs() //Destructor ( we don't need yet until there is a heap member
{
  //maybe myGM???
  //maybe myPlayer???
}






bool GameMechs::getExitFlagStatus()
{
<<<<<<< HEAD
   return exitFlag;
=======
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
>>>>>>> 9326ca0dedc180c54a65b7726c964f6cd51bf2ab
}


bool GameMechs::getLoseFlagStatus()
{
   return loseFlag;
}


char GameMechs::getInput()
{
<<<<<<< HEAD
   if(MacUILib_hasChar())
   {
       input = MacUILib_getChar();
   }


   return input;
=======
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }

    return input;
>>>>>>> 9326ca0dedc180c54a65b7726c964f6cd51bf2ab
}


int GameMechs::getBoardSizeX()
{
<<<<<<< HEAD
   return boardSizeX;
=======
    return boardSizeX;
>>>>>>> 9326ca0dedc180c54a65b7726c964f6cd51bf2ab
}


int GameMechs::getBoardSizeY()
{
<<<<<<< HEAD
   return boardSizeY;
}
char GameMechs::getScore()
{
   return score;
=======
    return boardSizeY;
}
char GameMechs::getScore()
{
    return score;
>>>>>>> 9326ca0dedc180c54a65b7726c964f6cd51bf2ab
}

void GameMechs::setExitTrue()
{
<<<<<<< HEAD
   exitFlag = true;
}


void GameMechs::setLoseFlag()
{
   loseFlag = true;
}
void GameMechs::setInput(char this_input)
{
   input = this_input;
=======
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}
void GameMechs::setInput(char this_input)
{
    input = this_input;
>>>>>>> 9326ca0dedc180c54a65b7726c964f6cd51bf2ab
}


void GameMechs::clearInput()
{
<<<<<<< HEAD
   input = 0;
}


void GameMechs::incrementScore()
{
   score++;
}
=======
    input = 0;
}

void GameMechs::incrementScore()
{
    score++;
}
>>>>>>> 9326ca0dedc180c54a65b7726c964f6cd51bf2ab
