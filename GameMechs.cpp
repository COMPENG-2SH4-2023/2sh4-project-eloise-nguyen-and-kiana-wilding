#include "GameMechs.h"
#include "MacUILib.h"




GameMechs::GameMechs()
{
   //Default game mode




   input = 0; //nothing comes in
   exitFlag = false;
   loseFlag = false;
   boardSizeX = 30;
   boardSizeY = 15;
   score = 0;
}




GameMechs::GameMechs(int boardX, int boardY)
{
   input = 0; //nothing comes in
   exitFlag = false;
   loseFlag = false;
   boardSizeX = boardX;
   boardSizeY = boardY;
   score = 0;
}








// do you need a destructor?




GameMechs::~GameMechs() //Destructor ( we don't need yet until there is a heap member
{
  //maybe myGM???
  //maybe myPlayer???
}












bool GameMechs::getExitFlagStatus()
{
   return exitFlag;
}




bool GameMechs::getLoseFlagStatus()
{
   return loseFlag;
}




char GameMechs::getInput()
{
   if(MacUILib_hasChar())
   {
       input = MacUILib_getChar();
   }




   return input;
}




int GameMechs::getBoardSizeX()
{
   return boardSizeX;
}




int GameMechs::getBoardSizeY()
{
   return boardSizeY;
}
char GameMechs::getScore()
{
   return score;
}




void GameMechs::setExitTrue()
{
   exitFlag = true;
}




void GameMechs::setLoseFlag()
{
   loseFlag = true;
}
void GameMechs::setInput(char this_input)
{
   input = this_input;
}




void GameMechs::clearInput()
{
   input = 0;
}




void GameMechs::incrementScore()
{
   score++;
}


