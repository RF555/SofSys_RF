#ifndef _MY_SEQ_H_
#define _MY_SEQ_H_

#define TXT 1024
#define WORD 30
#define WE1 ' '
#define WE2 '\t'
#define WE3 '\n'
#define TXTE '~'
#define GEM "Gematria Sequences:"
#define ATB "Atbash Sequences:"
#define ANG "Anagram Sequences:"
#define A_ASCII 65
#define Z_ASCII 90
#define a_ASCII 97
#define z_ASCII 122
#define LETT_NUM 26

int gematria_seq(char (*word)[WORD], int (*text)[TXT]);

int atbash_seq(char (*word)[WORD], int (*text)[TXT]);

int anagram_seq(char (*word)[WORD], int (*text)[TXT]);

#endif