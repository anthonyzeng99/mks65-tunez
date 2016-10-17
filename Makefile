all:
	gcc SongList.c Tunez.c -o Tunez

run: tunez
	./Tunez

clean:
	rm *~
