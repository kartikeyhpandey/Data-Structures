// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the CARDGAME_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// CARDGAME_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CARDGAME_EXPORTS
#define CARDGAME_API __declspec(dllexport)
#else
#define CARDGAME_API __declspec(dllimport)
#endif

// This class is exported from the dll
class CARDGAME_API CCardGame {
public:
	CCardGame(void);
	// TODO: add your methods here.
};

extern CARDGAME_API int nCardGame;

CARDGAME_API int fnCardGame(void);
