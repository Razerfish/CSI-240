/*
Author: Fiona Wilson
Class: CSI-240-03
Assignment: Final Project
Date Assigned: April 5 2021
Due Date: April 29 2021
Description: Create a management system for the Champlain bookstore.
Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully documented references to the work of others. I understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of
academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service
(which may then retain a copy of this assignment on its database for
the purpose of future plagiarism checking)
*/

#include "linkedList.h"

// Again, adapted from the linked list skeleton code on canvas.

/*********************************************************
*						Constructors					 *
*********************************************************/

/*	Function: LinkedList::Node::Node();
*	Pre: None
*	Post: mNext is initialized to nullptr.
*	Purpose: Initialize mNext to nullptr to indicate that it
*	doesn't point anywhere.
*	Author: Fiona Wilson
*	Citation: Wei Kian Chen, https://champlain.instructure.com/courses/1623244/files/184733441
*********************************************************/
LinkedList::Node::Node()
{
	mNext = nullptr;
	mData = 0.0;
}


/*	Function: LinkedList::Node::Node(double data);
*	Pre: A double to initialize mData to.
*	Post: mNext is set to nullptr and mData is set to
*	the provided value.
*	Purpose: Initialize mNext and mData.
*	Author: Fiona Wilson
*	Citation: Wei Kian Chen, https://champlain.instructure.com/courses/1623244/files/184733441
*********************************************************/
LinkedList::Node::Node(double data)
{
	mNext = nullptr;
	mData = data;
}


/*	Function: LinkedList::LinkedList();
*	Pre: None
*	Post: mHead and mTail are set to nullptr and mCount
*	is set to 0.
*	Purpose: Initialize the LinkedList object.
*	Author: Fiona Wilson
*	Citation: Wei Kian Chen, https://champlain.instructure.com/courses/1623244/files/184733441
*********************************************************/
LinkedList::LinkedList()
{
	mHead = nullptr;
	mTail = nullptr;
	mCount = 0;
}


/*********************************************************
*						Destructor						 *
*********************************************************/

/*	Function: LinkedList::~LinkedList();
*	Pre: None
*	Post: All elements will be deleted.
*	Purpose: Clean up and prevent memory leaks.
*	Author: Fiona Wilson
*	Citation: Wei Kian Chen, https://champlain.instructure.com/courses/1623244/files/184733441
*********************************************************/
LinkedList::~LinkedList()
{
	clear();
}


/*********************************************************
*						Accessors						 *
*********************************************************/

/*	Function: int LinkedList::getCount();
*	Pre: None
*	Post: Returns the amount of elements in the object.
*	Purpose: Get the length of the LinkedList object.
*	Author: Fiona Wilson
*	Citation: Wei Kian Chen, https://champlain.instructure.com/courses/1623244/files/184733441
*********************************************************/
int LinkedList::getCount()
{
	return mCount;
}


/*	Function: double LinkedList::getData(int index);
*	Pre: The index that the data to retrive is located at.
*	Post: If the given index exists the data at that location
*	is returned, otherwise an out_of_range exception is thrown.
*	Purpose: Get the data located at an index.
*	Author: Fiona Wilson
*	Citation: Wei Kian Chen, https://champlain.instructure.com/courses/1623244/files/184733441
*********************************************************/
double LinkedList::getData(int index)
{
	if (index < 0 || index >= mCount)
	{
		throw out_of_range("Index out of range!");
	}

	int i;
	Node* tmp;

	tmp = mHead;
	for (i = 0; i < index; i++)
	{
		tmp = tmp->mNext;
	}

	return tmp->mData;
}


/*********************************************************
*						Mutators						 *
*********************************************************/

