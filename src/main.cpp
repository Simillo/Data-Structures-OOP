#include "DeusesGregos.h"

int main(int argc, char *argv[]) {
    const char *nome = "deuses.dat";
    DeusesGregos deus(nome);

    cout << deus.isOpen() << endl;

    deus.getData();

    Deuses d;
    cout << "id: ";
    cin >> d.Id;
    cin.ignore();
    cout << endl << "Nome: ";
    cin.getline(d.Nome, 50);
    cout << endl << "Dominio: ";
    cin.getline(d.Dominio, 50);
    cout << endl << "Biografia: ";
    cin.getline(d.Biografia, 200);
    deus.insertData(d);
}