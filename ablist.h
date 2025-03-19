#ifndef _LINKLIST_H_
#define _LINKLIST_H_

template <typename type>
class Node {
private:
	type _value;
	Node<type>* _pnext;
public:
	Node() { _pnext = nullptr; }
	Node(const type& value, Node<type>* pnext = nullptr) { _value = value; _pnext = pnext; }
};

template <typename type>
class ablist {
protected:
	unsigned int length;
public:
	unsigned int get_length() { return length; }
	virtual type get(const unsigned int i) = 0;
	virtual bool set(const type& value, const unsigned int i) = 0;
	virtual void make_empty() = 0;
	virtual bool insert(const type& value, const unsigned int i) = 0;
	virtual bool remove_index(const unsigned int i) = 0;
	virtual void remove_value(const type& value) = 0;
	virtual Node<type>* find_index(const unsigned int i) = 0;
	virtual Node<type>* find_value(const type& value) = 0;
};
template <typename type>
class ablinklist :
	public ablist<type> {
private:
	Node<type>* phead;
public:
	Node<type>* get_head() { return phead; }
	Node<type>* get_next(Node<type>& node) { return node._pnext == phead ? node._pnext->_pnext : node._pnext; }
	type get(const unsigned int i);
	bool set(const type& value, const unsigned int i);
	void make_empty();
	bool insert(const type& value, const unsigned int i = get_length());
	bool remove_index(const unsigned int i = get_length());
	void remove_value(const type& value);
	Node<type>* find_index(const unsigned int i);
	Node<type>* find_value(const type& value);
};

#endif // !_LINKLIST_H_	