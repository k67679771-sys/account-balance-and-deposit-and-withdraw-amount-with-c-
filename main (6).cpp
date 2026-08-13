/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct account {
    int accountnumber;
    string accountname;
    double accountbalance;
};

void createaccount(vector<account>& accountlist) {
    int accountnumber;
    string accountname;
    double accountbalance = 0.0;
    cout << "account number\n";
    cin >> accountnumber;
    cin.ignore();

    cout << "account holder name:";
    getline(cin, accountname);

    cout << "enter starting balance:";
    cin >> accountbalance;
    if (accountbalance == 0) {
        cout << "Minimum starting balance is required !!\n";
    } else {
        cout << "your starting balance is added successfully!!\n";
        cout << "your starting balance is:" << accountbalance << "\n";
    }
    accountlist.push_back({accountnumber, accountname, accountbalance});
}

void viewaccount(const vector<account>& accountlist) {
    if (accountlist.empty()) {
        cout << "the list of accounts is empty!!\n";
        return;
    }
    if (!accountlist.empty()) {
        for (auto i = 0; i < accountlist.size(); i++) {
            cout << accountlist[i].accountnumber << " | ";
            cout << accountlist[i].accountname << " | ";
            cout << accountlist[i].accountbalance << "\n";
        }
    }
}

void amountdeposit(vector<account>& accountlist) {
    viewaccount(accountlist);
    if (accountlist.empty()) {
        cout << "account list is empty!! cannot deposit\n";
        return;
    }
    int accountnumber;
    cout << "enter the account number:";
    cin >> accountnumber;
    double deposit = 0.0;
    double total = 0.0;
    cout << "enter the amount to deposit minimum 200Rs:";
    cin >> deposit;
    if (deposit == 0) {
        deposit = 0;
        cout<<"you should deposit more then 0  money!!\n";
        return;
    }
    if(deposit<200){
        cout<<"deposit amount is not minimum!!\n";
    }
    
        for (auto i = 0; i < accountlist.size(); i++) {
            if (accountlist[i].accountnumber == accountnumber){
               if(deposit>=200){
                accountlist[i].accountbalance += deposit;
                total = accountlist[i].accountbalance;
                cout << "you have successfully deposited amount of " << deposit << "\n";
                cout << "your total is:" << total << "\n";
                return;
               }
            }
        }
            
                cout<<"your account number does not match!!\n";
            
}
    


void widthdrawamount(vector<account>& accountlist) {
    if (accountlist.empty()) {
        cout << "your account list is empty!!\n";
        return;
    }

    viewaccount(accountlist);
    int widthdraw;
    int accountnumber;
    double total;

    cout << "enter your account number: ";
    cin >> accountnumber;
    cout << "enter widthdrawal amount: ";
    cin >> widthdraw;
    if (widthdraw == 0) {
        cout << "invalid widthdrawal amount!!\n";
    } else {
        for (auto i = 0; i < accountlist.size(); i++) {
            if (accountlist[i].accountnumber == accountnumber) {
                accountlist[i].accountbalance -= widthdraw;
                total = accountlist[i].accountbalance;
                cout << "you have successfully widthdrawal amount of " << widthdraw << "\n";
                cout << "your balance after widthdrawal is " << total << "\n";
                return;
            }
        }
    }
    cout<<"your account number does not match!!\n";
}

int main() {
    vector<account> accountlist;
    int choice;
    cout << "***********************\n";
    cout << "welcome to kundu's bank\n";
    cout << "***********************\n";
    do {
        cout << "\n1.inital balance deposit\n";
        cout << "2.view account\n";
        cout << "3.money deposit\n";
        cout << "4.widthdraw money\n";
        cout << "5.exit menu\n";
        cout << "choose our choice (1 to 5):";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1: {
                createaccount(accountlist);
                break;
            }
            case 2: {
                viewaccount(accountlist);
                break;
            }
            case 3: {
                amountdeposit(accountlist);
                break;
            }
            case 4: {
                widthdrawamount(accountlist);
                break;
            }
            case 5: {
                cout << "thank your for visiting kundu's bank!!\n";
                break;
            }
            default: {
                cout << "you did not choose any of the options\n";
                break;
            }
        }
    } while (choice != 5);
    return 0;
}