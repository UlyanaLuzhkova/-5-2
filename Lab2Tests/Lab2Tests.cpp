#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

// ќбъ€вление двух функций, которые мы планируем тестировать
void min_max(vector<int>& arr);
void average(vector<int>& arr);

TEST_CLASS(UnitTest1)
{
public:
    // ёнит-тесты дл€ функции min_max

    TEST_METHOD(TestMinMaxWithPositiveNumbers)
    {
        vector<int> arr = { 4, 8, 3, 19, 7 };
        min_max(arr);
        Assert::AreEqual(3, *min_element(arr.begin(), arr.end()));
        Assert::AreEqual(19, *max_element(arr.begin(), arr.end()));
    }

    TEST_METHOD(TestMinMaxWithEmptyArray)
    {
        vector<int> arr;
        min_max(arr); // no crash expected
    }

    TEST_METHOD(TestMinMaxWithNegativeNumbers)
    {
        vector<int> arr = { -5, -8, -3, -19, -7 };
        min_max(arr);
        Assert::AreEqual(-19, *min_element(arr.begin(), arr.end()));
        Assert::AreEqual(-3, *max_element(arr.begin(), arr.end()));
    }

    TEST_METHOD(TestMinMaxWithRepeatedValues)
    {
        vector<int> arr = { 5, 5, 5, 5, 5 };
        min_max(arr);
        Assert::AreEqual(5, *min_element(arr.begin(), arr.end()));
        Assert::AreEqual(5, *max_element(arr.begin(), arr.end()));
    }

    TEST_METHOD(TestMinMaxWithLargeArray)
    {
        vector<int> arr(1000, 5);
        min_max(arr); // checking performance
    }

    TEST_METHOD(TestMinMaxWithSortedArray)
    {
        vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        min_max(arr);
        Assert::AreEqual(1, *min_element(arr.begin(), arr.end()));
        Assert::AreEqual(9, *max_element(arr.begin(), arr.end()));
    }

    TEST_METHOD(TestMinMaxWithSingleValueArray)
    {
        vector<int> arr = { 10 };
        min_max(arr);
        Assert::AreEqual(10, *min_element(arr.begin(), arr.end()));
        Assert::AreEqual(10, *max_element(arr.begin(), arr.end()));
    }

    // ёнит-тесты дл€ функции average

    TEST_METHOD(TestAverageWithPositiveNumbers)
    {
        vector<int> arr = { 4, 8, 3, 19, 7 };
        average(arr);
        float expectedAverage = 8.2; // Replace this with the expected average
        float actualAverage = accumulate(arr.begin(), arr.end(), 0.0) / arr.size();
        Assert::AreEqual(expectedAverage, actualAverage);
    }

    TEST_METHOD(TestAverageWithEmptyArray)
    {
        vector<int> arr;
        average(arr); // no crash expected
    }

    TEST_METHOD(TestAverageWithNegativeNumbers)
    {
        vector<int> arr = { -5, -8, -3, -19, -7 };
        average(arr);
        float expectedAverage = -8.4; // Replace this with the expected average
        float actualAverage = accumulate(arr.begin(), arr.end(), 0.0) / arr.size();
        Assert::AreEqual(expectedAverage, actualAverage);
    }

    TEST_METHOD(TestAverageWithRepeatedValues)
    {
        vector<int> arr = { 5, 5, 5, 5, 5 };
        average(arr);

        for (int num : arr) {
            Assert::AreEqual(5, num);
        }
    }

    TEST_METHOD(TestAverageWithLargeArray)
    {
        vector<int> arr(1000, 5);
        average(arr); // checking performance
    }

    TEST_METHOD(TestAverageWithSortedArray)
    {
        vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        average(arr);
        float expectedAverage = 5; // Replace this with the expected average
        float actualAverage = accumulate(arr.begin(), arr.end(), 0.0) / arr.size();
        Assert::AreEqual(expectedAverage, actualAverage);
    }

    TEST_METHOD(TestAverageWithSingleValueArray)
    {
        vector<int> arr = { 10 };
        average(arr);
        for (int num : arr) {
            Assert::AreEqual(10, num);
        }
    }
};
