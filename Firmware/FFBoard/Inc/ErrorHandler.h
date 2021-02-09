/*
 * ErrorHandler.h
 *
 *  Created on: 09.02.2021
 *      Author: Yannick
 */

#ifndef SRC_ERRORHANDLER_H_
#define SRC_ERRORHANDLER_H_
#include <vector>
#include <string>


/*
 * Error code definitions
 */

/*
 * Error type for severity
 * temp is cleared when read back
 * critical errors cause a shutdown or have to be cleared externally
 */
enum class ErrorType : uint8_t{
	normal,critical,temp
};

struct Error_t{
	uint32_t code = 0;
	ErrorType type = ErrorType::normal;
	std::string info = "";
};


class ErrorHandler {
public:
	static std::vector<ErrorHandler*> errorHandlers;

	ErrorHandler();
	virtual ~ErrorHandler();
	virtual void errorCallback(Error_t &error, bool cleared); // Called when a new error happened

	static void addError(Error_t &error);
	static void clearError(Error_t &error);
	static void clearTemp();
	static void clearAll();

	static std::vector<Error_t>* getErrors(); // Returns a vector of active errors

protected:
	static std::vector<Error_t> errors;
};

#endif /* SRC_ERRORHANDLER_H_ */
