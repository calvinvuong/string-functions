// Calvin Vuong

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
char * strncpy(char *dest, char *src, int n) {
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

// returns > 0 if s1 is greater than s2
// returns < 0 if s1 is less than s2
// returns 0 if s1 == s2
int strcmp( char *s1, char *s2 ) {
  while ( *s1 != 0 || *s2 != 0 ) {
    if ( *s1 != *s2 )
      return *s1 - *s2;
    s1++;
    s2++;
  }
  return 0;
}

// returns memory address of char c in string s
// returns NULL if c not in s
char * strchr(char *s, char c) {
  while ( *s != c ) {
    if ( *s == 0 ) // null terminator
      return NULL;
    s++;
  }
  return s;
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

void test_strchr() {
  char hello[6] = "hello";
  printf( "Memory address of h in hello: %d\n", hello);
  printf( "Memory address of l in hello: %d\n", strchr(hello, 'l') ); // should be 2 bytes greater than h 
  printf( "Memory address of l in hello: %d\n", strchr(hello, 'A') ); // should be 0 
}

void test_strcmp() {
  char a[4] = "cat";
  char b[4] = "cap";
  char c[12] = "catastrophe";
  printf( "strcmp(\"cat\", \"cap\"): %d\n", strcmp(a,b) );
  printf( "strcmp(\"cap\", \"cat\"): %d\n", strcmp(b,a) );

  printf( "strcmp(\"cat\", \"catastrophe\"): %d\n", strcmp(a,c) );
  printf( "strcmp(\"catastrophe\", \"cat\"): %d\n", strcmp(c,a) );
}

int main() {
  test_strlen();
  test_strncpy();
  test_strcmp();
  test_strchr();

  return 0;
}
	  
