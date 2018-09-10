// Copyright [2014]
// Mateus Rissi e Guilherme Noronha
// FilaEnc.hpp

#ifndef FILAENC_H_
#define FILAENC_H_

#include <iostream>
#include <exception>
#include <cstdlib>
#include "Elemento.hpp"

using std::exception;

// ----------------ListaVazia
class ExcecaoVazia : public exception {
 public:
    virtual const char* what()const throw(){
        return("Fila Vazia!");
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
        return("Fila Cheia! Toda a Memoria da fila esta em uso!");
    }
};
// --------------------------------------------------------------------------

template <typename T>
class FilaEnc {
 private:
	Elemento<T>* lastIn;
	int size;

 public:
	FilaEnc() {
		lastIn = NULL;
		size = 0;
	}
	~FilaEnc() {
	    limparFila();
	}
	void inclui(const T& dado) {
		Elemento<T>* novo = new Elemento<T>(dado, NULL);
		if (novo == NULL) {
			throw ExcecaoCheia();
		} else {
			if(size == 0) {
				novo -> setProximo(lastIn);
				lastIn = novo;
				size++;
			} else {
				Elemento<T>* anterior;
				anterior = lastIn;
				for (int i = 0; i < size - 1; i++) {
					anterior = (anterior -> getProximo());
				}
				novo -> setProximo(anterior -> getProximo());
				anterior -> setProximo(novo);
				size++;
			}
		}
	}
	T retira() {
		if (filaVazia()) {
			throw ExcecaoVazia();
		} else {
			Elemento<T>* saiu;
			T volta;
			saiu = lastIn;
			volta = (saiu -> getInfo());
			lastIn = (lastIn -> getProximo());
			size--;
			delete saiu;
			return volta;
		}
	}
	T ultimo() {
		if (filaVazia()) {
			throw ExcecaoVazia();
		} else {
			Elemento<T>* anterior;
			anterior = lastIn;
			for (int i = 0; i < size - 1; i++) {
				anterior = (anterior -> getProximo());
			}
			return anterior -> getInfo();
		}
	}
	T primeiro() {
		if (filaVazia()) {
			throw ExcecaoVazia();
		} else {
			return lastIn->getInfo();
		}
	}
	void limparFila() {
		Elemento<T>* atual;
		while (lastIn != NULL) {
			atual = lastIn;
			lastIn = lastIn -> getProximo();
			delete atual;
		}
		size = 0;
	}
	bool filaVazia() {
		return (size == 0);
	}
};
#endif
