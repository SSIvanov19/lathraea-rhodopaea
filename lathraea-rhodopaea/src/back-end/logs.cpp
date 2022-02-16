/*! @file logs.cpp
*   @brief A source file for the logs.
*/

#include <back-end/logs.h>

/**
 * @brief Returns the lebel of severity as a string
 * @param logSeverity The level of severity
 * @return The level of severity as a string
*/
std::string enumToString(LogSeverity logSeverity)
{
	switch (logSeverity)
	{
	case LogSeverity::EMERG:
		return "Emergency";
		break;
	case LogSeverity::ALERT:
		return "Alert";
		break;
	case LogSeverity::CRIT:
		return "Critical";
		break;
	case LogSeverity::ERR:
		return "Error";
		break;
	case LogSeverity::WARNING:
		return "Warning";
		break;
	case LogSeverity::NOTICE:
		return "Notice";
		break;
	case LogSeverity::INFO:
		return "Informational";
		break;
	case LogSeverity::DEBUG:
		return "Debug";
		break;
	default:
		return "Debug";
		break;
	}
}

void LoggerManager::log(LogSeverity levelOfLog, std::string msg)
{
	// Get the time, return the seconds from 1 Jan 1970
	time_t rawtime = time(0);

	// Struct that contains a calendar date and time broken down into its components.
	struct tm timeinfo;

	// Convert the time to the structure
	localtime_s(&timeinfo, &rawtime);

	// Create an output stream
	std::ofstream trace_log("logfile.log", std::fstream::app);

	// Connect stream buffers
	std::streambuf* clogbuff = std::clog.rdbuf();
	std::clog.rdbuf(trace_log.rdbuf());

	// log 
	std::clog << std::put_time(&timeinfo, "%F %T %z %t") 
		<< enumToString(levelOfLog) << ": " << msg << std::endl;

	// restore
	std::clog.flush();
	std::clog.rdbuf(clogbuff);
}
