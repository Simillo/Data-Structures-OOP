#include "DeusesGregos.h"

int main(int argc, char *argv[]) {
    const char *nome = "deuses.dat";
    DeusesGregos deus(nome);

    bool flag = true;

    char operacao;
    
    while(flag) {
        cout << endl
             << "Digite (i) para inserer algum deus ou (p) para imprimir todos os deuses inseridos ou (q) para sair."
             << endl
             << "---------------------------------------------------------------------------------"
             << endl << endl;
        cin >> operacao;

        switch(operacao) {
            case 'i':
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
                break;
            case 'p':
                deus.getData();
                break;
            case 'q':
            default:
                flag = false;
                cout << "Saindo..." << endl;
                break;
        }
    }
}