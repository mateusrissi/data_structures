// Copyright [2014]
// Mateus Rissi e Guilherme Noronha
// ExcecaoCheia.h
// Classe de excecao para posicao invalida na estrutura
// Trata excecoes quando a lista solicita uma posicao inexistente

#ifndef EXCECAOERROPOSICAO_H_
#define EXCECAOERROPOSICAO_H_
#include <exception>

class ExcecaoErroPosicao {
 public:
// Metodo responsavel por descrever o erro relacionado a excecao
// Retorna um char*
    virtual const char* what()const throw(){
        return("Erro Posicao!");
    }
};

#endif
