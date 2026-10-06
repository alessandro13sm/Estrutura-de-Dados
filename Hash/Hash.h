#include <iostream>

class Hash
{
    public:
        std::string nome, plataforma, genero, ano;
        Hash *prox;
        int funcao_hashing(std::string);
        void mostrar_hash(Hash *[], int[], int);
        void Inserir(Hash *[], int, std::string, std::string, std::string, std::string);
};
