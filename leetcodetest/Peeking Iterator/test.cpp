#include"../leetcodetest/head.h"

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

//不清楚具体意义,留待后续解决
class PeekingIterator : public Iterator 
{
private:
	int cache;
	bool sign;

public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums), sign(false)
	{
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() 
	{
		if (sign)
		{
			return cache;
		}
		else
		{
			sign = true;
			return cache = Iterator::next();
		}
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() 
	{
		if (sign)
		{
			sign = false;
			return cache;
		}
		else
		{
			return Iterator::next();
		}
	}

	bool hasNext() const 
	{
		if (sign)
			return true;
		else 
			return Iterator::hasNext();
	}
};