// Copyright [2014]
// Mateus Rissi e Guilherme Noronha
// ListaEnc.hpp

#ifndef LISTACIRC_HPP_
#define LISTACIRC_HPP_
#include "ListaEnc.hpp"

template<typename T>
class ListaCirc : public ListaEnc<T> {
 public:
  ListaCirc();
  void adiciona(const T& dado);
  void adicionaEmOrdem(const T& data);
  void adicionaNaPosicao(const T& dado, int pos);
  void adicionaNoInicio(const T& dado);
  void eliminaDoInicio();
  T retira();
  T retiraDaPosicao(int pos);
  T retiraDoInicio();
  T retiraEspecifico(const T& dado);
  bool contem(const T& dado);
  int posicao(const T& dado) const;
  T* posicaoMem(const T& dado) const;
  T mostra(int pos);
  int verUltimo();
};

template<typename T>
ListaCirc<T>::ListaCirc() {
    Elemento<T>* sentinela = new Elemento<T>(0, 0);
    this->cabeca = sentinela;
    sentinela->setProximo(this->cabeca);
    this->tamanho = 0;
}

template<typename T>
void ListaCirc<T>::adiciona(const T& dado) {
    return adicionaNaPosicao(dado, this->tamanho);
}

template<typename T>
void ListaCirc<T>::adicionaEmOrdem(const T& data) {
  if (ListaEnc<T>::listaVazia()) {
    return adicionaNoInicio(data);
  }
  Elemento<T>* atual = this->cabeca->getProximo();
  int posicao = 1;
  while (atual->getProximo() != 0 &&
        ListaEnc<T>::maior(data, atual->getInfo())) {
    atual = atual->getProximo();
    posicao++;
  }
  if (ListaEnc<T>::maior(data, atual->getInfo())) {
    return adicionaNaPosicao(data, posicao + 1);
  }
  adicionaNaPosicao(data, posicao);
}

template<typename T>
void ListaCirc<T>::adicionaNaPosicao(const T& dado, int pos) {
  if (ListaEnc<T>::posicaoInvalida(pos)) {
    throw ExcecaoErroPosicao();
  }
  if (pos == 0) {
    adicionaNoInicio(dado);
    return;
  }
  Elemento<T>* anterior = this->cabeca->getProximo();
  Elemento<T>* novo = new Elemento<T>(dado, 0);
  if (novo == 0) {
    throw ExcecaoCheia();
  }
  for (int i = 1; i < pos; i++) {
    anterior = anterior->getProximo();
  }
  novo->setProximo(anterior->getProximo());
  anterior->setProximo(novo);
  this->tamanho++;
}

template<typename T>
void ListaCirc<T>::adicionaNoInicio(const T& dado) {
  Elemento<T>* novo = new Elemento<T>(dado, 0);
  if (novo == 0) {
    throw ExcecaoCheia();
  }
  novo->setProximo(this->cabeca->getProximo());
  this->cabeca->setProximo(novo);
  this->tamanho++;
}

template<typename T>
void ListaCirc<T>::eliminaDoInicio() {
  if (ListaEnc<T>::listaVazia()) {
    throw ExcecaoVazia();
  }
  Elemento<T>* saiu = this->cabeca->getProximo();
  this->cabeca->setProximo(saiu->getProximo());
  this->tamanho--;
  delete saiu;
}

template<typename T>
T ListaCirc<T>::retira() {
    return retiraDaPosicao(this->tamanho);
}

template<typename T>
T ListaCirc<T>::retiraDaPosicao(int pos) {
  if (ListaEnc<T>::posicaoInvalida(pos)) {
    throw ExcecaoErroPosicao();
  }
  if (pos == 0) {
    return retiraDoInicio();
  }
  Elemento<T>* anterior = this->cabeca->getProximo();
  for (int i = 1; i < pos - 1; i++) {
    anterior = anterior->getProximo();
  }
  Elemento<T>* eliminar = anterior->getProximo();
  T volta = eliminar->getInfo();
  anterior->setProximo(eliminar->getProximo());
  this->tamanho--;
  delete eliminar;
  return volta;
}

template<typename T>
T ListaCirc<T>::retiraDoInicio() {
  Elemento<T>* saiu;
  T volta;
  if (ListaEnc<T>::listaVazia()) {
    throw ExcecaoErroPosicao();
  }
  saiu = this->cabeca->getProximo();
  volta = saiu->getInfo();
  this->cabeca->setProximo(saiu->getProximo());
  this->tamanho--;
  delete saiu;
  return volta;
}

template<typename T>
T ListaCirc<T>::retiraEspecifico(const T& dado) {
    if (ListaEnc<T>::listaVazia()) {
        throw ExcecaoVazia();
    }
  return retiraDaPosicao(posicao(dado) + 1);
}

template<typename T>
bool ListaCirc<T>::contem(const T& dado) {
  if (ListaEnc<T>::listaVazia()) {
    throw ExcecaoVazia();
  }
  Elemento<T>* atual = this->cabeca->getProximo();
  for (int i = 0; i < this->tamanho; i++) {
    if (ListaEnc<T>::igual(dado, atual->getInfo())) {
      return true;
    }
    atual = atual->getProximo();
  }
    return false;
}

template<typename T>
int ListaCirc<T>::posicao(const T& dado) const {
  if (ListaEnc<T>::listaVazia()) {
    throw ExcecaoVazia();
  }
  Elemento<T>* atual = this->cabeca->getProximo();
  for (int i = 0; i < this->tamanho; i++) {
    if (dado == atual->getInfo()) {
      return i;
    }
    atual = atual->getProximo();
  }
  throw ExcecaoDadoInexistente();
}

template<typename T>
T* ListaCirc<T>::posicaoMem(const T& dado) const {
    if (ListaEnc<T>::listaVazia()) {
        throw ExcecaoVazia();
    }
    int posicao = this->posicao(dado);
    Elemento<T>* atual = this->cabeca->getProximo();
    for (int i = 1; i < posicao; i++) {
        atual = atual->getProximo();
    }
    T volta = atual->getInfo();
    T* retorno = &volta;
    return retorno;
}

template<typename T>
T ListaCirc<T>::mostra(int pos) {
  if (ListaEnc<T>::listaVazia()) {
    throw ExcecaoVazia();
  }
  Elemento<T>* atual = this->cabeca->getProximo();
  for (int i = 0; i < pos; i++) {
    atual = atual->getProximo();
  }
  return atual->getInfo();
}

template<typename T>
int ListaCirc<T>::verUltimo() {
  return this->tamanho;
}

#endif
