#include <stdio.h>
#include <stdlib.h>

#include "SongList.h"

song_node * insert_front(song_node *n, char *name, char *artist) {
  song_node *new_node = (song_node *) malloc(sizeof(song_node));
  new_node -> name = name;
  new_node -> artist = artist;
  new_node -> next = n;
  return new_node;  
}

int main() {

}
