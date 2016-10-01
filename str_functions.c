// Calvin Vuong
// MKS65 pd10
// Work 1: If you liked it then you should've put a string on it.
// 09-30-2016

#include <stdio.h>
#include <stdlib.h>

// computes length of character array pointed to by this pointer
int mystrlen(char *str) {
  int len = 0;
  while ( *str != 0 ) { // loop until you reach terminator
    len++;
    str++;
  }
  return len;
}

// copies n characters of string src onto dest
// returns pointer to the destination string
char * mystrncpy(char *dest, char *src, int n) {
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

// concatenates src string onto end of dest string
// returns a pointer to the destination string
char * mystrncat(char *dest, char *src) {
  char *dest_head = dest;
  while ( *dest != 0 ) // find null terminator of destination
    dest++;
  while ( *src != 0 ) { // add src chars until reach null terminator
    *dest = *src;
    src++;
    dest++;
  }
  *dest = 0; // add terminator
  return dest_head;
}

// returns > 0 if s1 is greater than s2
// returns < 0 if s1 is less than s2
// returns 0 if s1 == s2
int mystrcmp( char *s1, char *s2 ) {
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
char * mystrchr(char *s, char c) {
  while ( *s != c ) {
    if ( *s == 0 ) // null terminator
      return NULL;
    s++;
  }
  return s;
}

// returns memory address of first character of substring in string
char * mystrstr(char *haystack, char *needle) {
  haystack = mystrchr(haystack, *needle); // finds first char of needle in haystack

  while ( haystack != NULL ) {
    char *ret_ptr = haystack; // pointer to return; does not change
    char *needle_ptr = needle;    
    while ( *haystack == *needle_ptr ) {
      haystack++;
      needle_ptr++;
    }
    if ( *needle_ptr == 0 )
      return ret_ptr;
    else
      haystack = mystrchr(haystack, *needle);
  }
  return NULL;
}


/* TESTING METHODS */
void test_strlen() {
  char s1[41] = "hello";
  char s2[100] = "";
  printf( "Testing strlen(): \n" );
  printf( "s1: %s\t length=%d\n", s1, mystrlen(s1) );
  printf( "s2: %s\t\t length=%d\n\n", s2, mystrlen(s2) );
}

void test_strncpy() {
  char dest[100] = "hello";
  char src[100] = "bill";
  printf("Testing strncpy(): \n" );
  printf( "Source string:\t\t\t %s\n", src );
  printf( "Destination string:\t\t %s\n", dest );
  printf( "Copying 3 chrs of source string onto destination string...\n" );
  printf( "Destination string after copy:\t %s\n\n" , mystrncpy(dest, src, 3) );
}

void test_strchr() {
  char hello[6] = "hello";
  printf( "Testing strchr(): \n" );
  printf( "Looking for l in hello:\t %c\n", *mystrchr(hello, 'l') ); // should be 2 bytes greater than h 
  printf( "Looking for A in hello:\t %s\n\n", mystrchr(hello, 'A') ); // should be 0 
}

void test_strcmp() {
  char a[4] = "cat";
  char b[4] = "cap";
  char c[12] = "catastrophe";
  printf( "Testing strcmp(): \n" );
  printf( "strcmp(\"cat\", \"cap\"): %d\n", mystrcmp(a,b) );
  printf( "strcmp(\"cap\", \"cat\"): %d\n", mystrcmp(b,a) );

  printf( "strcmp(\"cat\", \"catastrophe\"): %d\n", mystrcmp(a,c) );
  printf( "strcmp(\"catastrophe\", \"cat\"): %d\n\n", mystrcmp(c,a) );
}

void test_strstr() {
  char a[12] = "catastrophe";
  char b[4] = "cat";
  char c[5] = "tast";
  char d[3] = "as";
  char e[10] = "pheromone";
  printf ("Testing strstr(): \n");
  printf( "Looking for cat in catastrophe: %s\n", mystrstr(a, b) );
  printf( "Looking for tast in catastrophe: %s\n", mystrstr(a, c) );
  printf( "Looking for as in catastrophe: %s\n", mystrstr(a, d) );
  printf( "Looking for  pheromone in catastrophe: %s\n\n", mystrstr(a, e) );
}

void test_strcat() {
  char a[50] = "All the ";
  char b[14] = "single ladies";
  printf( "Testing strcat(): \n" );
  printf( "String a: %s\n", a );
  printf( "String b: %s\n", b );
  mystrncat(a,b);
  printf( "String a after concatenating b onto a: %s\n\n", a );

}


int main() {
  test_strlen();
  test_strncpy();
  test_strcat();
  test_strcmp();
  test_strchr();
  test_strstr();
  return 0;
}
