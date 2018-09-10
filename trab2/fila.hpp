// Copyright 2014 Mateus Rissi & Guilherme Noronha. All rights reserved.

#ifndef FILA_H_
#define FILA_H_

#include "ErroFilaCheia.hpp"
#include "ErroFilaVazia.hpp"

template <typename T>
class Fila {
 private:
	T* dados = new T[1000];
	int lastIn;
	int maxTam;

 public:
/*	Fila()
		Metodo construtor. Executa o metodo inicializaPilha() (metodo tal que cria uma fila "padrao").
*/
	Fila() {
		inicializaFila();
	}
/*	Fila(int tam)
		Metodo construtor. Contem todas as instrucoes que sempre serao executadas 
		quando for instanciado um objeto desta classe.
		
		Zero elementos;
		Busca o tamanho que vai ser utilizado para a fila.
*/
	Fila<T>(int tam) {
		lastIn = -1;
		dados = new T[tam];
		maxTam = tam;
	}
/*	void inclui()
		Metodo que insere um elemento (recebido como parametro) no final da fila.
*/
	void inclui(T dado) {
		if (filaCheia()) {
			throw ErroFilaCheia();
		} else {
			lastIn = lastIn +1;
			dados[lastIn] = dado;
		}
	}
/*	T retira()
		Metodo que retorna e remove o elemento que está no final da fila, ou seja,
		o ultimo elemento inserido.
*/
	T retira() {
		if (filaVazia()) {
			throw ErroFilaVazia();
		} else {
	   		T aux = dados[0];

	   		for(int i = 1; i <= lastIn; i++) {
	   			dados[i-1] = dados[i];
	   		}
	   		lastIn = lastIn - 1;
	   		return aux;
		}
	}
/*	T ultimo()
		Metodo que retorna o ultimo elemento inserido na fila.
*/
	T ultimo() {
	    if (filaVazia()) {
	        throw ErroFilaVazia();
	    } else {
	        return dados[lastIn];
	    }
	}
/*	int getUltimo()
		Metodo que retorna(em inteiro) a posição em que se encontra o ultimo elemento da fila.
*/
	int getUltimo() {
		return lastIn;
	}
/*	bool filaCheia()
		Metodo que retorna um boolean para verificar se a fila esta cheia ou nao.
		TRUE se estiver cheia e FALSE se a fila não estiver cheia.
*/
	bool filaCheia() {
		return (lastIn == (maxTam-1));
	}
/*	bool filaVazia()
		Metodo que retorna um boolean para verificar se a fila esta vazia ou nao.
		TRUE se estiver vazia e FALSE se a fila possuir algum elemento.
*/
	bool filaVazia() {
		return (lastIn == -1);
	}
/*	void inicializaFila()
		Metodo que cria uma fila "padrao".
		
		Zero elementos;
		Tamanho 1000;
*/
	void inicializaFila() {
		maxTam = 1000;
		lastIn = -1;
	}
};
#endif
