#include "Lode.h"

Lode** Lode::Inserir(Lode **R, std::string U){
    Lode *novo = new Lode();
    novo -> url = U;
    if(R[0] == NULL){
        R[0] = R[1] = novo;
        R[0] -> anterior = NULL;
        R[1] -> proximo = NULL;
    } else{
        R[1] -> proximo = novo;
        novo -> anterior = R[1];
        R[1] = novo;
        R[1] -> proximo = NULL;
    }
    return R;
};

Lode** Lode::Excluir(Lode **R){
    Lode *aux = R[1];
    if(R[0] == R[1]){
        std::cout << "Somente uma pagina foi aberta. A navegacao sera encerrada!\n";
        R[0] = R[1] = NULL;
    } else{
        R[1] = R[1] -> anterior;
        R[1] -> proximo = NULL;
        std::cout << "Pagina atual: " << R[1] -> url << "\n";
    }
    delete(aux);
    return R;
};

void Lode::Listar(Lode **R){
    Lode *aux = R[1];
    while(aux != NULL){
        std::cout << aux -> url << "\n";
        aux = aux -> anterior;
    }
};
