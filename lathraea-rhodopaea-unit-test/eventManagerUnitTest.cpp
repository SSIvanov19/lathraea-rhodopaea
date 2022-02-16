#include "pch.h"
#include "CppUnitTest.h"
#include <back-end/eventManager.h>
#include <back-end/eventManager.cpp>
#include <back-end/datetimeManager.cpp>
#include <back-end/logs.cpp>
#include <external/strptime.cpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace eventManagementUnitTests
{
	TEST_CLASS(eventManagementUnitTests)
	{
	public:

		BEGIN_TEST_METHOD_ATTRIBUTE(ExpectToReturnConfirmationOfApprovmentOfEvent)
			TEST_OWNER(L"MZIlcheva19")
			TEST_PRIORITY("Medium")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ExpectToReturnConfirmationOfApprovmentOfEvent)
		{
			EventManager eventManager;

			//Arrange
			eventManager.addUprisingEvent(
				"April Uprising",
				{ "20 apr 1876", "15 may 1876" },
				{ 30, 76 },
				{ "Stefan Stambolov", "Ilarion Dragostinov", "Stoyan Zaimov", "Zahari Stoyanov" },
				false,
				200
			);


			// Act
			eventManager.approveEvent("April Uprising");

			// Assert
			Assert::AreEqual(true, eventManager.getEventWithName("April Uprising")->isAdminApproved);
		}
	};
}