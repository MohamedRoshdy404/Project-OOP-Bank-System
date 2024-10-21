#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
class clsTransferLog : protected clsScreen
{


private:

    static void PrintTransferLogRecordeLine(clsBankClient::stTransferLogRecord Client)
    {
        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.DateTime;
        cout << "| " << setw(12) << left << Client.SourceAccountNumber;
        cout << "| " << setw(40) << left << Client.DestBalanceAfter;
    }


public:



	static void ShowTransferLog()
	{


        vector <clsBankClient::stTransferLogRecord> vClients = clsBankClient::GetTransfersLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;

        cout << setw(10) << left << "" << "| " << left << setw(15) << "Date/Time";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;


        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord &Client : vClients)
            {
                PrintTransferLogRecordeLine(Client);
                cout << endl;
            }

        cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
        cout << "__________________________\n" << endl;


	}



};

