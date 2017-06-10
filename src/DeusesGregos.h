/**
 * GCC - 216, Estrutura de Dados
 * DeusesGregos.h
 * Propósito: Trabalho de gerenciamento de dados usando arquivo binário e orientação a objetos.
 * Tema: Deuses Gregos.
 * @author Simillo Nakai
 * @version 1.0 10/06/2017
*/

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
        int _quantity;
    public:
        DeusesGregos(const char *NOME, const char *NOMEAUX);
        void insertData(Deuses deus);
        void getData();
        void getData(int id);
        int getFirst();
        int getLast();
        void checkIfIsOpen();
        void deleteById(int id);
        int getQuantity();
};

#endif
