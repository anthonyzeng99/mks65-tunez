#ifndef SONGLIST_H
#define SONGLIST_H

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;


song_node * insert_front(song_node *n, char *name, char *artist);

song_node * insert_in_order(song_node *first_node, char *name, char *artist);

void print_list(song_node *n);

song_node * find_song(song_node *first_node, char *name);

song_node * find_song_by_artist(song_node *first_node, char *artist);

song_node * random_song();

song_node * remove_song(song_node *first_node, song_node *node_to_remove);

void free_list();

#endif
