#include<iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#ifndef LOGINFUNCTIONS_H
#define LOGINFUNCTIONS_H

const string delPass = "#$#";
const int numberOfLinesForUser = 6;

struct User {
    string id = "20210";
    string name;
    string email;
    string phone;
    string password;
    vector<string> oldPasswords; // array separated by a delimiter

    inline User(string, string, string, string, string, vector<string>);

    inline User(string, string, string, string, string);

    inline User(string, string, string);

    inline User();

};

inline vector<User> listUsers;

inline vector<string> listIDs;

inline void getChoices();

inline void registerUser(User);

inline string login();

inline void changePassword();

inline string getPasswordAndCheck(bool changePassword);

inline User getUserByID(string id);

inline int indexOf(string str, char character);

// ---DO NOT CHANGE--- ALPHABET characters and reversed
const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string ALPHABET_REVERSED = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
// ---DO NOT CHANGE---

inline string encrypt(string pass);

inline string decrypt(string encryptedPass);

inline void makeListOfIDs();

inline void makeListOfUsers();

inline vector<string> convertStringToVector(string oldPass);

inline istream &operator>>(istream &, User);

#endif