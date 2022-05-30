#include"hashTable.h"



std::pair<int, std::string> HashTable::null_data(-99999999, "null");

HashTable::HashTable()
{
	m_size = 0;
	m_capacity = 16;
	m_hashtable.reserve(8);
	m_ptable = new std::pair<int, std::string>*[m_capacity];
	for (int i = 0; i < m_capacity; i++)
	{
		m_ptable[i] = &null_data;
	}
}

HashTable::HashTable(int power_of_2_capacity)
{
	m_size = 0;
	if (power_of_2_capacity >= 4)
	{
		m_capacity = (int)pow(2, power_of_2_capacity);
	}
	else
	{
		m_capacity = 16;
	}
	m_hashtable.reserve(8);
	m_ptable = new std::pair<int, std::string>*[m_capacity];
	for (int i = 0; i < m_capacity; i++)
	{
		m_ptable[i] = &null_data;
	}
}

HashTable::~HashTable()
{
	delete[] m_ptable;
	m_hashtable.clear();
	m_hashtable.shrink_to_fit();
}

int HashTable::size()
{
	return m_size;
}

int HashTable::capacity()
{
	return m_capacity;
}

bool HashTable::isEmpty() const
{
	return m_size == 0;
}

bool HashTable::colision_check(int index)
{
	return m_ptable[index]->first != -99999999;
}

int HashTable::hash(int key, bool& rehashing)
{
	int index = (int)(m_capacity * fmod(key * 0.618033, 1));
	if (colision_check(index))
	{
		std::cout << "rehashing: r = 5" << std::endl;
		rehashing = 1;
		index = rehash(index, 5);
	}
	return index;
}

int HashTable::hash(int key)
{
	int index = (int)(m_capacity * fmod(key * 0.618033, 1));
	if (colision_check(index))
	{
		index = rehash(index, 5);
	}
	return index;
}

int HashTable::rehash(int index_init, int r)
{
	std::string r_binary = decimalToBinary(r);
	std::string offset_binary;
	if (r_binary.length() <= 2)
	{
		offset_binary.resize(0);
	}
	else
	{
		offset_binary.resize(r_binary.length() - 2);
	}
	for (int i = 0; i < offset_binary.length(); i++)
	{
		offset_binary[i] = r_binary[i];
	}
	int offset = binaryToDecimal(offset_binary);

	int index = (index_init + offset) % m_capacity;

	if (colision_check(index))
	{
		if (r * 5 == 1953125)
		{
			std::cout << r;
		}
		std::cout << "rehashing: r = " << r * 5 << std::endl;
		return rehash(index_init, r * 5);
	}
	else
	{
		return index;
	}
}

int HashTable::find(int key, int r)
{
	int index = (int)(m_capacity * fmod(key * 0.618033, 1));
	if (r == 1 && m_ptable[index]->first == key)
	{
		return index;
	}

	std::string r_binary = decimalToBinary(r);
	std::string offset_binary;
	if (r_binary.length() <= 2)
	{
		offset_binary.resize(0);
	}
	else
	{
		offset_binary.resize(r_binary.length() - 2);
	}
	for (int i = 0; i < offset_binary.length(); i++)
	{
		offset_binary[i] = r_binary[i];
	}
	int offset = binaryToDecimal(offset_binary);

	index = (index + offset) % m_capacity;

	if (r >= pow(5, 12))
	{
		while (m_ptable[index]->first != -99999999)
		{
			index = (index + 1) % m_capacity;
		}
		return index;
	}

	if (m_ptable[index]->first != key)
	{
		return find(key, r * 5);
	}
	else
	{
		return index;
	}
}

bool HashTable::insert(int key, std::string data)
{
	if ((((float)m_size + 1) / (float)m_capacity) > 0.67)
	{
		reallocate(m_capacity * 2);
	}

	m_hashtable.emplace_back(key, data);
	m_size++;
	std::vector<std::pair<int, std::string>>::iterator it = --m_hashtable.end();

	bool rehashing = 0;
	int index = hash(key, rehashing);
	m_ptable[index] = &(*it);

	return rehashing;
}

void HashTable::reallocate(int new_capacity)
{
	m_capacity = new_capacity;
	delete[] m_ptable;
	m_ptable = new std::pair<int, std::string>*[m_capacity];
	for (int i = 0; i < new_capacity; i++)
	{
		m_ptable[i] = &null_data;
	}
	for (std::vector<std::pair<int, std::string>>::iterator it = m_hashtable.begin(); it != m_hashtable.end(); it++)
	{
		int index = hash(it->first);
		m_ptable[index] = &(*it);
	}
}

void HashTable::erase(int key)
{
	if ((((float)m_size - 1) / (float)m_capacity) < 0.25)
	{
		reallocate(m_capacity / 2);
	}

	int ptr_index = find(key);
	if (m_ptable[ptr_index]->first != -99999999)
	{
		std::vector<std::pair<int, std::string>>::iterator it = m_hashtable.begin();
		std::pair<int, std::string>* p_vector_begin = &(*it);
		int64_t v_index = m_ptable[ptr_index] - p_vector_begin;
		m_ptable[ptr_index] = &null_data;
		m_hashtable.erase(it + v_index);
		m_size--;
	}
	else
	{
		//std::cout << "erase(): key '" << key << "' not found, the row is not erased\n";
		throw std::invalid_argument("key is not found, the row is not erased");
	}
}

int HashTable::binaryToDecimal(std::string n)
{
	std::string num = n;
	int dec_value = 0;
	int base = 1;

	int len = (int)num.length();
	for (int i = len - 1; i >= 0; i--) {
		if (num[i] == '1')
			dec_value += base;
		base = base * 2;
	}

	return dec_value;
}

std::string HashTable::decimalToBinary(int num)
{
	std::string to_reverse;
	while (num) {
		if (num & 1)
			to_reverse += '1';
		else
			to_reverse += '0';
		num >>= 1;
	}
	std::string binary;
	for (int i = (int)to_reverse.size() - 1; i >= 0; i--)
	{
		binary.push_back(to_reverse[i]);
	}
	return binary;
}

void HashTable::print()
{
	for (int i = 0; i < m_hashtable.size(); i++)
	{
		std::cout << "[" << m_hashtable[i].first << "] = " << m_hashtable[i].second << "; ";
	}
}

std::string& HashTable::operator[](int key)
{
	return m_ptable[find(key)]->second;
}

int HashTable::key_colision(int key)
{
	int count = 0;
	std::vector<std::pair<int, std::string>>::iterator it = m_hashtable.begin();
	for (it; it < m_hashtable.end(); it++)
	{
		if (it->first == key)
		{
			count++;
		}
	}
	return count;
}