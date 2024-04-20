#include <iostream>
#include <string>
using namespace std;
class BankAccount
{
private:
    static const int MAX_ACCOUNTS = 1000;
    struct Account
    {
        string number;
        string password;
        string name;
        double balance;
    };
    Account accounts[MAX_ACCOUNTS];
    int accountCount=4;
    int changeACnumber = 0;
public:
    BankAccount()
    {
        initializeAccounts();

    }

    void initializeAccounts()
    {
        accounts[0] = {"01406501", "Rafi014", "Tahamid hasan rafi", 500000};
        accounts[1] = {"01795561", "Alvi017", "Alvi hasan", 401235};
        accounts[2] = {"01909419", "Hasib019", "Hasibul santo", 300000};
        accounts[3] = {"01630200", "Kamrul016", "Kamrul Hasan", 256321};
}
    void getData()
    {
        string response;
        cout << "---WELCOME NUB BANK---\nDo you have any Account in this bank?\n"
             << "yes\n"
             << "or\n"
             << "no\n";
        cin >> response;

        if (response == "yes" || response == "YES" || response == "Yes")
        {
            getExistingAccountData();
        }
        else if (response == "no" || response == "No" || response == "NO")
        {
            createNewAccount();
        }
        else
            {
            cout << "Type 'yes' or 'no'\n:";

            getData();
            }
    }

    void getExistingAccountData()
    {
        string enteredNumber, enteredPassword;

        cout << "Enter your AC number:";
        cin >> enteredNumber;

        cout << "Enter your Password:";
        cin >> enteredPassword;

        matchData(enteredNumber, enteredPassword);
    }

    void createNewAccount()
    {
        changeACnumber=changeACnumber+188;


        if (accountCount < MAX_ACCOUNTS)
        {
            int nid;
            int phone;
            string NomineeName;
            int NomineePhone;
            int index = accountCount;

            cout << "Enter your name:";
            cin >> ws;
            getline(cin, accounts[index].name);

            cout << "Enter your password:";
            cin >> accounts[index].password;
            cout << "Enter your phone number:";
            cin>>phone;
            cout << "Enter your NID number:";
            cin>>nid;
            cout << "Enter your nominee name:";
            cin >> ws;
            getline(cin, NomineeName);
            cout << "Enter your nominee phone number:";
            cin>>NomineePhone;

            accounts[index].number = generateAccountNumber();
            accounts[index].balance = 0;

            cout << "\n-After creating a new account-\n"
                 << "AC number: " << accounts[index].number << "\n"
                 << "AC name: " << accounts[index].name << "\n"
                 << "AC password: " << accounts[index].password << "\n"
                 << "New account balance: " << accounts[index].balance << "\n";

            deposit(index);


            cout << "-----THANK YOU!-----\n";
             accountCount= accountCount+1;
            getData();
        }
        else
        {
            cout << "Can't create a new account. Maximum limit you have reached.\n";
        }
    }

  string generateAccountNumber()
    {
        return "1" + to_string(changeACnumber) + "000";
    }
void handleTransaction(int accountIndex)
    {
        string transactionType;
        cout << "Your AC number: " << accounts[accountIndex].number << "\n"
             << "Your AC name: " << accounts[accountIndex].name << "\n"
             << "Your Balance: $" << accounts[accountIndex].balance << "\n";

        cout << "What do you want?\n"
             << "1) Withdraw\n"
             << "2) Deposit\n"
             << "3) Transfer\n"
             << "type 1 , 2 or 3:\n ";
        cin >> transactionType;

        if (transactionType == "1")
        {
            withdraw(accountIndex);
        }
        else if (transactionType == "2")
        {
            deposit(accountIndex);
        }
        else if (transactionType == "3")
        {
            string transferid;
            cout << "Enter transfer AC Number:\n";
            cin>>transferid;
            matchData(transferid, accountIndex, accounts[accountIndex].balance );

        }
        else
        {
            cout << "Invalid transaction type: Please type '1' for withdrawal or '2' for deposit and '3' for transfer \n";
            handleTransaction(accountIndex);
        }
    }
  void deposit(int accountIndex)
    {
        double amount;
        cout << "For new account :If you want to deposit then type 'd': ";
        char response;
        cin >> response;

        if (response == 'd' || response == 'D')
        {
            cout << "How much?";
            cin >> amount;

            if (amount > 0)
            {
                accounts[accountIndex].balance += amount;
                cout << "Deposit successful ! New balance: $" << accounts[accountIndex].balance << "\n";
            }
            else
            {
                cout << "\nInvalid deposit amount : Amount must be greater than 0.\n";
            }
        }
    }

    void matchData(string enteredNumber, string enteredPassword)
    {
        for (int i = 0; i < accountCount; i++)
        {
            if (enteredNumber == accounts[i].number && enteredPassword == accounts[i].password)
            {
                handleTransaction(i);
                return;
            }
        }

        cout << "Account number and password do not match !! \n";
        cout << "Enter valid AC number and password:\n";
        getExistingAccountData();
    }

    int matchData(string enteredNumber, int acid, double y)
    {
        int e=0;
        double t;
        for (int i = 0; i < accountCount; i++)
        {
            if (enteredNumber == accounts[i].number)
            {
                cout << "Transfer AC match! AC name:\n"<<accounts[i].name<<" \n Enter your transfer amount:";
                cin>>t;
                if(t>=0 && t<=y)
                {transfer(enteredNumber, acid, y, t);
                e++;
                }
                else
                    cout << "Amount must be grater then 0 and less then Main amount.";

            }

        }
        while(e==0)
        {
           cout << "No Account in this bank !!\n";
           e++;
        }


    }

    void withdraw(int accountIndex)
    {
        double amount;
        cout << "How much?";
        cin >> amount;

        if (amount > 0 && amount <= accounts[accountIndex].balance)
        {
            accounts[accountIndex].balance -= amount;
            cout << "Withdrawal successful ! \n New balance: $" << accounts[accountIndex].balance << "\n";
        }
        else
        {
            cout << "\nInvalid withdrawal amount. Amount must be greater than 0 and less than or equal to the balance.\n";
        }
    }
    void transfer(string accountIndex, int acid, double u, double q)
 {


            cout << "Transfer successful!\n Now your balance: "<<u-q;

 }
};

int main()
{
    BankAccount B;
    B.getData();
    return 0;
}
