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
        inline bool _isOpen();
        int _lastId;
    public:
        DeusesGregos(const char *nome);
        void insertData(Deuses deus);
        void getData();
        Deuses* getData(int id);
        Deuses* getData(char nome);
        int getLast();
        void checkIfIsOpen();
        void deleteById(int id);
};

#endif