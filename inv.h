#ifndef INV_S
#define INV_S

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

// Text color macros
#define RESET   "\033[0m"
#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"

typedef struct sub_node
{
    char *fname;
    int w_count;
    struct sub_node *s_link;
}sub;

typedef struct main_node
{
    char *word;
    int f_count;
    sub *sub_link;
    struct main_node *m_link;
}main_t;

typedef struct hashtable
{
    int index;
    main_t *h_link;
}hash_t;

typedef struct filename
{
    char *filename;
    struct filename *f_link;
}file;

int validate(file **head,char *fname);

int get_index(char ch);

int delete_file(file **f_head,char *fname);

void create_HT(hash_t *HT, int size);

int create_db(file **f_head,hash_t *arr);

int search_db(hash_t *arr);

void display_db(hash_t *arr);

void save_db(hash_t *arr);

void delete_db(hash_t *arr,file **head);

int update_db(file **f_head,hash_t *arr);

#endif