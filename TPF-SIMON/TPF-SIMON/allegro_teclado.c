
#include "allegro_teclado.h"



int allegro_teclado_main (void)
{
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_EVENT ev1;
	
	bool key_pressed[6] = { false, false, false, false, false, false};

	bool redraw = false;

	bool do_exit = false;


	if (!al_install_keyboard()) {    //Inicializo el teclado
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}


	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "Failed to create timer!\n");
		return -1;
	}

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "Failed to create event_queue!\n");
		al_destroy_timer(timer);
		
		return -1;
	}

	//HAY QUE PONER EL DISPLAY TAMBMIEN COMO EVENT_SOURCE ASI SE PUEDE ACTUALIZAR

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(timer);

	while (!do_exit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)		//PONER EN CADA IF LO QUE TIENE QUE HACER (LLAMAR A VALIDACION CON ESA TECLA)
		{
			if (key_pressed[KEY_SPACE])
				

			if (key_pressed[KEY_UP])
				

			if (key_pressed[KEY_DOWN])
				

			if (key_pressed[KEY_LEFT])
				

			if (key_pressed[KEY_RIGHT])
				

			redraw = true;
		}

		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			do_exit = true;

		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_SPACE:
				key_pressed[KEY_SPACE] = true;
				break;

			case ALLEGRO_KEY_UP:
				key_pressed[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key_pressed[KEY_DOWN] = true;
				break;

			case ALLEGRO_KEY_LEFT:
				key_pressed[KEY_LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				key_pressed[KEY_RIGHT] = true;
				break;
			}
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_SPACE:
				key_pressed[KEY_SPACE] = false;
				break;

			case ALLEGRO_KEY_UP:
				key_pressed[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key_pressed[KEY_DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				key_pressed[KEY_LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				key_pressed[KEY_RIGHT] = false;
				break;
			case ALLEGRO_KEY_ESCAPE:
				do_exit = true;
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {

			redraw = false;
			
			al_flip_display();
			//tendria que ir a validacion

		}
	}
	
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);

	return 0;
}
