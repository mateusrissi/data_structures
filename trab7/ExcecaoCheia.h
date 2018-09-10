// Copyright [2014]
// Mateus Rissi e Guilherme Noronha
// ExcecaoCheia.h
// Classe de excecao para estrutura cheia
// Trata excecoes quando a lista esta cheia

#ifndef EXCECAOCHEIA_H_
#define EXCECAOCHEIA_H_
#include <exception>

class ExcecaoCheia {
 public:
// Metodo responsavel por descrever o erro relacionado a excecao
// Retorna um char*
    virtual const char* what()const throw(){
        return("Lista Cheia! Toda a Memoria da Lista esta em uso!");
    }
};

#endif
