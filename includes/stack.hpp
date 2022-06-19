#ifndef			STACK_HPP
# define		STACK_HPP

# include		"vector.hpp"

namespace 		ft
{
	template	<class Typ, class Cnt = vector<Typ> >
    class		stack
	{
	/*
	** ----------------------------------------------------------------------------------
	** TYPES
	*/
	public:
		typedef	Cnt			container_type;
		typedef	Typ			value_type;
		typedef size_t		size_type;
	protected:
		container_type		c;
	
	public:
		/*
		** ----------------------------------------------------------------------------------
		** CONSTRUCTORS
		*/
		explicit stack(const container_type& _cnt = container_type())
							: c(_cnt) {}
		
		/*
		** ----------------------------------------------------------------------------------
		** BASIC: empty, size, top, push, pop
		*/
		bool                empty() const				{ return this->c.empty(); }
		size_type           size() const				{ return this->c.size(); }
		value_type&         top()						{ return (this->c.back()); }
		const value_type&   top() const					{ return (this->c.back()); }
		void                push(const value_type& val)	{ this->c.push_back(val); }
		void                pop()						{ this->c.pop_back(); }

		/*
		** ----------------------------------------------------------------------------------
		** OPERATORS: ==, !=, <, <=, >, >=
		*/
		friend bool			operator==	(const stack<Typ, Cnt>& _st1, const stack<Typ, Cnt>& _st2) {return (_st1.c == _st2.c);}
		friend bool			operator!=	(const stack<Typ, Cnt>& _st1, const stack<Typ, Cnt>& _st2) {return (_st1.c != _st2.c);}
		friend bool			operator<	(const stack<Typ, Cnt>& _st1, const stack<Typ, Cnt>& _st2) {return (_st1.c < _st2.c);}
		friend bool			operator<=	(const stack<Typ, Cnt>& _st1, const stack<Typ, Cnt>& _st2) {return (_st1.c <= _st2.c);}
		friend bool			operator>	(const stack<Typ, Cnt>& _st1, const stack<Typ, Cnt>& _st2) {return (_st1.c > _st2.c);}
		friend bool			operator>=	(const stack<Typ, Cnt>& _st1, const stack<Typ, Cnt>& _st2) {return (_st1.c >= _st2.c);}
	};
}

#endif
