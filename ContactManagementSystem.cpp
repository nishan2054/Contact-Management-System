#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

//Declaring global variables
string fName, lName, phoneNum;

//Functions

void addContact();
void searchContact();
void help();
void self_exit();
bool check_digits(string);
bool check_num(string);


int main()
{
    short int option;
    system("cls");
    system("color 0A");
    cout << "\n\n\n\t\t\tContact Management";
    cout << "\n\n\t 1. Add Contact\n\t 2. Search Contact\n\t 3. Help\n\t 4. Exit\n\t > ";
    cin >> option;

    switch(option)
    {

    case 1:
        addContact();
        break;
    case 2:
        searchContact();
        break;
    case 3:
        help();
        break;
    case 4:
        self_exit();
        break;
    default:
        cout << "\n\n\t Invalid Input !";
        cout << "Please any key to continue..";
        getch();
        main();
    }
    return 0;
}
void self_exit()
{
    system("Cls");
    cout << "\n\n\t\t\tThank you for using";
    exit(1);
}

void help()
{
    cout << "Help is on the way";

}
void addContact()
{
    ofstream phone("phoneNumber.txt", ios::app);
    system("cls");
    cout << "\n\n\tEnter First Name: ";
    cin >> fName;
    cout << "\n\tEnter Last Name: ";
    cin >> lName;
    cout << "\n\tEnter phone number: ";
    cin >>phoneNum;

    if(check_digits(phoneNum) == true)
    {
        if(check_num(phoneNum) == true)
        {
            if(phone.is_open())
            {
                    phone << fName << " " << lName << " " << phoneNum << endl;
                    cout << "\n\tContact Saved Successful";
            }
            else
            {
                cout << "\n\tError Opening File!";
            }
        }
        else{
            cout << "\n\t A Phone number must contain number only";
        }

    }
    else
    {
        cout << "\n\tPhone number must contain 10 digits";
    }
    phone.close();

}

void searchContact()
{
    bool found = true;
    ifstream myfile("phoneNumber.txt");
    string keyword;
    cout << "\n\tEnter Name To Search: ";
    cin >> keyword;
    while(myfile >> fName >> lName >> phoneNum)
    {
        if(keyword == fName || keyword == lName)
        {
            system("cls");
            cout << "\n\n\n\t\tContact details...";
            cout << "n\n\tFirst Name: " << fName;
            cout << "\n\tLast Name: " << lName;
            cout << "\n\tPhone Number: " << phoneNum;
            found = true;
            break;
        }
    }
    if(found==false)
        cout << "\n\tNo such contact is available";
}

bool check_digits(string x)
{
    if(x.length() == 10)
        return true;
    else
        return false;
}

bool check_num(string x)
{
    bool check = true;
    for(int i =0; i <x.length(); i++)
    {
        if(!(int(x[i]) >= 48 && int(x[i]) <= 57))
        {
            check = false;
            break;
        }
    }

    if(check == true)
        return true;
    if(check == false)
        return false;
}
