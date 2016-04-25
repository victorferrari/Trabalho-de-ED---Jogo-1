#include "Pilha.h"

extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_FONT *arial36;

extern ALLEGRO_COLOR background_color;
extern ALLEGRO_COLOR cardColor[4];
extern ALLEGRO_COLOR black_color;

#ifndef GAME_H
#define GAME_H

class Game
{
	public:
		Game();
		~Game();
		
		//Desenha todo o jogo
		//Deve chamar o Draw das outras classes
		void Draw();
		void DrawPilha(const Pilha&);
		void DrawNode();
	private:
		Pilha pilhas[6];
		
		
		const int posicao_pilha[7] = { height/3, width/8, width/4, 3*width/8, 5*width/8, 2*width/3, 7*width/8 } // x de cada, y de todas
		
		const int distancia_card = 30;
		const int tamanho_card = 20;
	
		//Posicao de cada card (refresh antes do draw?)
		
};

#endif
