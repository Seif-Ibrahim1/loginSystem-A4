#include "LoginFunctions.h"

// Main constructor
User::User(string ID, string Name, string Email, string Phone, string Password, vector<string> OldPasswords,
           int PasswordTrials) {
    id = ID;
    name = Name;
    email = Email;
    phone = Phone;
    password = Password;
    oldPasswords = OldPasswords;
    passwordTrials = PasswordTrials;
};

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
}

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

    // Helpful for writing in file
//    fstream userDataFile("UsersData.txt", ios::app);
//    char ch;
//
//    while (true)
//    {
//        cin.get(ch);
//        userDataFile.put(ch);
//        if (ch == '.')
//            break;
//    }
//    userDataFile.close();


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

    for (char c: encryptedPass) {

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

void makeListOfIDs() {
    fstream userDataFile("UsersData.txt", ios::app | ios::in);
    char name[50];

    int lineNumber = 0;
    int counter = 1; // not used yet

    while (!userDataFile.eof()) {

        lineNumber++;

        userDataFile.getline(name, 50);

        if (lineNumber % 8 == 1) {
            listIDs.push_back(name);
        }

        counter++;
    }
    userDataFile.close();

}

void makeListOfUsers() {
    fstream userDataFile("UsersData.txt", ios::app | ios::in);
    char line[50];

    int lineNumber = 0;
    int counter = 1; // not used yet

    string id = "20210";
    string name;
    string email;
    string phone;
    string password;
    vector<string> oldPasswords; // array separated by a delimiter
    int passwordTrials;

    while (!userDataFile.eof()) {

        lineNumber++;

        userDataFile.getline(line, 50);

        if (lineNumber % 8 == 1) {
            id = line;
        } else if (lineNumber % 8 == 2) {
            name = line;
        } else if (lineNumber % 8 == 3) {
            email = line;
        } else if (lineNumber % 8 == 4) {
            phone = line;
        } else if (lineNumber % 8 == 5) {
            password = line;
        } else if (lineNumber % 8 == 6) {
            oldPasswords = convertStringToVector(line);
        } else if (lineNumber % 8 == 7) {
            passwordTrials = stoi(line);
        }

        if (counter == 8) {

            User user = User(id, name, email, phone, password, oldPasswords, passwordTrials);

            listUsers.push_back(user);

            counter = 0;

        }


        counter++;
    }
    userDataFile.close();

}

vector<string> convertStringToVector(string oldPass) {

    vector<string> oldPasswords;

    int dilem = oldPass.find(delPass);

    string firstPass = oldPass.substr(0, dilem);

    oldPasswords.push_back(firstPass);

    oldPass = oldPass.substr(dilem + 3, oldPass.length() - 1);

    dilem = oldPass.find(delPass);

    string secondPass = oldPass.substr(0, dilem);

    oldPasswords.push_back(secondPass);

    oldPass = oldPass.substr(dilem + 3, oldPass.length() - 1);

    dilem = oldPass.find(delPass);

    string thirdPass = oldPass.substr(0, dilem);

    oldPasswords.push_back(thirdPass);

    return oldPasswords;
}