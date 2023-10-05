#include<iostream>
#include<string>
#include<windows.h>
#include<conio.h>

using namespace std;

struct dataMahasiswa{
    string nrp;
    string name;
    string major;
    int age;
    bool gender;
    int stat = 0; //0=empty, 1=occupied, 2=deleted
}Mahasiswa[10];
int MahasiswaID = 0;

//input data function
void InputData(int USERID){
    cout << "USER ID : " << USERID << endl;
    cout << "NRP \t\t: ";			cin >> Mahasiswa[USERID].nrp;
    cout << "Name \t\t: ";			cin >> Mahasiswa[USERID].name;
    cout << "Major \t\t: ";			cin >> Mahasiswa[USERID].major;
    cout << "Age \t\t: ";			cin >> Mahasiswa[USERID].age;
    cout << "Gender M(1)/F(0): ";	cin >> Mahasiswa[USERID].gender;
    Mahasiswa[USERID].stat = 1;
}

//delete data function
void DeleteData(int delID){
    Mahasiswa[delID].nrp    = "";
    Mahasiswa[delID].name   = "";
    Mahasiswa[delID].major  = "";
    Mahasiswa[delID].age    = 0;
    Mahasiswa[delID].gender = 0;
    Mahasiswa[delID].stat 	= 2;
}

//show data function
void ShowData(int showID){
    //show occupied data
    if (Mahasiswa[showID].stat == 1){
        cout << "NRP \t\t : " 	<< Mahasiswa[showID].nrp << endl;
        cout << "Name \t\t : " 	<< Mahasiswa[showID].name << endl;
        cout << "Major \t\t : "	<< Mahasiswa[showID].major << endl;
        cout << "Age \t\t : " 	<< Mahasiswa[showID].age << endl;
        if (Mahasiswa[showID].gender == 1){
            cout << "Gender \t\t : Male" << endl;
        }
        if (Mahasiswa[showID].gender == 0){
            cout << "Gender \t\t : Female" << endl;
        }
        cout << "back to main menu? (press enter) ";
        getch();
    }
    //show empty data
    else if (Mahasiswa[showID].stat == 0){
        cout << "data is unavailable" << endl;
        cout << "back to main menu? (press enter) ";
        getch();
    }
    //show deleted data
    else if (Mahasiswa[showID].stat == 2){
        cout << "data is deleted" << endl;
        cout << "back to main menu? (press enter) ";
        getch();
    }
}

//menu function
void menu(){
    int choice;
    while(choice!=5){
        system("cls");
        cout << "Student Identity Database : " << endl;
        cout << "[1] Input data" << endl;
        cout << "[2] Delete data" << endl;
        cout << "[3] Change data" << endl;
        cout << "[4] Show data" << endl;
        cout << "[5] exit" << endl;
        cout << "input : ";
        cin >> choice;
        switch (choice){ 
        case 1:
            system("cls");
			InputData(MahasiswaID);
            MahasiswaID++;
            break;

        case 2:
            system("cls");
            int delID;
            cout << "what id do you want to delete? ";
            cin >> delID;
            DeleteData(delID);
            break;

        case 3:
            system("cls");
            int changeID;
            cout << "what id do you want to change? ";
            cin >> changeID;
            InputData(changeID);
            break;

        case 4:
            system("cls");
            int showID;
            cout << "user id do you want to see?  ";
            cin >> showID;
            ShowData(showID);
            break;

        default:
            cout << "there is no option" << endl;
            break;
        }
    }
}

int main(){
    menu();
}
