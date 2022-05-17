#include "String.h"
typedef std::vector<Rule>::iterator iter;

//exception enum constants
enum LOOP_MARKOV
{
	LOOP_DURATION = 5000,
	STR_LEN = 100
};

//main markov algorithm
String markovAlg(std::vector<Rule>& rules, String data)
{
	if (rules.empty())                   //no rules => exception
	{
		throw BadRule(data);
	}
	String result = data;               //move data
	iter loop = rules.begin();          //from start
	short loop_counter = 0;             //counter for exception
	while (loop != rules.end())         //while not last rule
	{
		int pos = result.find(loop->from); //find substring
		if (pos != -1)                     //if found
		{
			if (result.replace(loop->from, loop->to))  //replace
			{
				loop = rules.begin();                  //move to 1st rule
			}
			if (loop->terminal)                        //if last production
			{
				break;                                 //exit
			}
		}
		else                                           //not found =>
		{ 
			++loop;                                    //next rule
		}

		++loop_counter;                                //exception counter
		if (result.length() > LOOP_MARKOV::STR_LEN || loop_counter > LOOP_MARKOV::LOOP_DURATION)
		{
			throw BadRule(data);
		}
	}
	return result;
}

String::String()
{
	size = 0;
	cont = nullptr;
}

String::String(const char* str)
{
	size = strlen(str);
	cont = new char[size + 1];
	memcpy(cont, str, size);
}

String::String(const String& str)
{
	size = str.size;
	cont = new char[size];
	memcpy(this->cont, str.cont, size);
}

String::~String()
{
	delete[] cont;
}

size_t String::length() const
{
	return size;
}

//differentiate text 
String String::substring(size_t pos, size_t len) const
{
	if (pos + len > size)
	{
		throw std::invalid_argument("BAD POSITION OR LENGTH!");
	}
	String res;
	res.size = len;
	res.cont = new char[len];
	memcpy(res.cont, &cont[pos], len);
	return res;
}

//finds an index of substring in a text
int String::find(const String& substr) const
{
	int pos = -1;
	if (this->size >= substr.size)
	{
		size_t last_index_to_check = size - substr.size;
		for (size_t i = 0; i <= last_index_to_check; ++i)
		{
			size_t j;
			bool still_equal = false;
			for ( j  = 0; j < substr.size; ++j)
			{
				if (cont[i + j] != substr.cont[j])
				{
					still_equal = false;
					break;
				}
				still_equal = true;
			}
			if (still_equal)
			{
				pos = i;
			}
			
		}
		
	}
	return pos;
}

bool String::replace(const String& from, const String& to)
{
	bool if_carried = false;
	int from_position = this->find(from);                           //search for substr 
	if (from_position != -1)                                        //if found
	{
		String before = this->substring(0, from_position);          //start - begin f substr
		int pos_from = from_position + from.length();               //end of substr   
		int length_of_substr = this->length() - pos_from;           //length of substr
		String after = this->substring(pos_from, length_of_substr); //after
		*this = before + to + after;                                //before + to + after
		if_carried = true; 
	}
	return if_carried;
}

String& String::operator=(const String& str)
{
	this->size = str.size;
	delete[] cont;
	cont = new char[size];
	memcpy(this->cont, str.cont, size);
	return *this;
}

String String::operator+(const String& str)
{
	String res;
	res.size = this->size + str.size;
	res.cont = new char[res.size];
	memcpy(res.cont, this->cont, this->size);
	memcpy(res.cont + this->size, str.cont, str.size);
	return res;
}

bool String::operator==(const String& str) const
{
	return (this->size == str.size) && (0 == memcmp(this->cont, str.cont, size));
}

String::iterator String::begin()
{
	return iterator(cont);
}

String::iterator String::end()
{
	return iterator(cont + size);
}

std::ostream& operator<<(std::ostream& out, const String& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		out << str.cont[i];
	}
	return out;
}



String::iterator::iterator(char* _ptr)
{
	ptr = _ptr;
}

String::iterator& String::iterator::operator++()
{
	++ptr;
	return *this;
}

char& String::iterator::operator*()
{
	return *ptr;
}

bool String::iterator::operator!=(const iterator& it)
{
	return ptr != it.ptr;
}

bool String::iterator::operator==(const iterator& it)
{
	return ptr == it.ptr;
}

bool String::iterator::operator<(const iterator& it)
{
	return ptr < it.ptr;
}
