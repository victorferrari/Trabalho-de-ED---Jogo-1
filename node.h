#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>

#ifndef NODE_H
#define NODE_H

class Node{
	
	public:
		Node() {
			Info = 0;
			Next = NULL;
			cor = -1;
		};
		
		Node(int _cor, char _info){
			cor = _cor;
			Info = _info;
		};
		
		char getInfo() const{
			return Info;
		};
		
		int getCor() const{
			return cor;
		};
		
		char Info;
		int cor;
		Node* Next;
};

#endif
