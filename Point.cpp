//
// Created by 72555 on 9/19/2021.
//

#include <iostream>
#include "Point.h"


Point::Point(int x, int y, int z) {

    Temp ++ ;
    this->Id = Temp;
    this->Tm = time(NULL);
    this->x = x;
    this->y = y;
    this->z = z;
    this->prev_hash = temp_hash;
    string toHash = to_string(x) + to_string(y) + to_string(z) + to_string(Tm) + to_string(Id) + prev_hash;
    hash<string> string_hash;
    size_t h = string_hash(toHash);
    this->curr_hash = h;
    temp_hash = to_string(h);

}
int Point::Temp = 1;
string Point::temp_hash = "0";
ostream& operator<<(ostream& os, const Point& point)
{
    os<<point.Id<<", "<<point.Tm<<", "<<point.x<<", "<<point.y<<", "<<point.z<<", "<<point.curr_hash<<", "<<point.prev_hash<<", ";
    return os;
}
istream& operator>>(istream& is, Point& point)
{
    is>>point.Id>>point.Tm>>point.x>>point.y>>point.z>>point.curr_hash>>point.prev_hash;
    return is;
}

Point::Point() {
auto Id = Tm = x = y = z = curr_hash = 0;
prev_hash = "0";
}

