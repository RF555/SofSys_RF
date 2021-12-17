#include <stdio.h>
#include "my_seq.h"
#include "string.h"

int main() {
//    char input[] = "abcd\n"
//                   "a-bc,dbca-zwxyzabzyxw0dcba~";
//    int total_size = sizeof(input);
    char input[TXT];
    int total_size = 0;
    while (input[total_size - 1] != '~') {
        char temp;
        scanf("%c", &temp);
        input[total_size] = temp;
        ++total_size;
    }
    char *word_ptr = input;
    int word_size = 0;
    char word[WORD];
//    while ((*(word_ptr + word_size) != WE1) && (*(word_ptr + word_size) != WE2) && (*(word_ptr + word_size) != WE3)) {
    while ((*(word_ptr + word_size) != ' ') && (*(word_ptr + word_size) != '\t') && (*(word_ptr + word_size) != '\n')) {
        word[word_size] = input[word_size];
        ++word_size;
    }
    char *text_ptr = word_ptr + word_size;
    gematria_seq(word, word_size, text_ptr, (total_size - word_size));
    printf("\n");
    atbash_seq(word, word_size, text_ptr, (total_size - word_size));
    printf("\n");
//    anagram_seq(word, word_size, text_ptr, (total_size - word_size));
    return 0;
}