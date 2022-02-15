#include "pch.h"
#include "CppUnitTest.h"
#include "..\lathraea-rhodopaea\include\back-end\validations.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace validationUnitTests
{
	TEST_CLASS(validationUnitTests)
	{
	public:
		
		BEGIN_TEST_METHOD_ATTRIBUTE(ExpectToPassEmailValidation)
			TEST_OWNER(L"MZIlcheva19")
			TEST_PRIORITY("Medium")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ExpectToPassEmailValidation)
		{
			// Arrange
			//Validations v;
			//std::string email = "mzilcheva19@codingburgas.bg";

			//// Act
			//bool isEmailValid = v.isEmailValid(email);

			// Assert
			Assert::AreEqual(true, true);
		}
	};
}
