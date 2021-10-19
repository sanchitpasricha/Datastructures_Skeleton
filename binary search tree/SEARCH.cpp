#include <iostream>

using namespace std;
 
class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
};
 
class Queue{
private:
    int size;
    int front;
    int rear;
    Node** Q; 
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(Node* x);
    Node* dequeue();
};
 
Queue::Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node* [size];
}
 
Queue::~Queue() {
    delete [] Q;
}
 
bool Queue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}
 
bool Queue::isFull() {
    if (rear == size-1){
        return true;
    }
    return false;
}
 
void Queue::enqueue(Node* x) {
    if (isFull()){
        cout << "Queue Overflow" << endl;
    } else {
        rear++;
        Q[rear] = x;
    }
}
 
Node* Queue::dequeue() {
    Node* x = NULL;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        front++;
        x = Q[front];
    }
    return x;
}
 
Node* root = new Node;
 
void createTree(){
    Node* p;
    Node* t;
    int x;
    Queue q(10);
 
    cout << "Enter root value: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    q.enqueue(root);
 
    while (! q.isEmpty()){
        p = q.dequeue();
 
        cout << "Enter left child value of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
 
        cout << "Enter right child value of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}
 
Node* search(Node* t,int key){
	while(t != NULL){
		if(key==t->data){
			return t;
		}
		else if(key < t->data){
			t=t->lchild;
		}
		else{
			t=t->rchild;
		}
	}
	return NULL;
} 

Node* Rsearch(Node* t,int key){
	if(t=NULL){
		return NULL;
	}
	if(key==t->data){
		return t;
	}
	else if(key < t->data){
		Rsearch(t->lchild,20);
	}
	else{
		Rsearch(t->rchild,20);
	}
} 

 
int main() {
 
    createTree();
    cout<<search(root,15);
    cout<<Rsearch(root,20);
    return 0;
}