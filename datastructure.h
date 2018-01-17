
#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H
//
class Object{
	void toShow();
}

class LinkListNode{
	LinkListNode *next;
	Object *object;
}

class LinkList{
	public:
		LinkListNode *head;
		LinkListNode *tail;
		void add(Object);
		void del(Object);
}



#endif
