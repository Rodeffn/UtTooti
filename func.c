#include "func.h"
//in function ba estefade az dynamic array srting ra ta jaee ke \n ya space bashad mikhanad
char *readstring(){
    int i=-1;
    char *v=(char *)(malloc(sizeof (char)));
    while( v[i]!=' ' && v[i]!='\n')
    {
        i++;
        v=(char *)realloc(v,sizeof (char)*(i+1));
        v[i]=getchar();

    }
    v[i] = '\0';
    return v;
}
//fargh in ba ghabli in ast ke ta \n mikhanad
char *second_readstring(){
    int i=-1;
    char *v=(char *)(malloc(sizeof (char)));
    while( v[i]!='\n')
    {
        i++;
        v=(char *)realloc(v,sizeof (char)*(i+1));
        v[i]=getchar();

    }
    v[i] = '\0';
    return v;
}
//ba gereftane head va text post migozarad
void posting(char* post_text,user *carbar){
  post *v=carbar->head;
  int id=1;
  while(v->next!=NULL){
    v=v->next;
    id++;
  }
  v->next=(post *)(malloc(sizeof (post)));
  v=v->next;
  v->post_text=post_text;
  v->post_id=id;
  v->like=0;
  printf("user: %s\n",carbar->user_name);
  printf("text: %s\n",v->post_text);
  printf("post_id: %d\n",v->post_id);
  printf("likes: %d\n",v->like);
  v->next=NULL;
  v->people=(likes*)(malloc(sizeof (likes)));
  v->people->next=NULL;
  v->people->username="";
}
//user jadid ra be sar link list ezafe mikonad
user* new_user(char *username, char *password,user *users,int i){
    if(i==1){

    users=(user *)(malloc(sizeof (user)));
    users->user_name=username;
    users->password=password;
    users->head=(post *)(malloc(sizeof (post)));
    users->head->next=NULL;
    users->next=NULL;
    return users;
}

    else {
        user*temp=users;
        while(temp->next!=NULL)
            temp==temp->next;
        temp->next=(user *)(malloc(sizeof (user)));
        temp=temp->next;
        temp->user_name=username;
        temp->password=password;
        temp->head=(post *)(malloc(sizeof (post)));
        temp->head->next=NULL;
        temp->next=NULL;
        return users;

    }

}
// ba estefade head pointer  user ra ba migardanad
user *find_user(user *n,char *name){
    while(n!=NULL){
        if(strcmp(n->user_name,name)==0){
            return n;
        }
        else {
            n=n->next;
        }
    }
    puts("user was not  found");
    return NULL;
}
void print_objective_user(user* n){
    printf("user name:%s\n",n->user_name);
    post *m=n->head;
    while(m->next!=NULL){
        m=m->next;
        printf("post %d : %s\nlikes: %d\n",m->post_id,m->post_text,m->like);
    }
}
//dar inja ba kar ba switch case va readstring kalame aval ro mikhanad va dar sooratv adam vojood -1 return mikonad
int wich_one(char opinos[9][10],char *enter){
    for (int i=0;i<9;i++) {
        for (int j=0;j<10;j++) {
            if(opinos[i][j]==enter[j] && opinos[i][j]!='\0'){
                continue;
            }
            if(opinos[i][j]==enter[j] && opinos[i][j]=='\0'){
                return  i;
            }
            if(opinos[i][j]!=enter[j]){
                break;
            }
        }
    }
    return -1;
}
// ba post id  head va user  post ra like mikonad vali ghabl an ba function see if already user like the post check mikonad
int like_the_post(user *copy,int id,user *n){
    post *m=copy->head;

    while(m->post_id!=id){
        m=m->next;
    }
   if(see_if_user_already_like_the_post(n,m)==0)
    m->like++;
   else {
       printf("already liked the post\n");
       return 0;
   }
    likes *temp=m->people;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->username=malloc(sizeof (n->user_name));
    temp->username=n->user_name;
    temp->next=malloc(sizeof (likes));
    temp->next->next=NULL;
    temp->next->username="";
    printf("user: %s\npost %d : %s\nlikes: %d\n",copy->user_name,
           
           m->post_id,m->post_text,m->like);
}
int see_if_user_already_like_the_post(user *n,post *m){
    likes *poeple=m->people;
    while (poeple!=NULL) {
        if(strcmp(n->user_name,poeple->username)==0)
            return 1;
        poeple=poeple->next;
    }
    return 0;
}
//post ra ba post id va head delete mikonad
void delete_post(user *n, int id){
    post *m=n->head;
    post *previous=m;
    while(m!=NULL){
        if(m->post_id==id){
          previous->next=m->next;
          rearrenge(n);
          break;
        }
        else {
            previous=m;
            m=m->next;
        }
    }
}
//tartib post haro baad delete dorost  mikonad
void rearrenge(user *n){
    post *m=n->head;
    m=m->next;
    int i=1;
    while(m!=NULL){
        m->post_id=i;
        m=m->next;
        i++;
    }
}
void info(user *n){
    printf("user name : %s\n",n->user_name);
    printf("password : %s\n",n->password);
    post *m=n->head;
    m=m->next;
    while (m!=NULL) {
        printf("post %d : %s\nlikes: %d\n",m->post_id,m->post_text,m->like);
        m=m->next;
    }
}
//dar link list search mikonad va  check mikonad
int see_if_user_already_exits(char *user_name,user *copy){
    user *temp=copy;
    while(temp!=NULL){
        if(strcmp(temp->user_name,user_name)==0)
            return 0;
        else {
            temp=temp->next;
        }
    }
    return 1;

}
// baad az signup login mikonad va pointer user bar migardanad
user *login(user *copy, char *user_name,char * password){
    user *temp=copy;
    if(see_if_user_already_exits(user_name,copy)==0){
        while(temp!=NULL){
            if(strcmp(user_name,temp->user_name)==0){
                if(strcmp(password,temp->password)==0){
                    printf("you logged in succefully\n");
                    return temp;
                }
                else {
                    printf("password is wrong \n");
                    return NULL;
                    break;
                }
            }
            temp=temp->next;
        }
    }
    printf("user doesnt exits\n");
    return NULL;
}
//baraye contorol voroodi
int how_many_post_does_user_have(user *n){
    post *m=n->head;
    int a=0;
    while(m->next!=NULL){
        a++;
        m=m->next;
    }
    return a;
}
//neveshtan dar file baad az etmam kar
void write(user *copy){
    FILE *account_file=fopen("accounts.txt","w");
    FILE *posts_file=fopen("posts.txt","w");
    while(copy!=NULL){
        fprintf(account_file,"%s %s %d\n",copy->user_name,copy->password,how_many_post_does_user_have(copy));
        post *s=copy->head;
        s=s->next;
        while(s!=NULL){
            fprintf(posts_file,"%s %s %d\n",s->post_text,copy->user_name,s->like);
            s=s->next;
        }
        copy=copy->next;
    }
    fclose(account_file);
    fclose(posts_file);


}
