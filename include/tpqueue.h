// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
  private:
    T Arr[10];
    int n, k;

  public:
    TPQueue(): n(0), k(0) {}
    int Dimension() {
      return k - n;
    }
  void push(T value) {
    if (Dimension() >= size) {
      throw std::string("Full!");
    } else {
      int totaliser = k - 1;
      while (totaliser >= n && value.prior > Arr[totaliser % size].prior) {
        Arr[(totaliser + 1) % size] = Arr[totaliser % size];
        totaliser--;
      }
      Arr[(totaliser + 1) % size] = value;
      k++;
    }
  }
  T pop() {
    if (n == k) {
      throw std::string("Empty!");
    } else {
      return Arr[(n++) % size];
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
