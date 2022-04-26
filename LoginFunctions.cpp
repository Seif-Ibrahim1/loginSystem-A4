#include "LoginFunctions.h"

User::User(string ID, string Name, string Email, string Password){
    id = ID;
    name = Name;
    email = Email;
    password = Password;
}

User::User(string Name, string Email, string Password){
    name = Name;
    email = Email;
    password = Password;
}
