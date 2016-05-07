#ifndef _SNODE_H_
#define _SNODE_H_

struct SNode
{
	int value;
	int index;
	int previous;
	SNode()
	{
		this->index = -1;
		this->value = 0;
		this->previous = -1;
	}
	SNode(const int& index, const int& previous, const int& value)
	{
		this->index = index;
		this->previous = previous;
		this->value = value;
	}
	bool operator()(const SNode& node1, const SNode& node2)
	{
		return node1.value > node2.value;
	}
};

#endif