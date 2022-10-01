#include<iostream>
using namespace std;

struct Node{
	int coef;
	int grado;
	Node *next;
};
struct polinomio{
	Node *head=nullptr;
	
	void insert(int coef, int grado){
		Node*new_node = new Node();
		new_node->coef=coef;
		new_node->grado=grado;

		
		new_node->next=head;
		head=new_node;
	}
		
	void print(){
		Node *x=this->head;
		Node *y=this->head;
		Node *z=this->head;
		
		do{
			cout<<x->coef<<"x"<<x->grado<<" -> ";
			x=x->next;
		}while(x->next!=nullptr);
		
		cout<<endl<<endl;
		
		while(y!=nullptr){
			cout<<y->coef<<"x"<<y->grado<<" -> ";
			y=y->next;
		}
	}
};

int main(){
	polinomio pol;
	pol.insert(3,4);
	pol.insert(5,6);
	pol.insert(6,16);
	pol.insert(20,30);
	pol.insert(50,40);
	pol.insert(60,70);
	pol.print();
	return 0;
}
