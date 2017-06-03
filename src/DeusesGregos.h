#ifndef DEUSES_GREGOS_H
#define DEUSES_GREGOS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

struct Deuses {
    int Id;
    char Nome[50]; 
    char Dominio[50];
    char Biografia[200];
};

class DeusesGregos {
    private:
        fstream _arquivo;
        Deuses _deus;
    public:
        DeusesGregos(char *msg);
};

#endif