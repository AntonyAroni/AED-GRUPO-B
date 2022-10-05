#include <iostream>
#include <cstring>
using namespace std;
struct Node{
	string op;
	Node *next;
};

struct Stack{
	Node *top=nullptr;
	void push(string op){
		for(int i=op.length()-1;i>=0;i--){
			Node*newNode = new Node();
			newNode->op=op[i];
			newNode->next=top;
			top=newNode;
		}
		
		
	}
		string pop(){
			Node *x=this->top;
			string temp=x->op;
			top=x->next;
			free(x);
			return temp;
		}
			
			void mostrar(){
				Node *x=this->top;
				while(x!=nullptr){
					cout<<x->op<<" ";
					x=x->next;
				}
			}
};
auto posfix(Stack datos){
	Node *x=this->top;
	Stack stack;
	Stack profix;
		while(x!=nullptr){
			if(x->op>=A && x->op<=Z){
				profix.push(x->op);
			}
		}
	return profix;
}

int main(){
	Stack x;
	string op;
	cout<<"valor: "<<endl; //A+(B*C)
	cin>>op;
	x.push(op);
	x.mostrar();
	cout<<endl<<"valor pop: "<<x.pop()<<endl;
	x.mostrar();
}
	
	
