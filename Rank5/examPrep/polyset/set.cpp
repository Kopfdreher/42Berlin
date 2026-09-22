#include "set.hpp"

// private:
// searchable_bag& _bag;

// public:
	
set::set(searchable_bag& bag) : _bag(bag) {}

set::set(const set& other) : _bag(other._bag) {}

set& set::operator=(const set& other) {
	if (this != &other) {
		this->_bag = other._bag;
	}
	return *this;
}

set::~set() {}

searchable_bag& set::get_bag() const {
	return _bag;
}

void set::insert(int val) {
	if (!_bag.has(val)) {
		_bag.insert(val);
	}
}

void set::insert(const int* array, int size) {
	if (!array) return;
	for (int i = 0; i < size; ++i) {
		this->insert(array[i]);
	}
}

bool set::has(int val) const {
	return _bag.has(val);
}

void set::print() const {
	_bag.print();
}

void set::clear() {
	_bag.clear();
}
