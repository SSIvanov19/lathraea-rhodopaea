#include <back-end/errorManager.h>


/**
 * @brief Converts error code to error description
 * @param errorCode The error code
 * @return string The error description
*/
std::string GetLastErrorAsString(DWORD errorCode)
{
	if (errorCode == 0)
	{
		return "The operation completed successfully.";
	}

	//Buffer for the message, because we don't yet know how long the message string will be.
	LPSTR messageBuffer = nullptr;

	//Give us the description version of the error code and save it into the buffer
	size_t size = FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		errorCode,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPSTR)&messageBuffer,
		0,
		NULL
	);

	//Copy the error message from the buffer into a string.
	std::string message(messageBuffer, size);

	//Free the Win32's string's buffer.
	LocalFree(messageBuffer);

	return message;
}

ErrorHandler::ErrorHandler(
	std::string fileName_,
	std::string functionName_,
	DWORD errorCode_
)
{
	fileName = fileName_;
	functionName = functionName_;
	errorCode = errorCode_;
	errorMsg = GetLastErrorAsString(errorCode_);
}

ErrorHandler::ErrorHandler(
	std::string fileName_,
	std::string functionName_,
	std::string errorMsg_
)
{
	fileName = fileName_;
	functionName = functionName_;
	errorCode = NULL;
	errorMsg = errorMsg_;
}
