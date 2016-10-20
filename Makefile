all:
	gcc main.c song_list.c song_library.c -o tunez

run: tunez
	./tunez

clean:
	rm *~
