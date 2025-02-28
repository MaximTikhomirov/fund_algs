#include "solution.h"

int len(const char* str) {
    int i = 0;
    while (str[i++] != '\0');
    return i - 1;
}


int shift_table(const char *template, int n, int *result) {
    if (n == 0)
        return 1;

    int i = 1, j = 0;
    result[0] = 0;
    while (i < n) {
        if (template[i] != template[j]) {
            if (j == 0) {
                result[i] = 0;
                i++;
            } else if (j > 0) {
                j = result[j - 1];
            }
        } else {
            j++;
            result[i] = j;
            i++;
        }
    }
    return 0;
}


int substr(const char* str, int n, const char* key, int m) {
    n--;
    m--;
    int table[m], i = 0, j = 0;

    shift_table(key, m, table);

    while (i < n) {
        if (isspace(str[i]) && isspace(key[j])) {
            while (isspace(str[i])) i++;
            while (isspace(key[j])) j++;
        }
        if (str[i] == key[j]) {
            i++;
            j++;
            if (j == m) {
                return i - j; 
            }
        } else {
            if (j > 0) {
                j = table[j - 1];
            } else {
                i++;
            }
        }
    }
    return -1;
}

int line_counter(const char *str, int size) {
    int count = 1;
    for (int i = 0; i < size; ++i) {
        if (str[i] == '\n')
            count++;
    }
    return count;
}

int pos_in_line(const char *str, int size) {
    if (str[size - 1] == '\n')
        return 1;
    for (int i = size - 2; i >= 0; --i) {
        if (str[i] == '\n')
            return size - i - 1;
    }
    return size;
}

int file_handler(char *key, int m, char *filename) {
    FILE* stream = fopen(filename, "r");
    if (!stream)
        return 1;

    fseek(stream, 0, SEEK_END);
    int size = ftell(stream);
    fseek(stream, 0, SEEK_SET);

    char *content = (char*) malloc(size + 1);
    if (!content) {
        fclose(stream);
        return 1;
    }

    fread(content, 1, size, stream);
    content[size] = '\0';

    int i = 0, ind = 0;

    while (ind < size) {
        i = substr(content + ind, size - ind, key, m);
        if (i == -1) break;
        ind += i;
        printf("Found occurrence in file %s, line %d, character %d\n", filename, line_counter(content, ind),
               pos_in_line(content, ind));
        ind++; 
    }

    free(content);
    fclose(stream);
    return 0;
}

int find_substr_in_files(char *substr, int m, int file_count, ...) {
    va_list files;
    char* filename;

    va_start(files, file_count);
    for (int i = 0; i < file_count; ++i) {
        filename = va_arg(files, char*);
        int err = file_handler(substr, m, filename);
        if (err) {
            va_end(files);
            return err;
        }
    }
    va_end(files);

    return 0;
}
