#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "Functions.h"

typedef struct user User;
typedef struct post Post;

#define TRUE 1 
#define FALSE 0 


/*add user*/
void add_user(User *head, char* username)
{
    User *current = head;
    User *new = malloc(sizeof(User));
    /*travers till then end of the list*/
    while (current->next_user != NULL)
    {
        current = current->next_user;
    }

    current->next_user = new;
    new->next_user = NULL;
    new->userName = malloc(sizeof(char) * 100);
    new->password = malloc(sizeof(char) * 100);
    scanf("%s", new->password);
    new->userName = username;
    new->numberOfPosts = 0;
}

/*search from user*/
User* search_user(User *u, char* usernameCheck, char* passwordCheck)
{
    User *current  = malloc(sizeof(User));
    current = u;

    /*travers till then end of the list*/
    while (current->next_user != NULL)
    {
        current = current->next_user;
        if ((strcmp(current->userName, usernameCheck) == 0) && (strcmp(current->password, passwordCheck) == 0))
        {
            return current;
        }
        
    }

    return NULL;
}

/* adding post :/ */
void add_post(Post *head, User*u_logged)
{
    Post *current = head;
    Post *new = malloc(sizeof(Post));

    /*travers till then end of the list*/
    while (current->next_post != NULL)
    {
        current = current->next_post;
    }

    current->next_post = new;
    new->next_post = NULL;

    new->text = malloc(sizeof(char) * 200);
    new->p_username = malloc(sizeof(char) * 100);
    scanf("%[^\n]", new->text);
    new->like = 0;
    new->p_username = u_logged->userName;
    u_logged->numberOfPosts ++;
    new->post_id = u_logged->numberOfPosts;
    
}

/*print users posts*/
void print_user_posts(User *u, Post *head)
{
    Post *current_p;
    current_p = head;

    /*travers till then end of the list*/
    while (current_p->next_post != NULL)
    {
        current_p = current_p->next_post;
        if (strcmp(current_p->p_username, u->userName) == 0)
        {
            printf("user : %s\npost_id : %d\nlike : %d\npost : %s\n\n", current_p->p_username, current_p->post_id, current_p->like, current_p->text);
        }
    }
}

/*delete post*/
void delete_post(Post *head_post, User *logged_u, int id)
{
    Post *current = head_post;
    Post *previos = head_post;
    if (current->next_post == NULL)
    {
        printf("There is no post to delete\n");
        return;
    }
    /*travers till then end of the list*/
    while (current->next_post != NULL)
    {
        previos = current;
        current = current->next_post;
        if ((current->next_post == NULL) && (strcmp(logged_u->userName, current->p_username) == 0) && (current->post_id == id))
        {
            previos->next_post = NULL;
            current = NULL;
            free(current); 
            return; 
        }
        if ((strcmp(logged_u->userName, current->p_username) == 0) && (current->post_id == id))
        {
            previos->next_post = current->next_post;
            current = NULL;
            free(current);
            return;
        }
    }
    printf("The requested post for delete was not found\n");
    
}

/*like post*/

void like_post(Post *head_post, char post_ownar_name[], int id)
{
    Post *current = head_post;
    
    /*travers till then end of the list*/
    while (current->next_post != NULL)
    {
        current = current->next_post;

        if ((strcmp(post_ownar_name, current->p_username) == 0) && (id == current->post_id))
        {
            current->like++;
            return;
        }
        
    }
    
    printf("The requested post for like was not found\n");
}

/*search user whitouth pass*/
User* search_user_whitouth_pass(User *head, char username[])
{
    User *current = head;
    /*travers till then end of the list*/
    while (current->next_user != NULL)
    {
        current = current->next_user;
        if (strcmp(current->userName , username) == 0)
        {
            return current;
        }
        
    }
    return NULL;

}