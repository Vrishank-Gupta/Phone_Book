#ifndef _HASHNODE_H_
#define _HASHNODE_H_
#include <cstring>

template <typename V>
class Hashnode
{
public:
	char* key;
	V value;
	Hashnode<V>* next;
	Hashnode(char* name,V& val){
		key = new char[std::strlen(name) + 1];
		std::strcpy(key, name);
		value = val;
		next = 0;
	}

	~Hashnode()
	{
		if(next!=NULL)
			{
				delete next;
				next=NULL;
			}
		delete [] key;
	}
};
#endif