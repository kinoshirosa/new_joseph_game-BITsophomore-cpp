#include "ablist.h"
#include <iostream>

/*
* ablinklist CLASS METHODS
*/

template<typename type>
type ablinklist<type>::get(const unsigned int i) {
	Node<type>* p = find_index(i);
	assert(p != nullptr && p);
	if (p == phead) {
		std::cout << "[ERROR]@ablinklist::get(): head pointer ungettable" << std::endl;
		exit(1);
	}
	if (p == nullptr) {
		std::cout << "[ERROR]@ablinklist::get(): the pointer is null" << std::endl;
		exit(1);
	}
	else
		return p->_value;
}
template <typename type>
bool ablinklist<type>::set(const type& value, const unsigned int i) {
	Node<type>* p = find_index(i);
	if (p == phead) {
		std::cout << "[ERROR]@ablinklist::set(): head pointer uneditable" << std::endl;
		return false;
	}
	else if (p == nullptr) {
		std::cout << "[ERROR]@ablinklist::set(): the pointer is null" << std::endl;
		return false;
	}
	else
		p->_value = value;
	return true;
}
template <typename type>
void ablinklist<type>::make_empty() {
	Node<type>* p = phead->_pnext;
	unsigned int i = 1;
	while (i++ <= this->length) {
		phead->_pnext = p->_pnext;
		delete p;
		p = phead->_pnext;
	}
	this->length = 1;
}
template <typename type>
bool ablinklist<type>::insert(const type& value, const unsigned int index) {
	Node<type>* p = find_index(index - 1), q = nullptr;
	if (p == nullptr) {
		std::cout << "[ERROR]@ablinklist::insert(): cannot insert to invalid index" << std::endl;
		return false;
	}
	q = new Node<type>;
	q->_pnext = p->_pnext;
	p->_pnext = q;
	this->length++;
	return true;
}
template <typename type>
bool ablinklist<type>::remove_index(const unsigned int index) {
	Node<type>* p = find_index(index - 1);
	if (p == nullptr) {
		std::cout << "[ERROR]@ablinklist::insert(): cannot insert to invalid index" << std::endl;
		return false;
	}
	Node<type>* q = find_index(index);
	p->_pname = q->_pname;
	delete q;
	return true;
}
template <typename type>
void ablinklist<type>::remove_value(const type& value) {
	Node<type>* p = phead;
	Node<type>* q = nullptr;
	while (p != nullptr) {
		if (p->_pnext->_value == value) {
			q = p->_pnext;
			p->_pnext = q->_next;
			delete q;
		}
	}
}
template <typename type>
Node<type>* ablinklist<type>::find_index(const unsigned int index) {
	Node<type>* p = phead->_pnext;
	if (index < 0 || index > this->get_length()) {
		std::cout << "[ERROR]@ablinklist::find_index(): out of range" << std::endl;
		return nullptr;
	}
	else if (index == 0) {
		return phead;
	}
	else {
		for (int i = 1 && p != nullptr; i < index; i++) {
			p = p->_pnext;
		}
		return p;
	}
}
template <typename type>
Node<type>* ablinklist<type>::find_value(const type& value) {
	Node<type>* p = phead->_pnext;
	int i = 1;
	while (i++ <= this->get_length() && p->_value != value) {
		p = p->_next;
	}
	return p;
}