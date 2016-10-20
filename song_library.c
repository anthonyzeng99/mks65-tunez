#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "song_list.h"
#include "song_library.h"

song_node *table[26];

int letter_to_index(char *letter) {
  if (*letter >= 65 && *letter <= 90) {
    return *letter - 65;
  } else if (*letter >= 97 && *letter <= 122) {
    return *letter - 97;
  } 
  return;
}

song_node * add_song(song_node *library, char *name, char *artist) {
  song_node *node_to_insert_at = table[letter_to_index(&artist[0])];
  return insert_in_order(node_to_insert_at, name, artist);
}

song_node * search_for_song(song_node *library, char *name) {
  int index = 0;
  while (index < 26) {
    song_node *search_result = find_song(table[index], name);
    if (!search_result) {
      return search_result;
    }
    index++;
  }
  return 0;
}

song_node * search_for_artist(song_node *library, char *artist) {
  song_node *node_to_search = table[letter_to_index(&artist[0])];
  return find_song_by_artist(node_to_search, artist);
}

void print_letter_song(song_node *library, char letter) {
  song_node *node_to_print = table[letter_to_index(&letter)];
  print_list(node_to_print);
}

void print_library(song_node *library) {
  int index = 0;
  while (index < 26) {
    print_list(table[index]);
    index++;
  }
}

void print_shuffle(song_node *library, int num_songs) {
  srand(time(NULL));
  int songs_printed = 0;
  while(num_songs) {
    song_node *song = random_song(table[rand() % 26]);
    printf("random song %d: %s - %s\n", songs_printed, song -> name, song -> artist);
  }
 }

song_node * delete_song(song_node *library, char *name, char *artist) {
  song_node *song_location_node = table[letter_to_index(&artist[0])];
  return remove_song(song_location_node, name, artist);
}

song_node * delete_library(song_node *library) {
  int index = 0;
  while (index < 26) {
    free_list(table[index]);
    index++;
  }
}



