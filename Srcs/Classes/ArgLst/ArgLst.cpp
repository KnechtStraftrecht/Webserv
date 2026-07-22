#include "ArgLst.hpp"

// <===*%ArgLst Class%*===>

// <===Constructors & Destructors===>

ArgLst::ArgLst() : Size(0) {}

ArgLst::ArgLst(ArgLst& Old) {
	if (Old.isEmpty() == true)
		return ;
	this->Size = Old.Size;
	this->Args = new Var[Old.Size];
	for (int i = 0; i <= Old.Size; i++) {
		this->Args[i] = Old.Args[i];
	}
}

ArgLst::~ArgLst() {
	delete[] this->Args;
}

// <===Operators===>

ArgLst&	ArgLst::operator=(ArgLst& Old) {
	if (Old.isEmpty())
		return ;
	if (this->Size > 0)
		delete[] this->Args;
	this->Size = Old.Size;
	this->Args = new Var[Old.Size];
	for (int i = 0; i < Old.Size; i++) {
		this->Args[i] = Old.Args[i];
	}
	return (*this);
}

// <===Methods===>

void	ArgLst::Add(int Index, Var var) {
	if (this->Size == 0) {
		this->Args = new Var[1];
		this->Args[0] = var;
	}

	Var	*Temp = new Var[this->Size + 1];
	int	Size = this->Size;

	for (int i = 0; i < Size; i++) {
		Temp[i] = this->Args[i];
	}
	Temp[Size] = var;
	delete[] this->Args;
	this->Args = Temp;
	this->Size++;
}

void	ArgLst::Remove(int Index) {
	if (this->Size == 0)
		return ;

	Var	*Temp = new Var[this->Size + 1];
	int	Size = this->Size;

	for (int i = 0; i < Size; i++) {
		if (i != Index)
			Temp[i] = this->Args[i];
	}
	delete[] this->Args;
	this->Args = Temp;
	this->Size--;
}
template <typename V> V	ArgLst::getArg(int Index) {
	return (this->Args[Index].getValue());
}
bool	ArgLst::isEmpty() {
	if (this->Size == 0)
		return (true);
	return (false);
}
int		ArgLst::getSize() {
	return (this->Size);
}

// <===*%Var Class%*===>

// <===Constructors & Destructors===>

Var::Var() {
	this->Value = nullptr;
}

Var::Var(Var& Old) {
	this->Type = Old.Type;
	this->Value = Old.Value;
}

Var::~Var() {}

// <===Operators===>
Var&	Var::operator=(Var& Old) {
	this->Type = Old.Type;
	this->Value = Old.Value;
}

// <===Methods===>
template <typename V> void	Var::setValue(V var) {
	this->Value = <static_cast>(void*)var;
}

template <typename V> V	Var::getValue() {
	switch (this->Type) {
		case 3000 {
			return (<static_cast>(std::string)this->Value);
			break ;
		}
		case 3001 {
			return (<static_cast>(int)this->Value);
			break ;
		}
		case 3002 {
			return (this->Value);
			break ;
		}
	}
}
void	Var::setType(std::string _Type) {
	if (_Type == "string")
		this->Type = STRING;
	if (_Type == "int")
		this->Type = INT;
	if (_Type == "void")
		this->Type = VOID;
}

int	Var::getType() {
	return (this->Type);
}
