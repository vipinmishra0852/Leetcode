class MyCircularDeque {
public:
    vector<int>dq;
    int f=-1;
    int r=-1;
    int curr=0;
    int size=0;;
    MyCircularDeque(int k) {
        vector<int>arr(k);
        dq=arr;
        size=k;
    }
    
    bool insertFront(int value) 
    {
      if(isFull()) return false;
      if(f==-1 && r==-1) 
      {
        f=r=0;
        dq[f]=value;
        
      }
      else if(f==0)
      {
        f=size-1;
        dq[f]=value;
      }
      else
      { f=f-1;
        dq[f]=value;
      }
      curr++;
      return true;
    }
    
    bool insertLast(int value) 
    {
       if(isFull()) return false;
      if(f==-1 && r==-1) 
      {
        f=r=0;
        dq[r]=value;
        
      }
      else if(r==size-1)
      {
        r=0;
        dq[r]=value;
      }
      else
      {
         r=r+1;
        dq[r]=value;
      }
      curr++;
      return true;
    }
    
       
    bool deleteFront() {
        if (isEmpty()) return false;
        if (f == r) {
            f = r = -1;
        } else if (f == size - 1) {
            f = 0;
        } else {
            f++;
        }
        curr--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        if (f == r) {
            f = r = -1;
        } else if (r == 0) {
            r = size - 1;
        } else {
            r--;
        }
        curr--;
        return true;
    }
    
    int getFront() 
    { if(isEmpty()) return -1;
      return dq[f];
        
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return dq[r];
    }
    
    bool isEmpty()
     {
        return (curr==0);
    }
    
    bool isFull()
     {
       return (curr==size); 
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */