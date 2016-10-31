BERTOLINO_SORT=../__sorts/bertolino_sort/modelo_vetor/bertolino_sort.c 
BUBBLE_SORT=../__sorts/bubble_sort/modelo_vetor/bubble_sort.c
INSERTION_SORT=../__sorts/insertion_sort/modelo_vetor/insertion_sort.c 
QUICK_SORT=../__sorts/quick_sort/modelo_vetor/quick_sort.c
SHELL_SORT=../__sorts/shell_sort/modelo_vetor/shell_sort.c

$main_: main.c populadores.c menu.populador.openGL.c menu.sorts.openGL.c openGL.c int_p_string.c delay.c $(BERTOLINO_SORT) $(BUBBLE_SORT) $(INSERTION_SORT) $(QUICK_SORT) $(SHELL_SORT)
	gcc -o main $^ -Wall -pedantic -ansi -g -std=gnu99 -lGLEW -lglut -lGL -lGLU -lm