// Copyright 2014 Mateus Rissi & Guilherme Noronha. All rights reserved.

#ifndef ERROFILAVAZIA_H_
#define ERROFILAVAZIA_H_

#include <iostream>
using namespace std;

class ErroFilaVazia {
 public:
    ErroFilaVazia() {}
    void print_erro() {
        cerr << "A fila está vazia." << endl;
        }
};
#endif
