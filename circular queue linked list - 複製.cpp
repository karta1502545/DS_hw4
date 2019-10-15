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

            backnode = frontnode;
            frontnode = headnode;
        }
        
        int pop(){
            if(size == 0){ // should judge if the queue is empty before calling the function, instead of there.
                cout << "Empty." << endl;
                return -100;
            }

            if(size == 1){
                size--;
                int temp_val = frontnode->value;
                
                Node *temp_node = frontnode;
                frontnode = nullptr;
                backnode = nullptr;

                delete temp_node;
                return temp_val;
            }
            else{
                size--;
                int temp_val = frontnode->value;
                
                Node *temp_node = frontnode;
                frontnode->prev->next = frontnode->next;
                frontnode->next->prev = frontnode->prev;
                frontnode = frontnode->next;

                delete temp_node;
                return temp_val;
            }
        }
        void push(int input){
            if(size >= max_size){
                cout << "THE QUEUE IS FULL!" << endl;
                return;
            }
            
            size++;

            if(frontnode == nullptr){
                frontnode = new Node(input);
                frontnode->next = frontnode;
                frontnode->prev = frontnode;
                backnode = frontnode;
            }
            else{
                Node *input_node = new Node(input);
                input_node->prev = backnode;
                backnode->next = input_node;
                backnode->next->prev = input_node;
                input_node->next = backnode->next;

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
    c_queue q(3);
    q.push(1);
    cout << q.back() << endl;
    q.push(2);
    cout << q.back() << endl;
    q.push(3);
    cout << q.back() << endl;
    q.push(4);
    cout << q.back() << endl;

    for(int i=0; i<5; i++){
        if(q.size != 0)
           cout << q.pop() << endl;
    }

    return 0;
}