#include "LoginFunctions.h"

User::User(string ID, string Name, string Email, string Phone, string Password) {
    id = ID;
    name = Name;
    email = Email;
    phone = Phone;
    password = Password;
};

User::User(string Name, string Email, string Password) {
    name = Name;
    email = Email;
    password = Password;
};

void getChoices() {

    int choice;

    cout << "Welcome to Our login System ! " << endl;

    while (true) {
        cout << "Enter your choice : " << endl;
        cout << "(1) Register " << endl;
        cout << "(2) Login " << endl;
        cout << "(3) Change Password " << endl;
        cout << "(4) Exit " << endl;

        cin >> choice;
        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            login();
        } else if (choice == 3) {
            changePassword();
        } else if (choice == 4) {
            cout << "Thanks for using Our login System, GoodBye " << endl;
            exit(0);
        } else {
            cout << "Wrong Choice !" << endl;
        }
    }
}

void registerUser() {

}

void login() {

}

void changePassword() {

}

// get index of character in string
int indexOf(string str, char character) {

    for (int i = 0; i < str.length(); i++) {

        if (character == str[i]) {
            return i;
        }

    }

    return 0;
}


string encrypt(string pass) {

    string encryptedPass;

    for (char c: pass) {

        // print spaces as is
        if (isalpha(c)) {
            // print the character by getting its index from the alphabet and using the index in the reverse alphabet
            // convert to upper case
            encryptedPass += alphabetReversed[indexOf(alphabet, toupper(c))];

        } else {
            encryptedPass += c;
        }

    }

    return encryptedPass;

}

string decrypt(string encryptedPass) {

    string pass;

    for (char c : encryptedPass) {

        // print spaces as is
        if (isalpha(c)) {
            // print the character by getting its index from the reversed alphabet and using the index in the alphabet
            // convert to upper case
            pass += alphabet[indexOf(alphabetReversed, toupper(c))];

        } else {
            pass += c;
        }

    }

    return pass;

}