#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "SongList.h"

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
  printf("%d:%s - %s\n", ctr, node -> name, node-> artist);
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

int remove_song(song_node *first_node, char *name, char *artist ) {
  song_node *current_node = first_node;
  song_node *previous_node = 0;
  while (current_node -> next) {
    if (!strcmp(current_node -> name, name) && !strcmp(current_node -> artist, artist)) {
      previous_node -> next = current_node -> next;
      free(current_node);
      return 1;
    };
    previous_node = current_node;
    current_node = current_node -> next;
  }
  return 0;
}

void free_list(song_node *first_node) {
  song_node *current_node = first_node;
  while (current_node -> next) {
    free_list(current_node -> next);
  }
  free(current_node);
}

int main() {

  //print_list(a);

  song_node *a = (song_node *) malloc(sizeof(song_node));
  strcpy(a -> name, "Shut Up and Dance");
  strcpy(a -> artist, "Walk the Moon");
  
  printf("\nSongList Tests:\n");

  song_node *front = insert_front(a, "Fireflies", "Owl City");

  front = insert_in_order(front, "Defying Gravity", "Idina Menzel");
  front = insert_in_order(front, "Let It Go", "Idina Menzel"); 
  front = insert_in_order(front, "Payphone", "Maroon 5"); 
  front = insert_in_order(front, "Sugar", "Maroon 5"); 
  front = insert_in_order(front, "Animals", "Maroon 5"); 
  print_list(front);

  remove_song(front, "Let It Go", "Idina Menzel");

  print_list(front);
  
}
