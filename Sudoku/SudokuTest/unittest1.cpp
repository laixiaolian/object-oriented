#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\sudoku\SudokuGenerate.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SudokuTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			SudokuGenerate sudoku;
			//将数独第一行第一列设为3
			sudoku.set(3);

			
			//第一行第三列填入数字3，此时应该return false;
			bool test1 = sudoku.IsRightPlace(3, 0, 2);

			//第三行第一列填入数字3，此时应该return false;
			bool test2 = sudoku.IsRightPlace(3, 2, 0);

			//第二行第二列填入数字3，此时3*3九宫格中有重复数字，return false;
			bool test3 = sudoku.IsRightPlace(3, 1, 1);

			//在第二行第七列填入数字3，与三个判断条件都不冲突，return true;
			bool test4 = sudoku.IsRightPlace(3, 1, 6);
			
			Assert::IsTrue(test1 == false);
			Assert::IsTrue(test2 == false);
			Assert::IsTrue(test3 == false);
			Assert::IsTrue(test4 == true);
		}

	};
}