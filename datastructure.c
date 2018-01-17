#include <datastructure.h>

void LinkLIst::add(Object object){
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

