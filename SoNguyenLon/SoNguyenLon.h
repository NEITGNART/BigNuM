#pragma once

#ifndef SoNguyenLon_H
#define SoNguyenLon_H
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <ctime>

using namespace std;

typedef long long ll;

struct node {
    string data;
    node* next;
};
class SoNguyenLon {
private:
    node* head;
    node* tail;
public:
    void Init();
    SoNguyenLon();
    SoNguyenLon(string str);
    SoNguyenLon(ll x);
    SoNguyenLon(ll x, ll y);
    node* CreateNode(const string& n);
    friend ostream& operator<<(ostream& os, const SoNguyenLon& x);
    /*ll& operator[](const int& i);*/
    friend SoNguyenLon operator+(SoNguyenLon x, SoNguyenLon y);
    SoNguyenLon& operator+=(SoNguyenLon x);
    friend SoNguyenLon operator-(SoNguyenLon x, SoNguyenLon y);
    friend SoNguyenLon operator-(ll x, SoNguyenLon y);
    friend SoNguyenLon operator-(SoNguyenLon x, ll y);
    friend SoNguyenLon operator+(ll x, SoNguyenLon y);
    friend SoNguyenLon operator+(SoNguyenLon x, ll y);
    friend bool operator>=(SoNguyenLon x, SoNguyenLon y);
    friend bool operator==(SoNguyenLon x, SoNguyenLon y);
    friend SoNguyenLon operator*(SoNguyenLon x, SoNguyenLon y);

};

#endif