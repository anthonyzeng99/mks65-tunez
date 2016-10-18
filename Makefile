all:
	gcc SongList.c -o SongList

run: tunez
	./Tunez

clean:
	rm *~
