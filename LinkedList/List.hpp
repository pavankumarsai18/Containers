//Init
//initilializes the head and the tail
template <typename T>
void List<T>::init()
{
    head = new Node();
    tail = new Node();
    
    head->next = tail;
    tail->prev = head;
    theSize = 0;
    
}

//Constructor
template <typename T>
List<T>::List()
{
    init();
}

// copy constructor
template <typename T>
List<T>::List(const List &rhs)
{
    init();
    for(auto itr = rhs.begin(); itr != rhs.end(); itr++)
    {
        push_back(*itr);
    }

}

// move constructor
template <typename T>
List<T>::List(List && rhs):theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail}
{
    rhs.theSize = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;
}


// num elements with value of val
template <typename T>
List<T>::List(int num, const T& val )
{
    init();
    for(size_t i = 0; i < num; i++)
    {
        push_back(val);
    }
}

// constructs with elements [start, end)
template <typename T>
List<T>::List(const_iterator start, const_iterator end)
{
    init();
    for(auto itr = start; itr != end; itr++)
    {
          push_back(*itr);
    }
}

// constructs with a copy of each of the elements in the initalizer_list
template <typename T>
List<T>::List (std::initializer_list<T> iList)
{
    init();
    for(auto itr = iList.begin(); itr != iList.end(); itr++)
    {
        push_back(*itr);
    }
}

// destructor
template <typename T>
List<T>::~List()
{
    clear();
    delete head;
    delete tail;
    
    theSize = 0;
}


// copy assignment operator
template <typename T>
const List<T>& List<T>::operator=(const List &rhs)
{
    List<T> temp = rhs;
    std::swap(*this, temp);
    return *this;
}

// move assignment operator
template <typename T>
List<T>& List<T>::operator=(List && rhs)
{
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);
    std::swap(theSize, rhs.theSize);
    return *this;
}

// sets list to the elements of the initializer_list
template <typename T>
List<T>& List<T>::operator= (std::initializer_list<T> iList)
{
    init();
    for(auto itr = iList.begin(); itr != iList.end(); itr++)
    {
        push_back(*itr);
    }
    return *this;
}


// member functions
template <typename T>
int List<T>::size() const
{
    return theSize;
}

//checks whter the list is empty or not
template <typename T>
bool List<T>::empty() const{
    return ( theSize == 0);
}

//clears the list
template <typename T>
void List<T>::clear()
{
    while(size())
    {
        pop_back();
    }
}

//Reverses the list
template <typename T>
void List<T>::reverse()
{
    //We take two nodes
    //a node which walks forward and another node which walks backward
    //we swap the elements till we rach hail the size
    //similar to reversing an array
    List<T>::Node*forward = head->next;
    List<T>::Node*backward = tail->prev;
    for(size_t i = 0; i < size()/2; i++)
    {
        std::swap(forward->data, backward->data);
        forward = forward->next;
        backward = backward->prev;
    }
}

template <typename T>
T& List<T>::front()
{
    //returns data of the first inserted element
    return head->next->data;
}

template <typename T>
const T& List<T>::front() const
{
    //returns const data of the first inserted elements
    return head->next->data;
}

template <typename T>
T& List<T>::back()
{
    // reference to the last element
    return tail->prev->data;
}

template <typename T>
const T& List<T>::back() const
{
    // consant reference to the last element
    return tail->prev->data;
}

template <typename T>
void List<T>::push_front(const T & val)
{
    // insert to the beginning
    insert(begin(), val);

}
template <typename T>
void List<T>::push_front(T && val)
{
    /// move version of insert
    insert(begin(), std::move(val));
}

template <typename T>
void List<T>::push_back(const T & val)
{
    // insert to the end
    insert(end(), val);
}
template <typename T>
void List<T>::push_back(T && val)
{
     // move version of insert
    insert(end(), std::move(val));
    
}

template <typename T>
void List<T>::pop_front()
{
    // delete first element
    erase(begin());
}

template <typename T>
void List<T>::pop_back()
{
     // delete last element
    //since the iterator pints to one node past the ;ast node
    // we decrement it to point to the last inserted node
        erase(--end());
}

template <typename T>
void List<T>::remove(const T &val)
{
    //we iterate through the list and check wheter the value of the node is the same
    // as the val
    for(auto itr = begin(); itr != end(); itr++)
    {
        if(*itr == val)
        {
            erase(itr);
        }
    }
    
}

//Rempves elements if the predicate value is true
template <typename T>
template <typename PREDICATE>
void List<T>::remove_if(PREDICATE pred)
{
    for(auto itr = begin(); itr != end();)
    {
        if(pred(*itr))
        {
            itr = erase(itr);
        }
        else
        {
            itr++;
        }
    }
}   // remove all elements for which Predicate pred
//  returns true. pred can take in a function object

// print out all elements. ofc is deliminitor
template <typename T>
void List<T>::print(std::ostream& os, char ofc) const
{
    for(auto itr = begin();itr != end(); itr++)
    {
        os<<*itr<<ofc;
    }
}

// iterator to first element
template <typename T>
typename List<T>::iterator List<T>::begin()
{
    List<T>::iterator itr;
    itr.current = head->next;
    return itr;
}

//returns const iterator which points to the first element
template <typename T>
typename List<T>::const_iterator List<T>::begin() const
{
    List<T>::const_iterator itr;
    itr.current = head->next;
    return itr;
}

