#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

struct Deuses {
    int Id;
    char Nome[50]; 
    char Dominio[50];
    char Biografia[200];
};

int main(int argc, char *argv[]) {
    fstream arq("deuses.dat", ios_base::in|ios_base::out|ios_base::binary|ios_base::app);
    Deuses deus;
    do{
        cout << "id: ";
        cin >> deus.Id;
        if(deus.Id < 1)
            break;
        
        cin.ignore();
        
        cout << endl << "Nome: ";
        cin.getline(deus.Nome, 50);
        if(strlen(deus.Nome) == 0) 
            break;

        cout << endl << "Dominio: ";
        cin.getline(deus.Dominio, 50);
        if(strlen(deus.Dominio) == 0)
            break;
        
        cout << endl << "Biografia: ";
        cin.getline(deus.Biografia, 200);
        if(strlen(deus.Biografia) == 0)
            break;

        arq.write((char *) &deus, sizeof(Deuses));
    } while(1);

    arq.seekg(0, ios_base::beg);

    while(arq.read((char *) &deus, sizeof(Deuses))){
        cout << "Id: " << deus.Id << endl;
        cout << "Nome: " << deus.Nome << endl;
        cout << "Dominio: " << deus.Dominio << endl;
        cout << "Biografia: " << deus.Biografia << endl;
    }

    arq.close();
}