#ifndef L_CHAR_STACK
#define L_CHAR_STACK

typedef char ListItemType;

class L_Char_Stack
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
		L_Char_Stack();
		~L_Char_Stack();
		bool isEmpty() const;
		int get_size() const;
		bool push(const ListItemType& newItem);
		char pop();
    bool clear();

};  // end L_Char_Stack

#endif
