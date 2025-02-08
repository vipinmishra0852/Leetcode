
class NumberContainers {
public:
    map<int,int>m;
    map<int,set<int>>ind; 
    NumberContainers() {
       
    }
    
    void change(int index, int number) 
    {
      if(m.find(index) != m.end())
      {
        int old = m[index];
        ind[old].erase(index);
        if(ind[old].empty())
        {
            ind.erase(old);
        }
      }
      m[index] = number;
      ind[number].insert(index);
    }
    
    int find(int number) 
    {
      if(ind.find(number) != ind.end() && !ind[number].empty())
      {
        return *ind[number].begin();
      } 
      return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */