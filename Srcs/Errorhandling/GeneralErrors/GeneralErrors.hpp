#pragma once

#include "ArgLst.hpp"

// 0-19 Reserved
enum GeneralErrors {
	ArgNb = 2,
	AllocFail = 3
} GeneralErrors;

void	GeneralEHandler(ArgLst Lst, int Error);
void	EAllocFail(ArgLst Lst);
