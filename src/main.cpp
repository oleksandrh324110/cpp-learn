#include <iostream>

#include "math/vector.h"
#include "math/matrix.h"

int main() {
  {
    vector<float, 4> v = { -1, 2, 3, 4 }; v.print();
    v = v * 2; v.print();
    v = v + vector<float, 4>({ 1, 2, 3, 4 }); v.print();
    v.normalize().print();
    double normalizedDotProduct = v.normalize().dot((vector<float, 4>({ -1, 2, 0, 0 })).normalize());
    std::cout << "normalized dot product: " << normalizedDotProduct << '\n';
  }

  {
    matrix<int, 2, 3> m1 = { {1, 2, 3}, {4, 5, 6} };
    matrix<int, 3, 2> m2 = { {1, 2}, {3, 4}, {5, 6} };

    auto m3 = m1 * m2;

    m3.print();

    matrix<int, 2, 2> m4 = { {1, 2}, {3,4} };
    std::cout << m4.det() << '\n';
  }
}
