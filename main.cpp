#include <iostream>
#include "Point.h"
#include <fstream>

void worker();
int Menu()
{
    int ch;
    cout<< "What would you like to do?"<< endl;
    cout<< "(1) Write new information to database"<<endl;
    cout<< "(Any symbol) Exit"<<endl;
    cin>>ch;
    if (ch == 1) {
        worker();
    }
    else
    {
        return 0;
    }
}

void worker()
{
    string path = "simple_DB.csv";
    int x, y, z;
    cout << "Input x : y : z " << endl;
    cin >> x;
    cin >> y;
    cin >> z;
    Point p(x, y, z);

    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);
    if (!fs.is_open()) {
        cout << "Error" << endl;
    } else {
        cout << "File is open" << endl;
        fs << p << "\n";
        cout << "Your Data has been successfuly written" << endl << p << endl;
    }
    fs.close();
    Menu();
}

int main() {
   Menu();
   return 0;
}
