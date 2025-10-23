
#ifndef Tree_hpp
#define Tree_hpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

template <typename T>
class Heap
{
private:
    typedef std::vector<T> heap;
    typedef typename heap::size_type heapIndex;

    heap tree;

    heapIndex getLeftChildPosition(heapIndex i)
    {
        return (2 * i);
    }

    heapIndex getRightChildPosition(heapIndex i)
    {
        return (2 * i) + 1;
    }

    heapIndex getParentPosition(heapIndex i)
    {
        return (heapIndex)std::floor(i / 2);
    }

    heapIndex heapifyDown(heapIndex index)
    {
        heapIndex leftChildIndex = this->getLeftChildPosition(index);
        T leftChild = (leftChildIndex < this->tree.size()) ? this->tree.at(leftChildIndex) : std::numeric_limits<T>::max();

        heapIndex rightChildIndex = this->getRightChildPosition(index);
        T rightChild = (rightChildIndex < this->tree.size()) ? this->tree.at(rightChildIndex) : std::numeric_limits<T>::max();

        heapIndex minValueChildIndex = (leftChild < rightChild) ? leftChildIndex : rightChildIndex;

        if (minValueChildIndex < this->tree.size())
        {
            if (this->tree.at(minValueChildIndex) < this->tree.at(index))
            {
                std::cout << "Swap positions " << minValueChildIndex << "(" << this->tree.at(minValueChildIndex) << ") and" << index << "(" << this->tree.at(index) << ")." << std::endl;
                std::swap(this->tree.at(minValueChildIndex), this->tree.at(index));
                this->heapifyDown(minValueChildIndex);
                return minValueChildIndex;
            }
        }
        return this->tree.size();
    }

public:
    Heap()
    {
        this->tree.push_back((T)NULL);
    }

    Heap(std::vector<T> tree)
    {
        tree.insert(tree.begin(), (T) NULL);
        this->heapify(tree);
    }

    bool isHeapEmpty()
    {
        return this->tree.size() <= 1;
    }

    void printHeap()
    {
        this->printVector(this->tree);
    }

    void heapify(std::vector<T> tree)
    {
        this->tree = tree;
        for (heapIndex index = this->tree.size() - 1; index >= 1; index--)
        {
            this->heapifyDown(index);
        }
    }

    void printVector(std::vector<T> numVector)
    {
        std::cout << "[ ";
        for (heapIndex index = 0; index < numVector.size(); index++)
        {
            if (numVector.at(index) != (T)NULL)
            {
                std::cout << numVector.at(index);
                if (index != (numVector.size() - 1))
                {
                    std::cout << ", ";
                }
            }
        }
        std::cout << " ]" << std::endl;
    }

    T popTop()
    {
        if (this->isHeapEmpty())
        {
            return std::numeric_limits<T>::min();
        }
        const heapIndex ROOT_INDEX = 1;

        T topElement = this->tree.at(ROOT_INDEX);
        std::cout << "Removed top element: " << topElement << std::endl;
        std::cout << "Placing index: " << (this->tree.size() - 1) << "(" << this->tree.at(this->tree.size() - 1) << ") to the top" << std::endl;
        this->tree.at(ROOT_INDEX) = this->tree.at(this->tree.size() - 1);
        this->tree.pop_back();

        std::cout << "Checking the if the heap condition is valid after popping out top of heap: " << topElement << std::endl;
        heapIndex parent = ROOT_INDEX;
        this->heapifyDown(parent);
        return topElement;
    }

    std::vector<T> heapSort(std::vector<T> numList)
    {
        Heap<T> tree1;
        for (typename std::vector<T>::size_type index = 0; index < numList.size(); index++)
        {
            tree1.insert(numList[index]);
        }

        std::vector<T> sortedNumList;
        while (!tree1.isHeapEmpty())
        {
            sortedNumList.push_back(tree1.popTop());
            this->printVector(sortedNumList);
        }
        return sortedNumList;
    }


    void insert(T element)
    {
        this->tree.push_back(element);
        
        heapIndex index = this->tree.size() - 1;
        
        while (index > 1) 
        {
            heapIndex parent = this->getParentPosition(index);
            
            if (this->tree.at(index) < this->tree.at(parent))
            {
                std::swap(this->tree.at(index), this->tree.at(parent));
                index = parent;
            }
            else
            {
                break; 
            }
        }
    }

    void remove(T value)
    {
        heapIndex indexToRemove = this->tree.size(); 
        
        for (heapIndex i = 1; i < this->tree.size(); i++)
        {
            if (this->tree.at(i) == value)
            {
                indexToRemove = i;
                break;
            }
        }
        
        if (indexToRemove >= this->tree.size())
        {
            return;
        }
        
        this->tree.at(indexToRemove) = this->tree.at(this->tree.size() - 1);
        this->tree.pop_back();
        
        if (indexToRemove >= this->tree.size())
        {
            return;
        }
        
        heapIndex afterDown = this->heapifyDown(indexToRemove);
        
        if (afterDown == this->tree.size() || afterDown == indexToRemove)
        {
            heapIndex index = indexToRemove;
            while (index > 1)
            {
                heapIndex parent = this->getParentPosition(index);
                if (this->tree.at(index) < this->tree.at(parent))
                {
                    std::swap(this->tree.at(index), this->tree.at(parent));
                    index = parent;
                }
                else
                {
                    break;
                }
            }
        }
    }


    T getMin()
    {
        if (this->isHeapEmpty())
        {
            return std::numeric_limits<T>::min();
        }
        
        return this->tree.at(1);
    }
};

#endif 