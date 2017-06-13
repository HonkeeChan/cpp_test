/*
 * TimeTools.cpp
 *
 *  Created on: 2017年2月10日
 *      Author: honkee
 */

#include "TimeTools.h"
#include <ratio>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <iostream>
#include <cstring>

namespace utils {

using namespace std::chrono;
typedef duration<int,std::ratio<60*60> > hour_type;
typedef duration<int> second_type;
typedef duration<long, std::milli> milli_type;

TimeTools::TimeTools() {
	// TODO Auto-generated constructor stub

}

TimeTools::~TimeTools() {
	// TODO Auto-generated destructor stub
}

string TimeTools::getNow(string format){
	chrono::time_point<system_clock, second_type> dateTimeNow = time_point_cast<second_type>(system_clock::now());
	time_t tt = system_clock::to_time_t(dateTimeNow);
	auto t = std::put_time(localtime(&tt), format.c_str());
	stringstream ss;
	ss << t;
	string timeStr;
	ss >> timeStr;
	return timeStr;
}

string TimeTools::getDateTimeNow(){
	return getNow("%Y-%m-%d_%H-%M-%S");
}
string TimeTools::getDateNow(){
	return getNow("%Y-%m-%d");
}


string TimeTools::getDateTimeWithMsNow(){
	chrono::time_point<system_clock, milli_type> dateTimeNowMs = time_point_cast<milli_type>(system_clock::now());
	chrono::time_point<system_clock, second_type> dateTimeNow = time_point_cast<second_type>(system_clock::now());
	int milliDis = dateTimeNowMs.time_since_epoch().count() - dateTimeNow.time_since_epoch().count() * 1000;
	
	time_t tt = system_clock::to_time_t(dateTimeNow);
	auto t = std::put_time(localtime(&tt), "%Y-%m-%d_%H-%M-%S");
	stringstream ss;
	ss << t;
	ss << "-" << milliDis;
	string timeStr;
	ss >> timeStr;
	return timeStr;
}

int TimeTools::getWeekNow(){
	string dateTime = getDateNow();
	return getWeekNow(dateTime);
}
int TimeTools::getWeekNow(const string& date){
	using namespace std;
	std::cout << "input date: " << date << std::endl;
	int year,month,day;
	sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
	cout << "year: " <<  year << " month: " <<  month << " day: " <<  day << endl;
	struct tm tm;
	memset(&tm, 0, sizeof tm);
	tm.tm_mday = day;
	tm.tm_mon = month - 1;
	tm.tm_year = year - 1900;
	mktime(&tm);
	auto t = std::put_time(&tm, "%W");
	stringstream ss;
	ss << t;
	int week;
	ss >> week;
	return week;
}

string TimeTools::getGMTimeNow(){
	//return getGMTime("%a, %d %b %G %H:%M:%S GMT");
	return getGMTimeNow("%a, %d %b %G %H:%M:%S GMT");
}

string TimeTools::getGMTimeNow(const string& format){
	time_t rawtime;
	struct tm * ptm;
	time ( &rawtime );
	ptm = gmtime ( &rawtime );
	auto t = std::put_time(ptm, format.c_str());
	string timestr;
	stringstream ss;
	ss << t;
	ss << "\n";
	getline(ss, timestr);
	return timestr;
}

string TimeTools::getGMTime(const time_t& t){
	return getGMTime(t, "%a, %d %b %G %H:%M:%S GMT");
}
string TimeTools::getGMTime(const time_t& tt, const string& format){
	struct tm * ptm;
	ptm = gmtime ( &tt );
	auto t = std::put_time(ptm, format.c_str());
	string timestr;
	stringstream ss;
	ss << t;
	ss << "\n";
	getline(ss, timestr);
	return timestr;
}

void TimeTools::parseGMTTime(const std::string& gmtstring, const std::string& format, std::tm& t){
	//std::tm t;
	strptime(gmtstring.c_str(), format.c_str(), &t);
	//time = std::mktime(&t);
}
void TimeTools::parseGMTTime(const std::string& gmtstring, std::tm& t){
	string f("%a, %d %b %G %H:%M:%S GMT");
	return parseGMTTime(gmtstring, f, t);
}

} /* namespace utils */
