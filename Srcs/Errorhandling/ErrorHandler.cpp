#include "ErrorHandler.hpp"

void	ThrowError(ArgLst Lst, int Error) {
	if (Error > 0 && Error < 20)
		GeneralEHandler(Lst, Error);
	else if (Error > 19 && Error < 40)
		ConfigParsigEHandler(Lst, Error);
	else if (Error > 299 && Error < 600)
		HTTPEHandler(Lst, Error);
}
