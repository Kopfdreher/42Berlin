#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set {
private:
	searchable_bag& _bag;

public:
	set(searchable_bag& bag);
	set(const set& other);
	set& operator=(const set& other);
	~set();

	searchable_bag& get_bag() const;

	void insert(int val);
	void insert(const int* array, int size);
	bool has(int val) const;
	void print() const;
	void clear();
};

#endif
