#include <iostream>
#include "clsLoginScreen.h"
#include "clsDate.h"

int main()
{

	
	while (true)
	{
		system("Color 73");		
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}

	}


    return 0;
}