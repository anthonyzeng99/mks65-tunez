#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "song_list.h"
#include "song_library.h"

song_node *table[26]; 

void initialize_library(){
  int i = 0;
  for (; i < 26; i++) {
    table[i] = (song_node*) malloc(sizeof(song_node));
    strcpy(table[i] -> name, "");
    strcpy(table[i] -> artist, "");
  }
}

int list_is_empty(song_node *node) {
  if (strcmp(node -> artist, "") == 0) {
    return 0;
  }
  return 1;
}

int letter_to_index(char *letter) {
  if (*letter >= 65 && *letter <= 90) {
    return *letter - 65;
  } else if (*letter >= 97 && *letter <= 122) {
    return *letter - 97;
  } 
  return;
}

int index_to_letter(char index) {
  return index + 65;
}

song_node * add_song(char *name, char *artist) {
  song_node *song_list = table[letter_to_index(&artist[0])];
  if (!list_is_empty(song_list)) {
    strcpy(song_list -> name, name);
    strcpy(song_list -> artist, artist);
    table[letter_to_index(&artist[0])] = song_list;
    return song_list;
  }
  table[letter_to_index(&artist[0])] = insert_in_order(song_list, name, artist);
  return song_list;
}

song_node * search_for_song(char *name) {
  int index = 0;
  while (index < 26) {
    song_node *search_result = find_song(table[index], name);
    if (search_result != 0) {
	  return search_result;
      }
      index++;
  }
  
  return 0;
}

song_node * search_for_artist(char *artist) {
  song_node *node_to_search = table[letter_to_index(&artist[0])];
  return find_song_by_artist(node_to_search, artist);
}

void print_letter_song(char *letter) {
  song_node *node_to_print = table[letter_to_index(letter)];
  print_list(node_to_print);
}

void print_library() {
  int index = 0;
  while (index < 26) {
    
    if (list_is_empty(table[index])) {
      printf("%c:\n", index_to_letter(index));
      print_list(table[index]);
    }    
    index++;
  }
}

void print_shuffle(int num_songs) {
  // srand(time(NULL));
  int songs_printed = 0;
  while(num_songs) {
    int random_list = rand() % 26;
    while (!list_is_empty(table[random_list])) {
      random_list = rand() % 26;
    }
    song_node *song = random_song(table[random_list]);
    printf("random song %d: %s - %s\n", songs_printed, song -> name, song -> artist);
    num_songs--;
    songs_printed++;
  }
 }

song_node * delete_song(char *name, char *artist) {
  song_node *song_location_node = table[letter_to_index(&artist[0])];
  return remove_song(song_location_node, name, artist);
}

song_node * delete_library() {
  int index = 0;
  while (index < 26) {
    free(table[index]);
    index++;
  }
}



