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
	size = 0;          //empty
	cont = nullptr;    //no container
}

String::String(const char* str)
{
	size = strlen(str);           //get size of C-string
	cont = new char[size];        //create cont
	memcpy(cont, str, size);      //copy memory
}

String::String(const String& str)       
{
	size = str.size;                    //equalize size
	cont = new char[size];              //new container
	memcpy(this->cont, str.cont, size); //copy mem
}

String::~String()
{
	delete[] cont;        //delete dynamic arr
}

size_t String::length() const
{
	return size;
}   

//differentiate text 
String String::substring(size_t pos, size_t len) const
{
	if (pos + len > size)          //if try to find after end
	{                              //=>exception
		throw std::invalid_argument("BAD POSITION OR LENGTH!");
	}
	String res;                        //resulting string
	res.size = len;                    //equalise size
	res.cont = new char[len];          //cont of size of substring
	memcpy(res.cont, cont + pos, len); //start copy from pos
	return res;
}

//finds an index of substring in a text
int String::find(const String& substr) const
{
	int pos = -1;                                          //assume that won't find
	if (this->size >= substr.size)                         //if substring size is less!!!
	{
		size_t last_index_to_check = size - substr.size;   //determine probable las ind 
		for (size_t i = 0; i <= last_index_to_check; ++i)  //start loop
		{
			bool still_equal = false;                      //assume that chars are not equal
			for (size_t j = 0; j < substr.size; ++j)       //2nd loop: check up to substr size
			{
				if (cont[i + j] != substr.cont[j])         //string[i+j] == substr[j] ??
				{
					still_equal = false;                   //no - false => break
					break;
				}
				still_equal = true;                        //yes => still_equal
			}
			if (still_equal)                               //if in the end of loop 
			{                                              //equal
				pos = i;                                   //save position
			}	
		}
	}
	return pos;                                            
}

//replaces substring *from* to substr *to* in *this*
bool String::replace(const String& from, const String& to)
{
	bool if_carried = false;                                        //bool-state of sucess
	int from_position = this->find(from);                           //search for substr 
	if (from_position != -1)                                        //if found
	{
		String before = this->substring(0, from_position);          //start - begin f substr
		int pos_from = from_position + from.length();               //end of substr   
		int length_of_substr = this->length() - pos_from;           //length of substr
		String after = this->substring(pos_from, length_of_substr); //after
		*this = before + to + after;                                //before + to + after
		if_carried = true;                                          //success!
	}
	return if_carried;
}

String& String::operator=(const String& str)
{
	this->size = str.size;                 //equalise size
	delete[] cont;                         //delete old container
	cont = new char[size];                 //create new of size
	memcpy(this->cont, str.cont, size);    //copy mem
	return *this;
}

String String::operator+(const String& str)
{
	String res;                                         //result String
	res.size = this->size + str.size;                   //size + str.size
	res.cont = new char[res.size];                      //new cont
	memcpy(res.cont, this->cont, this->size);           //copy from this to begin of new cont
	memcpy(res.cont + this->size, str.cont, str.size);  //copy from str to begin + size of this
	return res;
}

bool String::operator==(const String& str) const     //first check size; if equal =>
{                                                    //then we check char by char
	return (this->size == str.size) && (0 == memcmp(this->cont, str.cont, size));
}

String::iterator String::begin()
{
	return iterator(cont);         //iterator to begin
}

String::iterator String::end()
{
	return iterator(cont + size); //iterator to end
}

//print container
std::ostream& operator<<(std::ostream& out, const String& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		out << str.cont[i];   
	}
	return out;
}

//iterator constructor
String::iterator::iterator(char* _ptr)
{
	ptr = _ptr;
}

//increment operator
String::iterator& String::iterator::operator++()
{
	++ptr;
	return *this;
}

//dereference operator
char& String::iterator::operator*()
{
	return *ptr;
}

//non-equal
bool String::iterator::operator!=(const iterator& it)
{
	return ptr != it.ptr;
}

//equal
bool String::iterator::operator==(const iterator& it)
{
	return ptr == it.ptr;
}

//less
bool String::iterator::operator<(const iterator& it)
{
	return ptr < it.ptr;
}
