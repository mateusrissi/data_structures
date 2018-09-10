// Copyright 2014 Mateus Rissi & Guilherme Noronha. All rights reserved.


#ifndef PILHA_H_
#define PILHA_H_

#include "ErroPilhaCheia.hpp"
#include "ErroPilhaVazia.hpp"

/* Classe Pilha.hpp

	O conceito implementado pela pilha é o de “Last-in, 
	First-out” ou “Último a entrar, Primeiro a sair”.

FUNÇÕES:
	Pilha();
		Método construtor. Contém todas as instrucoes que sempre serao executadas 
		quando for instanciado um objeto desta classe.
		
		Zero elementos; 
		Tamanho "padrão".
	
	Pilha(int t);
		Método construtor. Contém todas as instrucoes que sempre serao executadas 
		quando for instanciado um objeto desta classe.
		
		Zero elementos;
		Busca o tamanho que vai ser utilizado para a pilha.
	
	Empilha(T dado);
		Método que insere um elemento (recebido como parâmetro) no topo da pilha.
	
	Desempilha();
		Método que retorna e remove o elemento que está no topo da pilha, ou seja,
		o último elemento inserido.
	
	Topo();
		Método que retorna o elemento que está no topo da Pilha.
	
	getPosTop();
		Método que retorna(em inteiro) a posição em que se encontra o ultimo elemento inserido,
		ou seja, o topo.
	
	limparPilha();
		Método que transforma em nulo todos os elementos da pilha e "reseta" a 
		posTopo(posTopo = -1) para limpar a pilha.
	
	PilhaVazia();
		Método que retorna um boolean para verificar se a pilha está vazia ou não.
		TRUE se estiver vazia e FALSE se a pilha possuir algum elemento.
	
	PilhaCheia();
		Método que retorna um boolean para verificar se a pilha está cheia ou não.
		TRUE se estiver cheia e FALSE se a pilha não estiver com o número máximo de elementos.

DADOS DOS MEMBROS:

	dados
		Responsável por conter os dados da pilha e disponibilizá-los para edição.
	
	posTopo
		Responsável por indicar o local onde está localizado o
        primeiro elemento da pilha.
	
	maxTam
		Responsável por indicar o tamanho máximo da pilha.
*/

template<typename T>
class Pilha {
 private:
	T* dados = new T[1000];
	int posTopo;
	int maxTam;

 public:
/*	Pilha()
 	Método construtor. Contém todas as instrucoes que sempre serao executadas 
	quando for instanciado um objeto desta classe.

	Zero elementos; 
	Tamanho "padrão".
*/
    Pilha() {
        posTopo = -1;
        maxTam = 1000;
    }
/*	Pilha(int t)
	Método construtor. Contém todas as instrucoes que sempre serao executadas 
	quando for instanciado um objeto desta classe.

	Zero elementos;
	Busca o tamanho que vai ser utilizado para a pilha.
*/
    Pilha<T>(int t) {
        posTopo = -1;
        dados = new T[t];
        maxTam = t;
    }
/*	void empilha(T dado)
	Método que insere um elemento (recebido como parâmetro) no topo da pilha.
*/
	void empilha(T dado) {
	    if (PilhaCheia()) {
        throw ErroPilhaCheia();
    } else {
            posTopo = posTopo + 1;
            dados[posTopo] = dado;
        }
	}
/* T desempilha()
	Método que retorna e remove o elemento que está no topo da pilha, ou seja,
	o último elemento inserido.
*/
	T desempilha() {
	    if (PilhaVazia()) {
        throw ErroPilhaVazia();
    } else {
            T aux = dados[posTopo];
            posTopo = posTopo - 1;
            return aux;
        }
	}
/* T topo()
	Método que retorna o elemento que está no topo da Pilha.
*/
	T topo() {
		if (PilhaVazia()) {
	        throw ErroPilhaVazia();
	    } else {
	        return dados[posTopo];
	    }
	}
/* int getPosTopo()
	Método que retorna(em inteiro) a posição em que se encontra o ultimo elemento inserido,
	ou seja, o topo.
*/
	int getPosTopo() {
	    if (PilhaVazia()) {
	        throw ErroPilhaVazia();
	    } else {
	        return posTopo;
	    }
	}
/* void limparPilha()
	Método que seta o posTopo para -1 para limpar a pilha.
*/
	void limparPilha() {
	    posTopo = -1;
	}
/* bool PilhaVazia()
	Método que retorna um boolean para verificar se a pilha está vazia ou não.
	TRUE se estiver vazia e FALSE se a pilha possuir algum elemento.
*/
	bool PilhaVazia() {
	    return (posTopo == -1);
	}
/* bool PilhaCheia()
	Método que retorna um boolean para verificar se a pilha está cheia ou não.
	TRUE se estiver cheia e FALSE se a pilha não estiver com o número máximo de elementos.
*/
	bool PilhaCheia() {
	    return (posTopo == (maxTam-1));
	}
};
#endif
