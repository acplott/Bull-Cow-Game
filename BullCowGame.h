/* The game logic (no view code or direct user interaction)
The game is a simple guess the word game based on Mastermind.
*/

#pragma once
#include <string>

using FString = std::string; //conforms to unreal standards
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
};

class FBullCowGame
{
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;

	void Reset(); 
	EGuessStatus CheckGuessValidity(FString) const; 

	//counts bulls and cows and increases try #, assuming valid guess
	FBullCowCount SubmitValidGuess(FString);


private:
	int32 MyMaxTries;
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsLowerCase(FString) const;
	bool IsIsogram(FString) const;

};
