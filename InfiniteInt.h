/**
 * This is a class which can represent an "infinite"
 * length of number, and its operations
 * Name: Zhangfan Li
 * WisID: 9080148449
 * NetID: zli854
 **/
#ifndef INFINITEINT_H
#define INFINITEINT_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>

class InfiniteInt {
 private:
  std::vector<unsigned int>*digits = new std::vector<unsigned int>;
  const unsigned int radix = 10;

  static std::vector<unsigned int>*count(long val);
  static std::vector<unsigned int>*cpy(std::vector<unsigned int>*);
 public:
  int main();
  std::vector<unsigned int>* getDigits();

  InfiniteInt();
  InfiniteInt(unsigned long long val);
  explicit InfiniteInt(std::vector<unsigned int>* new_digits);
  InfiniteInt(const InfiniteInt &obj);
  InfiniteInt& operator=(const InfiniteInt &);
  ~InfiniteInt();

  friend std::ostream& operator<< (std::ostream&, const InfiniteInt&);
  friend std::istream& operator>> (std::istream&, InfiniteInt&);
  bool operator< (const InfiniteInt&);
  bool operator> (const InfiniteInt&);
  bool operator<= (const InfiniteInt&);
  bool operator>= (const InfiniteInt&);
  bool operator== (const InfiniteInt&);
  bool operator!= (const InfiniteInt&);
  InfiniteInt operator+ (const InfiniteInt&);
  InfiniteInt operator- (const InfiniteInt&);
  InfiniteInt operator+= (const InfiniteInt&);
  InfiniteInt operator-= (const InfiniteInt&);
  InfiniteInt& operator++ (); // prefix
  InfiniteInt& operator-- ();
  InfiniteInt operator++ (int); // postfix
  InfiniteInt operator-- (int);

};



#endif
