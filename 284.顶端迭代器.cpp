#include<iostream>
#include<vector>
using namespace std;

/*
请你在设计一个迭代器，在集成现有迭代器拥有的 hasNext 和 next 操作的基础上，还额外支持 peek 操作。

实现 PeekingIterator 类：
	PeekingIterator(Iterator<int> nums) 使用指定整数迭代器 nums 初始化迭代器。
	int next() 返回数组中的下一个元素，并将指针移动到下个元素处。
	bool hasNext() 如果数组中存在下一个元素，返回 true ；否则，返回 false 。
	int peek() 返回数组中的下一个元素，但 不 移动指针。
	注意：每种语言可能有不同的构造函数和迭代器 Iterator，但均支持 int next() 和 boolean hasNext() 函数。
	
*/

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		flag = Iterator::hasNext();
		if (flag) {
			nextElement = Iterator::next();
		}
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		return nextElement;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		int ret = nextElement;
		flag = Iterator::hasNext();
		if (flag) {
			nextElement = Iterator::next();
		}
		return ret;
	}

	bool hasNext() const {
		return flag;
	}

private:
	int nextElement;
	bool flag;
};
