#include <stdio.h>
#include <string.h>
#include <my_seq.h>

int is_minimal(char *curr_seq, int seq_size); //if is minimal -> return 1

int gematria(char(*word), char(*text));

int gematria_val(char latter);

int meaningless(char latter); //if is meaningless -> return 1

int gematria_seq(char word[WORD], char text[TXT])
{
    char print_gem[TXT];
    char *word_ptr = word;
    char *src_ptr = text;
    int word_value = 0;
    for (int i = 0; i < WORD; ++i)
    {
        word_value = word_value + gematria_val(*(word_ptr + i));
    }
    while (*src_ptr != TXTE)
    {
        if (meaningless(*src_ptr) == TRUE)
        {
            ++src_ptr;
        }
        char *dest_ptr = src_ptr + 1;
        while (*dest_ptr != TXTE)
        {
            if (*src_ptr = *dest_ptr)
            {
                ++dest_ptr;
            }
            if (meaningless(*dest_ptr) == TRUE)
            {
                ++dest_ptr;
            }
            int seq_size = dest_ptr - src_ptr;
            int seq_value = 0;
            for (int i = 0; i < seq_size; ++i)
            {
                seq_value += gematria_val(*(src_ptr + i));
            }
            if (seq_value == word_value && is_minimal(src_ptr, seq_size) == TRUE)
            {
                strncpy((print_gem + sizeof(print_gem)), src_ptr, seq_size);
                ++src_ptr;
                break;
            }
            else if (seq_value < word_value)
            {
                ++dest_ptr;
            }
            else
            {
                ++src_ptr;
                break;
            }
            
        }

        int curr_gem_sum = 0;
        if (meaningless(*dest_ptr) == TRUE)
        {
        }
        for (int i = 0; i < (dest_ptr - src_ptr); ++i)
        {
        }
    }

    return 0;
}

int meaningless(char ch)
{
    if (ch == WE1 || ch == WE2 || ch == WE3)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int gematria_val(char latter)
{
    int ascii_val = (int)latter;
    if (ascii_val >= A_ASCII && ascii_val <= Z_ASCII)
    {
        return (ascii_val - A_ASCII + 1);
    }
    else if (ascii_val >= a_ASCII && ascii_val <= z_ASCII)
    {
        return (ascii_val - a_ASCII + 1);
    }
    else
    {
        return 0;
    }
}

int is_minimal(char *curr_seq, int seq_size)
{
    if (meaningless(*(curr_seq)) == FALSE && meaningless(*(curr_seq + seq_size - 1) == FALSE))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int atbash_seq(char word[WORD], char text[TXT])
{

    // return 0;
}

int anagram_seq(char word[WORD], char text[TXT])
{

    // return 0;
}
