/**
 * This is a class which can represent an "infinite"
 * length of number, and its operations
 * Name: Zhangfan Li
 * WisID: 9080148449
 * NetID: zli854
 **/
#include "InfiniteInt.h"
using namespace std;

vector<unsigned int>* InfiniteInt::count(long val) {
  vector<unsigned int>* count = new vector<unsigned int>;

  if (val <= 0) {
    count->push_back(0);
    return count;
  }

  while (val != 0) {
    int temp = val % 10;
    count->push_back(temp);
    val = val / 10;
  }

  reverse(count->begin(), count->end());
  return count;
}

vector<unsigned int>* InfiniteInt::cpy(vector<unsigned int>* digit) {
  vector<unsigned int>* ret = new vector<unsigned int>;
  for (size_t i = 0; i < digit->size(); ++i) {
    ret->push_back(digit->at(i));
  }
  return ret;
}

vector<unsigned int>* InfiniteInt::getDigits() { return digits; }

InfiniteInt::InfiniteInt() : digits(), radix(10) {
  vector<unsigned int>* ret = new std::vector<unsigned int>;
  ret->push_back(0);
  digits = ret;
};

InfiniteInt::InfiniteInt(unsigned long long val)
    : digits(count(val)), radix(10){};

InfiniteInt::InfiniteInt(vector<unsigned int>* new_digits)
    : digits(new_digits){};

InfiniteInt::InfiniteInt(const InfiniteInt& obj)
    : digits(cpy(obj.digits)), radix(obj.radix){};

InfiniteInt::~InfiniteInt() { delete (digits); }

InfiniteInt& InfiniteInt::operator=(const InfiniteInt& infinite) {
  if (this != &infinite) {
    delete this->digits;
    this->digits = new vector<unsigned int>;
    for (size_t i = 0; i < infinite.digits->size(); ++i) {
      this->digits->push_back(infinite.digits->at(i));
    }
  }
  return *this;
}

ostream& operator<<(ostream& out, const InfiniteInt& infinite) {
  for (size_t i = 0; i < infinite.digits->size(); ++i) {
    out << infinite.digits->at(i);
  }
  return out;
}

istream& operator>>(istream& in, InfiniteInt& infinite) {
  string num;
  in >> num;
  for (size_t i = 0; i < num.size(); ++i) {
    if ((int)num.at(i) < 48 || (int)num.at(i) > 57) {
      cout << "Invalid entry" << endl;
      return in;
    }
  }
  long n = static_cast<long>(atoi(num.c_str()));
  infinite = InfiniteInt(n);
  return in;
}

bool InfiniteInt::operator<(const InfiniteInt& infinite) {
  if (this->digits->size() < infinite.digits->size()) {
    return true;
  } else if (this->digits->size() > infinite.digits->size()) {
    return false;
  }
  for (size_t i = 0; i < digits->size(); ++i) {
    if (digits->at(i) < infinite.digits->at(i)) {
      return true;
    } else if (digits->at(i) > infinite.digits->at(i)) {
      return false;
    }
  }
  return false;
}

bool InfiniteInt::operator>(const InfiniteInt& infinite) {
  if (this->digits->size() > infinite.digits->size()) {
    return true;
  } else if (this->digits->size() < infinite.digits->size()) {
    return false;
  }
  for (size_t i = 0; i < digits->size(); ++i) {
    if (digits->at(i) > infinite.digits->at(i)) {
      return true;
    } else if (digits->at(i) < infinite.digits->at(i)) {
      return false;
    }
  }
  return false;
}

bool InfiniteInt::operator<=(const InfiniteInt& infinite) {
  if (this->digits->size() < infinite.digits->size()) {
    return true;
  } else if (this->digits->size() > infinite.digits->size()) {
    return false;
  }
  for (size_t i = 0; i < digits->size(); ++i) {
    if (digits->at(i) < infinite.digits->at(i)) {
      return true;
    } else if (digits->at(i) > infinite.digits->at(i)) {
      return false;
    }
  }
  return true;
}

