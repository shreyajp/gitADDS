
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