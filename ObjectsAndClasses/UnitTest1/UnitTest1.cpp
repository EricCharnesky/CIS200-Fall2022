#include "pch.h"
#include "CppUnitTest.h"
#include "..\ObjectsAndClasses\Cup.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethodFillOverMax)
		{
			// AAA convention

			// Arrange - setup the variables we need to test
			int expectedVolume = 200;
			Cup cup("", expectedVolume, false, false, "");

			// Act - call the code we are testing and get results
			bool actualResult = cup.fillCup(100);
			int actualVolume = cup.getCurrentVolumeOfContentsInMilliliters();

			// Assert - did we get what we expected
			Assert::AreEqual(expectedVolume, actualVolume);
			Assert::IsFalse(actualResult);

		}
	};
}