bool InfiniteInt::operator>=(const InfiniteInt& infinite) {
  if (this->digits->size() > infinite.digits->size()) {
    return true;
  } else if (this->digits->size() < infinite.digits->size()) {
    return false;
  }
  for (size_t i = 0; i < digits->size(); ++i) {
    if (digits->at(i) > infinite.digits->at(i)) {
      return true;
    } else if (digits->at(i) < infinite.digits->at(i)) {
      return false;
    }
  }
  return true;
}

bool InfiniteInt::operator==(const InfiniteInt& infinite) {
  if (this->digits->size() != infinite.digits->size()) {
    return false;
  }
  for (size_t i = 0; i < digits->size(); ++i) {
    if (digits->at(i) != infinite.digits->at(i)) {
      return false;
    }
  }
  return true;
}

bool InfiniteInt::operator!=(const InfiniteInt& infinite) {
  if (this->digits->size() != infinite.digits->size()) {
    return true;
  }
  for (size_t i = 0; i < digits->size(); ++i) {
    if (digits->at(i) == infinite.digits->at(i)) {
      continue;
    } else {
      return true;
    }
  }
  return false;
}

InfiniteInt InfiniteInt::operator+(const InfiniteInt& infinite) {
  int a;    // for nums in the first
  int b;    // for nums in the second
  int num;  // for storing the result
  bool up = false;
  InfiniteInt ret = InfiniteInt();
  ret.digits->clear();

  auto sizeA = this->digits->size();
  auto sizeB = infinite.digits->size();
  auto& v1 = (sizeA < sizeB) ? infinite : *this;
  auto& v2 = (sizeA < sizeB) ? *this : infinite;
  auto maxSize = v1.digits->size();
  auto minSize = v2.digits->size();

  if (*this == infinite) {
    reverse(v1.digits->begin(), v1.digits->end());
  } else {
    reverse(v1.digits->begin(), v1.digits->end());
    reverse(v2.digits->begin(), v2.digits->end());
  }
  for (size_t i = 0; i < minSize; ++i) {
    a = v1.digits->at(i);
    b = v2.digits->at(i);

    num = a + b;

    if (up) {
      num = num + 1;
    }

    if (static_cast<unsigned int>(num) >= ret.radix) {
      up = true;
      num = num - ret.radix;
      ret.digits->push_back(num);
    } else {
      up = false;
      ret.digits->push_back(num);
    }
  }

  for (size_t i = minSize; i < maxSize; ++i) {
    if (up) {
      num = v1.digits->at(i) + 1;
    } else {
      num = v1.digits->at(i);
    }
    if (static_cast<unsigned int>(num) >= radix) {
      num = num - radix;
    } else {
      up = false;
    }
    ret.digits->push_back(num);
  }

  if (*this == infinite) {
    reverse(v1.digits->begin(), v1.digits->end());
  } else {
    reverse(v1.digits->begin(), v1.digits->end());
    reverse(v2.digits->begin(), v2.digits->end());
  }

  if (up) {
    ret.digits->push_back(1);
  }

  reverse(ret.digits->begin(), ret.digits->end());
  return ret;
}

