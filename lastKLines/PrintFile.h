
#ifndef __PRINTFILE__
#define __PRINTFILE__

#include <fstream>
#include <iostream>

class PrintFile {
  
public:
  
  PrintFile () = delete;
  
  PrintFile (std::string filename) ;
  

  
  void printKLines (int k);
  
private:
  
  std::ifstream f;

  template<typename T>
  class CircularBuffer {
  public:
    
    CircularBuffer ()=delete;
    CircularBuffer (int capacity) :_buf{new T[capacity]},_idx{0}, _capacity(capacity) {}
    
    void push (const T& item){
      _buf[(_idx++)%_capacity] = item;
    }
    
    const T& operator[] (size_t idx) const { return _buf[idx];}
    T& operator[] (size_t idx) { return _buf[idx];}
    
    ~CircularBuffer(){
      delete[]  _buf;
    }
    
    size_t lastIdx () const { return _idx;}
    
    
  private:
    T *_buf;
    int _idx;
    int _capacity;
  };
  
};

#endif //__PRINTFILE__