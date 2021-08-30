/*  
 Hang_Person 

 NAME: Kate Walley
 DATE: July 27, 2021

 PURPOSE: This program will play the game hang person
 where one player enters in a word and the other player(s)
 attempt to guess it before the hang person
 is fully drawn. 
 */

#include <iostream>
#include <conio.h>								
using namespace std;

//Prototypes
void find_answer(char answer[11]);																	//Get the answer word from one player
void picture_display(int wrong_guesses);															//Draws the hang person baised on the number of wrong guesses there have been
bool letter_finder(char letter, char answer[11]);												//Sees if the letter the player guesses is in the word 
void show_letters(char letter, char answer[11], bool see_letters[11]);			//Shows the blanks and the correctly guessed letters

int main(void)
{
	char answer[11];			//The answer word (11 spots to allow for 10 letters and an EOS character)
	char letter;						//Letter the player guesses
	bool see_letters[11];		//Will allow us to see the letters that have been correctly guessed
	char play_again;			//Allows the user to play the game again
	int wrong_guesses;		//Number of wrong guesses the user has made
	int i,k,j;							//Loop counters
	char used_letter[11];		//The letters that have already been used
	int guesses;					//The number of guesses the user has made
	int counter;						//Spot counter for the used letters
	bool done;						//Keeps track if the word has been correctly guessed yet
	int amount;						//Tracks the amount of correctly guessed letters
	int answer_length;			//Tracks the length of the answer
	char copy[11];				//Answer copy to see if the user has correctly guessed the word

	//Welcom message
	cout << "Welcome to HangPerson the fun word guessing game fit for the whole family !" << endl;
	cout << endl;

	//Initialize
	amount = 0;
	do
	{
		//Initialize
		guesses = 0;
		counter = 0;
	
		//Get the word to guess from player 1
		find_answer(answer);
		answer_length = 0;
		//Find the length of the answer
		for (i = 0; answer[i] != '\r';i++)
		{
			answer_length++;
		}//for
		//Initialize
		wrong_guesses = 0;
		//Set all spots to false
		for (i = 0; i < 11; i++)
		{
			see_letters[i] = false;
		}//for
		done = false;
		//Reset all the used letters
		for (i = 0; i < 11; i++)
		{
			used_letter[i] = '\0';
		}//for
		do
		{
			//Set play again to a non-existant value
			play_again = '\0';
			//Have player 2 guess the word	cout << "Enter a letter to guess ";
			cout << "Enter a letter to guess: ";
			letter = toupper(_getwche());
			cout << endl;
			//Initalize
			k = 0;
			//Loop to find any letters that have been guessed twice 
			for (j = 0; j < 11; j++)
			{
				for (i = 0; i < 100; i++)
				{
					while ((letter == used_letter[i]) || (letter == used_letter[k]))
					{
						cout << "You've already guessed " << letter << " please enter a new letter: ";
						letter = toupper(_getwche());
						cout << endl;
						k++;
					} //while
				}//for
			}//for
			//Enter in the newly guessed letter
			used_letter[counter] = letter;
			show_letters(letter, answer, see_letters);
			//Give the user the results of their guess
			if (letter_finder(letter, answer) != true)
			{
				cout << "There are no " << letter << " 's" << endl;
				wrong_guesses++;
				picture_display(wrong_guesses);
			}//if
			//Set the amount of correctly guessed letters to zero
			amount = 0;
			for (i = 0; i < 11; i++)
			{
				if (see_letters[i] == true)
				{
					copy[i] = letter;
					amount++;
				}//if
			}//for
			//See if the user has got the word correct
			if (amount==answer_length)
			{
				if (strncmp(answer, copy, 10) != 0)
				{
					done = true;
				}//if
			}//if
			//Up date the number of guesses the user has made
			guesses++;
			//Print out the used letters
			cout << "Used Letters : ";
			for (i = 0;i<guesses; i++)
			{
				cout << used_letter[i]<<" ";
			}//for
			cout << endl;
			counter++;
		} while ((wrong_guesses<6)&&(done!=true));
		//If the user wins print this message
		if (wrong_guesses < 6)
		{
			cout << "You got it! ";
		}//if
		//If the user loses print this message
		else
		{
			cout << "Nice try but you lost! ";
		}//else
		//Tell the user what the word was
		cout << "The word was : ";
		for (i = 0; answer[i] != '\r'; i++)
		{
			cout << answer[i]<<" ";
		}//for
		cout << endl;
		//Ask if they want to play again
		cout << "Would like to play again? (Y)es/(N)o: ";
		play_again = toupper(_getwche());
		cout << endl;
		//Validate
		while (play_again != 'Y'&&play_again != 'N')
		{
			cout << "Invalid choice! Would like to play again? (Y)es/(N)o: ";
			play_again = toupper(_getwche());
			cout << endl;
		}//while
	} while (play_again == 'Y');
	//Print goodbye message
	cout << "Thanks for 'hanging out' and playing this game!" << endl;
	return 0;
}//Main 


