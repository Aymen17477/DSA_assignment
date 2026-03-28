//Printer Queue Simulation

#include <stdio.h>
#include <string.h>

#define MAX 100

struct Document{
    char name[50];
    int pages;
};

struct Document queue[MAX];
int front=-1;
int rear=-1;          // queue pointers

void add(){
    if(rear==MAX-1){  // check queue full
        printf("Printer Queue Full!\n");
    }
    else{
    struct Document doc;
    printf("Enter file name:");
    scanf("%s",&doc.name);   // input file name
    printf("Enter pages:");
    scanf("%d",&doc.pages);  // input pages

    if (front==-1){   // first element
        front = 0;
    }
    rear++;
    queue[rear]=doc;  // add to queue
    printf("'%s' added to queue.\n", doc.name);

}
}

void print() {
    if (front==-1||front>rear) {   // check empty
        printf("No documents in queue!\n");
      
    }
    else{
    printf("Printing: '%s' (%d pages)\n", queue[front].name,queue[front].pages);
    front++;   // remove element
    }
}

void displayPending(){
    if (front==-1||front>rear) {   // check empty
        printf("No pending documents.\n");
    }
    else{
    printf("\nPending Documents:\n");
    for (int i=front;i<=rear;i++) {
        printf("%s - %d pages\n",queue[i].name, queue[i].pages);  // display queue
    }
}
}

int main() {
    int choice;

    while(1){
        printf("\n--- Printer Queue ---\n");
        printf("1. Add Document\n");
        printf("2. Print Document\n");
        printf("3. Display Pending\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice==1){
             add();   // add document
        }

        else if(choice==2){
             print(); // print document
        }

        else if(choice==3) {
            displayPending(); // show pending
        }

        else if(choice==4) {
            break;   // exit
        }

        else {
            printf("Invalid choice!\n");
        }

    }

    return 0;   // end program
}