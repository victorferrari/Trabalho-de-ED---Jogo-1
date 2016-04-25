#include <iostream>
#include "pilha.h"

#define tam = 10

Pilha::Pilha(){
	Topo->Next = NULL;
	elementos = 0;
}

bool Pilha::Vazia(){
	if(elementos == 0){
		return true;
	}
	return false;
}

bool Pilha::Cheia(){
	if(elementos == 10){
		return true;
	}
	return false;
}

bool Pilha::Empilha(char x){
	Node *PAux = new Node;
	PAux->Info = x;
	
	if(Cheia()){
		return false;	
	} else if(Vazia()){
		Topo = PAux;
		Topo->Next = NULL;
		elementos++;
		return true;
	} else{
		PAux->Next = Topo;
		Topo = PAux;
		PAux = NULL;
		elementos++;
		return true;
	}
}

bool Pilha::Desempilha(char &x){
	if(Vazia()){
		return false;
	} else if(elementos == 1){
			x = Topo->Info;
			delete(Topo);
			Topo->Next = NULL;
			elementos--;
			return true;
		} else{
			Node *PAux;
			PAux = Topo;
			x = Topo->Info;
			Topo = Topo->Next;
			delete(PAux);
			elementos--;
			return true;
		}
}

