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

List::List()
{
	head = new(Node);
	(*head).next = NULL;
}/*---------------------------------------------------------------*/

List::List(const List& list2)
{
	Clean();
	head = new(Node);


}
void List::Clean()
{
	Node *p, *q;// Рабочие указатели
	p = head;
	q = p->next; // Указатель q "опережает" указатель q.
	while (q != NULL)
	{
		p = q;
		q = q->next;
		delete p;
	}
}/*--------------------------------------------------------------*/

List& List::operator=(const List& list2)
{
	Clean();
	Node* cur=head;
	
	//while(cur->next)
		

}/*--------------------------------------------------------------*/

void List::InsertToHead(const DataType& d)
{
	Node* node = new Node(d);
	node->next = head;//новый узел привязываем к старому головному
	head = node;//новый становится головным
}/*--------------------------------------------------------------*/

void List::InsertToTail(const DataType& d)
{

}/*--------------------------------------------------------------*/

void List::InsertAfter(Node* node, const DataType& d)
{
	Node* node1 = new Node(d);
	node1->next = node->next;
	node = node1;
}/*---------------------------------------------------------------*/

void List::Delete(const DataType& d)
{

}/*--------------------------------------------------------------*/

Node* List::Search(const DataType& d)
{
	Node* cur = head;
	do
	{
		if (cur->data == d)
			return cur;
		cur = cur->next;
	} 
	while (cur->next);
	return nullptr;//???
}/*---------------------------------------------------------------*/

 int List::GetSize()
{
	 int s;
	 for (Node* n = head; n != NULL; n = n->next)
		 s++;
	 return s;
}/*--------------------------------------------------------------*/

void List::Inverse()
{
	if (head)
	{
		Node* temp = head->next;
		head->next = NULL;
		Node* cur = head;
		Node* p;
		while (cur->next)
		{
			p = temp->next;
			temp->next = cur;
			cur = temp;
			temp = p;
		}
	}
	
}/*--------------------------------------------------------------*/

 List List::Merge(Node* node, const List& list2)
{

}/*--------------------------------------------------------------*/

List List::Merge(const List& list2)
{

}/*--------------------------------------------------------------*/

bool List::operator==(const List& list2) const
{

}/*--------------------------------------------------------------*/