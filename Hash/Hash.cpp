#include "Hash.h"

int Hash::funcao_hashing(std::string chave){
    int resultado = 0;
    for(int i = 0; i < chave.length(); i++)
        resultado += (int)chave[i];
    return resultado % 29;
};

void Hash::mostrar_hash(Hash *tabela[], int totais[], int T){
    Hash *aux;
    for(int i = 0; i < T; i++){
        aux = tabela[i];
        if(totais[i] > 0){
            std::cout << "Gênero: " << aux -> genero << " " << totais[i] << "\n";
            while(aux != NULL){
                std::cout << "Entrada: " << i << ": " << aux -> nome << "\n";
                aux = aux -> prox;
            }
        }
    }
};

void Hash::Inserir(Hash *tabela[], int pos, std::string n, std::string p, std::string g,std::string a){
    Hash *novo = new Hash();
    novo -> nome = n;
    novo -> plataforma = p;
    novo -> genero = g;
    novo -> ano = a;
    novo -> prox = tabela[pos];
    tabela[pos] = novo;
};
