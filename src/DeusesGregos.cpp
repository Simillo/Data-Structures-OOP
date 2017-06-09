#include "DeusesGregos.h"

DeusesGregos::DeusesGregos(const char *nome) {
    _arquivo.open(nome, ios_base::in | ios_base::out | ios_base::binary | ios_base::app);
    _firstId = getFirst();
    _lastId = getLast();
}

inline bool DeusesGregos::_isOpen() {
    return _arquivo.is_open();
}

void DeusesGregos::insertData(Deuses deus) {
    if(_isOpen()) {
        // deus.Id = ++_lastId;
        _arquivo.clear();
        Deuses deusAux;
        _arquivo.seekg(0, _arquivo.beg);
        int anterior = _firstId;
        while(_arquivo.read((char *) &deusAux, sizeof(Deuses))) {
            if(deusAux.id >)
        }
        // _arquivo.write((char *) &deus, sizeof(Deuses));
    }
}

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

int DeusesGregos::getFirst() {
    if(_isOpen()) {
        _arquivo.seekg(0, _arquivo.beg);
        Deuses deus;
        _arquivo.read((char *) &deus, sizeof(Deuses));
        return deus.Id;
    }
    return -1;
}

int DeusesGregos::getLast() {
    if(_isOpen()) {
        _arquivo.seekg(-sizeof(Deuses), _arquivo.end);
        Deuses deus;
        _arquivo.read((char *) &deus, sizeof(Deuses));
        return deus.Id;
    }
    return -1;
}

void DeusesGregos::checkIfIsOpen() {
    cout << (_isOpen() ? "Sim" : "Nao") << endl;
}

void DeusesGregos::deleteById(int id) {
    cout << id << endl;
}