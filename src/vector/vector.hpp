template <typename T>
Vector<T>::Vector()
{
	curSize = 0;
	size = 0;
	maxSize = 16;

	arr = new T[maxSize];
}

template <typename T>
int Vector<T>::nearestPower(int size){
	int twoPower = 1; 
	while(twoPower < size)
	{
		twoPower *= 2;
	}

	return twoPower;
}

template <typename T>
Vector<T>::Vector(T value, int size){
	maxSize = nearestPower(size);

	curSize = 0;

	arr  = new T[maxSize];
}

template <typename T>
Vector<T>::Vector(const Vector && v){
	curSize = v.curSize;
	size = v.size;
	maxSize = v.maxSize;

	arr = new T[maxSize];

	for(int i = 0;i < v.size();i++)
	{
		arr[i] = v.arr[i];
	}

}

template <typename T>
const Vector<T>::Vector& operator=(const Vector&& v){
	curSize = v.curSize;
	size = v.size;
	maxSize = v.maxSize;

	arr = new T[maxSize];

	for(int i = 0;i < v.size();i++)
	{
		arr[i] = v.arr[i];
	}

	return *this;
}

template <typename T>
void Vector<T>::push_back(T val){

	T* newArr;

	if(curSize == maxSize)
	{
		maxSize *= 2;
		newArr = new T[maxSize];

		for(int i = 0; i < size; i++)
		{
			newArr[i] = arr[i];
		}

		newArr[size] = val;
		size++;
		curSize++;
	}
	else{
		newArr[size] = val;
		size++;
		curSize++;
	}
}

template <typename T>
int Vector<T>::findElement(T val){

	int index = -1;

	for(int i = 0; i < size; i++)
	{
		if(arr[i] == val)
			return i;
	}

	return index;
}

template <typename T>
void Vector<T>::deleteElement(T val){

	int index = findElement(val);
	if(index != -1)
	{
		for(int i = index; i < size - 1; i++)
		{
			arr[i] = arr[i+1];
		}
		size--;
	}

	return;
}

template <typename T>
void Vector<T>::void clear(){
	size = 0;
}


template <typename T>
Vector<T>::~Vector(){

	delete arr;
	size = 0;
	curSize = 0;
}