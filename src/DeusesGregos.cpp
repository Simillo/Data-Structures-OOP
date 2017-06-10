/**
 * GCC - 216, Estrutura de Dados
 * DeusesGregos.cpp
 * Propósito: Trabalho de gerenciamento de dados usando arquivo binário e orientação a objetos.
 * Tema: Deuses Gregos.
 * @author Simillo Nakai
 * @version 1.0 10/06/2017
*/

#include "DeusesGregos.h"


/**
 * Construtor da classe 'DeusesGregos'
 * @param NOME Nome do arquivo principal que será armazenado as ações.
 * @param NOMEAUX Nome do arquivo auxiliar para auxiliar nas ações. 
*/

DeusesGregos::DeusesGregos(const char *NOME, const char *NOMEAUX) {
    _arquivo.open(NOME, ios_base::in | ios_base::out | ios_base::binary | ios_base::app);
    _fileName = NOME;
    _fileNameAux = NOMEAUX;
    _lastId = getLast();
}

/**
 * Verifica se o arquivo principal está aberto.
 * @returns Valor boolean;
*/

inline bool DeusesGregos::_isOpen() {
    return _arquivo.is_open();
}

/**
 * Insere um objeto no arquivo principal. 
 * @param deus Objeto do tipo 'Deuses' que é feito pelo usuário.
*/

void DeusesGregos::insertData(Deuses deus) {
    if(_isOpen()) {
        fstream arquivoAux(_fileNameAux, ios_base::in | ios_base::out | ios_base::binary | ios_base::trunc);
        Deuses deusAux;
        
        int counter = 0;
        bool inserted = false;
        
        _arquivo.clear();
        _arquivo.seekg(0, _arquivo.beg);

        arquivoAux.clear();
        arquivoAux.seekg(0, arquivoAux.beg);
        
        while(_arquivo.read((char *) &deusAux, sizeof(Deuses))) {
			if(deusAux.Id < deus.Id || inserted){
                arquivoAux.write((char *) &deusAux, sizeof(Deuses));
                ++counter;
            } else {
                arquivoAux.write((char *) &deus, sizeof(Deuses));
                arquivoAux.write((char *) &deusAux, sizeof(Deuses));
                counter += 2;
                inserted = true;
            }
		}
        if(counter == 0 || !inserted) {
            _arquivo.clear();
            _arquivo.seekg(0, _arquivo.beg);
            _arquivo.write((char *) &deus, sizeof(Deuses));
        } else {
            _arquivo.close();
            _arquivo.open(_fileName, ios_base::in | ios_base::out | ios_base::binary | ios_base::trunc);
            arquivoAux.clear();
            arquivoAux.seekg(0, arquivoAux.beg);
            while(arquivoAux.read((char *) &deusAux, sizeof(Deuses))) {
                _arquivo.write((char *) &deusAux, sizeof(Deuses));
            }
            _arquivo.close();
            _arquivo.open(_fileName, ios_base::in | ios_base::out | ios_base::binary | ios_base::app);
        }
        arquivoAux.close();
        remove(_fileNameAux);
        _lastId = getLast();
    }
}

/**
 * Imprime todos os dados inseridos no arquivo.
*/

void DeusesGregos::getData() {
    if(_isOpen()) {
        Deuses deus;
        _arquivo.clear();
        _arquivo.seekg(0, _arquivo.beg);
        cout << endl;
        while(_arquivo.read((char *) &deus, sizeof(Deuses))) {
            cout << "Id: "        << deus.Id        << endl;
            cout << "Nome: "      << deus.Nome      << endl;
            cout << "Dominio: "   << deus.Dominio   << endl;
            cout << "Biografia: " << deus.Biografia << endl;
            cout << "---------------------------------------" << endl;
        }
        cout << endl;
    }
}

/**
 * Imprime um deus que será procurado.
 * @param id Valor do id do deus que será procurado.
*/

void DeusesGregos::getData(int id) {
    if(_isOpen()) {
        if(id <= _lastId){
            Deuses deus;
            _arquivo.clear();
            _arquivo.seekg(0, _arquivo.beg);
            cout << endl;
            while(_arquivo.read((char *) &deus, sizeof(Deuses))) {
                if(deus.Id == id){
                    cout << "Id: "        << deus.Id << endl;
                    cout << "Nome: "      << deus.Nome << endl;
                    cout << "Dominio: "   << deus.Dominio << endl;
                    cout << "Biografia: " << deus.Biografia << endl;
                    cout << "---------------------------------------" << endl << endl;
                    return;
                }
            }
            cout << "Deus com o id " << id << " nao encontrado." << endl;
        }
    }
}

/**
 * Pega o id do primeiro deus.
 * @returns Valor do id do primeiro deus, -1 se não existir nenhum deus.
*/

int DeusesGregos::getFirst() {
    if(_isOpen()) {
        _arquivo.seekg(0, _arquivo.beg);
        Deuses deus;
        _arquivo.read((char *) &deus, sizeof(Deuses));
        return deus.Id;
    }
    return -1;
}

/**
 * Pega o id do último deus.
 * @returns Valor do id do último deus, -1 se não existir nenhum deus. 
*/

int DeusesGregos::getLast() {
    if(_isOpen()) {
        _arquivo.seekg(-sizeof(Deuses), _arquivo.end);
        Deuses deus;
        _arquivo.read((char *) &deus, sizeof(Deuses));
        return deus.Id;
    }
    return -1;
}

/**
 * Imprime para o usuário se o arquivo está aberto ou não.
*/

void DeusesGregos::checkIfIsOpen() {
    cout << (_isOpen() ? "Sim" : "Nao") << endl;
}

/**
 * Delete um deus pelo ID.
 * @param id Id que o usuário escolher para deletar.
 * @returns Valor boolean se conseguiu deletar ou não.
*/

void DeusesGregos::deleteById(int id) {
    cout << id << endl;
}
