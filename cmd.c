#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "app.h"

int first_path = 0;

node *stack = NULL;

void update_dirs(char *dir) {
     node *new_dir = (node *)malloc(sizeof(struct node *));
     strcpy(new_dir->path, dir);
     new_dir->link = stack;
     stack = new_dir;
}


void pushd (char *ch_dir) {
     char current_dir[LENGTH] = {'\0'};
     printf("pushd");
     if (!first_path) {
        if (getcwd(current_dir, LENGTH) != NULL ) {
           update_dirs(current_dir);
           first_path = 1;
        }
     }
     if (chdir(ch_dir) == 0) {
        if (getcwd(current_dir, LENGTH) != NULL) {
           update_dirs(current_dir);
        }
     } else {
       
        printf("\n  No such file or directory" );
     }

     dirs();
}

void pushd_right(int k) {
    if (stack == NULL || k == 0) return;
    printf("\n rotateRight: %d", k);
    node * oldHead = stack;
    node * current = oldHead;
    int length = 1;

    while (current->link != NULL) {
        current = current->link;
        length++;
    }

    k = k % length;
    if (k == 0) return;

    node  *newTail = stack;
    for (int i = 1; i < length - (k+1); i++) {
        newTail = newTail->link;
    }

    node *newHead = newTail->link;
    newTail->link = NULL;
    current->link = stack;
    stack = newHead;
    if (chdir(stack->path) != 0) {
      printf("\n  No such file or directory" );
    }
}

void pushd_left(int k) {
    if (stack == NULL || k <= 0) {
        return;
    }

    node* current = stack;
    node* new_tail = NULL;
    node* new_head = NULL;
    node* prev = NULL;
    int length = 1;

    while (current->link != NULL) {
        current = current->link;
        length++;
    }

    current->link = stack;

    k = k % length; 
    if (k == 0) {
        current->link = NULL;
        return;
    }

    new_tail = stack;
    for (int i = 1; i < length - (k+1); i++) {
        new_tail = new_tail->link;
    }

    new_head = new_tail->link;
    new_tail->link = NULL;

    stack = new_head;
    if (chdir(stack->path) != 0) {
      printf("\n  No such file or directory" );
    }
}


void popd_left(int k) {
     if(stack == NULL) {
        return;
     }
     node * temp =stack;
     node * prev = NULL;
     
     if(k == 0) {
       stack = temp->link;
       free(temp);
       return;
     }
     for (int i=0; temp != NULL && i <= k;i++) {
         prev =temp;
         temp = temp->link;
     } 
     prev->link = temp->link;
     free(temp);
    if (chdir(stack->path) != 0) {
      printf("\n  No such file or directory" );
    }
     
}
 

void popd_right(int k) { 
  if (stack == NULL) {
     return;
  }
  int length = 1;
  node *temp =stack;
  while(temp->link !=NULL) {
     temp = temp->link;
     length++;
  }
  k = length - k;
  temp = stack;
  node *prev = NULL; 
  
     for (int i=0; temp != NULL && i < k;i++) {
         prev =temp;
         temp = temp->link;
     } 
     prev->link = temp->link;
     free(temp);
    if (chdir(stack->path) != 0) {
      printf("\n  No such file or directory" );
    }

}

void pop(void) {
    if (stack ==NULL){
       printf("\n DIR STACK EMPTY\n");
    }
    node *temp = stack;
    if (chdir(temp->path) == 0) {
       stack = stack->link;
       free(temp);
    }
    if (chdir(stack->path) != 0) {
      printf("\n  No such file or directory" );
    }

    dirs();
}

void dirs(){
   node *current = stack;
    while (current != NULL) {
        printf("%s\n", current->path);
        current = current->link;
    }
}

int main() {
    char input[LENGTH];

    printf("Enter command  (type 'exit' to quit):\n");
    printf("\n Command are: \npushd \npopd \ndirs\n ");

    while (1) {
        printf("\nCommand: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\nError During fgets");
            return 1;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "pushd") == 0) {
            printf("\nPlease provide:  [+N | -N | dir]"); 
            char input[LENGTH];

            if (fgets(input, sizeof(input), stdin) == NULL) {
                printf("\nError During fgets");
                return 1;
             }
             input[strcspn(input, "\n")] = '\0';
             if (input[0] == '+') {
                pushd_right(atoi(&(input[1]))); 
             } else if (input[0] == '-') {
               pushd_left(atoi(&(input[1]))); 
             }else
             pushd(input);
        } else  if (strcmp(input, "popd") == 0) {
            char input[LENGTH];

            printf("\nPlease provide:  [+N | -N | dir]"); 
            if (fgets(input, sizeof(input), stdin) == NULL) {
                printf("\nError During fgets");
                return 1;
             }
             input[strcspn(input, "\n")] = '\0';
             if (input[0] == '+') {
                popd_right(atoi(&(input[1]))); 
             } else if (input[0] == '-') {
               popd_left(atoi(&(input[1]))); 
             }else
              pop();
        }else if (strcmp(input, "dirs") == 0) {
           dirs();
        }else 
           printf("\n Command not found");

        if (strcmp(input, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }

    }

    return 0;
}

