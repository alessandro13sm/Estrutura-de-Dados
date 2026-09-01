#include <iostream>
#include "Lode.h"

using namespace std;

void Menu(){
    system("cls"); // 'clear' para Linux
    cout << "1 - Inserir endereco\n";
    cout << "2 - Listar historico\n";
    cout << "3 - Voltar pagina\n";
    cout << "4 - Finalizar\n";
    cout << "Escolha: ";
}

int main()
{
    Lode **L, Lo;
    L = new Lode*[2];
    L[0] = L[1] = NULL;
    string url;
    int op;

    do {
        Menu();
        cin >> op;
        switch(op){
            case 1:
                cout << "Digite o link: ";
                cin.ignore();
                cin >> url;
                L = Lo.Inserir(L, url);
                cout << "Inserido com sucesso!\n";
                cout << "Pagina atual: " << url << "\n";
                break;
            case 2:
                if(L[0] == NULL){
                    cout << "Sem historico para listar!\n";
                } else{
                    cout << "---- HISTORICO ----\n";
                    Lo.Listar(L);
                }
                break;
            case 3:
                if(L[0] == NULL){
                    cout << "Sem paginas para voltar!\n";
                } else{
                    cout << "Pagina retrocedida com sucesso!\n";
                    L = Lo.Excluir(L);
                }
                break;
            case 4:
                cout << "Adios!\n";
                break;
            default:
                cout << "Opcao invalida!\n";
        }
        cout << "Aperte qualquer tecla para continuar...\n";
        cin.ignore().get();
    } while(op != 4);

    return 0;
}
