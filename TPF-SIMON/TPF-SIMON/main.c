

#include "main.h"

#include "allegro_display.h"


int main(void)
{
	if (ALLEGRO)
	{
		if (allegro_display_main())		//Llamo a la funcion de allegro de forma defensiva
		{
			fprintf(stderr, "Failed to initialize allegro!\n");
			return -1;
		}
	}

	else
	{

	}
	

	return 0;
}