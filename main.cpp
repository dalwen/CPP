#include "FollowPointer.hpp"
#include "ArrayElement.hpp"
#include "Node.hpp"
#include "RvalueRef.hpp"
#include "RefTest.hpp"

int main()
{
  // FollowPointer();
  // GetGrade();
  // NodeTest();
  // NodeTest1();

  RvalueRef r;
  r.RunTest();

  RefTest t;
  t.RunTest();
}
