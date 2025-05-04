#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    char symbol;
    struct node* next;
};

struct node* top=NULL;

bool isEmpty() {
    return top == NULL;
}

void push(char symbol) {
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->symbol=symbol;
    ptr->next=NULL;
    if (isEmpty()){
        top=ptr;
    }else {
        ptr->next=top;
        top=ptr;
    }

}

void pop() {
    struct node* ptr=top;
    if(isEmpty()){
        printf("stack is empty");
        return;
    }else {
        top=top->next;
        free(ptr);
    }
}

bool checkSequence(char opening,char closing) {
    if(opening=='(' && closing==')') {
        return true;
    }else if(opening=='[' && closing==']') {
        return true;
    }else if(opening=='{' && closing=='}') {
        return true;
    }else {
        return false;
    }
}
bool isValid(const char* sequence) {
    for (int i=0;sequence[i]!='\0';i++) {
        char c= sequence[i];
        if(c=='('||c=='['||c=='{') {
            push(c);
        }else if (c==')'||c==']'||c=='}') {
            if(isEmpty()) {
                return false;
            }
            if(checkSequence(top->symbol,c)) {
                pop();
            }else {
                return false;
            }
        }

    }
    return isEmpty();
}

int main() {
    char sequence[100];
    printf("enter sequence");
    scanf("%s",sequence);


    if(isValid(sequence)) {
        printf("%d",1);
    }else {
        printf("%d",0);

    }
    return 0;
}