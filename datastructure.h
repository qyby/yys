//为避免头文件被多个文件包含导致的重复定义问题，要求所有头文件都写在ifndef和endif之间
#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H
//定义物体类,作为一切可显示物体的父类
class Object{
	void toShow();
}
//定义链表节点类
class LinkListNode{
	LinkListNode *next;
	Object *object;
}
//定义链表类
class LinkList{
	public:
		LinkListNode *head;
		LinkListNode *tail;
		void add(Object);
		void del(Object);
}



#endif
