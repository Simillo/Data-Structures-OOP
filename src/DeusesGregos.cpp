#include "DeusesGregos.h"

DeusesGregos::DeusesGregos(const char *nome) {
    _arquivo.open(nome, ios_base::in | ios_base::out | ios_base::binary | ios_base::app);
    _lastId = getLast();
}

inline bool DeusesGregos::isOpen() {
    return _arquivo.is_open();
}

void DeusesGregos::insertData(Deuses deus) {
    if(isOpen()) {
        deus.Id = ++_lastId;
        _arquivo.clear();
        _arquivo.write((char *) &deus, sizeof(Deuses));
    }
}

void DeusesGregos::getData() {
    if(isOpen()) {
        Deuses deus;
        _arquivo.clear();
        _arquivo.seekg(0, ios_base::beg);
        cout << endl;
        while(_arquivo.read((char *) &deus, sizeof(Deuses))) {
            cout << "Id: " << deus.Id << endl;
            cout << "Nome: " << deus.Nome << endl;
            cout << "Dominio: " << deus.Dominio << endl;
            cout << "Biografia: " << deus.Biografia << endl;
            cout << "---------------------------------------" << endl;
        }
        cout << endl;
    }
}

Deuses* DeusesGregos::getData(int id) {
    if(isOpen()) {
        if(id <= _lastId){
            Deuses *deus;
            _arquivo.clear();
            _arquivo.seekg(0, ios_base::beg);
            while(_arquivo.read((char *) &deus, sizeof(Deuses))) {
                if(deus->Id == id)
                    return deus;
            }
        }
    }
    return NULL;
}

Deuses* DeusesGregos::getData(char nome) {
    if(isOpen()) {
        if(id <= _lastId){
            Deuses *deus;
            _arquivo.clear();
            _arquivo.seekg(0, ios_base::beg);
            while(_arquivo.read((char *) &deus, sizeof(Deuses))) {
                if(deus->Nome == nome)
                    return deus;
            }
        }
    }
    return NULL;
}

int DeusesGregos::getLast() {
    if(isOpen()) {
        _arquivo.seekg(-sizeof(Deuses), _arquivo.end);
        Deuses deus;
        _arquivo.read((char *) &deus, sizeof(Deuses));
        return deus.Id;
    }
    return -1;
}

void DeusesGregos::checkIfIsOpen() {
    cout << (isOpen() ? "Sim" : "Nao") << endl;
}

void DeusesGregos::deleteById(int id) {
    cout << id << endl;
}