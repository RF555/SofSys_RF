#include <stdio.h>
#include <string.h>
#include "my_seq.h"


int meaningless(char ch) { //if is meaningless -> return 1
//    if (ch == WE1 || ch == WE2 || ch == WE3) {
    if ((ch >= A_ASCII && ch <= Z_ASCII) || (ch >= a_ASCII && ch <= z_ASCII)) {
        return FALSE;
    } else {
        return TRUE;
    }
}

int is_minimal(char *curr_seq, int seq_size) { //if is minimal -> return 1
    if (meaningless(*(curr_seq)) == FALSE && meaningless(*(curr_seq + seq_size - 1)) == FALSE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

// GEMATRIA functions

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

int gematria_seq(char *word, int word_size, char *text, int text_size) {
    char print_gem[TXT];
    int print_gem_size = 0;
    char *src_ptr = text;
    int word_value = 0;
    for (int i = 0; i < word_size; ++i) {
        word_value = word_value + gematria_val(*(word + i));
    }
    while (*src_ptr != '~') {
        if (meaningless(*src_ptr) == TRUE) {
            ++src_ptr;
        }
        char *dest_ptr = src_ptr;
        while (*dest_ptr != '~') {
//            if (*src_ptr == *dest_ptr) {
//                ++dest_ptr;
//            }
            if (meaningless(*dest_ptr) == TRUE) {
                ++dest_ptr;
            }
            int seq_size = (int) (dest_ptr - src_ptr) + 1;
            int seq_value = 0;
            for (int i = 0; i < seq_size; ++i) {
                int temp_val = gematria_val(*(src_ptr + i));
                seq_value = seq_value + temp_val;
            }
            if (seq_value == word_value && is_minimal(src_ptr, seq_size) == TRUE) {
                if (print_gem_size > 0) {
                    print_gem[print_gem_size] = '~';
                    ++print_gem_size;
                }
                strncpy((print_gem + print_gem_size), src_ptr, seq_size);
                print_gem_size = print_gem_size + seq_size;
                break;
            } else if (seq_value < word_value) {
                ++dest_ptr;
            } else {
                break;
            }
        }
        ++src_ptr;
    }
    print_gem[print_gem_size] = '\0';
    printf("%s%s", GEM, print_gem);
    return 0;
}

// ATBASH functions

char atbash_swap(char ch) {
    if (ch >= A_ASCII && ch <= Z_ASCII) {
        return Z_ASCII + A_ASCII - ch;
    } else if (ch >= a_ASCII && ch <= z_ASCII) {
        return z_ASCII + a_ASCII - ch;
    }
    return 0;
}

int is_atb(char *atb_ptr, int atb_size, char *seq_ptr, int seq_size) {
    if (*atb_ptr == *seq_ptr) {
        int j = 0;
        for (int i = 0; i < atb_size; ++i) {
            if (meaningless(*(seq_ptr + j)) == TRUE) {
                ++j;
            }
            if (*(atb_ptr + i) != *(seq_ptr + j)) {
                return FALSE;
            }
        }
        return TRUE;
    }
    return FALSE;
}

int atbash_seq(char *word, int word_size, char *text, int text_size) {
    char print_atb[TXT];
    int print_atb_size = 0;
    char *src_ptr = text;
    char word_atb[word_size];
    char word_rev_atb[word_size];
    for (int i = 0; i < word_size; ++i) {
        char temp = atbash_swap(word[i]);
        word_atb[i] = temp;
        word_rev_atb[word_size - 1 - i] = temp;
    }
    while (*src_ptr != '~') {
        if (meaningless(*src_ptr) == TRUE) {
            ++src_ptr;
        }
        char *dest_ptr = src_ptr + word_size - 1;
        while (*dest_ptr != '~') {
            if (meaningless(*dest_ptr) == TRUE) {
                ++dest_ptr;
            }
            int seq_size = (int) (dest_ptr - src_ptr) + 1;
            int seq_value = 0;
            for (int i = 0; i < seq_size; ++i) {
                if (meaningless(*(src_ptr + i)) == TRUE) {

                }

            }
            if (is_minimal(src_ptr, seq_size) == TRUE &&
                (is_atb(word_atb, word_size, src_ptr, seq_size) == TRUE ||
                 is_atb(word_rev_atb, word_size, src_ptr, seq_size) == TRUE)) {
                if (print_atb_size > 0) {
                    print_atb[print_atb_size] = '~';
                    ++print_atb_size;
                }
                strncpy((print_atb + print_atb_size), src_ptr, seq_size);
                print_atb_size = print_atb_size + seq_size;
                break;
            } else if (seq_value < word_size) {
                ++dest_ptr;
            } else {
                break;
            }
        }
        ++src_ptr;
    }
    print_atb[print_atb_size] = '\0';
    printf("%s%s", ATB, print_atb);
    return 0;
}

int anagram_seq(char *word, int word_size, char *text, int text_size) {

    return 0;
}
