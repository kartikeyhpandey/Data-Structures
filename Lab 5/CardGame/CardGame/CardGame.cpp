// CardGame.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "CardGame.h"


// This is an example of an exported variable
CARDGAME_API int nCardGame=0;

// This is an example of an exported function.
CARDGAME_API int fnCardGame(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CCardGame::CCardGame()
{
    return;
}
