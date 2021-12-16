#include <stdio.h>
#include "my_seq.h"
#include "string.h"

int main() {
    char input[TXT + WORD];
//    scanf("%c", select);
//    scanf("%s",&input[0]);
    int total_size = 0;
//    char *ptr = &input[0];
//    while (*(ptr + total_size) != '~' && total_size < (TXT + WORD)) {
    while (input[total_size - 1] != '~') {
        char temp;
        scanf("%c", &temp);
        input[total_size] = temp;
        ++total_size;
    }
    char *word_ptr = input;
    int word_size = 0;
    while ((*(word_ptr + word_size) != WE1) && (*(word_ptr + word_size) != WE2) && (*(word_ptr + word_size) != WE3)) {
        ++word_size;
    }
    char *text_ptr = word_ptr + word_size;
    gematria_seq(word_ptr, word_size, text_ptr, (total_size - word_size));
//    atbash_seq(word_ptr, text_ptr);
//    anagram_seq(word_ptr, text_ptr);
    return 0;
}