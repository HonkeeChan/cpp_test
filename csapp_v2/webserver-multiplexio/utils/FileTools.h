/*
 * FileTools.h
 *
 *  Created on: 2017年2月10日
 *      Author: honkee
 */

#ifndef UTIL_FILETOOLS_H_
#define UTIL_FILETOOLS_H_
#include <string>
namespace utils {
using std::string;

class FileTools {
public:
	FileTools();
	virtual ~FileTools();
	static int mkdirp(string path);
	static string getFileModifyTimeLinux(string filePath);
	static bool isFileExist(string filePath);

};

} /* namespace utils */

#endif /* UTIL_FILETOOLS_H_ */
