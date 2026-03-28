//Reverse a string using stack

#include<stdio.h>
#include<string.h>

char stack[100];      
int top=-1;            // stack top index

void push(char ch){
    if (top==99){      // check overflow
        printf("Stack overflow\n");
        return;
    }

    top++;
    stack[top]=ch;   
}

void pop(){
    if(top==-1){       // check underflow
        printf("Stack underflow\n");
        return;
    }
    else{
        printf("%c", stack[top]); // print top element
        top--;                  
    }
}

int main(){

    char word[100];
    printf("Enter a word: ");
    scanf("%s", word);  
 
    int len=strlen(word);  // find length

    for(int i=0;i<len;i++){
        push(word[i]);     // push each character
    }

    for(int i=0;i<len;i++){
        pop();             // pop to reverse
    }

    return 0;
}
