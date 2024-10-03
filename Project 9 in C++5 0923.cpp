#include<iostream>
#include <cstdlib> 
#include<cassert>
#include <ctime>
using namespace std;
bool checkWinner(int& guess,int& secret,bool isComputer);
bool playerTurn(int&computerSecret);
bool computerTurn(int&computerSecret,int& playerSecret);



bool checkWinner(int& guess,int& secret,bool isComputer){
	if(isComputer){
	    cout<<"Computer guessed "<<guess<<endl;	
	}
	else{
		cout<<"User guessed "<<guess<<endl;	
	}
	
	if(guess==secret){
		cout<<"Correct"<<endl;
		return 1;
	}
	else{
		cout<<"Incorrect"<<endl;
		return 0;
	}
	
}

bool playerTurn(int&computerSecret){
	int guess;
	cout<<"Guess:";
	cin>>guess;	
	if(guess>computerSecret){
		cout<<"The guess is too high."<<endl;
	}
	else if(guess<computerSecret){
		cout<<"The guess is too low."<<endl;
	}
	if(guess==computerSecret){
		return 1;
	}
	else{
		return 0;
	}
}

/*have the computer make a guess at the player¡¦s secret and output whether the guess is correct,*/

/*If the guess is not correct, then this function should call the playerTurn function as the penultimate line of the
function.*/

/* The final line of the function should return true if a game winner has been found and
false if the game is continuing.*/

bool computerTurn(int&computerSecret,int& playerSecret){
	int guess=rand()%101;
	cout<<guess<<endl;
	if(guess>playerSecret){
		cout<<"The guess is too high."<<endl;
	}
	else if(guess<playerSecret){
		cout<<"The guess is too low."<<endl;
	}
	
	
	if(checkWinner(guess,playerSecret,1)){
			return 1;
		}	
		
	else if(playerTurn(computerSecret)){
		if(checkWinner(computerSecret,computerSecret,0)){
			return 1;
		}		
			}
		
	else{
			return 0;
		}
	}		



int main(){
	srand(time(NULL));
	int computerSecret=rand()%101;
	int playerSecret;
	cout<<"PlayerSecret:";
	cin>>playerSecret;
	
	while(1){
	   	if(computerTurn(computerSecret,playerSecret)==1){
	   		break;
		   }
	}
	
	
}
