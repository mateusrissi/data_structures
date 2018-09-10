/* Copyright <Mateus Rissi e Guilherme Noronha>
 * Lista.hpp
 */

#ifndef LISTA_H_
#define LISTA_H_

#include <exception>
using namespace std;

// -----------------ListaCheia
class ExcecaoListaCheia : public exception {
 public:
    virtual const char* what()const throw(){
        return("Excecao Lista Cheia!");
    }
};
// ----------------ListaVazia
class ExcecaoListaVazia : public exception {
 public:
    virtual const char* what()const throw(){
        return("Excecao Lista Vazia!");
    }
};
// ----------------ErroPosicao
class ExcecaoErroPosicao : public exception {
 public:
    virtual const char* what()const throw(){
        return("Erro Posição!");
    }
};
// --------------------------------------------------------------------------

template<typename T>
class Lista {
 private:
	T* dados;
	int lastIn;
	int maxTam;

 public:
// Construtor da Lista
	Lista() {
		dados = new T[1000];
		lastIn = -1;
		maxTam = 1000;
	}
// Construtor da Lista onde o cliente decide o tamanho
	explicit Lista(int tam) {
		dados = new T[tam];
		lastIn = -1;
		maxTam = tam;
	}
// Adiciona um dado na Lista. Retorna uma exceção caso a lista estiver cheia
	void adiciona(T dado) {
		if (listaCheia()) {
			throw ExcecaoListaCheia();
		} else {
			lastIn = lastIn + 1;
			dados[lastIn] = dado;
		}
	}
// Adiciona um dado no inicio da lista. Joga todos os outros dados uma
// posicao para cima para entao adicionar o dado no inicio.
// Retorna uma exceção caso a lista estiver cheia
	void adicionaNoInicio(T dado) {
		if (listaCheia()) {
	    	throw ExcecaoListaCheia();
	    } else {
	        lastIn = lastIn + 1;

	        for (int i = lastIn; i > 0; i--) {
	        	dados[i] = dados[i - 1];
	        }
	        dados[0] = dado;
	    }
	}
// Adiciona um dado na posicao escolhida. Joga todos os outros dado acima
// da posicao escolhida para uma posicao para cima para entao adicionar o
// dado na posicao desejada. Retorna uma exceção caso a lista estiver cheia
	void adicionaNaPosicao(T dado, int posicao) {
	    if (listaCheia()) {
	    	throw ExcecaoListaCheia();
	    } else {
	        if (posicao > lastIn + 1 || lastIn < 0) {
	        	throw ExcecaoErroPosicao();
	        } else {
	        	lastIn = lastIn +1;
	        	for(int i = lastIn; i > posicao; i--) {
	        		dados[i] = dados[i-1];
	        	}
	        	dados[posicao] = dado;
	        }
	    }
	}
// Adiciona um dado na lista do menor para o maior. O metodo verifica
// cada posicao até encontrar um dado maior do que o que se deseja inserir.
// Quando encontra retorna o metodo adicionaNaPosicao.
// Retorna uma exceção caso a lista estiver cheia
	void adicionaEmOrdem(T dado) {
		if (listaCheia()) {
			throw ExcecaoListaCheia();
		} else {
			int posicao = 0;
			while (posicao <= lastIn && maior(dado , dados[posicao])) {
				posicao = posicao + 1;
			}
			adicionaNaPosicao(dado , posicao);
		}
	}
// Retira o dado em que esta na ultima posicao da lista.
// Retorna uma exceção caso a lista estiver vazia
	T retira() {
		if (listaVazia()) {
			throw ExcecaoListaVazia();
		} else {
			T aux = dados[lastIn];
			lastIn = lastIn - 1;
			return aux;
		}
	}
// Retira o dado que esta no inicio da lista. Joga todos os outros dados
// uma posicao para baixo. Retorna uma exceção caso a lista estiver vazia
	T retiraDoInicio() {
		if (listaVazia()) {
			throw ExcecaoListaVazia();
		} else {
			T aux = dados[0];
			lastIn = lastIn - 1;
			for(int i = 0; i <= lastIn; i++) {
				dados[i] = dados[i+1];
			}
			return aux;
		}
	}
// Retira o dado da posicao escolhida. Joga os dados que estao acima
// da posicao escolhida para uma posicao para baixo. Retorna uma
// exceção caso a posicao escolhida nao exista ou caso a lista estiver vazia
	T retiraDaPosicao(int posicao) {
		if (posicao > lastIn || posicao < 0) {
			throw ExcecaoErroPosicao();
		} else {
			if (listaVazia()) {
				throw ExcecaoListaVazia();
			} else {
				T aux = dados[posicao];
				lastIn = lastIn -1;
				for(int i = posicao; i <= lastIn; i++) {
					dados[i] = dados[i+1];
				}
				return aux;
			}
		}
	}
// Retira um dado especificado. Verifica cada posicao ate encontrar
// um dado igual ao procurado. Quando o encontra retorna o metodo
// retiraDaPosicao. Retorna uma excecao caso a lista estiver vazia
	T retiraEspecifico(T dado) {
		if (listaVazia()) {
			throw ExcecaoListaVazia();
		} else {
			int pos = posicao(dado);
			if(pos > lastIn || pos < 0) {
				throw ExcecaoErroPosicao();
			} else {
				return retiraDaPosicao(pos);
			}
		}
	}
// Retorna em int a posicao de determinado dado na lista.
// Retorna uma excecao caso o dado nao exista.
	int posicao(T dado) {
		int pos = 0;
		while(pos <= lastIn && !(igual(dado , dados[pos]))) {
			pos = pos + 1;
		}
		if (pos > lastIn) {
			throw ExcecaoErroPosicao();
		} else {
			return pos;
		}
	}
// Verifica cada posicao da lista ate encontrar um dado igual ao procurado.
// Retorna um boolean TRUE caso encontre ou FALSE se nao existir tal dado.
// Retorna uma excecao se a lista estiver vazia.
	bool contem(T dado) {
		if (listaVazia()) {
			throw ExcecaoListaVazia();
		} else {
			for(int i = 0; i <= lastIn; i++) {
				return (igual(dado , dados[i]));
			}
			return false;
		}
	}
// Verifica se dois dados da lista sao iguais.
// Retorna um boolean TRUE caso forem iguais ou FALSE se forem diferentes
	bool igual(T dado1, T dado2) {
		return (dado1 == dado2);
	}
// Verifica qual dado e o maior entre dois dados da lista.
// Retorna um boolean TRUE caso o dado1 for o maior ou FALSE caso o dado2
// for o maior
	bool maior(T dado1, T dado2) {
		return (dado1 > dado2);
	}
// Verifica qual dado e o menor entre dois dado da lista.
// Retorna um boolean TRUE caso o dado1 for o menor ou FALSE caso o dado2
// for o menor
	bool menor(T dado1, T dado2) {
		return (dado1 < dado2);
	}
// Verifica se a lista esta cheia. Retorna um boolean TRUE caso a lista
// estiver cheia ou FALSE caso nao estiver
	bool listaCheia() {
		return (lastIn == (maxTam - 1));
	}
// Verifica se a lista esta vazia. Retorna um boolean TRUE caso a lista
// estiver vazia ou FALSE caso nao estiver
	bool listaVazia() {
		return (lastIn == -1);
	}
// Destroi a lista
	void destroiLista() {
		lastIn = -1;
	}
};
#endif
