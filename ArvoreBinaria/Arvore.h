#include <iostream>

class Arvore
{
    public:
        int num;
        Arvore *dir, *esq;
        Arvore* Inserir(Arvore*, int);
        void MostrarPreOrdem(Arvore*);
        void MostrarEmOrdem(Arvore*);
        void MostrarPosOrdem(Arvore*);
        void Somar(Arvore*, int*);
        Arvore* Remover(Arvore*, int);
        Arvore* Esvaziar(Arvore*);
};
