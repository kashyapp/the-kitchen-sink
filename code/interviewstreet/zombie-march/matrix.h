#include <valarray>
#include <iomanip>
#include <ostream>
#include <cassert>

#define FOR(I, N) for(int I = 0; I < N; ++I)

namespace kashyap {
  template<typename T>
  class matrix {
    std::valarray<T> el;
    int size;

    public:
    matrix(int n) : el(n*n), size(n) { }

    T& operator() (int i, int j) {
      return el[size * i + j];
    }

    T operator() (int i, int j) const {
      return el[size * i + j];
    }

    matrix<T> operator * (const matrix<T>&) const;
    std::valarray<T> operator * (const std::valarray<T>&) const;
    matrix<T> operator ^ (unsigned int) const;

    template<typename R>
    friend std::ostream& operator<< (std::ostream&, const matrix<R> &);

    private:

  };


  template<typename T>
  matrix<T> matrix<T>::operator* (const matrix<T>& that) const {
    assert(size == that.size);

    matrix<T> result(size);

    FOR(i, size) {
      FOR(j, size) {

        result(i, j) = 
          (el[std::slice(size * i, size, 1)] 
           * that.el[std::slice(j, size, size)])
          .sum();

      }
    }

    return result;
  }

  template<typename T>
  std::valarray<T> matrix<T>::operator* (const std::valarray<T> &vec) const {
    std::valarray<T> result(size);
    FOR(i, size) {
      result[i] = (vec * el[std::slice(i * size, size, 1)]).sum();
    }
    return result;
  }

  template<typename T>
  matrix<T> matrix<T>::operator^ (unsigned int exp) const {
    matrix<T> result(size);
    FOR(i, size) {
      result(i, i) = 1;
    }

    const unsigned int mask = 1;
    for(int bit = 0; exp > 0; exp >>= 1, bit++) {
      if (exp & mask) {
        matrix<T> temp = *this;
        FOR(i, bit) {
          temp = temp * temp;
        }
        result = result * temp;
      }
    }

    return result;
  }

  template<typename T>
  std::ostream& operator<< (std::ostream& o, const matrix<T> &m) {
    FOR(i, m.size) {
      FOR(j, m.size) {
        o << std::setprecision(2) << std::setw(4) << m(i, j) << " ";
      }
      o << std::endl;
    }
    return o;
  }
}

#undef FOR
