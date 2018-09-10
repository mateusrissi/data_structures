// Copyright 2014 Mateus Rissi & Guilherme Noronha. All rights reserved.

#ifndef ERROPILHAVAZIA_H_
#define ERROPILHAVAZIA_H_

#include <iostream>
using namespace std;

class ErroPilhaVazia {
 public:
    ErroPilhaVazia() {}
    void print_erro() {
        cerr << "A pilha esta vazia." << endl;
        }
};
#endif
