#ifndef SONG_LIST_H
#define SONG_LIST_H

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;


song_node * insert_front(song_node *n, char *name, char *artist);

song_node * insert_in_order(song_node *first_node, char *name, char *artist);

int check_insertion_point(song_node *current_node, song_node *node_to_insert);

void print_listHelper(song_node *node, int ctr);

void print_list(song_node *n);

song_node * find_song(song_node *first_node, char *name);

song_node * find_song_by_artist(song_node *first_node, char *artist);

song_node * random_song(song_node *first_node);

song_node * remove_song(song_node *first_node, char *name, char *artist);

void free_list();

#endif
