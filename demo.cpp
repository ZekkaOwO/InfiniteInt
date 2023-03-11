/**
 * Cpp file that contains main function
 * Name: Zhangfan Li
 * WisID: 9080148449
 * NetID: zli854
 **/
#include "InfiniteInt.h"
using namespace std;

// call all functions to test
int main() {
  long testa = 412;
  long testb = 400;
  InfiniteInt first = InfiniteInt(testa);
  InfiniteInt second = InfiniteInt(testb);
  cout << "First InfiniteInt: " << first << endl;
  cout << "Second InfiniteInt: " << second << endl;
  InfiniteInt third = first + second;
  InfiniteInt fourth = first - second;
  InfiniteInt fifth = InfiniteInt(413);
  InfiniteInt sixth = InfiniteInt(414);
  InfiniteInt seventh = InfiniteInt(399);
  InfiniteInt eighth = InfiniteInt(398);

  if (second > first && second >= first) {
    cout << "\"<\" and \"<=\" are incorrent." << endl;
  }

  if (first < second && first <= second) {
    cout << "\">\" and \">=\" are incorrect." << endl;
  }

  if (first == second) {
    cout << "\"==\" is incorrect." << endl;
  }

  if (!(first != second)) {
    cout << "\"!=\" is incorrect." << endl;
  }

  if (first + second != third) {
    cout << "\"+\" is incorrect." << endl;
  }

  if (first - second != fourth) {
    cout << "\"-\" is incorrect." << endl;
  }

  first -= second;

  if (first != fourth) {
    cout << "\"-=\" is incorrect." << endl;
  }

  InfiniteInt temp = InfiniteInt(testa);
  first += second;

  if (first != temp) {
    cout << "\"+=\" is incorrect." << endl;
  }

  ++first;
  if (first != fifth) {
    cout << "pre \"++\" is incorrect." << endl;
  }
  first++;
  if (first != sixth) {
    cout << "post \"++\" is incorrect." << endl;
  }

  --second;
  if (second != seventh) {
    cout << "pre \"--\" is incorrect." << endl;
  }
  second--;
  if (second != eighth) {
    cout << "post \"--\" is incorrect." << endl;
  }

  

}