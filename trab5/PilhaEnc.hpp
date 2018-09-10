// Copyright [2014]
// Mateus Rissi e Guilherme Noronha
// PilhaEnc.hpp

#ifndef FILAENC_H_
#define FILAENC_H_

#include <iostream>
#include <exception>
#include <cstdlib>
#include "Elemento.hpp"

using std::exception;

// ----------------ErroVazia
class ExcecaoVazia : public exception {
 public:
    virtual const char* what()const throw(){
        return("Pilha Vazia!");
    }
};
// ----------------ErroPosicao
class ExcecaoErroPosicao : public exception {
 public:
    virtual const char* what()const throw(){
        return("Erro Posicao!");
    }
};
// ----------------ErroCheia
class ExcecaoCheia : public exception {
 public:
    virtual const char* what()const throw(){
        return("Pilha Cheia! Toda a Memoria da pilha esta em uso!");
    }
};
// --------------------------------------------------------------------------

template <typename T>
class PilhaEnc{
 public:
    PilhaEnc() {
        lastIn = NULL;
		size = 0;
    }
    ~PilhaEnc() {
        limparPilha();
    }
    void empilha(const T& dado) {
		Elemento<T>* novo = new Elemento<T>(dado, NULL);
		if (novo == NULL) {
			throw ExcecaoCheia();
		} else {
		    novo -> setProximo(lastIn);
		    lastIn = novo;
		    size = size + 1;
		}
    }
    T desempilha() {
		if (PilhaVazia()) {
			throw ExcecaoVazia();
		} else {
			Elemento<T>* saiu;
			T volta;
			saiu = lastIn;
			volta = (saiu -> getInfo());
			lastIn = (lastIn -> getProximo());
			size = size -1;;
			delete saiu;
			return volta;
		}
    }
	T topo() {
		if (PilhaVazia()) {
			throw ExcecaoVazia();
		} else {
			return lastIn -> getInfo();
		}
	}
	void limparPilha() {
		Elemento<T>* atual;
		while (lastIn != NULL) {
			atual = lastIn;
			lastIn = lastIn -> getProximo();
			delete atual;
		}
		size = 0;
	}
	bool PilhaVazia() {
	    return (size == 0);
	}

 private:
    Elemento<T>* lastIn;
    int size;
};
#endif
