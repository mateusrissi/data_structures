// Copyright 2014 Mateus Rissi & Guilherme Noronha. All rights reserved.

#ifndef ERROPILHACHEIA_H_
#define ERROPILHACHEIA_H_

#include <iostream>
using namespace std;

class ErroPilhaCheia {
 public:
    ErroPilhaCheia() {}
    void print_erro() {
        cerr << "A pilha esta cheia." << endl;
        }
};
#endif