/* find_answer - This method will get the answer word that players will try to guess and will star it out 
   on the screen so it is not visible. The parameter answer is what the players will attempt to guess.
*/
void find_answer(char answer[11])
{
	int i;			//Loop counter

	//Get the user to enter in the answer word and then star it out
	cout << "Enter the answer word (max 10 letters): ";
	for (i = 0; ((i <= 10) && (answer[i-1] != '\r')); i++)
	{
		answer[i] = toupper(_getwch());
		if (answer[i] != '\r')
		{
			cout << "*";
		}//if
	}//for
	cout << endl;
}//find_answer


/* picture_display - This method draw the hang person baised on the number of wrong guesses.
   The parameter wrong_guesses is the number of wrong guesses the user has made.
*/
void picture_display(int wrong_guesses)			
{
		switch (wrong_guesses)
		{
		case 1:cout << " o " << endl;
			cout << "5 more wrong guesses allowed" <<endl; break;
		case 2:cout << " o " << endl;
			cout << " | " << endl;
			cout << "4 more wrong guesses allowed" << endl; break;
			case 3:cout << "   o " << endl;
				cout << " - | " << endl; 
				cout << "3 more wrong guesses allowed" << endl; break;
			case 4:cout << "  o " << endl;
				cout << " -|- " << endl; 
				cout << "2 more wrong guesses allowed" << endl; break;
			case 5:cout <<  "   o " << endl;
				cout << "  -|- " << endl;
				cout << "  (" << endl;
				cout << "1 more wrong guess allowed" << endl; break;
			case 6:cout <<  "  o " << endl;
				cout << " -|- " << endl;
				cout << " ( )" << endl; 
				cout << "No more guessing allowed" << endl; break;
		}//switch
}//picture_display

/* letter_finder - This method sees if the letter the player guesses is in the word.
   The parameter letter is what the player has guessed and answer is what the player
   is trying to guess.
*/
bool letter_finder(char letter, char answer[11])
{
	int i;								//Loop counter
	int num_correct;		//Number of letters in the word that match the guessed letter

	//Initialize
	num_correct = 0;

	//Loop to find matching letters to the guessed letter
	for (i = 0; answer[i] != '\r'; i++)
	{
		if (answer[i] == letter)
		{
			num_correct++;
		}//if 
	}//for

	if (num_correct > 0)
	{
		//If there was a matching letter
		return true;
	}//if
	else
	{
		//If there were no matching letters
		return false;
	}//else
}//letter_finder

/*show letters - This method shows the blanks and the correctly guessed letters.
  The parameter letter is the player's guess, answer is the what the player is
  attempting to guess and see_letters allows us to see the correctly guessed letters.
*/
void show_letters(char letter, char answer[11], bool  see_letters[11])
{
	int i;			//Loop counter

	//Print out the word so far
	cout << "The word is : ";
		for (i = 0; answer[i] != '\r'; i++)
		{
			if (answer[i] == letter)
			{
				see_letters[i] = true;
			}//if 
		}//for
		for (i = 0; answer[i] != '\r'; i++)
		{
			if (see_letters[i] == true)
			{
				cout << " " << answer[i] << " ";
			}//if
			else
			{
				cout << " _ ";
			}//else
		}//for
		cout << endl;
}//show_letters 