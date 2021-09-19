#include <iostream>
#include "Point.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

void isChainValid(string path);
void worker(string path);
int Menu(string path)
{
    int ch;
    cout<< "What would you like to do?"<< endl;
    cout<< "(1) Write new information to database"<<endl;
    cout<< "(2) Check Is chain still valid?"<< endl;
    cout<< "(Any symbol) Exit"<<endl;
    cin>>ch;

    if (ch == 1 || ch == 2) {
        switch (ch) {
            case 1:
                worker(path);
            case 2:
                isChainValid(path);
        }
    }
    else
    {
        return 0;
    }


}

void worker(string path)
{

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
    Menu(path);
}

void isChainValid(string path) {
    //==========Open the File=============
    ifstream file(path);
    string segment;
    bool validation = false;

    vector<string> vec;

    int i = 0;

    while(getline(file, segment))
    {
        vec.push_back(segment);
//    cout<< vec[i]<< endl;
        i++;
    }
    //======================================
    vector<string> vec2;
    string s;
    for (int j = 0; j < vec.size(); ++j) {
        stringstream ssin(vec[j]);

        while(getline(ssin, s, ','))
        {
            vec2.push_back(s);
        }
    }
int z = 13;
    while (z <= vec2.size()) {
        if (vec2[z] == vec2[z+=9])
        {
            validation = true;
        }
        else
        {
            validation = false;
            cout<<"Chain is not valid"<<endl;
            break;
        }
        z+=7;
    }
    if(validation)
    {
        cout<< "Chain is valid!"<< endl;
    }

    file.close();
    Menu(path);
    };

int main() {
    string path = "simple_DB.csv";
   Menu(path);
   return 0;
}
