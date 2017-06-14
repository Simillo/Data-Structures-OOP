/**
 * GCC - 216, Estrutura de Dados
 * DeusesGregos.h
 * Propósito: Header de declaração da classe 'DeusesGregos' e o struct 'Deuses'.
 * Tema: Deuses Gregos.
 * Trabalho de gerenciamento de dados usando arquivo binário e orientação a objetos.
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
        int _quantity;
        int _firstId;
        int _lastId;
    public:
        DeusesGregos(const char *NOME, const char *NOMEAUX);
        void insertData(Deuses deus);
        void getData();
        void getData(int id);
        int getFirst();
        int getLast();
        void checkIfIsOpen();
        void deleteDeus(int id);
        void deleteDeus(char nome[50]);
        int getQuantity();
};

#endif