//returns iterator which points to one past the last insertrd node
template <typename T>
typename List<T>::iterator List<T>::end()
{
    List<T>::iterator itr;
    itr.current = tail;
    return itr;
}

//returns a const iterator to one node past the last inserted node
template <typename T>
typename List<T>::const_iterator List<T>::end() const
{
    List<T>::const_iterator  itr;
    itr.current = tail;
    return itr;
}

//inserts a values ahead of itr
template <typename T>
typename List<T>::iterator List<T>::insert(iterator itr, const T& val)
{
    List<T>::Node* curr_node = itr.current;
    
    List<T>::Node* new_node = new Node(val, curr_node->prev, curr_node);
    (curr_node->prev)->next = new_node;
    curr_node->prev = new_node;
    
    theSize++;
    List<T>::iterator result;
    result.current = new_node;
    return result;
    
}


//inserts a iterator to one node past the to the one the iterator points o
//we use move semantics as we pass an rvalue refernce as a parameter
template <typename T>
typename List<T>::iterator List<T>::insert(iterator itr, T && val)
{
    
    List<T>::Node* curr_node = itr.current;
    List<T>::Node*new_node = new Node(std::move(val), curr_node->prev, curr_node);
    
    (curr_node->prev)->next = new_node;
    curr_node->prev = new_node;
    
    theSize++;
    
    List<T>::iterator result;
    result.current = new_node;
    return result;
}     // move version of insert

//erases a node that the iterator points to
template <typename T>
typename List<T>::iterator List<T>::erase(iterator itr)
{
    List<T>::Node* Next = itr.current->next;
    List<T>::Node* Previous = itr.current->prev;
    
    Next->prev = Previous;
    Previous->next = Next;
    delete itr.current;
    theSize--;
    
    List<T>::iterator result;
    result.current = Next;
    return result;
}

//Erases a node that from [start, end)
template <typename T>
typename List<T>::iterator List<T>::erase(iterator start, iterator end)
{
    auto itr = start;
    while(itr != end)
    {
        itr = List<T>::erase(itr);
    }
    return itr;
}

// overloading comparison operators
template <typename T>
bool operator==(const List<T> & lhs, const List<T> &rhs)
{
    if(lhs.size() != rhs.size())
        return false;
    
    int size = lhs.size();
    auto itr1 = lhs.begin();
    auto itr2 = rhs.begin();
    
    for(size_t i = 0; i < size; i++)
    {
        if(*itr1 != *itr2)
            return false;
        itr1++;
        itr2++;
    }
    return true;
}


template <typename T>
bool operator!=(const List<T> & lhs, const List<T> &rhs)
{
    return !(lhs == rhs);
}

// overloading output operator
template <typename T>
std::ostream & operator<<(std::ostream &os, const List<T> &l)
{
    l.print(os);
    return os;
}


// Constant iterator
template <typename T>
List<T>::const_iterator::const_iterator()
{
    current = nullptr;
}
// default zero parameter constructor
template <typename T>
const T & List<T>::const_iterator::operator*() const
{
    return retrieve();
}// operator*() to return element

// increment/decrement operators
template <typename T>
typename List<T>::const_iterator& List<T>::const_iterator::operator++()
{
    current = current ->next;
    return *this;
}

//return a const_iterator
template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator++(int)
{
    List<T>::const_iterator result = *this;
    current = current->next;
    return result;
}

//points the previous node
template <typename T>
typename List<T>::const_iterator & List<T>::const_iterator::operator--()
{
    current = current ->prev;
    return *this;
}

//points the previous node
template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator--(int)
{
    List<T>::const_iterator result = *this;
    current = current->prev;
    return result;
}

// comparison operators
template <typename T>
bool List<T>::const_iterator::operator==(const List<T>::const_iterator &rhs) const
{
    return (current == rhs.current);
}

template <typename T>
bool List<T>::const_iterator::operator!=(const List<T>::const_iterator &rhs) const
{
    return !(*this == rhs);
}

template <typename T>
T & List<T>::const_iterator::retrieve() const
{
    return current->data;
}// retrieve the element refers to
template <typename T>
List<T>::const_iterator::const_iterator(Node *p)
{
    current = p;
}// protected constructor
//

//Iterator
template<typename T>
List<T>::iterator::iterator(): List<T>::const_iterator()
{}


template<typename T>
T & List<T>::iterator::operator*()
{
    return const_iterator::retrieve();
}

template<typename T>
const T & List<T>::iterator::operator*() const
{
    return const_iterator::operator*();
}

// increment/decrement operators
template<typename T>
typename List<T>::iterator & List<T>::iterator::operator++()
{
    if(this->const_iterator::current != nullptr)
        this->const_iterator::current = this->const_iterator::current->next;
    return *this;
}

// moves to the next node
template<typename T>
typename List<T>::iterator List<T>::iterator::operator++(int)
{
    List<T>::iterator result = *this;
    this->const_iterator::current = this->const_iterator::current->next;
    return result;
}

// moves to the previous node
template<typename T>
typename List<T>::iterator & List<T>::iterator::operator--()
{
    this->const_iterator::current = this->const_iterator::current->prev;
    return *this;
}

// moves to the previous node
template<typename T>
typename List<T>::iterator List<T>::iterator::operator--(int)
{
    List<T>::iterator result = *this;
    this->const_iterator::current = this->const_iterator::current->prev;
    return result;
}

// points to the ptr p
template <typename T>
List<T>::iterator::iterator(Node*p)
{
    this->const_iterator::current = p;
}
