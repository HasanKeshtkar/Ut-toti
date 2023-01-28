#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Functions.h"

typedef struct user User;
typedef struct post Post;

#define TRUE 1 
#define FALSE 0 

void main()
{
    /*head of user list*/
    User *user_head = malloc(sizeof(User));
    user_head->next_user = NULL;

    User *u_logged = malloc(sizeof(User));

    /*head of post list*/
    Post *post_head = malloc(sizeof(Post));
    post_head->next_post = NULL;
    

    /*While loop to be in program*/
    while (TRUE)
    {
        
        printf("Please enter your order\n");
        char order[10] = {};
        scanf("%s", order);

        /*signup*/
        char signup[] = "signup";
        if (strcmp(order, signup) == 0)
        {
            char* username = malloc(sizeof(char) * 100);
            scanf("%s", username);
            if (search_user_whitouth_pass(user_head, username) == NULL)
            {
               add_user(user_head, username); 
            }
            else
            {
                printf("That username is taken. Try another: \n");
                char pass_temp[20];
                scanf("%s",pass_temp);
            }
        }
        /*login*/
        char login[] = "login";
        if (strcmp(order, login) == 0)
        {
            char usernameCheck[20];
            char passwordCheck[20];
            scanf("%s %s", usernameCheck, passwordCheck);

            u_logged = search_user(user_head, usernameCheck, passwordCheck);

            if (u_logged == NULL)
            {
                printf("password or username is not correct!\n");
            }
        }

        /*logout*/
        char logout[] = "logout";
        if ((strcmp(order, logout) == 0) && (u_logged != NULL))
        {
            u_logged = NULL;
            printf("Bye\n");
        }
        
        /*addpost*/
        char post[] = "post";
        if ((strcmp(order, post) == 0) && (u_logged != NULL))
        {
            add_post(post_head, u_logged);
        }

        /*info*/
        char info[] = "info";
        if ((strcmp(order, info) == 0) && (u_logged != NULL))
        {
            print_user_posts(u_logged, post_head);
        }

        /*delete post*/
        char delete[] = "delete";
        if ((strcmp(order, delete) == 0) && (u_logged->userName != NULL))
        {
            int id;
            scanf("%d", &id);
            delete_post(post_head, u_logged, id);
        }

        /*like post*/
        char like[] = "like";
        if ((strcmp(order, like) == 0) && (u_logged != NULL))
        {
            char post_ownar_name[50];
            int id;
            scanf("%s %d", post_ownar_name, &id);
            
            like_post(post_head, post_ownar_name, id);
        }

        /*finde user*/
        char find_user[] = "find_user";
        if (strcmp(order, find_user) == 0)
        {
            char username[50];
            scanf("%s", username);
            if(search_user_whitouth_pass(user_head, username) != NULL)
            {
                print_user_posts(search_user_whitouth_pass(user_head, username), post_head);
            }
            else
            {
                printf("This username does not exist\n");
            }
        }

        /*fort wrong order*/
        if ((strcmp(order, find_user) != 0) && (strcmp(order, like) != 0) && (strcmp(order, delete) != 0) && (strcmp(order, info) != 0) && (strcmp(order, post) != 0) && (strcmp(order, logout) != 0) && (strcmp(order, login) != 0) &&(strcmp(order, signup) != 0))
        {
                printf("This command does not exist\n");
        }

        char temp[50];
        
        scanf("%[^\n]", temp);
        printf("Enter something\n");
        getch();
        system("cls");
        
    }
    
}

