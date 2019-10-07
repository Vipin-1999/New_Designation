#ifndef DESIGNATION_H
#define DESIGNATION_H
#include<iostream>
#include<fstream>
#include<string>
#include<stdexcept>
#include<vector>
#include<regex>

//#include "nbind/nbind.h"

typedef unsigned long size_t;
typedef std::vector<std::string> svector;

class Designation       {
    public:
        void VectorInit();
        void writetofile(std::string);
        bool Validate(std::string);
        std::string Random(int,int,int,bool);
        std::string Generate(size_t);
        std::string Generate_Invalid(size_t);
        void Add(std::string);
        void Remove(std::string);
        void Show();
        svector desList;
};

#endif


