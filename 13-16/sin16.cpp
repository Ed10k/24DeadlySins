//Permissions
#include <iostream>
#include <fstream>
using namespace std;

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

string low(){
    return "This requires low permissions so nothing is needed for this to run";
}

string high(){
    string text;
    string returnText;
    ifstream file;
    file.open("sample.txt");
    if(file.is_open()){
        while(!file.eof()){
            file >> text;
            returnText += text + " ";
        }
    }
    return returnText;
}

int main(){
    if(login()){
        string input;
        while(true){
            cout << "low permission (1)\nhigh Permission (2)\n Exit (3)";
            cin >> input;
            switch (stoi(input))
            {
            case 1: // poor usability would check credentials AGAIN before running this command
                cout << low() << endl;
                break;
            case 2: 
                cout << high() << endl;
                break;
            case 3:
                exit(0);
            
            default:
                break;
            }

        }
    }
    else{
        cout << "Incorrect login" << endl;
        exit(0);
    }
}