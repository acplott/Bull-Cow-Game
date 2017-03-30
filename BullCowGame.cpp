
#pragma once

#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}


void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet"; // this MUST be an isgram
	MyHiddenWord = HIDDEN_WORD;
	
	constexpr int32 CURRENT_TRY = 1;
	MyCurrentTry = CURRENT_TRY;
	bGameIsWon = false;
	return;
}

int32 FBullCowGame::GetMaxTries() const 
{
	
	TMap<int32, int32> WordLengthToMaxTries{ { 3,5 }, { 4,6 }, { 5,6 }, {6,6}, {7,7}, { 8,7 }, { 9,7 }, { 10,8 } };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (! IsIsogram(Guess)) // if guess is not an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess)) // if guess isn't lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) // if guess is the wrong length
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}

}

// recieved a valid guess
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();
	
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{
			if (Guess [GChar] == MyHiddenWord [MHWChar] ) 
			{
				if (MHWChar == GChar)
				{
					BullCowCount.Bulls++;
				}

				else
				{
					BullCowCount.Cows++;
				}

			}

		}
	}
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word)
		if (!islower(Letter))
		{
			return false;
		}
		
	return true;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }
	
	TMap<char, bool> LetterSeen; //setup our map.
	for (auto Letter : Word)
	{
		Letter = tolower(Letter); // handle mixed case letters.
		if (LetterSeen[Letter]) // if the letter is in the map.
		{
			return false; // we do NOT have an isogram.
		}
		else
		{
			LetterSeen[Letter] = true; // add the letter to the map as seen.
		}
	}
	
	return true;

}
