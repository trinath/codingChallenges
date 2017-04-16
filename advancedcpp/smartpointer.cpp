// author&src:learncpp.com 
// link: http://www.learncpp.com/cpp-tutorial/15-3-move-constructors-and-move-assignment/
// Using the move constructor and move assignment operator improve the efficiency of the program by 67%.
// Refer unique_ptr, shared_ptr and weak_ptr for further reference.
#include <iostream>
#include <iostream>
  
template<class T>
class Smartptr
{
	T* m_ptr;
public:
	Smartptr(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}
 
	~Smartptr()
	{
		delete m_ptr;
	}
 
	Smartptr(const Smartptr& a) = delete;
 
	Smartptr(Smartptr&& a)
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr;
	}
 
	Smartptr& operator=(const Smartptr& a) = delete;
 
	Smartptr& operator=(Smartptr&& a)
	{
		if (&a == this)
			return *this;
 
		delete m_ptr;
 
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
 
		return *this;
	}
 
	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};