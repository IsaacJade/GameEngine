#pragma once
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif
#include <iostream>
#include <ostream>

namespace Azul
{
	class my_string
	{
	private:
		char* buf = nullptr;
		unsigned int size = 0;

	public:
		my_string() : buf(nullptr), size(0) // default constructor
		{
		}

		my_string(const char* const buffer) // constructor
		{
			size = strlen(buffer);
			buf = new char[size + 1]; // + 1 for the keeping the null character
			strncpy_s(buf, size + 1, buffer, size); // copy from the incoming buffer to character buffer of the new object
		}
		my_string(float num)
		{
			size = 10;
			buf = new char[size + 1];
			sprintf_s(buf,size, "%5.3f", num);
		}

		my_string(const my_string& obj) // copy constructor
		{
			size = obj.size;
			buf = new char[size + 1]; // + 1 for the keeping the null character
			strncpy_s(buf, size + 1, obj.buf, size); // copy from the incoming buffer to character buffer of the new object
		}

		my_string& operator=(const my_string& obj) // copy assignment
		{
			__cleanup__(); // cleanup any existing data

			// Copy data from the newly assigned my_string object
			size = obj.size;
			buf = new char[size + 1]; // + 1 for the keeping the null character
			strncpy_s(buf, size + 1, obj.buf, size); // copy from the incoming buffer to character buffer of the new object
			return *this;
		}

		my_string(my_string&& dyingObj) noexcept
		// move constructor
		// && is a reference operator defined in the C++11 standard 
		// which means "dyingObj" is an r-value reference.
		// Compiler calls this constructor when the object passed in the argument
		// is about to die due to scope end or such
		{
			__cleanup__(); // cleanup any existing data

			// Copy data from the incoming object
			size = dyingObj.size;

			// Transfer ownership of underlying char buffer from incoming object to this object
			buf = dyingObj.buf;
			dyingObj.buf = nullptr;
		}

		my_string& operator=(my_string&& dyingObj) noexcept
		// move assignment
		{
			__cleanup__(); // cleanup any existing data

			// Copy data from the incoming object
			size = dyingObj.size;

			// Transfer ownership of underlying char buffer from incoming object to this object
			buf = dyingObj.buf;
			dyingObj.buf = nullptr;

			return *this;
		}

		my_string operator+(const my_string& obj) // concatenation
		{
			my_string s; // create a new string named 's'
			s.size = this->size + obj.size;
			s.buf = new char[s.size + 1]; // allocate memory to keep the concatenated string
			strncpy_s(s.buf, this->size + 1, this->buf, this->size); // copy the 1st string
			strncpy_s(s.buf + this->size, obj.size + 1, obj.buf, obj.size);

			return s;
		}

		char operator[](int index)
		{
			return buf[index];
		}

		unsigned int length()
		{
			return size;
		}

		const char* c_str() const
		{
			return buf;
		}

		~my_string() // destructor
		{
			__cleanup__();
		}

	private:
		void __cleanup__()
		{
			if (buf != nullptr)
			{
				delete[] buf;
			}
			size = 0;
		}
	};

	inline bool operator == (my_string& a, my_string& b)
	{
		return strcmp(a.c_str(), b.c_str()) == 0;
	}

	inline std::ostream& operator<<(std::ostream& cout, const my_string& obj)
	{
		cout << obj.c_str();
		return cout;
	}
}
