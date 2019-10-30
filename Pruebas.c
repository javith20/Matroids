#include <stdio.h>

 
char auxa(int posicion);           // prototipo de auxa
void escribe (int posicion, char (* ptr)(int) ); // L.5: prototipo de escribe
 
int main() {                       // ======================
  char (* fptr) (int);             // M.1: declara fptr puntero-a-función

  fptr = auxa;                     // M.2: inicia fptr
  printf("La letra%2d es una: %c\n", 5, auxa(5));
  escribe (5, fptr);               // M.4: llamada a escribe
  return (0);
}
 
char auxa (int num) {              // Definición de auxa
  char * str = "Hola mundo";
  return str[num];                 // L.16
}
 
void escribe (int pos, char (* fpointer)(int) ) { // definición de escribe
  char ch ;
  printf ("Estoy recibiendo la letra: %c\n", auxa(pos));
  ch = (* fpointer)(6);
  printf ("Estoy inventando la letra: %c\n", ch); 
}

