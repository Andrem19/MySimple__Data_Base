//
// Created by 72555 on 9/19/2021.
//
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
using namespace std;

#ifndef MY_DATA_BASE_POINT_H
#define MY_DATA_BASE_POINT_H


class Point {
public:
    Point(int x, int y, int z);
    Point();
    static int Temp;
    static string get_last_id();

    string get_last_hash();
    static vector<string> get_vector();
    size_t curr_hash;
    string prev_hash;
    int Id;
    int Tm;
    int x;
    int y;
    int z;
    friend ostream& operator<<(ostream& os, const Point& point);
    friend istream& operator>>(istream& is, Point& point);
};



#endif //MY_DATA_BASE_POINT_H
