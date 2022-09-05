#include <iostream>


struct Node
{
	int data;
	struct Node* next;

	Node(int x)
	{
		data = x;
		next = NULL;
	}
};


Node* reverseBetween(Node* head, int m, int n)
{
	Node* temp = head;
	int counter = 1;

	while (counter != m)
	{
		temp = temp->next;
		counter++;
	}


	Node* next=NULL, * current, * prev;
	current = temp;
	prev = NULL;
	while (current != NULL && counter <=n)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		counter++;
	
	}

	temp = prev;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	counter = 1;
	Node* headcheck = head;
	if (m != 1)
	{
		while (headcheck->next->next != NULL)
		{
			headcheck = headcheck->next;
		}

		headcheck->next = prev;
		temp->next = next;
		return head;

	}

	temp->next = next;
	
	head = prev;


	return head;
}

void printLL(Node* head)
{
	while (head != NULL)
	{
		std::cout << head->data << "->";
		head = head->next;
	}
	std::cout << "NULL"<<std::endl;
}

int main(void)
{
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = new Node(6);
	/*head->next->next->next->next->next->next = new Node(10);
	head->next->next->next->next->next->next->next = new Node(2);
	head->next->next->next->next->next->next->next->next = new Node(2);
	head->next->next->next->next->next->next->next->next->next= new Node(5);*/

	head = reverseBetween(head, 2,4);

	printLL(head);
	return 0;
}