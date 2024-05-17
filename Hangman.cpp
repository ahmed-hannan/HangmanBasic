#include<iostream> //i22-0943 Ahmed Hannan CS-A
using namespace std;

int main(){
	const int size =100;
	const int size1 = 30;
	const int size2 = size/2 +1;
	char words[size] = {};
	char let;
	char guess_t[size]={};
	bool found = 0,guessed = 0,c_guess=0;
	int count = 0, num_words = 0,location = 0,j = 0, correct = 0, wrong = 0,iter=0;
	char word[size2]={};
	char guess[size1]={};
	
	
	cout<<"Welcome to hangman"<<endl;
	cout << "Enter list of words, seperated by a comma, all lowercase"<<endl;
	cin>>words;
	//getting input
	
	for(int i=0;i<size;i++) //calculating the number of words
	{
		if(words[i] == '\0')
		{
			num_words+=1;
			break;
		}
		
		if(words[i] == ',')
		{
			num_words+=1;
		}
	}
	
	count =0;

	for(int k=0; k<num_words;k++) //seperation of words based off of ,
	{
		j=0;
		count =0;
		correct=0;
		wrong =0;
		for(int i =location; i<size;i++)
		{
			
			if(words[i] == ',' || words[i] == '\0')
			{
				break;
			}
		
			else
			{
				word[j] = words[i];
				count +=1;
				j++;
				
			}
		}
		word[count] = '\0';
		
		for(int j =0; j<size1;j++)
		{
			guess[j] = '_';
			guess_t[j]='_';
		}
		guess[count] = '\0';
		guess_t[count]='\0';
		
		location += count+1;
		
		
		iter =0;
		while(correct<count)
		{
			
			
			do{ //asking for input until user enters a character that isnt already guessed
				guessed = 0;
				found = 0;
				cout << "Enter a letter to guess"<<endl;
				cin  >> let;
				
					for(int m=0;m<size1;m++)
					{
						if(let == guess_t[m]) guessed=1;
					}		
				
			}while(guessed);
			
			for(int i =0; i<count ; i++)
			{
				if(word[i] == let)
					{
						correct++;
						guess[i] = let;
						guess_t[iter] = let;
						iter++;
						found =1;
					}
			}
			if(!found)
			{
				
				guess_t[iter] = let;
				iter++;
			}
			cout<<"\tIncorrect guesses till now are -> ";
			for(int v =0; v<iter;v++)
			{	
				c_guess=0;
				for (int w =0; w<count;w++)
				{
					if(guess_t[v] == guess[w])
					{
						c_guess = 1;
						
					}
				}
				if(!c_guess)
				{
					cout<<guess_t[v];//displaying incorrect guesses till now
				}
			}
			cout<<endl;
			cout<< "\tThe word -> " << guess<<endl; //displaying the guessed parts to make it visible for the user 
			
			if(!found)
			{
				wrong++;
			}
			
			if(wrong==1) //the seven stages of hangman/woman hangit
			{
				cout<<"    +---+\n    |   |\n\t|\n\t|\n\t|\n\t|\n  ========="<<endl;
			
			}
		
			else if(wrong ==2)
			{
				cout<<"    +---+\n    |   |\n    0   |\n\t|\n\t|\n\t|\n  ========="<<endl;
			}
			
			else if(wrong ==3)
			{
				cout<<"    +---+\n    |   |\n    0   |\n    |   |\n\t|\n\t|\n  ========="<<endl;
			}
			
			else if(wrong ==4)
			{
				cout<<"    +---+\n    |   |\n    0   |\n   /|   |\n\t|\n\t|\n  ========="<<endl;
			}
			
			else if(wrong ==5)
			{
				cout<<"    +---+\n    |   |\n    0   |\n   /|\\  |\n\t|\n\t|\n  ========="<<endl;
			}
			
			else if(wrong ==6)
			{
				cout<<"    +---+\n    |   |\n    0   |\n   /|\\  |\n   /    |\n\t|\n  ========="<<endl;
			}
			
			
			if(wrong ==7)
			{
				cout<<"    +---+\n    |   |\n    0   |\n   /|\\  |\n   / \\  |\n\t|\n  ========="<<endl;
				cout<<"You have used up all your lives better luck next time, word was = " << word <<endl;
				return 0;
				
			}
		}			
	}




return 0;
}
