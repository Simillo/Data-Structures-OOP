/**
 * GCC - 216, Estruturas de Dados
 * DeusesGregos.cpp
 * Propósito: Arquivo para a definição dos metódos da classe 'DeusesGregos'.
 * Tema: Deuses Gregos.
 * Trabalho de gerenciamento de dados usando arquivo binário e orientação a objetos.
 * @author Simillo Nakai, Rafael Resende, Vinicius Sezini.
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
    _quantity = getQuantity();
    _firstId = getFirst();
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
    if(deus.Id <= 0){
        cout << "O id do deus tem que ser maior ou igual a 1." << endl;
        return;
    }
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
            if(deusAux.Id == deus.Id) {
                cout << endl << "Deus com o id " << deus.Id << " ja existe." << endl;
                arquivoAux.close();
                remove(_fileNameAux);
                return;
            }
            if(deusAux.Id < deus.Id || inserted) {
                ++counter;
            } else {
                arquivoAux.write((char *) &deus, sizeof(Deuses));
                counter += 2;
                inserted = true;
            }
            arquivoAux.write((char *) &deusAux, sizeof(Deuses));
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
        ++_quantity;
        _lastId = getLast();
        _firstId = getFirst();
        cout << "Deus inserido com sucesso." << endl;
    }
}

/**
 * Imprime todos os dados inseridos no arquivo.
*/

void DeusesGregos::getData() {
    if(_isOpen()) {
        if(_quantity > 0){
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
        } else {
            cout << "Nao existe nenhum deus inserido." << endl;
        }
    }
}

/**
 * Imprime um deus que será procurado.
 * @param id Valor do id do deus que será procurado.
*/

void DeusesGregos::getData(int id) {
    if(_isOpen()) {
        if(_quantity > 0) {
            if(id >= _firstId && id <= _lastId){
                const int SIZE = sizeof(Deuses);
                int positionLastEntry;
                bool found = false;
                
                _arquivo.clear();
                positionLastEntry = _arquivo.seekg(-SIZE, _arquivo.end).tellg();
                Deuses deusAux;
                
                int number = positionLastEntry/SIZE + 1;

                int first = 0,
                    last = number,
                    middle = number/2;
                
                while(first <= last && !found) {
                    middle = (first + last)/2;
                    
                    _arquivo.clear();
                    _arquivo.seekg(middle * SIZE);
                    _arquivo.read((char *) &deusAux, sizeof(Deuses));

                    if(deusAux.Id < id) {
                        first = middle + 1;
                    } else if(deusAux.Id > id) {
                        last = middle - 1;
                    } else {
                        found = true;
                    }
                }
                if(found){
                    cout << "Id: "        << deusAux.Id        << endl;
                    cout << "Nome: "      << deusAux.Nome      << endl;
                    cout << "Dominio: "   << deusAux.Dominio   << endl;
                    cout << "Biografia: " << deusAux.Biografia << endl;
                    cout << "---------------------------------------" << endl;
                    return;
                } else {
                    cout << "Nenhum deus foi encontrado com o id " << id << "." << endl;
                }
            } else {
                cout << "Nenhum deus foi encontrado com o id " << id << "." << endl;
            }
        } else {
            cout << "Nao existe nenhum deus inserido." << endl;
        }
    }
}

/**
 * Pega o id do primeiro deus.
 * @returns Valor do id do primeiro deus, -1 se não existir nenhum deus.
*/

