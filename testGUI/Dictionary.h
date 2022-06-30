#pragma once

#include <iostream>
#include <map>
#include "exception.h"

template<class Key, class Value>
class dictionary
{
public:
	virtual ~dictionary() = default;

	virtual const Value& get(const Key& key) const = 0;
	virtual void set(const Key& key, const Value& value) = 0;
	virtual bool is_set(const Key& key) const = 0;
};


template<class Key, class Value>
class Dictionary : public dictionary<Key, Value>
{
	std::map<Key, Value> _key;
public:
	Dictionary() = default;
	Dictionary(const Dictionary&) = delete;
	Dictionary& operator=(const Dictionary&) = delete;
	Dictionary& operator=(Dictionary&&) = delete;
	Dictionary(Dictionary&&) = delete;
	~Dictionary() override = default;
public:
	const Value& get(const Key& key) const override
	{
		if (!_key.count(key))
		{
			throw KeyNotFoundException<int>(key);
		}
		return this->_key.at(key);
	}
	void set(const Key& key, const Value& value) override
	{
		if (_key.count(key))
		{
			_key.at(key) = value;
		}
		else _key.emplace(key, value);
	}
	bool is_set(const Key& key) const override
	{
		return !_key.count(key) ? false : true;
	}
};
