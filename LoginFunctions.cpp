#include "LoginFunctions.h"

User::User(string ID, string Name, string Email, string Password){
    id = ID;
    name = Name;
    email = Email;
    password = Password;
};

User::User(string Name, string Email, string Password){
    name = Name;
    email = Email;
    password = Password;
};

void getChoices(){

    int choice;

    while(true){
        cout << "Welcome to Our login System ! " << endl;
        cout << "Enter your choice : " << endl;
        cout << "(1) Register " << endl;
        cout << "(2) Login " << endl;
        cout << "(3) Change Password " << endl;
        cout << "(4) Exit " << endl;

        cin >> choice;
        if(choice == 1){
            Register();
        }
        else if(choice == 2){
            login();
        }
        else if(choice == 3){
            changePassword();
        }
        else if(choice == 4){
            cout << "Thanks for using Our login System, GoodBye " << endl;
            exit(0);
        }
        else{
            cout << "Wrong Choice !" << endl;
        }
    }
}

void Register(){

}

void login(){

}

void changePassword(){

}

