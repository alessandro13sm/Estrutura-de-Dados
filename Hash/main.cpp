#include "Hash.h"
#include <fstream> // biblioteca que le o arquivo na memória
#include <sstream> // trata as strings

#define TAM 27

using namespace std;

int main()
{
    Hash *tabela[TAM], obj;
    int totais[TAM];
    string linha, coluna1, nome, plataforma, genero, ano;
    int pos, i;

    // inicialização da tabela e totais
    for(i = 0; i < TAM; i++){
        tabela[i] = NULL;
        totais[i] = 0;
    }
    ifstream arquivo("VideoGames.csv");
    if(!arquivo.is_open()){
        cout << "Erro ao abrir arquivo!\n";
        return 1;
    }
    getline(arquivo, linha);
    while(getline(arquivo, linha)){ // enquanto houver linhas no arquivo .csv
        stringstream ss(linha); // pega a linha e quebra as linhas em diferentes variáveis abaixo
        getline(ss, coluna1, ',');
        getline(ss, nome, ',');
        getline(ss, plataforma, ',');
        getline(ss, ano, ',');
        getline(ss, genero, ',');
        pos = obj.funcao_hashing(genero);
        obj.Inserir(tabela, pos, nome, plataforma, genero, ano);
        totais[pos]++;
    }
    arquivo.close(); // fecha o arquivo na memória
    cout << "\n------ Tabela Hash carregada ------\n";
    obj.mostrar_hash(tabela, totais, TAM);

    return 0;
}
