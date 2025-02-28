#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int len(const char* str);
int substr(const char* str, int n, const char* key, int m);
int shift_table(const char* template, int n, int* result);
int line_counter(const char* str, int size);
int pos_in_line(const char *str, int size);
int find_substr_in_files(char* substr, int m, int file_count, ...);
int file_handler(char* key, int m, char* filename);