InfiniteInt InfiniteInt::operator-(const InfiniteInt& infinite) {
  int a;    // for nums in the first
  int b;    // for nums in the second
  int num;  // for storing the result
  bool down = false;
  InfiniteInt ret = InfiniteInt();
  ret.digits->clear();
  int n;
  int counta = digits->size() - 1;
  int countb = infinite.digits->size() - 1;

  if (digits->size() < infinite.digits->size()) {
    ret.digits->push_back(0);
    return ret;
  } else {
    n = infinite.digits->size();
  }

  for (int i = 0; i < n; ++i, --counta, --countb) {
    a = digits->at(counta);
    b = infinite.digits->at(countb);

    if (down) {
      num = (a - 1) - b;
    } else {
      num = a - b;
    }

    if (num < 0) {
      down = true;
      num = num + ret.radix;
      ret.digits->push_back(num);
    } else {
      down = false;
      ret.digits->push_back(num);
    }
  }

  if (counta >= 0) {
    while (counta >= 0) {
      if (down) {
        num = digits->at(counta) - 1;
        if (num < 0) {
          num = num + ret.radix;
          ret.digits->push_back(num);
          counta--;
        } else {
          ret.digits->push_back(num);
          counta--;
          down = false;
        }
      } else {
        num = digits->at(counta);
        ret.digits->push_back(num);
        counta--;
      }
    }
  }

  if (countb >= 0) {
    while (countb >= 0) {
      if (down) {
        num = digits->at(counta) - 1;
        if (num < 0) {
          num = num + ret.radix;
          ret.digits->push_back(num);
          counta--;
        } else {
          ret.digits->push_back(num);
          counta--;
          down = false;
        }
      } else {
        num = digits->at(countb);
        ret.digits->push_back(num);
        countb--;
      }
    }
  }

  // delete the 0 at the beginning
  int count = ret.digits->size() - 1;
  while (ret.digits->at(count) == 0 && count > 0) {
    ret.digits->pop_back();
    count--;
  }
  reverse(ret.digits->begin(), ret.digits->end());
  if (ret.digits->at(0) < 0 || down) {
    ret.digits->clear();
    ret.digits->push_back(0);
  }
  return ret;
}

InfiniteInt InfiniteInt::operator+=(const InfiniteInt& infinite) {
  *this = *this + infinite;
  return *this;
}

InfiniteInt InfiniteInt::operator-=(const InfiniteInt& infinite) {
  *this = *this - infinite;
  return *this;
}

// pre
InfiniteInt& InfiniteInt::operator++() {
  bool up;
  int n = this->digits->size() - 1;
  int last = this->digits->at(n);
  last = last + 1;

  this->digits->at(n) = last;

  if (static_cast<unsigned int>(last) >= this->radix) {
    up = true;
  } else {
    up = false;
  }

  while (up) {
    last = last - radix;
    this->digits->at(n) = last;
    n--;
    if (n < 0) {
      this->digits->push_back(1);
      reverse(this->digits->begin(), this->digits->end());
      break;
    }
    this->digits->at(n)++;
    last = this->digits->at(n);
    if (this->digits->at(n) < this->radix) {
      up = false;
    }
  }

  return *this;
}

InfiniteInt& InfiniteInt::operator--() {
  if (this->digits->size() <= 0) {
    this->digits->push_back(0);
    return *this;
  }

  InfiniteInt cmp = InfiniteInt();
  if (*this <= cmp) {
    this->digits->clear();
    this->digits->push_back(0);
    return *this;
  }

  bool down;
  int n = this->digits->size() - 1;
  int last = this->digits->at(n);
  last = last - 1;

  this->digits->at(n) = last;

  if (last < 0) {
    down = true;
  } else {
    down = false;
  }

  while (down && n > 0) {
    last = last + radix;
    this->digits->at(n) = last;
    n--;
    this->digits->at(n)--;
    last = this->digits->at(n);
    if (last > 0) {
      down = false;
    }
  }

  if (this->digits->at(0) == 0) {
    reverse(this->digits->begin(), this->digits->end());
    while (this->digits->size() > 1 && this->digits->back() == 0) {
      this->digits->pop_back();
    }
    reverse(this->digits->begin(), this->digits->end());
  }

  return *this;
}

InfiniteInt InfiniteInt::operator++(int num) {
  InfiniteInt pre = *this;
  InfiniteInt add = InfiniteInt(static_cast<long>(1));
  *this = *this + add;
  return pre;
}

InfiniteInt InfiniteInt::operator--(int num) {
  InfiniteInt pre = *this;
  InfiniteInt add = InfiniteInt(static_cast<long>(1));
  *this = *this - add;
  return pre;
}
