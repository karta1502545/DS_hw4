#include <iostream>
using namespace std;

class Node{
    public:
        int value;
        Node *next;
        Node *prev;
    
        Node(int data): value(data), next(nullptr), prev(nullptr){};
};

// push, pop, back, front
// size = 0 or size = 1 : frontnode == backnode
// size = max_size : frontnode->prev == backnode
class c_queue{
    public:
        Node *frontnode;
        Node *backnode;
        int size;
        int max_size;
        
        c_queue(int m_size): size(0), max_size(m_size)
        {
            frontnode = new Node(0);
            Node *headnode = frontnode;
            for(int i=0; i<max_size-1; i++){
                Node *temp = new Node(0);
                frontnode->next = temp;
                temp->prev = frontnode;
                frontnode = temp;
            }
            frontnode->next = headnode;
            headnode->prev = frontnode;

            backnode = headnode;
            frontnode = headnode;
        }
        
        int pop(){
            if(size == 0){ // should judge if the queue is empty before calling the function, instead of there.
                cout << "Empty." << endl;
                return -100;
            }

            if(size == 1){
                size--;
                return frontnode->value;
            }
            else{
                size--;
                int temp_val = frontnode->value;
                frontnode = frontnode->next;
                return temp_val;
            }
        }
        void push(int input){
            if(size >= max_size){
                cout << "THE QUEUE IS FULL!" << endl;
                return;
            }
            
            size++;
            if(size == 1){
                backnode->value = input;
            }
            else{
                backnode->next->value = input;
                backnode = backnode->next;
            }
        }
        int front(){
            return frontnode->value;
        }
        int back(){
            return backnode->value;
        }
};


int main()
{
    c_queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.push(4);

    for(int i=0; i<5; i++){
        if(q.size != 0)
           cout << q.pop() << endl;
    }
    
    cout << endl << endl;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    for(int i=0; i<5; i++){
        if(q.size != 0)
           cout << q.pop() << endl;
    }
    return 0;
}