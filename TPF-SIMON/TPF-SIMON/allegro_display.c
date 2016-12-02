#include "allegro_display.h"



int allegro_display_main(void)

{
	const char *title = { "SIMON" };
	
	ALLEGRO_DISPLAY * display = NULL;

	ALLEGRO_BITMAP * simon = NULL;

	ALLEGRO_BITMAP *icon = NULL;

//=====================================================================================================
//		INICIALIZO ALLEGRO, CREO DISPLAY Y CARGO IMAGENES
//=====================================================================================================

	if (!al_init()) { //Inicializo Allegro
		fprintf(stderr, "Failed to initialize allegro!\n");
		return -1;
	}
	if (!al_init_image_addon()) { // Inicializo ADDON de las imagenes
		fprintf(stderr, "failed to initialize image addon !\n");
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "Failed to create display!\n");
		return -1;
	}

	simon = al_load_bitmap("simon.png");
	if (!simon) {
		fprintf(stderr, "Failed to create welcome!\n");
		al_destroy_display(display);
		return -1;
	}

	icon = al_load_bitmap("simon_icon.png");
	if (!icon) {
		fprintf(stderr, "Failed to create icon!\n");
		al_destroy_display(display);
		al_destroy_bitmap(simon);
		return -1;
	}

//=========================================================================================================

	al_set_window_title(display, title); //Le pongo un titulo al display

	al_set_display_icon(display, icon);  //Icono del programa

//=========================================================================================================
	al_clear_to_color(al_color_name("white"));	//Fondo Blanco

	al_draw_bitmap(simon, 0, 0, 0);

	al_flip_display();		//Actualizo Pantalla
	
	al_rest(5.0);
	//al_acknowledge_resize(simon);
	//al_flip_display();
	//al_rest(3.0);


	
	al_destroy_display(display);
	al_destroy_bitmap(simon);
	al_uninstall_system();
	return 0;
}