#ifndef stack_hpp
#define stack_hpp

template <typename T>
Stack<T>::Stack()
{
}

template <typename T>
Stack<T>::~Stack()
{
}

template <typename T>
Stack<T>::Stack (const Stack<T>& rhs)
{
    items = rhs.items;
}//: copy constructor.

template <typename T>
Stack<T>::Stack(Stack<T> && rhs)
{
    items = std::move(rhs.items);
}
//: move constructor.

template <typename T>
Stack<T>& Stack<T>::operator= (const Stack <T>& rhs)
{
    items = rhs.items;
    return *this;
}
// copy assignment operator=

template <typename T>
Stack<T> & Stack<T>::operator=(Stack<T> && rhs)
{
    Stack<T> temp = rhs;
    std::swap(items, temp.items);
    return *this;
}// move assignment operator=

template <typename T>
bool Stack<T>::empty() const
{
    return items.empty();
}// returns true if the Stack contains no elements, and false otherwise.

template <typename T>
void Stack<T>::clear()
{
    items.clear();
}// delete all elements from the stack.

template <typename T>
void Stack<T>::push(const T& x)
{
    items.push_back(x);
}// adds  x  to the Stack.   copy version.

template <typename T>
void Stack<T>::push(T && x)
{
    T val = x;
    items.push_back(val);
}// adds x to the Stack. move version.

template <typename T>
void Stack<T>::pop()
{
    items.pop_back();
    
}// removes and discards the most recently added element of the Stack.

template <typename T>
T& Stack<T>::top()
{
    return items[items.size() - 1];
}// returns a reference to the most recently added element of the Stack (as a modifiable L-value).

template <typename T>
const T& Stack<T>::top() const
{
    return static_cast<const T>(items[items.size() - 1]);
    
}// accessor that returns the most recently added element of the Stack (as a const reference)

template <typename T>
int Stack<T>::size() const
{
    return items.size();
}// returns the number of elements stored in the Stack.

template <typename T>
void Stack<T>::print(std::ostream& os, char ofc) const
{
    for(auto i  = 0; i < items.size(); i++)
    {
        os<< items[i] <<ofc;
    }
    os<<"\n";
}//prints the contents in the stack

template <typename T>
std::ostream& operator<< (std::ostream& os, const Stack<T>& a)
{
    a.print(os);
    return os;
}
//: invokes the print() method to print the Stack<T> a in the specified ostream


template <typename T>
bool operator== (const Stack<T>& a, const Stack <T>& b)
{
    if(a.size() != b.size())
        return false;
    
    cop4530::Stack<T> temp_a = a;
    cop4530::Stack<T> temp_b = b;
    
    while(!temp_a.empty())
    {
        if(temp_a.top() != temp_b.top())
            return false;
        temp_a.pop();
        temp_b.pop();
    }
    return true;
}
//: returns true if the two compared Stacks have the same elements, in the same order, and false otherwise


template <typename T>
bool operator!= (const Stack<T>& lhs, const Stack <T>& rhs)
{
    return !(lhs == rhs);
}//: opposite of operator==().


template <typename T>
bool operator<= (const Stack<T>& a, const Stack <T>& b)
{
    cop4530::Stack<T> temp_a = a;
    cop4530::Stack<T> temp_b = b;
    while(!temp_a.empty())
    {
        if(temp_a.top() > temp_b.top())
            return false;
        temp_a.pop();
        temp_b.pop();
    }
    
    return true;
}

#endif
