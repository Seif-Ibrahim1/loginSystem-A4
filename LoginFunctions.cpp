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

User::User(){

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
    userData += human.password +'\n';
    userData += human.password +'\n';
    userData += "0 ";


    for(int i = 0; i < userData.length(); i++)
    {
        userDataFile.put(userData[i]);
    }

    userDataFile.put('\n');
    userDataFile.close();

}

void login() {

    string id;
    string password;

    bool validUser = false;

    while (!validUser){

        cout << "Please enter your ID :" << endl;
        cin >> id;

        cout << "Please enter your password : " << endl;
        cin >> password;

        User userToLogin = getUserByID(id);

        if (userToLogin.name == "" || userToLogin.password == "" || userToLogin.email == ""){
            continue;
        }

        if (userToLogin.password == password){

            cout << "Successful login, welcome " + userToLogin.name << endl << endl;
            validUser = true;
            continue;

        }else{
            cout << "Failed login. Try again." << endl;
        }

    }

}

void changePassword() {

}

User getUserByID(string id){

    for (User user: listUsers) {

        if (user.id == id){
            return user;
        }

    }

    return listUsers[0];
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

        if (lineNumber % 7 == 1) {
            id = line;
        } else if (lineNumber % 7 == 2) {
            name = line;
        } else if (lineNumber % 7 == 3) {
            email = line;
        } else if (lineNumber % 7 == 4) {
            phone = line;
        } else if (lineNumber % 7 == 5) {
            password = line;
        } else if (lineNumber % 7 == 6) {
            oldPasswords = convertStringToVector(line);
        } else if (lineNumber % 7 == 0) {
            passwordTrials = stoi(to_string(line[0])) - 48;
        }

        if (counter == 7) {

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

    if (dilem != -1){
        string firstPass = oldPass.substr(0, dilem);

        oldPasswords.push_back(firstPass);

        oldPass = oldPass.substr(dilem + 3, oldPass.length() - 1);

        dilem = oldPass.find(delPass);

        if (dilem != -1) {

            string secondPass = oldPass.substr(0, dilem);

            oldPasswords.push_back(secondPass);

            oldPass = oldPass.substr(dilem + 3, oldPass.length() - 1);

            dilem = oldPass.find(delPass);

            if (dilem != -1) {

                string thirdPass = oldPass.substr(0, dilem);

                oldPasswords.push_back(thirdPass);

            }

        }

    }



    return oldPasswords;
}

istream& operator>> (istream&read, User human){

    string id;
    string name;
    string email;
    string phone;
    string password;

    cout << "Enter an ID : " << endl;
    read >> id;

    cout << "Enter a name : " << endl;
    read >> name;

    cout << "Enter an email : " << endl;
    read >> email;

    cout << "Enter a phone : " << endl;
    read >> phone;

    cout << "Enter a password : " << endl;
    read >> password;

    human.id = id;
    human.name = name;
    human.email = email;
    human.phone = phone;
    human.password = password;

    registerUser(human);

    return read;
}