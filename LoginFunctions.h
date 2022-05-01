#include<iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>
#include <conio.h>

using namespace std;

#ifndef LOGINFUNCTIONS_H
#define LOGINFUNCTIONS_H

// ---DO NOT CHANGE--- ALPHABET characters and reversed
const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string ALPHABET_REVERSED = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
const string ALPHABET_LOWER = "abcdefghijklmnopqrstuvwxyz";
const string ALPHABET_REVERSED_LOWER = "zyxwvutsrqponmlkjihgfedcba";
// ---DO NOT CHANGE---

const string delPass = "#$#";
const int numberOfLinesForUser = 6;

struct User {
    string id;
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

inline string hideAndGetPassword();

inline string getPasswordAndCheck(int type);

inline bool saveAllUsersToFile();

inline User getUserByID(string id);

inline int getUserIndexByID(string id);

inline int indexOf(string str, char character);

inline bool contains(string text, string characters);

inline string encrypt(string pass);

inline string decrypt(string encryptedPass);

inline void makeListOfIDs();

inline void makeListOfUsers();

inline string convertVectorToString(vector<string> oldPasswords);

inline vector<string> convertStringToVector(string oldPass);

inline istream &operator>>(istream &, User);

inline string hideAndGetPassword();

#endif