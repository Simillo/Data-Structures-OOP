#include "DeusesGregos.h"


Node::Node(Deuses data) {
	_data = data;
	_next = NULL;
}

Deuses Node::getData() {
    return this->_data;
}

Node* Node::getNext() {
    return this->_next;
}

List::List() {
	_first = NULL;
	_last = NULL;
	_size = 0;
}

void List::insert(Deuses data) {
	Node *nodeAux = new Node(data);
	if(_first == NULL) {
		_first = nodeAux;
		_last = nodeAux;
	} else {
		_last->_next = nodeAux;
		_last = nodeAux;
	}
	++_size;
}

Node* List::getFirst() {
    return this->_first;
}

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
        fstream arquivoAux("deusesAux.bin", ios_base::in | ios_base::out | ios_base::binary | ios_base::app);
        Deuses deusAux;
        _arquivo.clear();
        _arquivo.seekg(0, _arquivo.beg);

        List listAux;
        int counter = 0;
        while(_arquivo.read((char *) &deusAux, sizeof(Deuses))) {
			if(deusAux.Id < deus.Id){
                listAux.insert(deusAux);
                ++counter;
            } else {
                break;
            }
		}
        Node *nodeAux = listAux.getFirst();
        while(nodeAux != NULL) {
            Deuses nodeData = nodeAux->getData();
            arquivoAux.write((char *) &nodeData, sizeof(Deuses));
            nodeAux = nodeAux->getNext();
        }
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
