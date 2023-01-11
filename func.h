#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//#define true 1
char *readstring(void);
char *second_readstring(void);
//dar inja ba tarif struct jadid baraye like post va user darim
typedef struct likes{
    char *username;
    struct likes  *next;
}likes;
typedef struct post{
    int like;
    int post_id;
    char *post_text;
     likes *people;
    struct post *next;
}post;
typedef struct user{
    char *user_name;
    char *password;
    post *head;
    struct user *next;
}user;

void posting(char* post_text,user *carbar);

user* new_user(char *username, char *password,user *users,int i);

user *find_user(user *n,char *name);

void print_objective_user(user* n);

int wich_one(char opinos[6][10],char *enter);

int like_the_post(user *copy,int id, user *n);

void delete_post(user *n, int id);

void rearrenge(user *n);

void info(user *n);

int see_if_user_already_exits(char *user_name,user *copy);

user *login(user *copy, char *username,char * password);

int how_many_post_does_user_have(user *n);

int see_if_user_already_like_the_post(user *n,post *m);

void write(user *copy);