/*	Funtion: void LinkedList::setData(int index, double data);
*	Pre: The index to modify and the data to use.
*	Post: If the given index exists it will have it's data set
*	to the provided value, otherwise an out_of_range error
*	will be thrown.
*	Purpose: Modify the data of an element in the list.
*	Author: Fiona Wilson
*	Citation: Wei Kian Chen, https://champlain.instructure.com/courses/1623244/files/184733441
*********************************************************/
void LinkedList::setData(int index, double data)
{
	if (index < 0 || index >= mCount)
	{
		throw out_of_range("Index out of range!");
	}

	int i;
	Node* tmp;

	tmp = mHead;
	for (i = 0; i < index; i++)
	{
		tmp = tmp->mNext;
	}

	tmp->mData = data;
}


/*********************************************************
*						Other							 *
*********************************************************/

/*	Function: bool LinkedList::append(double data);
*	Pre: The data to store in the appended element.
*	Post: An element containing the given data will
*	be appended to the end of the list. Returns true
*	if successful, otherwise returns false.
*	Purpose: Append an element to the end of the list.
*	Author: Fiona Wilson
*	Citation: Wei Kian Chen, https://champlain.instructure.com/courses/1623244/files/184733441
*********************************************************/
bool LinkedList::append(double data)
{
	Node* newNode = nullptr;

	newNode = new Node(data);
	if (newNode == nullptr)
	{
		return false;
	}

	if (mCount == 0)
	{
		mHead = newNode;
		mTail = newNode;
	}
	else
	{
		mTail->mNext = newNode;
		mTail = newNode;
	}

	mCount++;
	return true;
}


/*	Function: void LinkedList::clear();
*	Pre: None
*	Post: All elements in the list will be deleted.
*	Purpose: Delete all elements/nodes in the list.
*	Author: Fiona Wilson
*	Citation: Wei Kian Chen, https://champlain.instructure.com/courses/1623244/files/184733441
*********************************************************/
void LinkedList::clear()
{
	Node* tmp;

	tmp = mHead;
	while (mHead != nullptr)
	{
		mHead = mHead->mNext;
		tmp->mNext = nullptr;
		delete tmp;
		tmp = mHead;
	}

	mTail = nullptr;
	mCount = 0;
}


/*	Function: void LinkedList::remove(int index);
*	Pre: The index of the item to remove.
*	Post: If an item exists at the given index it will be
*	removed, otherwise an out_of_range error will be thrown.
*	If there are no nodes in the list a length_error will
*	be thrown.
*	Purpose: Remove a node from the list.
*	Author: Fiona Wilson
*	Citation: Wei Kian Chen, https://champlain.instructure.com/courses/1623244/files/184733441
*********************************************************/
void LinkedList::remove(int index)
{
	if (mHead == nullptr)
	{
		throw length_error("Cannot remove from empty list!");
	}

	if (index < 0 || index >= mCount)
	{
		throw out_of_range("Index out of range!");
	}

	Node* tmp;
	Node* target;
	Node* before;

	if (index == 0) // Removing from head
	{
		target = mHead;
		mHead = target->mNext;
		target->mNext = nullptr;

		delete target;
		mCount--;

		// If the list is now empty set mTail to NULL
		if (mCount == 0)
		{
			mTail = nullptr;
		}
	}
	else
	{
		tmp = mHead;
		before = nullptr;
		for (int i = 0; i < index; i++)
		{
			before = tmp;
			tmp = tmp->mNext;
		}

		target = tmp;
		if (target == mTail) // Removing tail
		{
			mTail = before;
			mTail->mNext = nullptr;
		}
		else // Deleting from middle
		{
			before->mNext = target->mNext;
			target->mNext = nullptr;
		}

		delete target;
		mCount--;
	}
}


/*********************************************************
*						Other							 *
*********************************************************/

/*	Function: double LinkedList::operator [](int index);
*	Pre: The index of the item to locate.
*	Post: If an item exists with the given index it will
*	be returned, otherwise an out_of_range error will be
*	thrown.
*	Purpose: Indices operator overload.
*	Author: Fiona Wilson
*	Citation: Wei Kian Chen, https://champlain.instructure.com/courses/1623244/files/184733441
*********************************************************/
double LinkedList::operator [](int index)
{
	return getData(index);
}
