#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "SongList.h"

song_node * insert_front(song_node *n, char *name, char *artist) {
  song_node *new_node = (song_node *) malloc(sizeof(song_node));
  strcpy(new_node -> name, name);
  strcpy(new_node -> artist, artist);
  new_node -> next = n;
  return new_node;  
}

song_node * insert_in_order(song_node *first_node, char *name, char *artist) {
  song_node *new_node = (song_node *) malloc(sizeof(song_node));
  strcpy(new_node -> name, name);
  strcpy(new_node -> artist, artist);

  song_node *current_node = first_node;
  song_node *previous_node = 0;
  int i = 0;
  while (current_node -> next) {
    if (strcmp(current_node -> artist, artist) <= 0) {
      if (strcmp(current_node -> name, name) < 0) {
	previous_node -> next = new_node;
	new_node -> next = current_node;
      }
    }
    previous_node = current_node;
    current_node = current_node -> next;
  }

  return new_node;
}

void print_listHelper(song_node *node, int ctr) {
  printf("%d:%s by %s\n", ctr, node -> name, node-> artist);
  song_node *next = node -> next;
  if (next) {
    print_listHelper(next, ctr + 1);
  }
}

void print_list(song_node *first_node) {
  print_listHelper(first_node, 0);
}

song_node * find_song(song_node *first_node, char *name) {
  song_node *current_node = first_node;
  while (current_node -> next) {
    if (!strcmp(current_node -> name, name)) return current_node;
    current_node = current_node -> next;
  }
  return 0;
}

song_node * find_song_by_artist(song_node *first_node, char *artist) {
  song_node *current_node = first_node;
  while (current_node -> next) {
    if (!strcmp(current_node -> artist, artist)) return current_node;
    current_node = current_node -> next;
  }
  return 0;
}

song_node * random_song(song_node *first_node) {
  srand(time(NULL));
  int rand_index = rand();
  
  song_node *current_node = first_node;
  while (rand_index) {
    if (current_node -> next) {
      current_node = first_node;
    } else {
      current_node = current_node -> next;
    }
    rand_index--;
  } return current_node;
}

song_node * remove_song(song_node *first_node, song_node *node_to_remove) {
  song_node *current_node = first_node;
  song_node *previous_node = 0;
  while (current_node -> next) {
    if (current_node == node_to_remove) {
      previous_node -> next = current_node -> next;
      free(current_node);
      return previous_node -> next;
    };
    previous_node  = current_node;
    current_node = current_node -> next;
  }
}

void free_list(song_node *first_node) {
  song_node *current_node = first_node;
  while (current_node -> next) {
    free_list(current_node -> next);
  }
  free(current_node);
}

int main() {
  song_node *a = (song_node *) malloc(sizeof(song_node));
  strcpy(a -> name, "Shut and Dance");
  strcpy(a -> artist, "Walk the Moon");
  song_node *b = (song_node *) malloc(sizeof(song_node));
  strcpy(b -> name, "Fireflies");
  strcpy(b -> artist, "Owl City");
  song_node *c = (song_node *) malloc(sizeof(song_node));
  strcpy(c -> name, "Let It Go");
  strcpy(c -> artist, "Idina Menzel");
  song_node *d = (song_node *) malloc(sizeof(song_node));
  strcpy(d -> name, "Defying Gravity");
  strcpy(d -> artist, "Idina Menzel");

  print_list(a);
  insert_front(a, "Fireflies", "Owl City");
  print_list(a);
}
