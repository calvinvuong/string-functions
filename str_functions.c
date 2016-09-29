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

// concatenates src string onto end of dest string
// returns a pointer to the destination string
char * strcat(char *dest, char *src) {
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

// returns memory address of first character of substring in string
char * strstr(char *haystack, char *needle) {
  char *start = strchr(haystack, *needle); // finds first char of needle in haystack
  char *ret_pointer = start;
  if ( start == NULL ) // first char of needle does not appear
    return NULL;
  
  while ( *start == *needle ) {
    start++;
    needle++;
  }
  if ( *needle == 0 )
    return ret_pointer;
  else
    return NULL;
}


/* TESTING METHODS */
void test_strlen() {
  char s1[41] = "hello";
  char s2[100] = "";
  printf( "Testing strlen(): \n" );
  printf( "s1: %s\t length=%d\n", s1, strlen(s1) );
  printf( "s2: %s\t\t length=%d\n\n", s2, strlen(s2) );
}

void test_strncpy() {
  char src[100] = "hello";
  char dest[100] = "bill";
  printf("Testing strncpy(): \n" );
  printf( "Source string:\t\t\t %s\n", src );
  printf( "Destination string:\t\t %s\n", dest );
  printf( "Copying 4 chrs of source string onto destination string...\n" );
  printf( "Destination string after copy:\t %s\n\n" , strncpy(dest, src, 4) );
}

void test_strchr() {
  char hello[6] = "hello";
  printf( "Testing strchr(): \n" );
  printf( "String: %s\n", hello );
  printf( "Memory address of hello:\t %d\n", hello);
  printf( "Memory address of l in hello:\t %d\n", strchr(hello, 'l') ); // should be 2 bytes greater than h 
  printf( "Memory address of A in hello:\t %d\n\n", strchr(hello, 'A') ); // should be 0 
}

void test_strcmp() {
  char a[4] = "cat";
  char b[4] = "cap";
  char c[12] = "catastrophe";
  printf( "Testing strcmp(): \n" );
  printf( "strcmp(\"cat\", \"cap\"): %d\n", strcmp(a,b) );
  printf( "strcmp(\"cap\", \"cat\"): %d\n", strcmp(b,a) );

  printf( "strcmp(\"cat\", \"catastrophe\"): %d\n", strcmp(a,c) );
  printf( "strcmp(\"catastrophe\", \"cat\"): %d\n", strcmp(c,a) );
}

void test_strstr() {
  char a[12] = "catastrophe";
  char b[4] = "cat";
  char c[5] = "tast";
  char d[2] = "t";
  char e[10] = "pheromone";
  printf( "Memory address of catastrophe: %d\n", a );
  printf( "Memory address of cat in catastrophe: %d\n", strstr(a, b) );
  printf( "Memory address of tast in catastrophe: %d\n", strstr(a, c) );
  printf( "Memory address of t in catastrophe: %d\n", strstr(a, d) );
  printf( "Memory address of pheromone in catastrophe: %d\n", strstr(a, e) );
  
}
void test_strcat() {
  char a[50] = "All the ";
  char b[14] = "single ladies";
  strcat(a,b);
  printf( "strcat(\"All the \", \"single ladies\"): %s\n", a );
}


int main() {
  test_strlen();
  test_strncpy();
  test_strcmp();
  test_strchr();
  test_strcat();
  test_strstr();
  return 0;
}
	  
