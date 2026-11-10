#include <iostream>
#include <limits>
#include "Jogadores.h"

using namespace std;

void Menu(){
    system("clear");
    cout << "1 - Inserir / Atualizar Jogador\n";
    cout << "2 - Excluir Jogador\n";
    cout << "3 - Exibir Ranking Geral\n";
    cout << "4 - Finalizar o programa\n";
    cout << "Escolha: ";
}

int main()
{
    GerenciadorJogadores gerenciador;
    string nickname;
    int pontuacao, op;

    do{
        Menu();
        cin >> op;
        switch(op){
            case 1:
                cout << "Informe o nome: ";
                cin >> nickname;
                cout << "Informe a pontuação: ";
                cin >> pontuacao;
                gerenciador.Inserir(nickname, pontuacao);
                break;
            case 2:
                cout << "Informe o nome: ";
                cin >> nickname;
                gerenciador.Excluir(nickname);
                break;
            case 3:
                gerenciador.Mostrar();
                break;
            case 4:
                cout << "Fim!\n";
                break;
            default:
                cout << "Opção inválida!\n";
                break;
        }

        if(op != 4){
            cout << "\nTecle ENTER para prosseguir... ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
    } while(op != 4);

    return 0;
}
