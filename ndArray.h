//#pragma once
//#include <iostream>
//using namespace std;
//
//template <class T>
//class ndArray
//{
//	int* dimensions;
//	int dim_size;
//	T* linearArray;
//	int lin_size;
//public:
//	ndArray();
//	ndArray(int); //for 1D array
//	ndArray(int, int); //for 2D array
//	ndArray(int, int, int);//for 3D array
//	ndArray(int* dimension, int size);
//	
//	ndArray(const ndArray& obj);
//	
//	bool insert(T element, int i); //insert in 1D array
//	bool insert(T element, int i, int j);//insert in 2D array
//	bool insert(T element, int i, int j, int k);  //insert in 3D array
//	bool insert(T element, int* indexes, int size);
//	
//	bool Delete(T const element);     //deletes a particular element and shifts the data
//	bool Delete(int* indexes, int size); // deletes the data at a particular address and shifts the data
//	
//	bool Extend();  //doubles the higher dimension
//	
//	bool Shrink(); //halves the higher dimension
//	
//	T Retrieve(T const element); //Returns the element if not found returns the first element 
//	
//	//will return first element when index is invalid
//	T& operator[](const int i);
//	T& operator()(const int i,const int j);                                      
//	T& operator()(const int i,const int j,const int k);
//	T& operator()(const int i,const int j,const int k,const int l);
//	
//	
//	~ndArray();
//	
//	friend ostream& operator<<(ostream& out, const ndArray& obj)
//	{
//		if (obj.dim_size == 2)
//		{
//			int i = 0;
//			for (int j = 0; j < obj.dimensions[0]; j++)
//			{
//				for (int k = 0; k < obj.dimensions[1]; k++)
//				{
//					out << obj.linearArray[i]<<" ";
//					i++;
//				}
//				out << endl;
//			}
//		}
//		else if (obj.dim_size == 3)
//		{
//			int i = 0;
//			for (int h = 0; h < obj.dimensions[0]; h++)
//			{
//				for (int j = 0; j < obj.dimensions[1]; j++)
//				{
//					for (int k = 0; k < obj.dimensions[2]; k++)
//					{
//						out << obj.linearArray[i] << " ";
//						i++;
//					}
//					out << endl;
//				}
//				out << endl;
//			}
//		}
//		else
//		{
//			for (int i = 0; i < obj.lin_size; i++)
//				out << obj.linearArray[i] << " ";
//		}
//		return out;
//	}
//	
//
//};
//
//
//
//template <class T>
//ndArray<T>::ndArray()
//{
//	dimensions = nullptr;
//	dim_size = 0;
//	linearArray = nullptr;
//	lin_size = 0;
//}
//
//template <class T>
//ndArray<T>::ndArray(int i)
//{
//	dim_size = 1;
//	dimensions = new int[dim_size]; 
//	dimensions[0] = i;
//
//	lin_size = i;
//	linearArray = new T[lin_size]; 
//	
//}
//
//template <class T>
//ndArray<T>::ndArray(int i, int j)
//{
//	dim_size = 2;
//	dimensions = new int[dim_size]; 
//	dimensions[0] = i;
//	dimensions[1] = j;
//
//	lin_size = i * j;
//	linearArray = new T[lin_size]; 
//	
//}
//
//template <class T>
//ndArray<T>::ndArray(int i, int j, int k)
//{
//	dim_size = 3;
//	dimensions = new int[dim_size];
//	dimensions[0] = i;
//	dimensions[1] = j;
//	dimensions[2] = k;
//
//	lin_size = i * j * k;
//	linearArray = new T[lin_size];
//	
//}
//
//template <class T>
//ndArray<T>::ndArray(int* dimension, int size)
//{
//	dim_size = size;
//	dimensions = new int[dim_size];
//	for (int i = 0; i < dim_size; i++)
//		dimensions[i] = dimension[i];
//	lin_size = 1;
//	for (int i = 0; i < dim_size; i++)
//		lin_size = lin_size * dimensions[i];
//
//	linearArray = new T[lin_size]; 
//
//
//}
//
//template <class T>
//ndArray<T>::ndArray(const ndArray& obj)
//{
//	this->lin_size = obj.lin_size;
//	this->dim_size = obj.dim_size;
//
//	this->dimensions = new int[dim_size];
//	this->linearArray = new T[lin_size];
//
//	for (int i = 0; i < dim_size; i++)
//		this->dimensions[i] = obj.dimensions[i];
//	for (int i = 0; i < lin_size; i++)
//		this->linearArray[i] = obj.linearArray[i];
//}
//
//
//template <class T>
//bool ndArray<T>::insert(T element, int i)
//{
//	if (dim_size != 1)
//		return false;
//	if(!(i < dimensions[0]))
//		return false;
//	linearArray[i] = element;
//	return true;
//}
//
//template <class T>
//bool ndArray<T>::insert(T element, int i, int j)
//{
//	if (dim_size != 2)
//		return false;
//	if (!(i < dimensions[0] && j < dimensions[1]))
//		return false;
//	int index = (i * dimensions[1]) + j;
//	linearArray[index] = element;
//	return true;
//}
//
//template <class T>
//bool ndArray<T>::insert(T element, int i, int j, int k)
//{
//	if (dim_size != 3)
//		return false;
//	if (!(i < dimensions[0] && j < dimensions[1] && k < dimensions[2]))
//		return false;
//	int index = i * dimensions[1] * dimensions[2] + j * dimensions[2] + k;
//	linearArray[index] = element;
//	return true; 
//
//}
//
//
//template <class T>
//bool ndArray<T>::insert(T element, int* indexes, int size)
//{
//	if (dim_size != size)
//	{
//		cout << "Invalid dimension for this objext" << endl;
//		return false;
//	}
//	for (int i = 0; i < dim_size; i++)
//	{
//		if (!(indexes[i] < dimensions[i]))
//		{
//			cout << "Invalid indexes"<<endl;
//			return false;
//		}
//	}
//	if (dim_size == 1)
//	{
//		linearArray[indexes[0]] = element;
//		return true;
//	}
//
//	int index = 0;
//	
//	for (int i = 0; i < dim_size-1; i++)
//	{
//		int x = 1;
//		for (int j = i + 1; j < dim_size; j++)
//			x = x* indexes[i] * dimensions[j];
//		index = index + x;
//	}
//	index = index + indexes[size - 1];
//	linearArray[index] = element;
//	return true;
//}
//
//template <class T>
//T& ndArray<T>::operator[](const int i)
//{
//	if (i > 0 && dim_size == 1 && i < dimensions[0])
//	{
//		return linearArray[i];
//	}
//	else
//	{
//		cout << "invalid index ";
//		return linearArray[0];
//
//	}
//}
//
//template <class T>
//T ndArray<T>::Retrieve(T const element)
//{
//	for (int i = 0; i < lin_size; i++)
//		if (linearArray[i] == element)
//			return linearArray[i];
//	cout << "Element not found\n";
//	return linearArray[0];
//}
//
//template<class T>
//bool ndArray<T>::Delete(T const element)
//{
//	int index = -1;
//	for (int i = 0; i < lin_size; i++)
//		if (linearArray[i] == element)
//			index = i;
//	if (index == -1)
//		return false;
//	else
//	{
//		for (int i = index; i < lin_size - 1; i++)
//			linearArray[i] = linearArray[i + 1];
//		linearArray[lin_size - 1] = 0;
//		return true;
//
//	}
//			
//	
//}
//
//template <class T>
//bool ndArray<T>:: Delete(int* indexes, int size)
//{
//	if (dim_size != size)
//	{
//		cout << "Invalid dimension for this objext" << endl;
//		return false;
//	}
//	for (int i = 0; i < dim_size; i++)
//	{
//		if (!(indexes[i] < dimensions[i]))
//		{
//			cout << "Invalid indexes" << endl;
//			return false;
//		}
//	}
//	
//	int index = 0;
//	if (dim_size == 1)
//	{
//		index = indexes[0];
//		for (int i = index; i < lin_size - 1; i++)
//			linearArray[i] = linearArray[i + 1];
//		linearArray[lin_size - 1] = 0;
//		return true;
//	}
//
//	
//	for (int i = 0; i < dim_size; i++)
//	{
//		for (int j = i + 1; j < dim_size; j++)
//			index = index + indexes[i] * dimensions[j];
//	}
//	index = index + indexes[size - 1];
//
//	for (int i = index; i < lin_size - 1; i++)
//		linearArray[i] = linearArray[i + 1];
//	linearArray[lin_size - 1] = 0;
//	return true;
//	
//
//}
//
//template <class T>
//bool ndArray<T>::Extend()
//{
//	if (dim_size == 0 || lin_size == 0)
//		return false;
//	dimensions[0] = dimensions[0] * 2;
//	int newsize = lin_size * 2;
//	T* arr = new T[newsize];
//	for (int i = 0; i < newsize; i++)
//		arr[i] = 0;
//	for (int i = 0; i < lin_size; i++)
//		arr[i] = linearArray[i];
//	delete[]linearArray;
//	linearArray = arr;
//	lin_size = newsize;
//	return true;
//}
//
//template <class T>
//bool ndArray<T>::Shrink()
//{
//	if (dim_size == 0 || dim_size == 1 || lin_size == 0)
//		return false;
//	dimensions[0] = dimensions[0] / 2;
//	lin_size = lin_size / 2;
//	T* arr = new T[lin_size];
//	for (int i = 0; i < lin_size; i++)
//		arr[i] = linearArray[i];
//	delete[] linearArray;
//	linearArray = arr;
//	return true;
//}
//
//template <class T>
//ndArray<T>::~ndArray()
//{
//	delete[] linearArray;
//	delete[] dimensions;
//	linearArray = nullptr;
//	dimensions = nullptr;
//	lin_size = 0;
//	dim_size = 0;
//
//}
//
//template <class T>
//T& ndArray<T>::operator()(const int i, const int j)
//{
//	if (dim_size != 2 || i<0 || j<0 || i>dimensions[0] || j>dimensions[1])
//	{
//		cout << "Invalid index ";
//		return linearArray[0];
//	}
//	int index = i * dimensions[1] + j;
//	return linearArray[index];
//}
//
//template <class T>
//T& ndArray<T>::operator()(const int i, const int j, const int k)
//{
//	if (dim_size != 3 || i<0 || j<0 || k<0|| i>dimensions[0] || j>dimensions[1] || k>dimensions[2])
//	{
//		cout << "Invalid index ";
//		return linearArray[0];
//	}
//	int index = i * dimensions[1] * dimensions[2] + j * dimensions[2] + k;
//	return linearArray[index];
//}
//
//template <class T>
//T& ndArray<T>::operator()(const int i, const int j, const int k, const int l)
//{
//	if (dim_size != 4 || i<0 || j<0 || k<0 || l<0|| i>dimensions[0] || j>dimensions[1] || k>dimensions[2] || l>dimensions[3])
//	{
//		cout << "Invalid operands ";
//		return linearArray[0];
//	}
//	int index = i * dimensions[1] * dimensions[2] * dimensions[3] + j * dimensions[2] * dimensions[3] + k * dimensions[3] + l;
//
//	return linearArray[index];
//
//
//}