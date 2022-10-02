#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/******************************************************************************
* This class contains all attributes and methods necessary to perform the login
* verification steps. The user may choose to create an account or attempt to
* log onto an already existing account.
******************************************************************************/
class loginManager {

private:
	
	// All necessary attributes for performing the credential verification.
	vector<string> userNames;
	vector<string> userPassWords;
	string userName;
	string userPassWord;
	string userNameAttempt;
	string passWordAttempt;

public:
	
	// The simple method for adding new usernames and passwords to the vectors
	// containing all login credentials.
	void createAccount()
	{
		cout << "Enter a username or email to identify your new account: ";
		cin >> userName;
		userNames.push_back(userName);
		cout << "Create a password for your account: ";
		cin >> userPassWord;
		userPassWords.push_back(userPassWord);
	}

	// The method that performs all steps to verify if the user has input a
	// correct username and password. The user is limited to 5 failed attempts.
	void loginAttempt()
	{
		int userNameIndex;
		int passWordIndex;
		int loginAttempts = 0;
		while (loginAttempts < 5)
		{
			cout << "Please enter your username: ";
			cin >> userNameAttempt;
			cout << "Please enter your password (Remember, passwords are CaSe SeNsItIvE): ";
			cin >> passWordAttempt;

			vector<string>::iterator itr = find(userNames.begin(), userNames.end(), userNameAttempt);
			if (itr != userNames.cend()) 
			{
				userNameIndex = distance(userNames.begin(), itr);

				vector<string>::iterator itr = find(userPassWords.begin(), userPassWords.end(), passWordAttempt);
				
				if (itr != userPassWords.cend())
				{
					passWordIndex = distance(userPassWords.begin(), itr);
					
					if (userNameIndex == passWordIndex)
					{
					cout << "\nYou have successfully logged in! Welcome " << userNameAttempt << endl;
					return;
					}
					
					else
					{
						cout << "\nUsername or password incorrect. Please try again." << endl;
					}
				}

				else
				{
					cout << "\nUsername or password incorrect. Please try again." << endl;
				}
			}

			else
			{
				cout << "\nUsername or password incorrect. Please try again." << endl;
			}
		}

		if (loginAttempts == 5)
		{
			cout << "\nToo many login attempts. Please try again later." << endl;
			return;
		}
	}
};

/******************************************************************************
* The main function initializes the loginManager class as an object and begins
* the program by allowing the user to select from a list of options. Based on
* their choice, a specific method from the loginManager class will be called.
******************************************************************************/
int main()
{
	loginManager login;

	int selection = 0;
	

	while (selection != 3)
	{
		cout << "\nWelcome to the account program! Please enter a number from the list below:" << endl;
		cout << "\n1) Create an account\n2) Attempt login\n3) Quit program" << endl;
		cout << "Enter selection here: ";
		cin >> selection;

		if (1 > selection > 3)
		{
			cout << "Invalid number. Please try again." << endl;
		}

		if (selection == 1)
		{
			login.createAccount();
			cout << "\nAccount created successfully!" << endl;
		}

		if (selection == 2)
		{
			login.loginAttempt();
		}

		if (selection == 3)
		{
			cout << "The program will now end. Have a nice day!" << endl;
		}
	}
}