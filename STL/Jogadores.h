#include <iostream>
#include <list>

class Jogadores
{
    public:
        std::string nickname;
        int pontuacao;
        Jogadores(std::string n, int p) : nickname(n), pontuacao(p){};
};

class GerenciadorJogadores
{
    public:
        std::list<Jogadores> listaJogadores;
        void Inserir(std::string nome, int ponto);
        void Excluir(std::string nome);
        void Mostrar() const;
};
