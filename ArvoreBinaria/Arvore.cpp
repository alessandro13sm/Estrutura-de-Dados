#include "Arvore.h"

Arvore* Arvore::Inserir(Arvore *P, int N){
    Arvore *novo, *aux = P;
    if(aux == NULL){
        novo = new Arvore();
        novo -> num = N;
        novo -> esq = NULL;
        novo -> dir = NULL;
        aux = novo;
    } else if(N < aux -> num){
        aux -> esq = Inserir(aux -> esq, N);
    } else{
        aux -> dir = Inserir(aux -> dir, N);
    }
    return aux;
};

void Arvore::MostrarPreOrdem(Arvore *P){
    Arvore *aux = P;
    if(aux != NULL){
        std::cout << aux -> num << " ";
        MostrarPreOrdem(aux -> esq);
        MostrarPreOrdem(aux -> dir);
    }
};

void Arvore::MostrarEmOrdem(Arvore *P){
    Arvore *aux = P;
    if(aux != NULL){
        MostrarEmOrdem(aux -> esq);
        std::cout << aux -> num << " ";
        MostrarEmOrdem(aux -> dir);
    }
};

void Arvore::MostrarPosOrdem(Arvore *P){
    Arvore *aux = P;
    if(aux != NULL){
        MostrarPosOrdem(aux -> esq);
        MostrarPosOrdem(aux -> dir);
        std::cout << aux -> num << " ";
    }
};

void Arvore::Somar(Arvore *P, int *S){
    Arvore *aux = P;
    if(aux != NULL){
        (*S) += aux -> num;
        Somar(aux -> esq, S);
        Somar(aux -> dir, S);
    }
};

Arvore* Arvore::Remover(Arvore *P, int N){
    Arvore *p1, *p2, *aux = P;
    if(aux -> num == N){
        if(aux -> esq == aux -> dir){
            delete(aux);
            return NULL;
        }
        else if(aux -> esq == NULL){
            p1 = aux -> dir;
            delete(aux);
            return p1;
        } else if(aux -> dir == NULL){
            p1 = aux -> esq;
            delete(aux);
            return p1;
        } else{
            p2 = aux -> dir;
            p1 = aux -> dir;
            while(p1 -> esq != NULL){
                p1 = p1 -> esq;
            }
            p1 -> esq = aux -> esq;
            delete(aux);
            return p2;
        }
    } else if(aux -> num < N){
        aux -> dir = Remover(aux -> dir, N);
    } else{
        aux -> esq = Remover(aux -> esq, N);
    }
    return aux;
};

Arvore* Arvore::Esvaziar(Arvore *P){
    if(P == NULL) return P;
    Esvaziar(P -> esq);
    Esvaziar(P -> dir);
    delete(P);
    P = NULL;
    return P;
};
