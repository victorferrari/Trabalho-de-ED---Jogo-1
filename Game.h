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
		void DrawPilha();
		void DrawNode();
	private:
		Pilha pilhas[6];
		
		
		int posicao_pilha[6][2]; // (x,y)
		int distancia_cards;
	
		//Posicao de cada card (refresh antes do draw?)
		
};

#endif
