// Copyright [2014]
// Mateus Rissi e Guilherme Noronha
// ExcecaoDadoInexistente.h
// Classe de excecao para dados que nao existem na estrutura
// Trata excecoes quando a lista não encontra o elemento solicitado

#ifndef EXCECAODADOINEXISTENTE_H_
#define EXCECAODADOINEXISTENTE_H_
#include <exception>

class ExcecaoDadoInexistente {
 public:
// Metodo responsavel por descrever o erro relacionado a excecao
// Retorna um char*
    virtual const char* what()const throw(){
        return("Dado não encontrado!");
    }
};

#endif
