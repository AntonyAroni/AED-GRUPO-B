//
// Created by olmer on 10/3/2022.
//

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};
void insert(Node** head, int new_data)
{
    auto* newNode = new Node;
    newNode->data = new_data;
    newNode->next = (*head);
    newNode->prev = nullptr;
    if ((*head) != nullptr)
        (*head)->prev = newNode;
    (*head) = newNode;
}
void delete_list(Node **head, int position){
    Node *temp, *temp2;
    temp=*head;
    int iterador=1;
    if (*head == nullptr){
        cout<<"Lista vacia!"<<endl;
        return;
    }
    if(position==1){
        *head=(*head)->next;
        if(*head!= nullptr){
            (*head)->prev= nullptr;
            free(temp);
            return;
        }
    }

    while((iterador<position)&&temp->next != nullptr){
        temp=temp->next;
        iterador++;
    }
    if(iterador!=position){
        cout<<"la posicion no existe!"<<endl;
        return;
    }
    temp2=temp->prev;
    temp2->next=temp->next;
    if(temp->next){
        temp->next->prev=temp2;
    }
    free(temp);
}
void printList(Node* node) {
    while (node != nullptr) {
        cout<<node->data<<" <--> ";
        node = node->next;
    }
    cout << "NULL"<<endl;

}
int main(){
    Node* head = nullptr;
    insert(&head, 20);
    insert(&head, 10);
    insert(&head, 30);
    insert(&head, 40);
    printList(head);
    delete_list(&head, 3);
    printList(head);
    return 0;
}