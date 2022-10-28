
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

template<class T>
struct Node
{
    T m_data;
    Node *m_right;
    Node *m_left;

    explicit Node(T data):m_data(data), m_right(nullptr), m_left(nullptr){}

    friend std::ostream &operator<<(std::ostream &os, Node<T> const &n) {
        return os << n.m_data;
    }

    void dot(ostream &file){
        file<<"node_"<<m_data<<" [label = \"<l> | <m> "<< m_data <<" | <r>\"];\n";
        if(m_left){
            file<<"node_"<<m_data<<":l -> node_"<<m_left->m_data<<":m;\n";
        }
        if(m_right){
            file<<"node_"<<m_data<<":r -> node_"<<m_right->m_data<<":m;\n";
        }
    }
};


template<class T>
struct BTS
{
    Node<T> *m_root;
    BTS():m_root(nullptr){}

    Node<T> * damInsert(Node<T>* current, T data, bool left=false){
        if(current==nullptr) return new Node<T>(data);
        if(left){
            current->m_left = damInsert(current->m_left, data, left);
        }else{
            current->m_right = damInsert(current->m_right, data, left);
        }
        return current;
    }

    void damInsert(T data, bool left = false){
        m_root = damInsert(m_root, data, left);
    }

    // Plotting a Tree
    void dot(const string& filename){
        ofstream mydot;
        mydot.open(filename, ios::out);

        mydot << "digraph g {\n";
        mydot << "node [shape=record, height=0.1];\n";
        dot(mydot, m_root);
        mydot << "}";
        mydot.close();
    }

    void dot(ofstream &file, Node<T>* current){
        if (current==nullptr)
        {
            return;
        }else{
            current->dot(file);
            dot(file, current->m_left);
            dot(file, current->m_right);
        }
    }


    Node<T>* insert(Node<T>* current, T data){
        if(current==nullptr) return new Node<T>(data);
        else{
            if(data < current->m_data){
                current->m_left = insert(current->m_left, data);
            }else if(data > current->m_data){
                current->m_right = insert(current->m_right, data);
            }
        }
        return current;
    }

    void insert(T data){
        m_root = insert(m_root, data);
    }

    Node<T>* find(Node<T>* current, T key){
        if(current==nullptr || current->m_data == key) return current;
        else if(key < current->m_data){
            return find(current->m_left, key);
        }
        return find(current->m_right, key);
    }

    Node<T>* find(T key){
        return find(m_root, key);
    }


    void inOrder(){
        cout<<"inOrder: ";
        if (m_root == nullptr){
            cout<<"NULL";
            return;
        }
        stack<Node<T> *> node;
        Node<T> *current = m_root;
        while (current != nullptr || node.empty() == false){
            while (current != nullptr){
                node.push(current);
                current = current->m_left;
            }
            current = node.top();
            node.pop();
            cout  << " -> "<< current->m_data;
            current = current->m_right;

        }
        cout<<endl;
    }

    void preOrder(){
        cout<<"preOrder: ";
        if (m_root == nullptr){
            cout<<"NULL";
            return;
        }
        stack<Node<T> *> stack_nodes;
        stack_nodes.push(m_root);

        while (stack_nodes.empty() == false){
            struct Node<T> *node = stack_nodes.top();
            cout<<" -> "<<node->m_data;
            stack_nodes.pop();
            if (node->m_right) stack_nodes.push(node->m_right);
            if (node->m_left) stack_nodes.push(node->m_left);
        }
        cout<<endl;
    }

    void PostOrder(){
        cout<<"postOrder: ";
        if (m_root == nullptr){
            cout<<"NULL";
            return;
        }
        stack <Node<T> *> stack_nodes_1,stack_nodes_2;
        Node<T> * node = m_root;
        stack_nodes_1.push(node);

        while (!stack_nodes_1.empty()){
            node = stack_nodes_1.top();
            stack_nodes_1.pop();
            stack_nodes_2.push(node);
            if (node->m_left != nullptr)
                stack_nodes_1.push(node->m_left);
            if (node->m_right != nullptr)
                stack_nodes_1.push(node->m_right);
        }

        while(!stack_nodes_2.empty()) {
            cout <<" -> "<< stack_nodes_2.top()->m_data ;
            stack_nodes_2.pop();
        }
        cout<<endl;
    }
    void LevelTraverse(){
        cout<<"LevelTraverse: ";
        if (m_root == nullptr){
            cout<<"NULL";
            return;
        }
        queue<Node<T>*> nodes;
        nodes.push(m_root);

        while (nodes.empty() == false) {
            Node<T>* node = nodes.front();
            cout << " -> "<< node->m_data ;
            nodes.pop();

            if (node->m_left != nullptr)
                nodes.push(node->m_left);
            if (node->m_right != nullptr)
                nodes.push(node->m_right);
        }
        cout<<endl;
    }
    auto minkey(Node<T>* node){
        Node<T>* current =node;
        while(current && current->m_left!= nullptr)
            current=current->m_left;
        return current;
    }

    Node<T>* deleteNode(Node<T>* current, int key){
        if(current == nullptr)
            return current;
        if(key<current->m_data)
            current->m_left = deleteNode(current->m_left,key);
        else if(key>current->m_data)
            current->m_right= deleteNode(current->m_right, key);
        else{
            if(current->m_left== nullptr && current->m_right== nullptr)
                return nullptr;
            else if(current->m_left== nullptr){
                Node<T>* temp = current->m_right;
                free(current);
                return temp;
            }
            else if(current->m_right== nullptr){
                Node<T>* temp = current->m_left;
                free(current);
                return temp;
            }
            Node<T>* temp = minkey(current->m_right);
            current->m_data=temp->m_data;
            current->m_right= deleteNode(current->m_right, temp->m_data);
        }
        return current;
    }
    void deleteNode(T key){
        m_root = deleteNode(m_root, key);
    }
};


int main() {

    BTS<int> t1 = BTS<int>();

    t1.insert(8);
    t1.insert(1);
    t1.insert(5);
    t1.insert(3);
    t1.insert(7);
    t1.insert(20);
    t1.dot("tree.dot");
    //cuatro ordenamientos.
    t1.inOrder();
    t1.preOrder();
    t1.PostOrder();
    t1.LevelTraverse();
    //eliminación;
    t1.deleteNode(5);
    t1.dot("tree.dot");

    return 0;
}