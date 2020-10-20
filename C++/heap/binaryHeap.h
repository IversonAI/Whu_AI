#pragma once
#include<iostream>
#include <limits.h>
using namespace std;
template<typename T>

class Heap
{
public:
	//define key-value pair of heap struct
	struct elem
	{
	public:
		int key;
		T data;
	};
private:
	int m_size;//current heap size
	int m_max;//max heap size
	elem *m_heap;//key value pairs

public:
	Heap(int max) {
		m_size = 0;
		m_max = max;
		m_heap = new elem[m_max];
	};
	~Heap() {
		delete[]m_heap;
	};
private:
	Heap(const Heap &);
	Heap& operator=(const Heap&);

public:
	//for loop through the kvs ????
	inline int count() const { return m_size; }

	//insert a key->value pair into heap
	void push(int key, const T&data)
	{
		//heap full,just return
		if (m_size == m_max) return;
		//put in the back,and try move upward the heap
		m_heap[m_size].key = key;
		m_heap[m_size].data = data;
		up(m_size);
		m_size++;

	}

	//emptiness test
	inline bool is_empty()const { return (m_size == 0) ? true : false; }

	//clear the heap
	inline void clear() { m_size = 0; }

	//check 
	bool contains(const T&data)
	{
		for (int i = 0; i < m_size; i++)
		{
			if (m_heap[i].data == data)
				return true;
		}
		return false;
	}

	//pop the min element
	elem pop()
	{
		int n = m_size - 1;
		swap(m_heap[0], m_heap[n]);
		down(0, n);
		m_size--;
		return m_heap[m_size];
	}

	//remove the given data
	bool remove(const T&data)
	{
		for (int i = 0; i < m_size; i++)//loop finding
		{
			if (m_heap[i].data == data)
			{
				int n = m_size - 1;
				if (n != i)
				{
					swap(m_heap[i], m_heap[n]);
					down(i, m_size);
					up(i);
				}
				m_size--;
				return true;
			}
		}
		return false;
	}

	void up(int j)
	{
		for (;;)
		{
			int i = (j - 1) / 2;//parent
			if (i == j || !less(j, i))
				break;
			swap(m_heap[i], m_heap[j]);
			j = i;
		}
	}

	void down(int i, int n)
	{
		for (;;)
		{
			int j1 = 2 * i + 1;
			if (j1 >= n || j1 < 0)
				break;

			int j = j1;
			int j2 = j1 + j;
			if (j2 < n && !less(j1, j2))
				j = j2;
			if (!less(j, i))
				break;
			swap(m_heap[i], m_heap[j]);
			i = j;
		}
	}

	void print_heap()
	{
		for (int i = 0; i < m_size; i++)
			cout << "key:" << m_heap[i].key << "  value:" << m_heap[i].data << endl;
	}

	bool less(int i, int j)
	{
		return m_heap[i].key < m_heap[j].key;
	}
};