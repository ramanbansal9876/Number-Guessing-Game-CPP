#include<iostream>
using namespace std;
const int N = 10; //Fixing Number of Attempts in the beginning

int stringToInt(string str){
	int wrong = -1;
	int val = 0;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0' && str[i]<='9'){
			val = val*10 + (str[i]-'0');
		}
		else{
			return wrong;
		}
	}
	return val;
}


int main()
{
    cout<<"************************************** WELCOME TO 'Guess The Number' GAME **************************************\n";
    cout<<"In this game, you have to guess the auto generated random number between 1 and 100 (both inclusive). \n";
    cout<<"You have 10 chances to do so.\n\nLET'S PLAY!\n\n";
    begin:
		int number , attempt = 1;
		string dummy;
	    char choice;
	    number = rand()%100 + 1; //to generate random numbers between 1 and 100
	    int guess;
		do
	    {
	        cout<<"Attempt Number: "<<attempt<<"\nYour Guess: ";
	        getline(cin,dummy);
	        guess = stringToInt(dummy);

	        while(guess<0 || guess>100){
	        	cout<<"Invalid Input!! Try Again\nYour Guess: ";
	        	getline(cin,dummy);
	        	guess = stringToInt(dummy);
			}
	        if(guess==number)
	            cout<<"\n\nCONGRATULATIONS!! You have guessed the number correctly and have won this game!";
	        else if(number>guess)
	            cout<<"Try a greater number! \n\n";
	        else
	            cout<<"Try a lesser number!  \n\n";
	        ++attempt;
	    } while(attempt<=N && guess!=number);
		string c;
	    cout<<"\nDo you want to play again? (y/n) \n";
	    cout<<"Press any other key to exit the game: ";
		getline(cin,c);
	    if(c=="y"){
	    	cout<<"\n-------Restarting the Game-------\n\n";
	    	goto begin;
		}
		
		//Else program will terminate automatically!
	    return 0;
}
