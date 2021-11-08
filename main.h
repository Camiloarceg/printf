#ifndef MAIN_FILE
#define MAIN_FILE
#include <stdarg.h>

int _printf(const char *format, ...);
char *nest(char *buffer, int *count, int *i, char c);
char *neststring(char *buffer, char *s, int *count, int *i);
char *nest_int(char *buffer, int *count, int *i, int n);
int _strlen(char *s);

#endif
