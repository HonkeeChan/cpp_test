/*
 * TimeTools.h
 *
 *  Created on: 2017年2月10日
 *      Author: honkee
 */

#ifndef UTIL_TIMETOOLS_H_
#define UTIL_TIMETOOLS_H_
#include <string>
#include <ctime>

namespace utils {

using namespace std;

class TimeTools {
public:
	TimeTools();
	virtual ~TimeTools();
	static string getDateNow();
	static string getNow(string format);
	static string getDateTimeNow();
	static string getDateTimeWithMsNow();
	static int getWeekNow();
	static int getWeekNow(const string& date);
	static string getGMTimeNow();
	static string getGMTimeNow(const string& format);
	static string getGMTime(const time_t& time);
	static string getGMTime(const time_t& time, const std::string& format);
	static void parseGMTTime(const std::string& gmtstring, const std::string& format, std::tm& time);
	static void parseGMTTime(const std::string& gmtstring, std::tm& time);
};

} /* namespace utils */

#endif /* UTIL_TIMETOOLS_H_ */
