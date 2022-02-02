#pragma once

#include <time.h>
#include <iomanip>
#include <sstream>

extern "C" char* strptime(const char* s, const char* f, struct tm* tm);