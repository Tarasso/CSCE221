/**************************************************************
 * File:    MaxHeap.h
 * Project: CSCE221 - Project 4
 * Author : Bryson Mrosko
 * Date   : 28-April-2020
 * Section: 221-518
 * E-mail:  kylemrosko@tamu.edu
 *
 *  This class extends the Heap class
 *  See comments for differences
 *  Note that some functions are the same as seen in Heap
 *
 *************************************************************/

#ifndef MAX_HEAP
#define MAX_HEAP

template<class T, int m_size>
class MaxHeap: public Heap<T, m_size>
{
public:

  // Constuctor, takes given heap and percolates it to become max heap
  MaxHeap(Heap<T, m_size>& origHeap)
  {
    this->m_array = origHeap.getM_Array();
    this->numPins = origHeap.getNumPins();
    this->currentMaxSize = origHeap.getCurrentMaxSize();

    // Sorting heap into max order
    for(unsigned int i = this->currentMaxSize / 2 - 1; i >= 1; i--)
    {
      PercolateDown(i);
    }
  }

  //Destructor
  ~MaxHeap()
  {
    //clearHeap();
		//delete this->m_array;
  }

  //Helper function to clear elements in heap
  void clearHeap()
	{
		while(this->numPins > 0)
			Remove();
	}

  // Contains, same as in heap
  virtual bool Contains(const T& needle) const
  {
    if(this->numPins == 0)
			return false;
		for(int i = 1; i < this->numPins; i++)
		{
			if(this->m_array[i] == needle)
				return true;
		}
		return false;
  }

  //Find, same as in heap
	virtual T* Find(const T& needle)
  {
    for(int i = 1; i < this->numPins; i++)
		{
			if(this->m_array[i] == needle)
			{
				T* ptr = &(this->m_array[i]);
				return ptr;
			}

		}
		return nullptr;
  }

  //Remove top element, same as in heap except
  //remove also percolates down the replaces element
	virtual T& Remove()
  {
    if(this->numPins == 0)
		{
			std::cout << "Cannot remove empty heap" << std::endl;
			// throw error?
		}

		T temp = this->m_array[1];
		this->m_array[1] = this->m_array[this->numPins];
		this->m_array[this->numPins] = this->m_array[0];
		this->numPins--;
		PercolateDown(1);
		return temp;
  }

  //Insert, same as in heap except
  //now percolate up the new item in the heap
	virtual void Insert(T& insertable)
  {
    if(Contains(insertable))
		{
			Find(insertable)->IncrementHits();
		}
		else
		{
			if(this->numPins == this->currentMaxSize-1)
			{
				this->resize(this->currentMaxSize * 2);

			}

			this->numPins++;
			this->m_array[this->numPins] = insertable;
			PercolateUp(this->numPins);
		}
  }

  // PercolateUp continously swaps child with parent
  // until max heap conditions are met
	virtual void PercolateUp(int index)
  {
    int parentIndex = floor(index/2);
		if( this->m_array[index].CompareTo(this->m_array[parentIndex]) > 0 && parentIndex != 0)
		{
			T temp = this->m_array[parentIndex];
			this->m_array[parentIndex] = this->m_array[index];
			this->m_array[index] = temp;
			PercolateUp(parentIndex);
		}
  }

  // PercolateDown continously swaps parent with largest child
  // until max heap conditions are met
	virtual void PercolateDown(int index)
  {
    int child;
		T temp = this->m_array[index];

		for( ; index * 2 <= this->numPins; index = child)
		{
			child = index * 2;
			if (child != this->numPins && this->m_array[child + 1].CompareTo(this->m_array[child]) > 0 )
				child++;
			if(this->m_array[child].CompareTo(temp) > 0)
				this->m_array[index] = this->m_array[child];
			else
				break;
		}
		this->m_array[index] = temp;
  }



};

#endif
