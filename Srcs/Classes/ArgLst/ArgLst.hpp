#pragma once

#include <iostream>

#define STRING 3000
#define INT 3001
#define VOID 3002

class Var {
	public:
	// <===Constructors & Destructors===>
		Var();
		Var(Var& Old);

		~Var();

	// <===Operators===>
		Var&	operator=(Var& Old);
		// int&		operator[](int);

	// <===Methods===>
		template <typename V> void	setValue(V var);
		template <typename V> V		getValue();
		void						setType(std::string _Type);
		int							getType();

	private:
		void			*Value;
		int				Type;
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
		void					Add(int Index, Var var);
		void					Remove(int Index);
		template <typename V> V	getArg(int Index);
		bool					isEmpty();
		int						getSize();

	private:
		int	Size;
		Var	*Args;
};
