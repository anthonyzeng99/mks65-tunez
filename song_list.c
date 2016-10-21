#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "song_list.h"

song_node * insert_front(song_node *first_node, char *name, char *artist) {
  song_node *new_node = (song_node *) malloc(sizeof(song_node));
  strcpy(new_node -> name, name);
  strcpy(new_node -> artist, artist);  
  new_node -> next = first_node;
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
    if(check_insertion_point(current_node, new_node)) {
	if (!previous_node) {
	  new_node -> next = first_node;
	  return new_node;
	}
	previous_node -> next = new_node;
	new_node -> next = current_node;
	return first_node;
    }
    previous_node = current_node;
    current_node = current_node -> next;
  }
  current_node -> next = new_node;
  return first_node;
}

int check_insertion_point(song_node *current_node, song_node *node_to_insert) {
  if (strcmp(current_node -> artist, node_to_insert -> artist) > 0) {
    return 1;
  } else if (strcmp(current_node -> artist, node_to_insert -> artist) == 0) {
    if (strcmp(current_node -> name, node_to_insert -> name)  > 0) {
      return 1;
    } 
  }
  return 0;
}

void print_list_helper(song_node *node, int ctr) {
  printf(" %d:%s - %s\n", ctr, node -> name, node-> artist);
  song_node *next = node -> next;
  if (next) {
    print_list_helper(next, ctr + 1);
  }
}

void print_list(song_node *first_node) {
  print_list_helper(first_node, 0);
}

song_node * find_song(song_node *first_node, char *name) {
  song_node *current_node = first_node;
  while (current_node) {
    if (!strcmp(current_node -> name, name)) return current_node;
    current_node = current_node -> next;
  }
  return 0;
}

song_node * find_song_by_artist(song_node *first_node, char *artist) {
  song_node *current_node = first_node;
  while (current_node) {
    if (!strcmp(current_node -> artist, artist)) return current_node;
    current_node = current_node -> next;
  }
  return 0;
}

song_node * random_song(song_node *first_node) {
  srand(time(NULL));
  int rand_index = rand();
  

  int songs = 0;
  song_node *current_node = first_node;
  while (current_node) {
    songs++;
    current_node = current_node -> next;
  }

  int i = rand_index % songs;
  current_node = first_node;
  while (i) {
    if (current_node) {
      current_node = current_node -> next;
    } else {
      current_node = first_node;
    }
    i--;
  } return current_node;
}

song_node * remove_song(song_node *first_node, char *name, char *artist ) {
  song_node *current_node = first_node;
  song_node *previous_node = 0;
  while (current_node) {
    if (!strcmp(current_node -> name, name) && !strcmp(current_node -> artist, artist)) {
      if (!previous_node) {
	song_node *new_first_node = current_node -> next;
	free(current_node);
	return new_first_node;
      }
      previous_node -> next = current_node -> next;
      free(current_node);
      return first_node;
    };
    previous_node = current_node;
    current_node = current_node -> next;
  }
  return first_node;;
}

void free_list(song_node *first_node) {
  song_node *current_node = first_node;
  while (current_node -> next) {
    free_list(current_node -> next);
  }
  free(current_node);
}


