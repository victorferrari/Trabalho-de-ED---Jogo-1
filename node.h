#include <iosteam>

#ifndef Node_H
#define Node_H

class Node{
	
	public:
		Node(int _cor, char _info){
			cor = _cor;
			Info = _info;
		}
		
		char getInfo() const{
			return Info;
		}
		
		int getCor() const{
			return cor;
		}
		
	private:
		char Info;
		int cor;
		Node *Next;
};

#endif
