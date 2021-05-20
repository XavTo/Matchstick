/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** fichier h prototypes
*/

#ifndef MY_H
#define MY_H

int my_isneg(int nb);
int my_check_even(int nb);
char *my_strstr(char *str, char const *to_find);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
void my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_put_nbr(int nb);
char *my_strdup(char const *src);
void my_swap(int *a, int *b);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strcapitalize(char *str);
int my_printf(char const *format, ...);
int my_put_short(short nb, int *p_ret);
int my_put_nbr2(int nb, int *p_ret);
int my_octa_convert(unsigned int ben, int *p_ret);
int my_exec_convert(unsigned int ben, int *p_ret);
int my_exec_maj_short(unsigned short ben, int *p_ret);
int my_exec_convert_short(unsigned short ben, int *p_ret);
int my_display_add(unsigned long long ben, int *p_ret);
char *binary_create(int a, int ben, int j, char *binary);

#endif
