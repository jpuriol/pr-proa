#include "sort.h"
#include "gtest/gtest.h"
#include<vector>

namespace 
{
  TEST(Sort, CountSort) 
  {
    std::vector<int> vectorToSort {6, 3, 1, 3, 2, 4, 0, 1,10,0};
    const std::vector<int> expectedSort {0,0, 1, 1, 2, 3, 3, 4, 6,10};
    const int biggestIntOnVector = 10;

    CountSort(vectorToSort, biggestIntOnVector);

    EXPECT_EQ(expectedSort, vectorToSort);
  }

  TEST(Sort, RadixSortVector)
  {
    std::vector<int> vectorToSort {13, 5, 1, 16, 24, 21, 10, 84, 0, 16};
    const std::vector<int> expectedSort {0, 1, 5, 10, 13, 16, 16, 21, 24, 84};
    const int biggestIntOnVector = 84;

    RadixSortVector(vectorToSort, biggestIntOnVector);

    EXPECT_EQ(expectedSort, vectorToSort);
  }
  
  TEST(Sort, RadixSortList)
  {
    std::list<int> listToSort {13, 5, 1, 16, 24, 21, 10, 84, 0, 16};
    const std::list<int> expectedSort {0, 1, 5, 10, 13, 16, 16, 21, 24, 84};
    const int biggestIntOnList = 84;

    RadixSortList(listToSort, biggestIntOnList);

    EXPECT_EQ(expectedSort, listToSort);
  }
}  // namespace
