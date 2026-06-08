#pragma once

#include <iostream>

class Var {
	public:
	// <===Constructors & Destructors===>
		Var();
		Var(Var& Old);
		template <typename V> Var(V var);
		template <class C> Var(C cl);

		~Var();

	// <===Operators===>
		Var&	operator=(Var& Old);

	// <===Methods===>
		template <typename V> void	setValue(V var);
		template <typename V> V		getValue();
		void						setType(std::string _Type);
		std::string					getType();

	private:
		void		*Value;
		std::string	type;
};

class ArgLst {
	public:
	// <===Constructors & Destructors===>
		ArgLst();
		ArgLst(ArgLst& Old);

		~ArgLst();

	// <===Operators===>
		ArgLst&	operator=(ArgLst& Old);

	// <===Methods===>
		void	Add(Var var);
		void	Remove(int Index, std::string Type);
		void	getArg(int Index, std::string Type);

	private:
		Var	Args[];
};
