/**
 * GCC - 216, Estrutura de Dados
 * main.cpp
 * Propósito: Arquivo principal, acontece a interação com o usuário.
 * Tema: Deuses Gregos.
 * Trabalho de gerenciamento de dados usando arquivo binário e orientação a objetos.
 * @author Simillo Nakai
 * @version 1.0 10/06/2017
*/

#include "DeusesGregos.h"

int main(int argc, char *argv[]) {
    const char *NOME = argc >= 2 ? argv[1] : "deuses.bin";
    const char *NOMEAUX = argc == 3 ? argv[2] : "deusesAux.bin";
    DeusesGregos deus(NOME, NOMEAUX);

    bool flag = true;

    char operacao;
    while(flag) {
        cout << endl
             << "Digite (i) para inserir algum deus;"
             << endl
             << "Digite (p) para imprimir todos os deuses inseridos;"
             << endl
             << "Digite (d) para deletar um deus;"
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
                cout << "ID: ";
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
            case 'd':
                char opcao;
                cout 
                << "Digite (i) para deletar por ID" 
                << endl 
                << "Digite (n) para deletar por Nome"
                << endl;
                cin >> opcao;
                switch(opcao) {
                    case 'i':
                        int id;
                        cout << "Digite o id a ser deletado: ";
                        cin >> id;
                        deus.deleteDeus(id);
                        break;
                    case 'n':
                        char nome[50];
                        cout << "Digite o nome a ser deletado: ";
                        cin.ignore();
                        cin.getline(nome, 50);
                        deus.deleteDeus(nome);
                        break;
                    default:
                        break;
                }
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
