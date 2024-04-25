// Sinfully updating without permisson

#include <iostream>
using namespace std;

int version = 1;

bool login(){
    string username;
    string password;

    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if(username == "user" && password == "password"){ // would check a database for correct user
        return true;
    }
    else{
        return false;
    }
}

int main(){
    while(true){
        if(login()){
            cout << version << endl;
            cout << "Simulate logging out over the weekend, next time we log in the version number will increase because we automatically updated the system." << endl;
            version++;
        }
        else{
            cout << "Incorrect Login." << endl;
            exit(0);
        }
    }
}