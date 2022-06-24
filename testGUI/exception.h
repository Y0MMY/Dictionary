#pragma once
#include <iostream>

template<class Key>
class not_found_exception : public std::exception {
public:
	virtual const Key& GetKey() const noexcept = 0;
};

template <class Key>
class KeyNotFoundException : public not_found_exception<Key>
{
private:
	Key _key;
public:
	KeyNotFoundException(Key key)
		: _key(key)
	{}

	const Key& GetKey() const noexcept override
	{
		return _key;
	}

	const char* what() const noexcept override
	{
		return "Error: Key is not found";
	}

};