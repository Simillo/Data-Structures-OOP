#include "DeusesGregos.h"

int main(int argc, char *argv[]) {
    const char *nome = "deuses.bin";
    DeusesGregos deus(nome);

    bool flag = true;

    char operacao;
    while(flag) {
        cout << endl
             << "Digite (i) para inserer algum deus;"
             << endl
             << "Digite (p) para imprimir todos os deuses inseridos;"
             << endl
             << "Digite (s) para procurar um deus;"
             << endl
             << "Digite (v) para verificar se o arquivo esta aberto;"
             << endl
             << "Digite (q) para sair."
             << endl
             << "---------------------------------------------------------------------------------------------------"
             << endl << endl;
        cin >> operacao;

        switch(operacao) {
            case 'i':
                Deuses d;
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
            case 'd':
                int id;
                cout << "Digite o ID a ser deletado: " << endl;
                cin >> id;
                deus.deleteById(id);
                break;
            case 's':
                int search;
                cout << "Digite o ID a ser procurado: ";
                cin >> search;
                deus.getData(search);
                break;
            case 'v':
                deus.checkIfIsOpen();
                break;
            case 'q':
            default:
                flag = false;
                cout << "Saindo..." << endl;
                break;
        }
    }
}