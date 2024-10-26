

#include <iostream>
#include <string>
#include <Windows.h>
#include <deque>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

//This is for the user infomation it works like a Loop
void reInputUserName();
void reInputPasword();
void checkUserNameAndPassword();
void isThisAUser();


//Checks The players Name And Password
string playerUserName;
string playerPassword;
int notUser = 0;
//Throws a Check to see if the user and Password is Right 
bool NotRightUsers;
bool rightPassword;
bool rightUserName;

int main()
{
	
	//Gets info from the player
	SetConsoleTextAttribute(h, 1);
	cout << "Welcome To CBT MMORPG ONLINE" << endl;
	cout << "Please Enter Your CBT UserName?" << endl;
	cin >> playerUserName;
	
	cout << "Please Enter You CBT Password" << endl;
	cin >> playerPassword;
	


	//Checks to see if the info is right with A Catch Statement
	checkUserNameAndPassword();

	isThisAUser();


}

//Has the player ReEnter There UserName
void reInputUserName()
{
	SetConsoleTextAttribute(h, 1);
	cout << "Please Enter Your CBT UserName?" << endl;
	cin >> playerUserName;

}
//Has the player ReEnter There Password
void reInputPasword()
{
	SetConsoleTextAttribute(h, 1);
	cout << "Please Enter You CBT Password" << endl;
	cin >> playerPassword;
}

//This Function Is where all my Try and Catch Statements are Mostly 
void checkUserNameAndPassword(){
	//This Try Checks to see if the user Put in The right UserName, Can be modified to be a ifStream
	try {
		if (playerUserName.compare(0, 9, "GamerName") != 0)
		{
			throw invalid_argument("Error: User Name Isn't Correct");
		}
		else
		{
			rightUserName = true;
		}

	}
	//If its wrong it Throws this error and Adds to the try counter And Lets the player try again. up to 4 tries
	catch (const invalid_argument& e)
	{
		SetConsoleTextAttribute(h, 4);
		cout << e.what() << endl;
		rightUserName = false;
		notUser++;

		if (notUser < 3)
		{
			reInputUserName();
		}
	}


	//This Try Checks to see if the user Put in The right password, Can be modified to be a ifStream
	try {
		if (playerPassword.compare(0, 10, "ILoveGames") != 0)
		{

			throw invalid_argument("Password Isn't Correct");
		}
		else
		{
			rightPassword = true;
		}

	}
	//If its wrong it Throws this error and Adds to the try counter And Lets the player try again. up to 4 tries
	catch (const invalid_argument& e)
	{
		SetConsoleTextAttribute(h, 4);
		cout << e.what() << endl;
		rightPassword = false;
		notUser++;

		if (notUser < 3)
		{
			reInputPasword();
		}
	}


}
//This is The final Checks to see if the user is getting into the game
void isThisAUser()
{
	//First It allows the user To Try Again if they haven't use all there tries
	checkUserNameAndPassword();
	//Then it try and see if the user name or the password is both correct
	try {


		if (!rightPassword || !rightUserName)
		{
			SetConsoleTextAttribute(h, 4);
			throw runtime_error("This is not a Valid User.");

		}
		

	}
	//If they are not both correct  the user doesnt get in
	catch (runtime_error& e)
	{
		SetConsoleTextAttribute(h, 4);
		cout << e.what() << endl;
	}
	//If they are The user gets in
	if (rightPassword && rightUserName)
	{
		SetConsoleTextAttribute(h, 5);
		cout << "Welcome user! Please Enjoy the game!" << endl;
	}
}