#include "solution.c"

int main(int argc, char** argv) {
    char sub[] = "ab\no\nba";
    find_substr_in_files(sub, len(sub), 2, "file1.txt", "file2.txt");
    return 0;
}