
#include "allegro_teclado.h"



int allegro_teclado_main (void)
{
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_EVENT ev1;
	
	bool key_pressed[11] = { false, false, false, false, false, false, false, false, false, false, false };

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

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			if (key_pressed[KEY_S])
				

			if (key_pressed[KEY_C])
				

			if (key_pressed[KEY_B])
				

			if (key_pressed[KEY_0])
				

			if (key_pressed[KEY_1])
				

			if (key_pressed[KEY_2])
				

			if (key_pressed[KEY_3])
				

			if (key_pressed[KEY_4])
				

			if (key_pressed[KEY_5])
				

			if (key_pressed[KEY_6])
				

			if (key_pressed[KEY_7])
				


			redraw = true;
		}

		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			do_exit = true;

		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_S:
				key_pressed[KEY_S] = true;
				break;

			case ALLEGRO_KEY_C:
				key_pressed[KEY_C] = true;
				break;

			case ALLEGRO_KEY_B:
				key_pressed[KEY_B] = true;
				break;

			case ALLEGRO_KEY_0:
				key_pressed[KEY_0] = true;
				break;
			case ALLEGRO_KEY_1:
				key_pressed[KEY_1] = true;
				break;
			case ALLEGRO_KEY_2:
				key_pressed[KEY_2] = true;
				break;
			case ALLEGRO_KEY_3:
				key_pressed[KEY_3] = true;
				break;
			case ALLEGRO_KEY_4:
				key_pressed[KEY_4] = true;
				break;
			case ALLEGRO_KEY_5:
				key_pressed[KEY_5] = true;
				break;
			case ALLEGRO_KEY_6:
				key_pressed[KEY_6] = true;
				break;
			case ALLEGRO_KEY_7:
				key_pressed[KEY_7] = true;
				break;
			}
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_S:
				key_pressed[KEY_S] = false;
				break;

			case ALLEGRO_KEY_C:
				key_pressed[KEY_C] = false;
				break;

			case ALLEGRO_KEY_B:
				key_pressed[KEY_B] = false;
				break;

			case ALLEGRO_KEY_0:
				key_pressed[KEY_0] = false;
				break;
			case ALLEGRO_KEY_1:
				key_pressed[KEY_1] = false;
				break;
			case ALLEGRO_KEY_2:
				key_pressed[KEY_2] = false;
				break;
			case ALLEGRO_KEY_3:
				key_pressed[KEY_3] = false;
				break;
			case ALLEGRO_KEY_4:
				key_pressed[KEY_4] = false;
				break;
			case ALLEGRO_KEY_5:
				key_pressed[KEY_5] = false;
				break;
			case ALLEGRO_KEY_6:
				key_pressed[KEY_6] = false;
				break;
			case ALLEGRO_KEY_7:
				key_pressed[KEY_7] = false;
				break;
			case ALLEGRO_KEY_ESCAPE:
				do_exit = true;
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {

			redraw = false;
			al_flip_display();

		}
	}
	
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);

	return 0;
}
