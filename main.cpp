#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_native_dialog.h>
#include "Game.h"

//Tamanho da tela
const int width = 1024;
const int height = 768;

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_FONT *arial36 = NULL;

bool init();

int main(int argc, char **argv) {
	if(!init()) {
		return -1;
	}
	
	Game* freeword;
	//Cores do jogo
	const ALLEGRO_COLOR background_color = al_map_rgb(34, 177, 76);
	const ALLEGRO_COLOR blueCard_color = al_map_rgb(0, 162, 232);
	const ALLEGRO_COLOR redCard_color = al_map_rgb(237, 28, 36);
	const ALLEGRO_COLOR grayCard_color = al_map_rgb(195, 195, 195);
	const ALLEGRO_COLOR yellowCard_color = al_map_rgb(255, 201, 14);
	const ALLEGRO_COLOR black_color = al_map_rgb(0, 0, 0);
	
	//Controle do laço principal
	bool done = false;
	
	al_clear_to_color(background_color);
	al_draw_text(arial36, black_color, width/2, 20, ALLEGRO_ALIGN_CENTRE, "FreeWord");
	al_flip_display();
	
	while(!done) {
	
		//Holds the details of a fired event
		ALLEGRO_EVENT ev;
		
		//Wait for something to happen 
		al_wait_for_event(event_queue, &ev);
		
		//Window close button
		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			done = true;
		}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if(ev.mouse.button & 1){
				//Evento quando botão esquerdo é utilizado
			}
		}
		
		
		freeword->Draw();
		//Troca o buffer de trás pelo da frente
		//al_flip_display();
		//Limpa o buffer de trás para a cor padrão
		//al_clear_to_color(background_color);
	}
	


	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	
	return 0;
}

bool init() {
	
	//Inicializando Allegro
	if(!al_init()) {
		al_show_native_message_box(NULL, NULL, NULL, "Allegro could not be initilizaed.", NULL, NULL);
		return false;
	}
	
	//Inicializando add-on para uso de primitivos
	al_init_primitives_addon();
	
	//Criando e atribuindo o display
	display = al_create_display(width, height);
	if(!display) {
		al_show_native_message_box(NULL, NULL, NULL, "Display could not be created.", NULL, NULL);
		return false;
	}
	//Nomeando o display
	al_set_window_title(display, "FreeWord");
	
	//Inicializando add-on para uso de fonte
	al_init_font_addon();
	//Inicializando add-on para uso de fontes em TTF
	if(!al_init_ttf_addon()) {
		al_show_native_message_box(NULL, NULL, NULL, "Font could not be initilizaed.", NULL, NULL);
		return false;
	}
	//Atribuindo fonte
	arial36 = al_load_font("arial.ttf", 36, 0);
	
	//Criando e atribuindo fila de eventos
	event_queue = al_create_event_queue();
	if(!event_queue) {
		al_show_native_message_box(NULL, NULL, NULL, "Event queue could not be created.", NULL, NULL);
		return false;
	}
	
	//Installing mouse
	al_install_mouse();
	//Register events so the queue may be filled with them
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	
	return true;
}
