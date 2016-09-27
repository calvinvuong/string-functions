#include <stdio.h>
#include <stdlib.h>

// computes length of character array pointed to by this pointer
int strlen(char *str) {
  int len = 0;
  while ( *str != 0 ) { // loop until you reach terminator
    len++;
    str++;
  }
  return len;
}

// copies n characters of string src onto dest
// returns pointer to the destination string
char *strncpy(char *dest, char *src, int n) {
  char *dest_head = dest;
  while ( *src != 0 && n != 0 ) { // loop until you reach terminator of source or n is reached
    *dest = *src;
    dest++;
    src++;
    n--;
  }
  // add terminator
  *dest = 0;
  return dest_head;
}
  



/* TESTING METHODS */
void test_strlen() {
  printf( "%d\n", strlen("hello") );
}

void test_strncpy() {
  char src[100] = "hello";
  char dest[100] = "bill";
  printf( "%s\n", strncpy(dest, src, 4) );
  //strncpy(dest, src, 4);
  //printf( "%s\n", dest);
}

int main() {
  test_strlen();
  test_strncpy();
  return 0;
}
	  
