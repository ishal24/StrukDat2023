#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Register(ofstream& file){
    string username, password;

    cout << "=====USER LOGIN=====\n";

    cout << "Enter your username: ";
    getline(cin, username);

    cout << "Enter your password: ";
    getline(cin, password);

    file << "username: " << username << endl;
    file << "password: " << password << endl;

    cout << "Registration successful!" << endl;
}

void Login(ifstream& file){
    string username, password;
    string line;

    cout << "=====USER REGISTER=====\n";

    cout << "Enter your username: ";
    getline(cin, username);

    cout << "Enter your password: ";
    getline(cin, password);

    while (getline(file, line)){
        if (line.find("username: " + username) != string::npos) {
            if (getline(file, line) && line == "password: " + password) {
                cout << "Login successful!" << endl;
                return;
            }
        }
    }

    cout << "Login failed. Incorrect username or password.\n" << endl;
}

int main(){
    ofstream outFile("users.txt", ios::app);
    ifstream inFile("users.txt");

    if (!outFile || !inFile) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    char choice;

    do{
        cout << "\n=====USER REGISTER/LOGIN=====\n";
        cout << "1. Register\n2. Login\n3. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1':
                Register(outFile);
                break;
            case '2':
                Login(inFile);
                break;
            case '3':
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '3');

    outFile.close();
    inFile.close();

    return 0;
}
