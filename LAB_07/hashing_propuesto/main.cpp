
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Node
{
    string name;
    Node * next{};
};

void readFile(Node * hashTable[], int numBuckets);
void savefile(Node * hashTable[], int numBuckets);
void insert(Node * hashTable[], int numBuckets, const string& name);
void insert_sondeo_lineal(Node * hashTable[], int numBuckets, const string& name);
void display(Node * hashTable[], int numBuckets);
void search(Node * hashTable[], int numBuckets, const string& name);
void remove(Node * hashTable[], int numBuckets, const string& name);
int hashFunction(const string& name, int numBuckets);

int main()
{
    const int numBuckets = 5;
    Node * hashTable[numBuckets];

    for(auto & i : hashTable)
    {
        i = nullptr;
    }
    readFile(hashTable, numBuckets);
    insert(hashTable, numBuckets, "ana");
    insert(hashTable, numBuckets, "juan");
    insert(hashTable, numBuckets, "pedro");
    insert(hashTable, numBuckets, "raul");
    insert(hashTable, numBuckets, "zara");
    insert(hashTable, numBuckets, "roberto");
    insert(hashTable, numBuckets, "carlos");
    savefile(hashTable, numBuckets);
    display(hashTable, numBuckets);


    return 0;
}

void readFile(Node * hashTable[], int numBuckets){
    ifstream fin;
    fin.open("nombres.txt");
    if(fin.fail()){
        cout << "error al abrir el archivo" << endl;
        exit(1);
    }

    string name;
    while(fin >> name){
        insert(hashTable, numBuckets, name);
    }

    fin.close();
}
void savefile(Node * hashTable[], int numBuckets){
    ofstream fout;
    fout.open("nombres.txt");
    if(fout.fail()){
        cout << "Error opening file" << endl;
        exit(1);
    }

    for(int i = 0; i < numBuckets; i++){
        Node * temp = hashTable[i];
        while(temp != nullptr){
            fout << temp->name << endl;
            temp = temp->next;
        }
    }

    fout.close();
}
void insert(Node * hashTable[], int numBuckets, const string& name) {
    int index = hashFunction(name, numBuckets);

    Node *newNode = new Node;
    newNode->name = name;
    newNode->next = nullptr;

    if (hashTable[index] == nullptr) {
        hashTable[index] = newNode;
    } else {
        Node *temp = hashTable[index];
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void insert_sondeo_lineal(Node * hashTable[], int numBuckets, const string& name){
    int index = hashFunction(name, numBuckets);
    int i = 0;
    while(hashTable[index] != nullptr){
        index = (index + 1) % numBuckets;
        i++;
    }

    Node *newNode = new Node;
    newNode->name = name;
    newNode->next = nullptr;
    hashTable[index] = newNode;
}
void display(Node * hashTable[], int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        cout << i << ": ";
        Node *temp = hashTable[i];
        while (temp != nullptr) {
            cout << temp->name << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
void search(Node * hashTable[], int numBuckets, const string& name){
    int index = hashFunction(name, numBuckets);

    Node * temp = hashTable[index];
    while(temp != nullptr){
        if(temp->name == name){
            cout << name << " si se encuentra en la tabla" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << name << " no se encuentra en la tabla" << endl;
}
void remove(Node * hashTable[], int numBuckets, const string& name){
    int index = hashFunction(name, numBuckets);

    Node * temp = hashTable[index];
    Node * prev = nullptr;
    while(temp != nullptr){
        if(temp->name == name){
            if(prev == nullptr){
                hashTable[index] = temp->next;
            }
            else{
                prev->next = temp->next;
            }
            delete temp;
            cout << name << " fue removido" << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << name << " no se encuentra en la tabla" << endl;
}
int hashFunction(const string& name, int numBuckets){
    int sum = 0;
    for(char i : name){
        sum += i;
    }
    return sum % numBuckets;
}


