#include <iostream>

int main();

class Node {
    public:

    Node(int num);
    ~Node();

    void set_next(Node * next_node);

    Node * get_next();

    private:

    int key;

    Node * p_next;
    
};

Node::Node(int num){
    key = num;
    p_next = nullptr;
}

Node::~Node(){

}

void Node::set_next(Node * next_node){
    p_next = next_node;
}

Node * Node::get_next(){

    return p_next;
}


class Linked_list{
    public:
    Linked_list();
    ~Linked_list();

    void insert (Node * my_node);

    //return the seciond half of the linke list
    Node * half();

    private:
    Node * p_head;

};

Linked_list::Linked_list(){
    p_head = nullptr;
}

Linked_list::~Linked_list(){

    if(p_head == nullptr){
        return;
    }

    while (p_head->get_next() != nullptr){
        Node * p_next = p_head->get_next();
        p_head->set_next(nullptr);
        delete p_head;
        p_head = p_next;        
    }
    delete p_head;
    p_head = nullptr;
}

void Linked_list::insert (Node * my_node){
    Node * p_through = p_head;
    while (p_through->get_next() != nullptr){
        p_through = p_through->get_next();
    }
    p_through->set_next(my_node);
    p_through == nullptr;
}

Node * Linked_list::half(){
    Node * p_through = this->p_head;
    Node * second_half = this->p_head;
    Node * prev_second_half = nullptr;
    while(p_through != nullptr || p_through->get_next() != nullptr){
        p_through = p_through->get_next()->get_next();
        prev_second_half = second_half;
        second_half = second_half->get_next();
    }
    prev_second_half->set_next(nullptr);
    return second_half;
}


int main(){

    
    return 0;
}
