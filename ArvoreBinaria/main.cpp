#include <iostream>
#include "Arvore.h"

using namespace std;

void Menu(){
    system("clear");
    cout << "1 - Gerar Árvore\n";
    cout << "2 - Apresentar valore pré-ordem\n";
    cout << "3 - Apresentar valore em ordem\n";
    cout << "4 - Apresentar valore pós-ordem\n";
    cout << "5 - Esvaziar Árvore\n";
    cout << "6 - Apresentar somatório de nós\n";
    cout << "7 - Verificar se a soma dos números corresponde à um número perfeito\n";
    cout << "8 - Finalizar\n";
    cout << "Escolha: ";
}

int main()
{
    Arvore *raiz = NULL, obj;
    int n, qtd = 0, soma = 0, op;
    srand(time(NULL));

    do{
        Menu();
        cin >> op;
        switch(op){
            case 1:
                while(qtd < 30){
                    n = rand() % 100 + 1;
                    raiz = obj.Inserir(raiz, n);
                    qtd++;
                }
                cout << "ARVORE FOI GERADA!\n";
                break;
            case 2:
                if(raiz == NULL) cout << "Árvore vazia!\n";
                else {
                    cout << "--- PRÉ-ORDEM ---\n";
                    obj.MostrarPreOrdem(raiz);
                }
                break;
            case 3:
                if(raiz == NULL) cout << "Árvore vazia!\n";
                else {
                    cout << "--- PRÉ EM ORDEM ---\n";
                    obj.MostrarEmOrdem(raiz);
                }
                break;
            case 4:
                if(raiz == NULL) cout << "Árvore vazia!\n";
                else {
                    cout << "--- PÓS-ORDEM ---\n";
                    obj.MostrarPosOrdem(raiz);
                }
                break;
            case 5:
                if(raiz == NULL) cout << "Árvore já está vazia!\n";
                else {
                    raiz = obj.Esvaziar(raiz);
                    cout << "Árvore foi esvaziada!\n";
                }
                break;
            case 6:
                if(raiz == NULL) cout << "Somatório: 0\n";
                else {
                    obj.Somar(raiz, &soma);
                    cout << "Somatório: " << soma << "\n";
                }
                soma = 0;
                break;
            case 7:
                if(raiz == NULL) cout << "É perfeito!\n";
                else {
                    int divisores = 0;
                    soma = 0;
                    obj.Somar(raiz, &soma);
                    for(int i = 1; i < soma; i++){
                        if(soma % i == 0)
                            divisores += i;
                    }
                    if(divisores == soma) cout << "É perfeito!\n";
                    else cout << "Não é perfeito!\n";
                }
                break;
            case 8:
                cout << "Adios!\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }
        cout << "Tecle qualquer tecla para continuar...\n";
        cin.ignore().get();
    } while(op != 8);

    return 0;
}
