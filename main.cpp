#include <iostream>
#include "Point.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>
#include <ctime>

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
    bool validator = false;
    ifstream file(path);
    string segment;

    vector<string> vec;

    int i = 0;

    while(getline(file, segment))
    {
        vec.push_back(segment);
        i++;
    }
    //================Add to vector======================
    vector<string> vec2;
    string s;
    for (int j = 0; j < vec.size(); ++j) {
        stringstream ssin(vec[j]);

        while(getline(ssin, s, ' '))
        {
            vec2.push_back(s);
        }
    }
    //=====DELETE COMAS=======
    string t;
    for (int j = 0; j < vec2.size(); ++j) {
        stringstream ssin(vec2[j]);
        while(getline(ssin, t, ','))
        {
            vec2[j] = t;
        }
    }
    //===================NEW - VALIDATOR======
    string toHash;
    hash<string> string_hash;
        for (int m = 5; m < vec2.size()-7; m += 7) {
            int d = m+4;
            int l = m+5;
            int k = m+6;
            int q = m+3;
            int c = m+2;
            int res = m+7;
           toHash = vec2[d] + vec2[l] + vec2[k] +vec2[q] + vec2[c] +vec2[m];
           size_t h = string_hash(toHash);
           if (to_string(h) == vec2[res]){
               validator = true;
           }
           cout<<"h :"<< h<< endl;
        }
    if(validator)
    {
        cout<< "Chain is valid!"<< endl;
    }

    file.close();
    Menu(path);
    };

int main() {
    Point test;
    test.get_last_id();
    test.get_last_hash();
    string path = "simple_DB.csv";
   Menu(path);
   return 0;
}
