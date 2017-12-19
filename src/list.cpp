#include "list.h"
Node::Node(DataType d, Node* n )
{
	data = d;
	next=n;
}/*---------------------------------------------------------------*/

Node::Node(const Node& node2)
{
	data = node2.data;
	next = node2.next;
}/*---------------------------------------------------------------*/

bool Node::operator==(const Node& node2) const
{
	bool res=false;
	if ((data == node2.data) && (next == node2.next))
		res = true;
	return res;
}/*---------------------------------------------------------------*/


List::List(const List& list2)
{
	if (list2.head == NULL)
	{
		head = list2.head;
	}
	else
	{
		head = new Node(list2.head->data, list2.head);
		Node *node1 = head;
		Node *node2 = list2.head->next;
		while (node2 != NULL)
		{
			node1->next = new Node(node2->data, node2->next);
			node1 = node1->next;
			node2 = node2->next;
		}
	}


}
void List::Clean()
{
	Node *p, *q;// Рабочие указатели
	p = head;
	if(head)
	{ 
	
	while (p)
	{
		q = p->next; // Указатель q "опережает" указатель q.
		delete p;
		p=q;
		
	}
	head = NULL;
	}
}/*--------------------------------------------------------------*/

List& List::operator=(const List& list2)
{
	if (this != &list2)
	{
		Clean();
		if (list2.head == NULL)
		{
			head = list2.head;
			return *this;
		}
		else
		{
			head = new Node(list2.head->data, list2.head);
			Node *tmp = head;
			Node *tmp2 = list2.head->next;
			while (tmp2 != NULL)
			{
				tmp->next = new Node(tmp2->data, tmp2->next);
				tmp = tmp->next;
				tmp2 = tmp2->next;
			}
			return *this;
		}
	}

}/*--------------------------------------------------------------*/

void List::InsertToHead(const DataType& d)
{
	Node* node = new Node(d);
	node->next = head;//новый узел привязываем к старому головному
	head = node;//новый становится головным
}/*--------------------------------------------------------------*/

void List::InsertToTail(const DataType& d)
{
	Node* temp = head;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new Node(d);
	}
	else
		head = new Node(d);
}/*--------------------------------------------------------------*/

void List::InsertAfter(Node* node, const DataType& d)
{
	if (node && head)
	{
		Node* temp = node->next;
		node->next = new Node(d, temp);
	}
	else

	if (head == NULL)
			throw 0;
}/*---------------------------------------------------------------*/

void List::Delete(const DataType& d)
{
	Node* temp = head;
	Node* cur;
	if (head)
	{
		if (head->data == d)
		{
			cur = temp->next;
			delete head;
			head = cur;
		}
		else
		{
			while (temp->next)
			{
				if (temp->next->data == d)
				{
					 cur = temp->next;
					break;
				}
				temp = temp->next;
			}
			if (temp->next)
			{
				temp->next = cur->next;
				delete cur;
			}
		}
	}

}/*--------------------------------------------------------------*/

Node* List::Search(const DataType& d)
{
	Node* cur = head;
	while (cur)
	{
		if (cur->data == d)
			return cur;
		cur = cur->next;
	} 
	return NULL;
}/*---------------------------------------------------------------*/

int List::GetSize()
{
	int s = 0;
	Node* n = head;

	while (n != NULL)
	{
		s++;
		n = n->next;
	}

	return s;
}
/*--------------------------------------------------------------*/

void List::Inverse()
{
	if (head)
	{
		Node* temp = head->next;
		head->next = NULL;
		Node* cur = head;
		Node* p;
		while (temp)
		{
			p = temp->next;
			temp->next = cur;
			cur = temp;
			temp = p;
		}
		head = cur;
	}
	
}/*--------------------------------------------------------------*/

 List List::Merge(Node* node, const List& list2)
{
	 List res;
	 Node* temp = head;
	 if (head)
	 {
		 res.head = new Node(head->data);
		 Node* temp1 = res.head;
		 while (temp->next && temp != node)
		 {
			 temp1->next = new Node(temp->next->data);
			 temp = temp->next;
			 temp1 = temp1->next;
		 }
		 if (temp == node)
		 {
			 if (list2.head)
			 {
				 Node* temp2 = list2.head;
				 while (temp2)
				 {
					 temp1->next = new Node(temp2->data);
					 temp2 = temp2->next;
					 temp1 = temp1->next;
				 }
			 }
			 while (temp->next)
			 {
				 temp1->next = new Node(temp->next->data);
				 temp = temp->next;
				 temp1 = temp1->next;
			 }
		 }
		 temp1->next = NULL;
	 }

	 return res;
}/*--------------------------------------------------------------*/

List List::Merge(const List& list2)
{
	List res(*this);
	if (res.head && list2.head)
	{
		Node* temp = res.head;
		while (temp->next)
			temp = temp->next;


		Node* temp1 = list2.head;
		while (temp1)
		{
			temp->next = new Node(temp1->data, temp1->next);
			temp = temp->next;
			temp1 = temp1->next;
		}
		temp->next = NULL;
	}
	else
		if (res.head == NULL)
			res = List(list2);
	return res;

}/*--------------------------------------------------------------*/

bool List::operator==(const List& list2) const
{
	bool res = true;
	Node* temp = head;
	Node* temp1 = list2.head;
	while (temp && temp1 && res)
	{
		if (temp->data != temp1->data)
			res = false;
		else
		{
			temp = temp->next;
			temp1 = temp1->next;
		}

	}
	if (temp || temp1)
		res = false;
	return res;
}/*--------------------------------------------------------------*/

ostream & operator<<(ostream & os, const List & l)
{
	Node* temp = l.head;
	while (temp)
	{
		os << temp->data << " ";
		temp = temp->next;
	}
	return os;
}/*--------------------------------------------------------------*/