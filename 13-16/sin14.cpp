//Poor usability

#include <iostream>
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

int add(){
    string valOne;
    string valTwo;

    cout << "value 1: ";
    cin >> valOne;
    cout << "value 2: ";
    cin >> valTwo;

    return stoi(valOne) + stoi(valTwo);
}

int subtract(){
    string valOne;
    string valTwo;

    cout << "value 1: ";
    cin >> valOne;
    cout << "value 2: ";
    cin >> valTwo;

    return stoi(valOne) - stoi(valTwo);
}

int multiply(){
    string valOne;
    string valTwo;

    cout << "value 1: ";
    cin >> valOne;
    cout << "value 2: ";
    cin >> valTwo;

    return stoi(valOne) * stoi(valTwo);
}

int divide(){
    string valOne;
    string valTwo;

    cout << "value 1: ";
    cin >> valOne;
    cout << "value 2: ";
    cin >> valTwo;

    return stoi(valOne) / stoi(valTwo);
}

int main(){
    if(login()){ // verify user then allow access to values
        string input;
        while(true){
            cout << "Add (1)\n Subtract (2)\n Multiply (3)\n Divide (4)\n Exit (5)";
            cin >> input;
            switch (stoi(input))
            {
            case 1: // poor usability would check credentials AGAIN before running this command
                cout << add() << endl;
                break;
            case 2: 
                cout << subtract() << endl;
                break;
            case 3: 
                cout << multiply() << endl;
                break;
            case 4: 
                cout << divide() << endl;
                break;
            case 5: 
                exit(0);
            
            default:
                break;
            }

        }
    }
    else{
        cout << "Invalid credentials!" << endl;
    }

    return 0;
}