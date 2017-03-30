#pragma once 

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void printIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; // Instantiate a new game.

int main()
{
	bool bPlayAgain = false; 
	do 
  {
		printIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
  } 
	while (bPlayAgain);
	return 0;
}

void printIntro()
{
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n";
	return;
}

void PlayGame()
{
	BCGame.Reset();
	
	int32 MaxTries = BCGame.GetMaxTries();
	

	//Loop for the number of turns asking for guesses.
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}
	PrintGameSummary();
	return;
}

FText GetValidGuess() // loop until player gives a valid guess.
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "\nTry " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << " Enter your guess: ";
		std::getline(std::cin, Guess);
		Status = BCGame.CheckGuessValidity(Guess);
		
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram.\n\n";
			break;
		
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n\n";
			break;
		
		default:
			break;
		}
	} while (Status != EGuessStatus::OK);
	
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	return (Response[0] == 'y') || (Response[0] == 'Y');
	
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Congratulations, you've won!\n";
	}
	else
	{
		std::cout << "Sorry, you didn't guess the isogram... Better luck next time!\n";
	}
}
