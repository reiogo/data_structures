#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int value;
    struct Node*  next;
    
}Node;

Node* head;

void insertList(int data) {

    Node* currentNode = (Node*)malloc(sizeof(Node));
    currentNode->value = data;
    currentNode->next = head;
    head = currentNode;

};

void printList() {

    Node* currentNode = head;
    printf("List is: ");
    while(currentNode != NULL) {
       
       printf(" %d", currentNode->value);
       currentNode = currentNode->next;
    }
    printf("\n");

};

void findLargest() {

    int largest = 0;
    Node* currentNode = head;
    while(currentNode != NULL) {

        if (currentNode->value > largest) {
            largest = currentNode->value;
        }
       currentNode = currentNode->next;

    }
    printf("The largest is: %d", largest);

}

void findTwoLargest() {

    Node* currentNode = head; // node 0
                              
    int secondLargest = currentNode->value;
    int largest = 0;

    currentNode = currentNode->next; // node 1
                                     
    if (currentNode->value > secondLargest) {

        largest = currentNode->value;    

    } else {

        largest = secondLargest;
        secondLargest = currentNode->value;

    }

    currentNode = currentNode->next; //node 2

    // Start loop at node 3
    while(currentNode != NULL) {

        if (currentNode->value > largest) {

            secondLargest = largest;
            largest = currentNode->value;

        } else if( currentNode->value > secondLargest && currentNode->value != largest) {

            secondLargest = currentNode->value;

        }
        currentNode = currentNode->next;

    }
    printf("\nThe largest is: %d. The second largest is: %d", largest, secondLargest);

}

int main() {

    head = NULL;

    insertList(2);
    insertList(5);
    insertList(33);
    insertList(2);
    insertList(108);
    insertList(59);
    insertList(22);
    insertList(40000);
    insertList(200);

    printList();
    findLargest();
    findTwoLargest();

}

