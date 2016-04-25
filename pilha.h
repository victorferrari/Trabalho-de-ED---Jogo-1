#include <iostream>
#include "node.h"

#ifndef PILHA_H
#define PILHA_H

class Pilha{
	
	public:
		Pilha();
		bool Vazia();
		bool Cheia();
		bool Empilha(char x);
		bool Desempilha(char &x);
		
	private:
		Node* Topo;
		int elementos;	
};

#endif
