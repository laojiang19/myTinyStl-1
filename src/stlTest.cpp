#include "__pool_alloc.h"
#include "__simple_alloc.h"
#include "__uninitialized.h"
#include "stl_vector.h"
#include <vector>
using namespace std;

int main(int argv, char ** argc) {
  char *p = (char *)XX::alloc::allocate(6);
  for(int i = 0; i < 5; ++i) {
    *(p + i) = 'a';
  }
  p[5] = '\0';
  cout << p << endl;
  XX::alloc::deallocate(p, 7);

  char *p2 = (char *)XX::alloc::allocate(206);
  for(int i = 0; i < 5; ++i) {
    *(p2 + i) = 'b';
  }
  p2[5] = '\0';
  cout << p2 << endl;
  XX::alloc::deallocate(p2, 206);

  int coo[10] = {1,2,3,4,5,6,7,8,9,0};
  XX::allocator<int> a1;   // int 的默认分配器
  int* a = a1.allocate(10);  // 一个 int 的空间
  // a1.construct(a, 7);       // 构造 int
  XX::uninitialized_copy(coo, coo + 10, a);
  for(int i = 0; i < 10; ++i) {
    cout << a[i] << endl;
  }
  // std::cout << a[0] << std::endl;
  // a1.destroy(a);
  a1.deallocate(a, 10);      // 解分配一个 int 的空间
 
  // vector<int> vec(10);
  // XX::uninitialized_copy(coo, coo + 10, &vec[0]);
  XX::vector<int> vec(10, 1);
  vec.insert(vec.begin() + 5, 20);
  vec.push_back(202);
  vec.insert(vec.begin() + 1, 10, 6);
  for(auto p: vec) {
    cout << p << endl;
  }

  XX::vector<int> stlVec(10);
  return 0;
} 