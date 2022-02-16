#include "pch.h"
#include "CppUnitTest.h"
#include <back-end/eventManager.h>
#include <back-end/eventManager.cpp>
#include <back-end/datetimeManager.cpp>
#include <back-end/logs.cpp>
#include <back-end/encryption.cpp>
#include <back-end/encryption.h>
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

		BEGIN_TEST_METHOD_ATTRIBUTE(ExpectToRemoveSelectedEvent)
			TEST_OWNER(L"MZIlcheva19")
			TEST_PRIORITY("Medium")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ExpectToRemoveSelectedEvent)
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
			bool isEventRemoved = eventManager.removeEvent(&eventManager.eventList, "April Uprising");

			// Assert
			Assert::AreEqual(true, isEventRemoved);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ExpectToGetEventWIthName)
			TEST_OWNER(L"MZIlcheva19")
			TEST_PRIORITY("Medium")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ExpectToGetEventWIthName)
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
			Event* eventFound = eventManager.getEventWithName("April Uprising");

			// Assert
			Assert::AreEqual((std::string)"April Uprising", eventFound->title);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ExpectToSeeIfDateIsInRange)
			TEST_OWNER(L"MZIlcheva19")
			TEST_PRIORITY("Medium")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ExpectToSeeIfDateIsInRange)
		{

			//Arrange
			DateManager dateManager;

			// Act
			bool isDateBetweenTwoDates = dateManager.isDateBetweenTwoDates({ 12, 07, 2009 }, { 13, 07, 2010 }, { 14, 07, 2011 });

			// Assert
			Assert::AreEqual(true, isDateBetweenTwoDates);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(ExpectToSeeAreDatesIsInOrder)
			TEST_OWNER(L"MZIlcheva19")
			TEST_PRIORITY("Medium")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ExpectToSeeAreDatesIsInOrder)
		{

			//Arrange
			DateManager dateManager;
			// Act
			bool areDatesInOrder = dateManager.areDatesInOrder({ 8, 12, 2009 }, { 13, 12, 1349 });

			// Assert
			Assert::AreEqual(false, areDatesInOrder);
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(ExpectToEncryptData)
			TEST_OWNER(L"MZIlcheva19")
			TEST_PRIORITY("Medium")
			END_TEST_METHOD_ATTRIBUTE()
			TEST_METHOD(ExpectToEncryptData)
		{

			//Arrange
			EncryptionManager encryptionManager;
			std::vector<int> expected = { 107, 81, 75, 93, 69, 81, 41, 46, 42 };

			// Act
			std::vector<int> encryptData = encryptionManager.encrypt("Mariya143");
			
			// Assert
			for (int i = 0; i < encryptData.size(); i++)
			{
				Assert::AreEqual(expected[i], encryptData[i]);
			}
			
		}
	};	
};
