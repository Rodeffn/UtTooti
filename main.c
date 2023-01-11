#include "func.h"
int main()
{
    user *current_user=NULL;
    user *temp=NULL;
    user *head;
    int state=1;
    char opions[9][10]={
        "signup",
        "post",
        "like",
        "info",
        "find_user",
        "delete",
        "logout",
        "login",
        "exit"

    };
    int how_many_signup_has_applied=1;
    while(state){
        fflush(stdin);
        system("cls");
        char *enter=readstring();
        int b=wich_one(opions,enter);
        switch (b) {
        case 0:
            //signup
        {
            char *user_name=readstring();
            char *password=second_readstring();
            if(how_many_signup_has_applied!=1){
                if(see_if_user_already_exits(user_name,head)==0){
                    printf("this user already exits\n");
                    getch();
                    break;
                }
            }
            head=new_user(user_name,password,head,how_many_signup_has_applied);
            printf("you signed in succefully\n");
            getch();
            how_many_signup_has_applied++;
            break;
        }
        case 1:
            //post
        {
            if(how_many_signup_has_applied==1){
                printf("you have to signup first\n");
                getch();
               break;
            }
            if(current_user==NULL){
                    printf("you have to login first");
                     getch();
                    break;
            }
            char *text=second_readstring();
            posting(text,current_user);
            getch();
            break;
        }
        case 2:
            //like
        {
            if(how_many_signup_has_applied==1){
                printf("you have to signup first\n");
                getch();
               break;
            }
            if(current_user==NULL){
                    printf("you have to login first");
                     getch();
                    break;
            }
            char *user_name=readstring();
            temp=find_user(head,user_name);
            if(temp==NULL){
                getch();
                break;
            }
            int id=atoi(second_readstring());
            if(id>how_many_post_does_user_have(temp) ||id<=0){
                printf("wrong post id\n");
                getch();
                break;
            }
            like_the_post(temp,id,current_user);
            temp=NULL;
            getch();
            break;

        }
        case 3:
            //info
        {
            if(how_many_signup_has_applied==1){
                printf("you have to signup first\n");
                getch();
               break;
            }
            if(current_user==NULL){
                    printf("you have to login first");
                     getch();
                    break;
            }
            info(current_user);
            getch();
            break;

        }
        case 4:
        {
            if(how_many_signup_has_applied==1){
                printf("user does not exit\n");
                getch();
               break;
            }
            //find_user
            char *user_name=second_readstring();
            temp=find_user(head,user_name);
            if(temp==NULL){
                getch();
                break;
              }
            print_objective_user(temp);
            temp=NULL;
            getch();
            break;

        }
        case 5:
            //delete
        {
            if(how_many_signup_has_applied==1){
                printf("you have to signup first\n");
                getch();
               break;
            }
            if(current_user==NULL){
                    printf("you have to login first");
                     getch();
                    break;
            }
            int post_number=atoi(second_readstring());
            delete_post(current_user,post_number);
            printf("post deleted\n");
            getch();
            break;

        }

        case 6:
            //logout
        {
            if(how_many_signup_has_applied==1){
                printf("you have to signup first\n");
                getch();
               break;
            }
            if(current_user!=NULL){
            printf("you logged out from %s\n",current_user->user_name);
            current_user=NULL;
            getch();
            break;}
            else {
                printf("you are not logged in any account\n");
                getch();
                break;
            }
        }
        case 7:
            //login
        {
            if(how_many_signup_has_applied==1){
                printf("you have to signup first\n");
                getch();
               break;
            }
           if(current_user==NULL){
            char *user_name=readstring();
            char *password=second_readstring();
            current_user=login(head,user_name,password);
            getch();
            break;}
           else {
               printf("you have to logout first\n");
               getch();
               break;
           }
        }
        case 8:
            //exit
        {
            state=0;
            write(head);
            break;
        }
        case -1:
            //wrong input
        {
            puts("pleas try again");
            getch();
            break;

        }
        }
    }
}

