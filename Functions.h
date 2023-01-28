#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct user User;
typedef struct post Post;

struct post
{
    int post_id;
    int like;
    char *text;
    char *p_username;

    Post *next_post;
};

struct user
{
    char *userName;
    char *password;
    int numberOfPosts;

    User *next_user;
};

#define TRUE 1 
#define FALSE 0 

void add_user(User *head, char* username);
User* search_user(User *u, char* usernameCheck, char* passwordCheck);
void add_post(Post *head, User*u_logged);
void print_user_posts(User *u, Post *head);
void delete_post(Post *head_post, User *logged_u, int id);
void like_post(Post *head_post, char post_ownar_name[], int id);
User* search_user_whitouth_pass(User *head, char username[]);

