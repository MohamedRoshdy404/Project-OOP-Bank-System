#pragma once
#include <iostream>
#include <iomanip>
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "Global.h"
#include "clsUser.h"


class clsLoginScreen : protected clsScreen
{

private:

	static bool _Login()
	{

		short FaildLoginCount = 0;

		bool loginFaild = false;

		string Username, Password;
		do
		{
				if (loginFaild)
				{
					FaildLoginCount++;
					cout << "\nInvalaid Username/Password!";
					cout << "\nYou have [ " << (3 - FaildLoginCount) << " ]" << endl;
					//_sleep(1000);
				}

				if (FaildLoginCount == 3)
				{
					cout << "You are not authorized to access the system. Please contact the admin personally to solve the problem." << endl;
					return false;
				}

				cout << "\nEnter Username? ";
				cin >> Username;

				cout << "\nEnter Password? ";
				cin >> Password;

				CurrentUser = clsUser::Find(Username, Password);

				loginFaild = CurrentUser.IsEmpty();


		} while (loginFaild);

		cout << "\a";
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true;
	}


public:


	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}


};

