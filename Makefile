all:
	gcc song_list.c -o song_list

run: tunez
	./Tunez

clean:
	rm *~
