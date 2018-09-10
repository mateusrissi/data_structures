// Copyright [2014]
// Mateus Rissi e Guilherme Noronha
// ListaEnc.hpp

#ifndef LISTAENC_HPP
#define LISTAENC_HPP

#include <iostream>
#include <exception>
#include "Elemento.hpp"

using std::exception;

// ----------------ErroVazia
// Classe de excecao para estrutura vazia
// Trata excecoes quando a lista esta vazia
class ExcecaoVazia : public exception {
 public:
// Metodo responsavel por descrever o erro relacionado a excecao
// Retorna um char*
    virtual const char* what()const throw(){
        return("Lista Vazia!");
    }
};
// ----------------ErroPosicao
// Classe de excecao para posicao invalida na estrutura
// Trata excecoes quando a lista solicita uma posicao inexistente
class ExcecaoErroPosicao : public exception {
 public:
// Metodo responsavel por descrever o erro relacionado a excecao
// Retorna um char*
    virtual const char* what()const throw(){
        return("Erro Posicao!");
    }
};
// ----------------ErroCheia
// Classe de excecao para estrutura cheia
// Trata excecoes quando a lista esta cheia
class ExcecaoCheia : public exception {
 public:
// Metodo responsavel por descrever o erro relacionado a excecao
// Retorna um char*
    virtual const char* what()const throw(){
        return("Lista Cheia! Toda a Memoria da Lista esta em uso!");
    }
};
// ----------------ErroDadoInexistente
// Classe de excecao para dados que nao existem na estrutura
// Trata excecoes quando a lista não encontra o elemento solicitado
class ExcecaoDadoInexistente : public exception {
 public:
// Metodo responsavel por descrever o erro relacionado a excecao
// Retorna um char*
    virtual const char* what()const throw(){
        return("Dado não encontrado!");
    }
};
// --------------------------------------------------------------------------
// Classe lista encadeada
// Sao listas onde cada elemento contido em uma lista esta armazenado
// em um Tipo Abstrato de Dado chamado elemento de lista. Cada elemento
// de lista referencia o proximo e so e alocado dinamicamente quando
// necessario. Para referenciar o primeiro elemento utilizamos um Tipo
// Abstrato de Dado cabeca de lista.
template<typename T>
class ListaEnc {
 public:
// Constutor
// Construtor basico da classe
	ListaEnc() {
		head = NULL;
		size = 0;
	}
// Destrutor
// Destrutor que deleta todos os nos
	~ListaEnc() {
		destroiLista();
	}
// Metodo para adicionar um dado no inicio da lista
	void adicionaNoInicio(const T& dado) {
		Elemento<T>* novo = new Elemento<T>(dado, NULL);
        if (novo == NULL) {
            throw ExcecaoCheia();
            } else {
                    novo -> setProximo(head);
		            head = novo;
		            size = size + 1;
		    }
	}
// Metodo para retirar um dado do inicio da lista
// Retorna o dado retirado do inicio da lista
	T retiraDoInicio() {
		if (listaVazia()) {
			throw ExcecaoVazia();
		} else {
			Elemento<T>* saiu;
			T volta;
			saiu = head;
			volta = (saiu -> getInfo());
			head = (head -> getProximo());
			size = size - 1;
			delete saiu;
			return volta;
		}
	}
// Metodo para eliminar o no do inicio da lista
	void eliminaDoInicio() {
		if (listaVazia()) {
			throw ExcecaoVazia();
		} else {
			Elemento<T>* saiu;
			saiu = head;
			head = (head -> getProximo());
			size = size - 1;
			delete saiu;
		}
	}
// Metodo para adicionar um dado em determinada posicao da lista
	void adicionaNaPosicao(const T& dado, int pos) {
		if (pos >= size + 1 || pos < 0) {
			throw ExcecaoErroPosicao();
		} else {
		    if (pos == 0) {
		    		adicionaNoInicio(dado);
		        } else {
		            Elemento<T>* novo = new Elemento<T>(dado, NULL);
		            if (novo == NULL) {
		                    throw ExcecaoCheia();
		                } else {
		                    Elemento<T>* anterior;
		                	anterior = head;
		                	for (int i = 0; i < pos - 1; i++) {
		                		anterior = (anterior -> getProximo());
		                	}
		                	novo -> setProximo(anterior -> getProximo());
		            	    anterior -> setProximo(novo);
		                	size = size + 1;
		                }
		         }
	       }
    }
// Metodo que retorna a posicao de um determinado dado da lista
// Retorna um inteiro contendo a posicao do dado especificado
	int posicao(const T& dado) const {
	    	if (listaVazia()) {
	    		throw ExcecaoVazia();
	    	} else {
	    		Elemento<T>* aux = head;
	    		for (int i = 0; i < size; i++) {
	    			if (dado == aux -> getInfo()) {
	    				return i;
	    			} else {
	    				aux = aux -> getProximo();
	    			}
	    		}
	    		throw ExcecaoErroPosicao();
	    	}
	}
// Metodo que retorna a posicao na memoria de um determinado dado da lista
// Retorna um ponteiro relacionado ao dado especificado
	T* posicaoMem(const T& dado) const {
		if (listaVazia()) {
			throw ExcecaoVazia();
		} else {
			Elemento<T>* aux = head;
			for (int i = 0; i < size; i++) {
				if (dado == aux -> getInfo()) {
					return aux -> getInfo();
				} else {
					aux = aux -> getProximo();
				}
			}
			throw ExcecaoErroPosicao();
		}
	}
// Metodo para verificar se existe a presenca de determinado dado na lista
// Retorna um booleano
	bool contem(const T& dado) {
	    if (listaVazia()) {
	        throw ExcecaoVazia();
	        } else {
	    	    Elemento<T>* aux;
	        	aux = head;
	        	for (int i = 0; i < size; i++) {
	    		    if (dado == aux -> getInfo()) {
	    		    	return true;
	    		    } else {
	    		    	aux = aux -> getProximo();
	    		    }
	    	    }
	        	return false;
	    	}
	}
// Metodo para retirar o dado de determinada posicao
// Retorna o dado retirado da posicao determinada
	T retiraDaPosicao(int pos) {
		if (listaVazia()) {
			throw ExcecaoVazia();
		} else {
			if (pos > size || pos < 0) {
				throw ExcecaoErroPosicao();
			} else {
				if (pos == 0) {
					return retiraDoInicio();
				} else {
					Elemento<T>* anterior;
					Elemento<T>* eliminar;
					T volta;
					anterior = head;
					for (int i = 0; i < pos - 2; i++) {
						anterior = anterior -> getProximo();
					}
					eliminar = anterior -> getProximo();
					volta = eliminar -> getInfo();
					anterior -> setProximo(eliminar -> getProximo());
					size = size - 1;
					delete eliminar;
					return volta;
				}
			}
		}
	}
// Metodo que adiciona determinado dado no fim da lista
	void adiciona(const T& dado) {
		if (listaVazia()) {
			adicionaNoInicio(dado);
		} else {
			adicionaNaPosicao(dado, size);
		}
	}
// Metodo que retira o ultimo dado da lista
// Retorna o dado retirado do fim da lista
	T retira() {
		if (listaVazia()) {
			throw ExcecaoVazia();
		} else {
			return retiraDaPosicao(size);
		}
	}
// Metodo que retira um dado especifico da lista
// Retorna o dado retirado da lista
	T retiraEspecifico(const T& dado) {
		if (listaVazia()) {
			throw ExcecaoVazia();
		} else {
			int pos = posicao(dado);
			return retiraDaPosicao(pos+1);
		}
	}
// Metodo para adicionar um dado em uma posicao especifica da lista
// de acordo com a ordem inerente da classe
	void adicionaEmOrdem(const T& data) {
		if (listaVazia()) {
			adicionaNoInicio(data);
		} else {
			Elemento<T>* novo;
			int pos = 1;
			novo = head;
			while ((novo -> getProximo()) != NULL && maior(data, (novo -> getInfo()))) {
				novo = novo -> getProximo();
				pos = pos + 1;
			}
			adicionaNaPosicao(data, pos);
		}
	}
// Metodo para verificar se a lista esta vazia
// Retorna um booleano TRUE caso a lista estiver vazia
// Retorna um booleano FALSE caso a lista não estiver vazia
	bool listaVazia() const {
		return (size == 0);
	}
// Metodo de comparacao de igualdade entre dois dados
// Retorna um booleano TRUE caso os dados forem iguais
// Retorna um booleano FALSE caso os dados forem diferentes
	bool igual(T dado1, T dado2) {
		return (dado1 == dado2);
	}
// Metodo que verifica qual o maior entre dois dados
// Retorna um booleano TRUE caso o primeiro dado seja o maior
// Retorna um booleano FALSE caso o segundo dado seja o maior
	bool maior(T dado1, T dado2) {
		return (dado1 > dado2);
	}
// Metodo que verifica qual o menor entre dois dados
// Retorna um booleano TRUE caso o primeiro dado seja o menor
// Retorna um booleano FALSE caso o segundo dado seja o menor
	bool menor(T dado1, T dado2) {
		return (dado1 < dado2);
	}
// Metodo que elimina todos os elementos da lista
	void destroiLista() {
		Elemento<T>* atual;
	    while (head != NULL) {
	        atual = head;
	        head = head -> getProximo();
	        delete atual;
	    }
	    size = 0;
	}

 private:
// Cabeca da Lista Encadeada
// Descreve o primeiro nó da lista encadeada
	Elemento<T>* head;
// Identificador de tamanho
// Tamanho da lista encadeada
	int size;
};

#endif
