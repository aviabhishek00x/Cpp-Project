#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>
using namespace std;
int password_user() // Employee Authentication
{
    string pass_reg = "";
    string name_reg = "";
    string pass = "";
    string name = "";
    fstream file;
    char ch;
    system("CLS");
    cout << "\n\t\t\t -------------------------------------------";
    cout << "\n\t\t\t||  WELCOME TO EMPLOYEE MANAGEMENT SYSTEM  ||";
    cout << "\n\t\t\t -------------------------------------------";
    cout << "\n\n\t\t\t   -| Press: [1] Register & [2] Login  |-";
    int selection;
    cout << "\n\nPlease Enter Value: ";
    cin >> selection;
    // if user press [1], then it would lead them to register.
    if (selection == 1)
    {
        system("CLS");
        cout << "\n\t\t\t\t\t---------------------------";
        cout << "\n\t\t\t\t\t>> REGISTRATION EMPLOYEE <<";
        cout << "\n\t\t\t\t\t---------------------------";
        cout << "\n\n\t\t\t\t\tEnter Your Name: ";
        cin >> name_reg;
        cout << "\n\t\t\t\t\tEnter Your Password: ";
        ch = getch();
        // this whileloop used for while typing password convert that in star.
        while (ch != 13)
        {
            pass_reg.push_back(ch);
            cout << '*';
            ch = getch();
        }
        file.open("test_login.txt", ios::app);
        file << " " << name_reg << " " << pass_reg << "\n";
        file.close();
        cout << "\nRegistration Succesfully save";
        // getch();
        password_user();
    }
    // if user press [2], then it would lead them to login.
    else if (selection == 2)
    {
        system("CLS");
        file.open("test_login.txt", ios::in);
        cout << "\n\t\t\t\t\t--------------------";
        cout << "\n\t\t\t\t\t>> LOGIN EMPLOYEE <<";
        cout << "\n\t\t\t\t\t--------------------";
        cout << "\n\n\t\t\t\t\tEnter Your Name: ";
        cin >> name;
        cout << "\n\t\t\t\t\tEnter Your Password: ";
        ch = getch();
         // this whileloop used for while typing password convert that in star.
        while (ch != 13)
        {
            pass.push_back(ch);
            cout << '*';
            ch = getch();
        }
        file >> name_reg >> pass_reg;
        while (!file.eof())
        {
            if (pass == pass_reg && name == name_reg)
            {
                cout << "\n\n\n\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t";
                for (int a = 1; a < 4; a++)
                {
                    Sleep(500);
                    cout << "...";
                }
                cout << "\n\nAccess Granted..\n\n";
                system("PAUSE");
            }
            else
            {
                cout << "\n\n\n\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t";
                for (int a = 1; a < 4; a++)
                {
                    Sleep(500);
                    cout << "...";
                }
                cout << "\n\nAccess Aborted...\n\n";
                system("PAUSE");
                system("CLS");
                password_user();
            }
            file >> name_reg >> pass_reg;
        }
        file.close();
    }
    else
    {
        cout << "\nInvalid Input.. Please Try Again..";
        password_user();
    }
    return 0;
}
int main()
{
    password_user();
    return 0;
}
