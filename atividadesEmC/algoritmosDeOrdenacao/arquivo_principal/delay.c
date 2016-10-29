#include "delay.h"
#include "openGL.h"
#include <time.h>

void delay_ms( void ){
	clock_t start , end;
	start = clock();
	do{
		end = clock();
	}while( start + CLOCKS_PER_SEC/(N*100) >= end );

}