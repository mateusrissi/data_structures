// Copyright 2014 Mateus Rissi & Guilherme Noronha. All rights reserved.

#ifndef ERROFILACHEIA_H_
#define ERROFILACHEIA_H_

#include <iostream>
using namespace std;

class ErroFilaCheia {
 public:
    ErroFilaCheia() {}
    void print_erro() {
        cerr << "A fila está cheia." << endl;
        }
};
#endif
