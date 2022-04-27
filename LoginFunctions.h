#include<iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#ifndef LOGINFUNCTIONS_H
#define LOGINFUNCTIONS_H

// ---DO NOT CHANGE--- alphabet characters and reversed
static char *const alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static char *const alphabetReversed = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
// ---DO NOT CHANGE---

const string delPass = "#*#";

struct User {
    string id = "20210";
    string name;
    string email;
    string phone;
    string password;
    vector<string> oldPasswords; // array separated by a delimiter
    int passwordTrials;

    inline User(string, string, string, string, string, vector<string>, int);

    inline User(string, string, string, string, string);

    inline User(string, string, string);
};

inline vector<string> listUsers;

inline vector<string> listIDs;

inline void getChoices();

inline void registerUser();

inline void login();

inline void changePassword();

inline int indexOf(string str, char character);

inline string encrypt(string pass);

inline string decrypt(string encryptedPass);

inline void makeListOfIDs();

inline void makeListOfUsers();

#endif