#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "song_list.h"
#include "song_library.h"

int main() {
    
  initialize_library();

  //Add songs to library
  printf("\nInserting songs:\n");
  add_song("Bohemian Rhapsody", "Queen");
  add_song("Under Pressure", "Queen");
  add_song("We Are The Champions", "Queen");
  add_song("Let It Go", "Idina Menzel");
  add_song("Defying Gravity", "Idina Menzel");
  add_song("Shut Up and Dance", "Walk the Moon");
  add_song("Payphone", "Maroon 5"); 
  add_song("Sugar", "Maroon 5"); 
  add_song("Animals", "Maroon 5"); 
  add_song("Apoligize", "OneRepublic");
  add_song("Feel Again", "OneRepublic");
  add_song("Kids", "OneRepublic");
  add_song("Fireflies", "Owl City");
  
  //Print library
  printf("Printing library:\n");
  print_library();

  //Print M Songs
  printf("\nPrint 'm' songs\n");
  print_letter_song("m");

  //Print M Songs
  printf("\nPrint 3 shuffle songs\n");
  print_shuffle(3);

  //Search for Song
  printf("\nSearching for 'Fireflies'\n");
  song_node *song_found = search_for_song("Shut Up and Dance");
  printf("Song found: %s - %s\n", song_found -> name, song_found -> artist);

  //Search for Song by Artist
  printf("\nSearching for 'Maroon 5'\n");
  song_node *song_found2 = search_for_artist("Maroon 5");
  printf("Song found: %s - %s\n", song_found2 -> name, song_found2 -> artist);

  //Delete songs
  printf("\nDeleting songs 'Defying Gravity' and 'Feel Again'\n");
  delete_song("Defying Gravity", "Idina Menzel");
  delete_song("Feel Again", "OneRepublic");
  print_library();
  ;
  //Delete library
  printf("\nDeleting library:\n");
  delete_library();
  }
