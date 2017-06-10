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
        const char* _fileName;
        const char* _fileNameAux;
        inline bool _isOpen();
        int _firstId;
        int _lastId;
    public:
        DeusesGregos(const char *nome);
        void insertData(Deuses deus);
        void getData();
        void getData(int id);
        int getFirst();
        int getLast();
        void checkIfIsOpen();
        void deleteById(int id);
};

#endif
