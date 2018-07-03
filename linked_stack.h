#ifndef LinkedList
#define LinkedList

typedef char ListItemType;

class Linked_List
{
	private:
		struct ListNode
		{
			ListItemType item;
			ListNode *next;
      ListNode *previous;
		};

		int size;
		ListNode *head;

	public:
		Linked_List();
		~Linked_List();
		bool isEmpty() const;
		int get_size() const;
		bool push(const ListItemType& newItem);
		char pop();
    bool clear();

};  // end Linked_List

#endif
