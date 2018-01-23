#include <datastructure.h>
//链表类函数的实现
//待优化
void LinkList::add(Object object){
	if (this->head==NULL){

		LinkListNode linkListNode=LinkListNode();
		this->head =&linkListNode;
		linkListNode->object=object;
		return 0;
	}
	LinkListNode linkListNode=LinkListNode();
	tail->next=&linkListNode;
	linkListNode->object=object;
}

Object::Object(){}
Object::Object(int id){
    id=this.id;
}
