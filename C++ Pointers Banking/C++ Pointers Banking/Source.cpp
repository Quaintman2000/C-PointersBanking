#include <iostream>
#include <string>

using namespace std;

//declare functions
void DisplayMemoryLocation(string* s);
void DisplayMemoryLocation(int* i);
string InputCommand();
void DisplayValue(int* i);
void DisplayValue(string* s);
void Deposit20(int* i);
void Withdraw20(int* i);

int main() 
{
	//program title
	cout << "\t\t** C++ Pointers Banking **\n\n";
	//Variables
	int moneyAmount = 10455;
	string accountCode = "A5AWDW8161GER6T12";

	//Their pointers
	int* p_moneyAmount = &moneyAmount;
	string* p_accountCode = &accountCode;

	//The program will keep looking for function keywords unless type QUIT
	while (true) 
	{
		string answer;
		//get command
		cout << "\nPlease enter a command:" << endl;
		cout << "Commands:'Check Location', 'Check Value', 'Deposit', 'Withdraw', 'Quit'." << endl;
		answer = InputCommand();
		
		//call function based on command inputed
		if (answer == "QUIT")
		{
			//end program
			return 0;
		}
		else if (answer == "CHECK LOCATION")
		{
			//ask what he wants to check
			cout << "\nSure, what do you want to find?" << endl;
			cout << "Account Balance or Account Code?" << endl;
			string thingToCheck = InputCommand();
			
			//find the thing the user wants to check
			if (thingToCheck == "ACCOUNT BALANCE")
			{
				//display info
				cout << "\nLocation on file: " << p_moneyAmount << endl;
				DisplayMemoryLocation(p_moneyAmount);
			}
			else if (thingToCheck == "ACCOUNT CODE")
			{
				//display info
				cout << "\nLocation on file: " << p_accountCode << endl;
				DisplayMemoryLocation(p_accountCode);
			}
			else
			{
				//display info
				cout << "\nInvalid command. Please try again." << endl;
			}
		}
		else if (answer == "CHECK VALUE")
		{
			cout << "\nSure, what do you want to check?" << endl;
			cout << "Account Balance or Account Code?" << endl;
			string thingToCheck = InputCommand();

			//find the thing the user wants to check
			if (thingToCheck == "ACCOUNT BALANCE")
			{
				//display info
				cout << "\nValue on file: " << *p_moneyAmount << endl;
				DisplayValue(p_moneyAmount);
			}
			else if (thingToCheck == "ACCOUNT CODE")
			{
				//display info
				cout << "\nValue on file: " << *p_accountCode << endl;
				DisplayValue(p_accountCode);
			}
			else
			{
				//display info
				cout << "\nInvalid command. Please try again." << endl;
			}
		}
		else if (answer == "DEPOSIT")
		{
			//show what it was
			cout << "\nYour balance was: $" << *p_moneyAmount << endl;
			//add $20
			Deposit20(p_moneyAmount);
			//show new value
			DisplayValue(p_moneyAmount);
		}
		else if (answer == "WITHDRAW")
		{
			//show what it was
			cout << "\nYour balance was: $" << *p_moneyAmount << endl;
			//subtract $20
			Withdraw20(p_moneyAmount);
			//show new value
			DisplayValue(p_moneyAmount);
		}
		//if input was an invalid command
		else
		{
			//ask them to try again
			cout << "\nInvalid command. Please try again and make sure your spelling is correct" << endl;
		}
	}
}

///display the memory location for the string pointed
void DisplayMemoryLocation(string* s)
{
	cout << "I double checked using the function and I found that it's stored here: " << s <<  " in your computer's memory" << endl;
}
//display the memory location for the integer pointed
void DisplayMemoryLocation(int* i)
{
	cout << "I double checked using the function and I found that it's stored here: " << i << " in your computer's memory" << endl;
}
//recieves commands and converts them to caps
string InputCommand()
{
	string answer;
	getline(cin, answer);

	//make the answer caps to make it easier to read
	for (int i = 0; i < answer.length(); i++)
	{
		answer[i] = toupper(answer[i]);
	}

	return answer;
}
//displays the vale of the integer pointed
void DisplayValue(int* i)
{
	cout << "Your current balance by checking with the function is: $" << *i << endl;
}
//displays the vale of the string pointed
void DisplayValue(string* s)
{
	cout << "Your account code by checking with the function is: " << *s << endl;
}
//adds $20 to the account via pointer
void Deposit20(int* i)
{
	cout << "Deposited $20 into your account." << endl;
	*i += 20;
}
//subtracts $20 from the account via pointer
void Withdraw20(int* i)
{
	cout << "Withdrawed $20 from your account" << endl;
	*i -= 20;
}