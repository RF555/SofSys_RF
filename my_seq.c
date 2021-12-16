#include <stdio.h>
#include <string.h>
#include "my_seq.h"

int is_minimal(char *curr_seq, int seq_size); //if is minimal -> return 1

int gematria(char(*word), char(*text));

int gematria_val(char latter);

int meaningless(char ch); //if is meaningless -> return 1

int gematria_seq(char *word, int word_size, char *text, int text_size){
    char print_gem[TXT];
    int print_gem_size = 0;
    char *word_ptr = word;
    char *src_ptr = text;
    int word_value = 0;
    for (int i = 0; i < word_size; ++i) {
        word_value = word_value + gematria_val(*(word_ptr + i));
    }
    while (*src_ptr != TXTE) {
        if (meaningless(*src_ptr) == TRUE) {
            ++src_ptr;
        }
        char *dest_ptr = src_ptr;
        while (*dest_ptr != TXTE) {
//            if (*src_ptr == *dest_ptr) {
//                ++dest_ptr;
//            }
            if (meaningless(*dest_ptr) == TRUE) {
                ++dest_ptr;
            }
            int seq_size = (int) (dest_ptr - src_ptr)+1;
            int seq_value = 0;
            for (int i = 0; i < seq_size; ++i) {
                int temp_val = gematria_val(*(src_ptr + i));
                seq_value = seq_value + temp_val;
            }
            if (seq_value == word_value && is_minimal(src_ptr, seq_size) == TRUE) {
                if (print_gem_size > 0) {
                    print_gem[print_gem_size] = TXTE;
                    ++print_gem_size;
                }
                strncpy((print_gem + print_gem_size), src_ptr, seq_size);
                print_gem_size = print_gem_size + seq_size;
                ++src_ptr;
                break;
            } else if (seq_value < word_value) {
                ++dest_ptr;
            } else {
                ++src_ptr;
                break;
            }
        }
    }
    printf("%s", GEM);
    return 0;
}

int meaningless(char ch) {
//    if (ch == WE1 || ch == WE2 || ch == WE3) {
    if ((ch >= A_ASCII && ch <= Z_ASCII) || (ch >= a_ASCII && ch <= z_ASCII)) {
        return FALSE;
    } else {
        return TRUE;
    }
}

int gematria_val(char latter) {
    int ascii_val = (int) latter;
    if (ascii_val >= A_ASCII && ascii_val <= Z_ASCII) {
        return (ascii_val - A_ASCII + 1);
    } else if (ascii_val >= a_ASCII && ascii_val <= z_ASCII) {
        return (ascii_val - a_ASCII + 1);
    } else {
        return 0;
    }
}

int is_minimal(char *curr_seq, int seq_size) {
    if (meaningless(*(curr_seq)) == FALSE && meaningless(*(curr_seq + seq_size - 1) == FALSE)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int atbash_seq(char word[WORD], char text[TXT]) {

    return 0;
}

int anagram_seq(char word[WORD], char text[TXT]) {

    return 0;
}