int DeusesGregos::getFirst() {
    if(_isOpen() && _quantity) {
        _arquivo.clear();
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
    if(_isOpen() && _quantity) {
        _arquivo.clear();
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
 * Deleta um deus pelo ID.
 * @param id Id do deus que o usuário escolheu para deletar.
*/

void DeusesGregos::deleteDeus(int id) {
    if(_isOpen()) {
        if(_quantity > 0){
            fstream arquivoAux(_fileNameAux, ios_base::in | ios_base::out | ios_base::binary | ios_base::trunc);
            Deuses deusAux;

            bool exists = false;

            _arquivo.clear();
            _arquivo.seekg(0, _arquivo.beg);

            arquivoAux.clear();
            arquivoAux.seekg(0, arquivoAux.beg);

            while(_arquivo.read((char *) &deusAux, sizeof(Deuses))) {
                if(deusAux.Id != id) {
                    arquivoAux.write((char *) &deusAux, sizeof(Deuses));
                } else {
                    exists = true;
                }
            }
            if(exists) {
                _arquivo.close();
                _arquivo.open(_fileName, ios_base::in | ios_base::out | ios_base::binary | ios_base::trunc);
                arquivoAux.clear();
                arquivoAux.seekg(0, arquivoAux.beg);
                while(arquivoAux.read((char *) &deusAux, sizeof(Deuses))) {
                    _arquivo.write((char *) &deusAux, sizeof(Deuses));
                }
                _arquivo.close();
                _arquivo.open(_fileName, ios_base::in | ios_base::out | ios_base::binary | ios_base::app);
                --_quantity;
                _lastId = getLast();
                _firstId = getFirst();
                cout << "Deus com o id " << id << " foi deletedo com sucesso." << endl;
            } else {
                cout << "Nao existe deus com o id " << id << " no arquivo." << endl;
            }
            arquivoAux.close();
            remove(_fileNameAux);
        } else {
            cout << "Nao existe nenhum deus inserido." << endl;
        }
    }
}

/**
 * Deleta um deus pelo nome.
 * @param nome[50] Nome do deus que o usuário escolheu para deletar.
*/

void DeusesGregos::deleteDeus(char nome[50]) {
    if(_isOpen()) {
        if(_quantity > 0){
            fstream arquivoAux(_fileNameAux, ios_base::in | ios_base::out | ios_base::binary | ios_base::trunc);
            Deuses deusAux;

            bool exists = false;

            _arquivo.clear();
            _arquivo.seekg(0, _arquivo.beg);

            arquivoAux.clear();
            arquivoAux.seekg(0, arquivoAux.beg);

            while(_arquivo.read((char *) &deusAux, sizeof(Deuses))) {
                if(strcmp(deusAux.Nome, nome) != 0 || exists) {
                    arquivoAux.write((char *) &deusAux, sizeof(Deuses));
                } else {
                    exists = true;
                }
            }
            if(exists) {
                _arquivo.close();
                _arquivo.open(_fileName, ios_base::in | ios_base::out | ios_base::binary | ios_base::trunc);
                arquivoAux.clear();
                arquivoAux.seekg(0, arquivoAux.beg);
                while(arquivoAux.read((char *) &deusAux, sizeof(Deuses))) {
                    _arquivo.write((char *) &deusAux, sizeof(Deuses));
                }
                _arquivo.close();
                _arquivo.open(_fileName, ios_base::in | ios_base::out | ios_base::binary | ios_base::app);
                --_quantity;
                _lastId = getLast();
                _firstId = getFirst();
                cout << "Deus com o nome " << nome << " foi deletedo com sucesso." << endl;
            } else {
                cout << "Nao existe deus com o nome " << nome << " no arquivo." << endl;
            }
            arquivoAux.close();
            remove(_fileNameAux);
        } else {
            cout << "Nao existe nenhum deus inserido." << endl;
        }
    }
}

/**
 * Método para pegar a quantidade de deuses no arquivo.
 * @returns Número inteiro referente a quantidade.
*/

int DeusesGregos::getQuantity() {
    int counter = 0;
    if(_isOpen()) {
         Deuses deus;
        _arquivo.clear();
        _arquivo.seekg(0, _arquivo.beg);
        while(_arquivo.read((char *) &deus, sizeof(Deuses))) {
            ++counter;
        }
    }
    return counter;
}

/**
 * Método para imprimir os dados do grupo.
*/

void DeusesGregos::getGroupData() {
    cout 
    << "********************************************************" << endl
    << "*       Trabalho de Estrutura de Dados - GCC 216       *" << endl
    << "*       Tema: Deuses Gregos                            *" << endl
    << "*       Integrantes: Simillo Nakai                     *" << endl
    << "*                    Rafael Resende                    *" << endl
    << "*                    Vinicius Sezini                   *" << endl
    << "* Repositorio no github: github.com/Simillo/TrabalhoED *" << endl
    << "********************************************************" << endl;
}

/**
 * Método para exportar para TXT os deuses salvos.
*/

void DeusesGregos::exportToTxt() {
    if(_isOpen()) {
        ofstream txtFile("deuses.txt");
        Deuses deusAux;
        _arquivo.clear();
        _arquivo.seekg(0, _arquivo.beg);
        while(_arquivo.read((char *) &deusAux, sizeof(Deuses))) {
            txtFile << "Id: "        << deusAux.Id        << endl;
            txtFile << "Nome: "      << deusAux.Nome      << endl;
            txtFile << "Dominio: "   << deusAux.Dominio   << endl;
            txtFile << "Biografia: " << deusAux.Biografia << endl;
            txtFile << "---------------------------------------" << endl;
        }
        cout << "Deuses exportados com sucesso para o arquivo \"deuses.txt\"." << endl;
    }
}