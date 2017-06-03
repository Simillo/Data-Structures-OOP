#include "DeusesGregos.h"

DeusesGregos::DeusesGregos(const char *nome) {
    _arquivo.open(nome, ios_base::in|ios_base::out|ios_base::binary|ios_base::app);
}

bool DeusesGregos::isOpen() {
    return _arquivo.is_open();
}

void DeusesGregos::insertData(Deuses deus) {
    if(isOpen()) {
        _arquivo.write((char *) &deus, sizeof(Deuses));
    }
}

void DeusesGregos::getData() {
    if(isOpen()) {
        Deuses deus;
        _arquivo.seekg(0, ios_base::beg);
        while(_arquivo.read((char *) &deus, sizeof(Deuses))) {
            cout << "Id: " << deus.Id << endl;
            cout << "Nome: " << deus.Nome << endl;
            cout << "Dominio: " << deus.Dominio << endl;
            cout << "Biografia: " << deus.Biografia << endl;
        }
    }
}