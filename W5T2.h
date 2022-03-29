
#ifndef BEER
#define BEER
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;

class Beer{
    char* brand;
    int size;

    void copy(const Beer& other);
    void erase();
    
    public:
    
    void setBrand(const char* brand);
    void setSize(int size);
    
    const char* getBrand()const;
    int getSize()const;

    Beer();
    Beer(const char* Brand,const int size);
    Beer(const Beer &other);
    Beer &operator=(const Beer &beer);
    ~Beer(); 
    
    void add(Beer &beer, int size);
    bool check(const char* brand);

    void print();
};
#endif