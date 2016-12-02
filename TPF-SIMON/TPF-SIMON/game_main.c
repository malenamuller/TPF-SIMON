#include "game_main.h"

void carga_secuencia_colores(int *);

int level;

int game_main(void)
{
	int arreglo[MAX_LEVEL] = NULL;
	pthread_t tid1, tid2, tid3, tid4;
	carga_secuencia_colores(arreglo);


	
}



void carga_secuencia_colores(int * arreglo)
{
	int i;
	for (i = 0; i <= MAX_LEVEL; ++i)
	{
		srand(time(NULL));
		int random_number = (rand() % (3));
		arreglo[i] = random_number;
	}

}

void* thread_muestra_secuencia()
{

}

void* thread_teclado_allegro()
{

}

void* thread_teclado_rpi()
{

}

void* thread_timer()
{

}

//void* thread_comparacion()
//{
//	int perdiste = FALSE;
//	while (!perdiste)
//	{
//		for (i=0; (i <= level) && (!perdiste) ; ++i)
//		{
//
//			if (!(buffer_circular == arreglo[i])) //puntero lectura del buffer
//			{
//				perdiste = TRUE;
//			}
//			++buffer_circular
//
//		}
//	}
//}
