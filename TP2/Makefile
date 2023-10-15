star.o : star.h star.c
	gcc -I ./include -c ./src/star.c -o ./exec/star.o

star-list.o : star-list.h star-list.c
	gcc -I ./include -c ./src/star-list.c -o ./exec/star-list.o

star-database.o : star-database.c star-database.h
	gcc -I ./include -c ./src/star-database.c -o ./exec/star-database.o

stars.o : stars.c
	gcc -I ./include -c stars.c -o ./exec/stars.o

stars : star.o star-list.o star-database.o stars.o
	gcc -I ./exec -o stars ./exec/star.o ./exec/star-list.o ./exec/star-database.o ./exec/stars.o