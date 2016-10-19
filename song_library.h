#ifndef SONG_LIBRARY_H
#define SONG_LIBRARY_H

int letter_to_index(char letter);

song_node * add_song(song_node *library, char *name, char *artist);

song_node * search_for_song(song_node *library, char *name);

song_node * search_for_artist(song_node *library, char *artist);

void print_letter_song(song_node *library, char letter);

void print_library(song_node *library);

void print_shuffle(song_node *library);

song_node *  delete_song(song_node *library, char *name, char *artist);

song_node * delete_library(song_node *library);

#endif
