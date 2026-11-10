#include "Jogadores.h"
#include <string>

void GerenciadorJogadores::Inserir(std::string nome, int p){
    int pontos = p;
    for(std::list<Jogadores>::iterator it = listaJogadores.begin(); it != listaJogadores.end(); ++it){
        if(it -> nickname == nome){
            pontos += it -> pontuacao;
            listaJogadores.erase(it);
            break;
        }
    }

    std::list<Jogadores>::iterator pos = listaJogadores.begin();
    while(pos != listaJogadores.end()){
        if(pontos > pos -> pontuacao) break;
        else if(pontos == pos -> pontuacao && nome < pos -> nickname) break;
        ++pos;
    }

    listaJogadores.insert(pos, Jogadores(nome, pontos));
};

void GerenciadorJogadores::Excluir(std::string nome){
    for(std::list<Jogadores>::iterator it = listaJogadores.begin(); it != listaJogadores.end(); ++it){
        if(it -> nickname == nome){
            listaJogadores.erase(it);
            std::cout << "\nBanido!\n";
            return;
        }
    }
    std::cout << "\nJogador não encontrado!\n";
};

void GerenciadorJogadores::Mostrar() const {
    if(listaJogadores.empty()){
        std::cout << "\nSem jogadores cadastrados!\n";
        return;
    }
    std::cout << "\nTODOS OS JOGADORES\n";

    for(std::list<Jogadores>::const_iterator it = listaJogadores.begin(); it != listaJogadores.end(); ++it){
        std::cout << "Nome: " << it -> nickname << " | Pontuação: " << it -> pontuacao << "\n";
    }
};
