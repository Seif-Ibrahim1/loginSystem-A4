#include "LoginFunctions.h"

// Main constructor
User::User(string ID, string Name, string Email, string Phone, string Password, vector<string> OldPasswords) {
    id = ID;
    name = Name;
    email = Email;
    phone = Phone;
    password = Password;
    oldPasswords = OldPasswords;
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

User::User() {

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
            cin >> User();
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

void registerUser(User human) {

    fstream userDataFile("UsersData.txt", ios::app);

    string userData = human.id + '\n';
    userData += human.name + '\n';
    userData += human.email + '\n';
    userData += human.phone + '\n';
    userData += human.password + '\n';
    userData += human.password;

    for (int i = 0; i < userData.length(); i++) {
        userDataFile.put(userData[i]);
    }

    userDataFile.put('\n');
    userDataFile.close();

}

string login() {

    string id = "";
    string password;

    bool validUser = false;

    int failedTrials = 0;

    while (!validUser) {

        if (failedTrials == 3) {

            cout << "You are deprived from accessing the system" << endl << endl;
            break;

        }

        cout << "Please enter your ID :" << endl;
        cin >> id;

        for (string ID: listIDs) {

            if (id == ID) {

                cout << "Please enter your password : " << endl;
                cin >> password;

                User userToLogin = getUserByID(id);

                if (userToLogin.name == "" || userToLogin.password == "" || userToLogin.email == "") {
                    continue;
                }

                if (userToLogin.password == password) {

                    cout << "Successful login, welcome " + userToLogin.name << endl << endl;
                    validUser = true;
                    continue;

                } else {
                    failedTrials += 1;
                    id = "";
                    cout << "Failed login. Try again." << endl;
                }

                break;

            }

        }

    }

    return id;

}

void changePassword() {

    string userID = login();

    if (!userID.empty()) {

        User currentUser = getUserByID(userID);

        string oldPassword;
        string newPassword;
        string newPassword2;

        cout << "You want to change your password," << endl;
        cout << "Please enter your OLD password :" << endl;
        cin >> oldPassword;

        // check if added before
        while (true) {

            bool validNewPassword = true;

            newPassword = getPasswordAndCheck(true);

            for (string pass: currentUser.oldPasswords) {
                if (newPassword == pass) {
                    validNewPassword = false;
                    break;
                }
            }

            while (newPassword2 != newPassword){

                newPassword2 = getPasswordAndCheck(true);

            }

            if (validNewPassword) {
                break;
            }

        }

        int userIndex = getUserIndexByID(userID);
        if (userIndex != -1) {

            listUsers[userIndex].password = newPassword;
            listUsers[userIndex].oldPasswords.push_back(newPassword);

            // add all users to file
            if (saveAllUsersToFile()) {

                cout << "Password changed successfully !" << endl;

            }

        }

    }

}

string getPasswordAndCheck(bool changePassword) {

    string password;

    bool invalidPassword = true;

    cin.ignore();
    while (invalidPassword) {
        if (changePassword) {
            cout << "Please enter your NEW password :" << endl;
        } else {
            cout << "Enter your Password :" << endl;
        }


        // logic goes here
        getline(cin, password);

        regex lowercase("[a-z]+.*");
        regex uppercase("[A-Z]+.*");
        regex numbers("[0-9]+.*");
        string specialChars = " !@#$%^&*()_+-=?<>|\\/,~`;:[]{}";



        if(password.length() >= 8)
        {
            if(regex_search(password, lowercase) && regex_search(password, uppercase)
                && regex_search(password, lowercase) && contains(password, specialChars))
            {
                invalidPassword = false; 
                break;
            }
        }

        cout << "invalid password ! " << endl;
        
    }

    return password;

}

bool saveAllUsersToFile() {

    string userData;

    fstream userDataFile("UsersData.txt", ios::out);

    for (User user: listUsers) {

        userData += user.id + '\n';
        userData += user.name + '\n';
        userData += user.email + '\n';
        userData += user.phone + '\n';
        userData += user.password + '\n';
        userData += convertVectorToString(user.oldPasswords) + '\n';

    }

    for (char c: userData) {

        userDataFile.put(c);

    }

    userDataFile.close();

    return true;

}

User getUserByID(string id) {

    for (User user: listUsers) {

        if (user.id == id) {
            return user;
        }

    }

    return listUsers[0];
}

int getUserIndexByID(string id) {

    for (int i = 0; i < listUsers.size(); ++i) {

        if (listUsers[i].id == id) {
            return i;
        }

    }

    return -1;

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

bool contains(string text, string characters){

    for (int i = 0; i < text.length(); ++i) {

        for (int j = 0; j < characters.length(); ++j) {

            if (text[i] == characters[j]){
                return true;
            }

        }

    }

    return false;

}

string encrypt(string pass) {

    string encryptedPass;

    for (char c: pass) {

        // print spaces as is
        if (isalpha(c)) {
            // print the character by getting its index from the ALPHABET and using the index in the reverse ALPHABET
            // convert to upper case
            encryptedPass += ALPHABET_REVERSED[indexOf(ALPHABET, toupper(c))];

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
            // print the character by getting its index from the reversed ALPHABET and using the index in the ALPHABET
            // convert to upper case
            pass += ALPHABET[indexOf(ALPHABET_REVERSED, toupper(c))];

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

        if (lineNumber % numberOfLinesForUser == 1) {
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

    while (!userDataFile.eof()) {

        lineNumber++;

        userDataFile.getline(line, 50);

        if (lineNumber % numberOfLinesForUser == 1) {
            id = line;
        } else if (lineNumber % numberOfLinesForUser == 2) {
            name = line;
        } else if (lineNumber % numberOfLinesForUser == 3) {
            email = line;
        } else if (lineNumber % numberOfLinesForUser == 4) {
            phone = line;
        } else if (lineNumber % numberOfLinesForUser == 5) {
            password = line;
        } else if (lineNumber % numberOfLinesForUser == 0) {
            oldPasswords = convertStringToVector(line);
        }

        if (counter == numberOfLinesForUser) {

            User user = User(id, name, email, phone, password, oldPasswords);

            listUsers.push_back(user);

            counter = 0;

        }


        counter++;
    }
    userDataFile.close();

}

string convertVectorToString(vector<string> oldPasswords) {

    string oldPasswordsString = "";

    for (string pass: oldPasswords) {

        oldPasswordsString += pass + delPass;

    }

    return oldPasswordsString;

}

vector<string> convertStringToVector(string oldPass) {

    vector<string> oldPasswords;

    int dilem = oldPass.find(delPass);

    string currentPass;

    while (true) {

        if (dilem != -1) {
            currentPass = oldPass.substr(0, dilem);

            oldPasswords.push_back(currentPass);

            oldPass = oldPass.substr(dilem + 3, oldPass.length() - 1);

            dilem = oldPass.find(delPass);
        } else {
            break;
        }

    }

    return oldPasswords;
}

istream &operator>>(istream &read, User human) {

    string id;
    string name;
    string email;
    string phone;
    string password;

    while (true) {

        bool validUserForRegistration = true;

        cout << "Enter your ID" << endl;
        read >> id;

        for (string uID: listIDs) {
            if (id == uID) {
                validUserForRegistration = false;
                break;
            }
        }


        if (validUserForRegistration) {
            break;
        }

    }

    cout << "Enter your Name" << endl;
    read >> name;
    cout << "Enter your Email" << endl;
    read >> email;
    cout << "Enter your Phone Number" << endl;
    read >> phone;

    cout << "Note that password  must be at least 8 characters" << endl;
    cout << "Must contain at least one lowecase character" << endl;
    cout << "at least one uppercase character " << endl;
    cout << "at least one special character" << endl;
    cout << "at least one number" << endl;

    password = getPasswordAndCheck(false);

    human.id = id;
    human.name = name;
    human.email = email;
    human.phone = phone;
    human.password = password;

    registerUser(human);

    return read;
}
