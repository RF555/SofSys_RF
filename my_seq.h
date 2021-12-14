#ifndef _MY_SEQ_H_
#define _MY_SEQ_H_

#define TXT 1024
#define WORD 30
#define GEM "Gematria Sequences:"
#define ATB "Atbash Sequences:"
#define ANG "Anagram Sequences:"

int gematria_seq(char (*word)[WORD], int (*text)[TXT]);

int atbash_seq(char (*word)[WORD], int (*text)[TXT]);

int anagram_seq(char (*word)[WORD], int (*text)[TXT]);

#endif