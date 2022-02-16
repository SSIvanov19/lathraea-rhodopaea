#include "pch.h"
#include "CppUnitTest.h"
#include <back-end/validations.h>
#include <back-end/validations.cpp>

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
			//Arrange
			Validations v;
			std::string email = "mzilcheva19@codingburgas.bg";

			// Act
			bool isEmailValid = v.isEmailValid(email);

			// Assert
			Assert::AreEqual(true, isEmailValid);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ExpectToPassPasswordValidation)
			TEST_OWNER(L"MZIlcheva19")
			TEST_PRIORITY("Medium")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ExpectToPassPasswordValidation)
		{
			//Arrange
			Validations v;
			std::string password = "MZIlcheva143";

			// Act
			bool isPasswordValid = v.isPassValid(password);

			// Assert
			Assert::AreEqual(true, isPasswordValid);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ExpectToPassUsernameValidation)
			TEST_OWNER(L"MZIlcheva19")
			TEST_PRIORITY("Medium")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ExpectToPassUsernameValidation)
		{
			//Arrange
			Validations v;
			std::string username = "Mariya143";

			// Act
			bool isUsernameValid = v.isPassValid(username);

			// Assert
			Assert::AreEqual(true, isUsernameValid);
		}
	};
}
