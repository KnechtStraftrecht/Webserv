#include "GeneralErrors.hpp"

void	GeneralEHandler(ArgLst Lst, int Error) {
	switch (Error) {
		case 2: {
			EAllocFail(Lst);
			break ;
		}
	}
}

void	EAllocFail(ArgLst Lst) {
	std::cout << "An allocation has failed, the program is exiting! Dowload more ram!";
	exit(AllocFail);
}
