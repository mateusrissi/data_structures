// Copyright [2014]
// Mateus Rissi e Guilherme Noronha
// ExcecaoVazia.h
// Classe de excecao para estrutura vazia
// Trata excecoes quando a lista esta vazia

#ifndef EXCECAOVAZIA_H_
#define EXCECAOVAZIA_H_
#include <exception>

class ExcecaoVazia {
 public:
// Metodo responsavel por descrever o erro relacionado a excecao
// Retorna um char*
    virtual const char* what()const throw(){
        return("Lista Vazia!");
    }
};

#endif
