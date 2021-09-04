#include<iostream>

using namespace std;

struct Node
{
	int data;
        Node *next;
	Node(int value) : data(value), next(nullptr) {}
};


class MyLinkedList 
{
public:
	int size;
   	Node *head;

    	MyLinkedList() 
    	{
		size = 0;
		head = nullptr;
    	}
    
    	int get(int index) 
	{
		if(index < 0 || index >= size)
			return -1;

		Node *node = head;

		while(index--)
			node = node->next;

		return node->data;
    	}
    
    	void addAtHead(int val) 
    	{	
		Node *newNode = new Node(val);

        	if(head == nullptr)
		{
			head = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
		size++;
    	}
    
    	void addAtTail(int val) 
    	{
        	if(head == nullptr)
        	{
                	head = new Node(val);
			size++;
			return;
        	}

		Node *node = head;
		
                while(node -> next != nullptr)
                {
                	node = node->next;

                }

		node->next = new Node(val);
		size++;
    	}
    
    	void addAtIndex(int index, int val) 
    	{
		if(index > size)
                        return;

		if(!index)
		{
			addAtHead(val);
		}
		else if(index == size)
		{
			addAtTail(val);
		}
		else
		{
			Node *newNode = new Node(val);
			Node *node = head;
		
			while(--index)
	        		node = node->next;
			
			newNode->next = node->next;
			node->next = newNode;	
			size++;
		}

    	}
    
    	void deleteAtIndex(int index) 
	{
		if(index < 0 || index >= size)
			return;

		if(!index)
		{
			head = head->next;
		}
		else
		{
			Node *node = head;

			while(--index)
				node = node->next;

			node->next = node->next->next;
		}
		size--;
    	}

	Node *getHead() const
	{
		return head;
	}

};

ostream &operator<<(ostream &out, const MyLinkedList &myLinkedList)
{
	Node *node = myLinkedList.getHead();

	while(node != nullptr)
	{
		out << node->data << " " ; 
		node = node->next;
	}
	return out;
}

int main(void)
{
	MyLinkedList* obj = new MyLinkedList();

	obj->addAtHead(0);	
	obj->addAtTail(1);
	obj->addAtTail(2);
	obj->addAtTail(3);
	obj->addAtTail(4);
	obj->addAtTail(5);

	cout << *obj << endl;

	obj->deleteAtIndex(3);

	cout << *obj << endl;

	obj->addAtIndex(3, 42);

	cout << *obj << endl;

	cout << "Value at index 3 is " << obj->get(3) << endl;
}
