#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "song_list.h"
#include "song_library.h"

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

  song_node *random_node = random_song(front);
  printf("\nrandom name:%s\nrandom artist:%s\n", random_node -> name,  random_node -> artist);

  song_node *artist_found = find_song_by_artist(front, "Walk the Moon");
  printf("\nsong found name:%s\nsong found artist:%s\n", artist_found -> name,  artist_found -> artist);


  front = remove_song(front, "Let It Go", "Idina Menzel");
  front = remove_song(front, "Defying Gravity", "Idina Menzel");
  front = remove_song(front, "Fireflies", "Owl City");
  front = remove_song(front, "Shut Up and Dance", "Walk the Moon");
  print_list(front);
}
