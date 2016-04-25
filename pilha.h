#include <iostream>
#include <node.h>


class Pilha{
	
	public:
		Pilha();
		bool Vazia();
		bool Cheia();
		bool Empilha(char x);
		bool Desempilha(char *x);
		
	private:
		NodePtr Topo;
		int elementos;	
};

#endif
