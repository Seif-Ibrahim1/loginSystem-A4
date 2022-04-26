#include<iostream>
using namespace std;

#ifndef LOGINFUNCTIONS_H
#define LOGINFUNCTIONS_H

const string delPass = "#*#";

struct User
{
    string id = "20210";
    string name;
    string email;
    string password;
    string oldPasswords; // array separated by a delimiter

    inline User(string, string, string, string);
    inline User(string, string, string);
};


#endif