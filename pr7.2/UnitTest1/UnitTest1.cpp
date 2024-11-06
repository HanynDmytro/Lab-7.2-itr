#include "pch.h"
#include "CppUnitTest.h"
#include "../pr7.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int n = 4, k = 3;
            int** a = new int* [n];
            for (int i = 0; i < n; ++i)
                a[i] = new int[k];

            // Заповнення матриці
            // Парні рядки: [8, 1, 3], [15, 4, 7]
            a[0][0] = 8; a[0][1] = 1; a[0][2] = 3;
            a[1][0] = 15; a[1][1] = 4; a[1][2] = 7;
            a[2][0] = 6; a[2][1] = 3; a[2][2] = 12;
            a[3][0] = 10; a[3][1] = 20; a[3][2] = 5;

            int maxSum = 0;
            bool result = MaxSum(a, n, k, maxSum);

            // Очікуємо максимуми 15 для другого рядка і 20 для четвертого рядка
            Assert::IsTrue(result);
            Assert::AreEqual(35, maxSum);

            // Звільняємо пам'ять
            for (int i = 0; i < n; ++i)
                delete[] a[i];
            delete[] a;
		}
	};
}
