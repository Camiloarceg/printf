#ifndef MAIN_FILE
#define MAIN_FILE
#include <stdarg.h>

int _printf(const char *format, ...);
char *nest(char *buffer, int *count, int *i, char c);
char *neststring(char *buffer, char *s, int *count, int *i);
char *nest_int(char *buffer, int *count, int *i, int n);
int _strlen(char *s);
char *neststring_r(char *buffer, char *s, int *count, int *i);
char *switch_case_adv(char *buffer, const char *format, int *count, va_list ap, int *i);
#endif
