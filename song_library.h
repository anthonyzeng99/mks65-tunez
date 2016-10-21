#ifndef SONG_LIBRARY_H
#define SONG_LIBRARY_H

void initialize_library();

int letter_to_index(char *letter);

int index_to_letter(char index);

song_node * add_song(char *name, char *artist);

song_node * search_for_song(char *name);

song_node * search_for_artist(char *artist);

void print_letter_song(char *letter);

void print_library();

void print_shuffle(int num_songs);

song_node *  delete_song(char *name, char *artist);

song_node * delete_library();

#endif
