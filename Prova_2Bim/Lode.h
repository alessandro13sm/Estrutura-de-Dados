#include <iostream>

class Lode
{
    public:
        std::string url;
        Lode *anterior, *proximo;
        Lode** Inserir(Lode**, std::string);
        Lode** Excluir(Lode**);
        void Listar(Lode**);
};
