#ifndef						STL_LIKE_HPP
#define						STL_LIKE_HPP

#include					<exception>
#include					<iostream>

namespace ft
{
	/**
	* ------------------------------------------------------------- *
	* ------------------------- FT::PAIR -------------------------- *
	*
	* - Coplien form:
	* (constructor):		Construct pair
	* (destructor):		 	Pair destructor
	* operator=:			Assign content
	*
	* - Public member variables:
	* T1:					First pair's member variable
	* T2:					Second pair's member variable
	* ------------------------------------------------------------- *
	*/

	template				<typename T1, typename T2>
	class					pair
	{
		public:
		/* ------------------------------------------------------------- */
		/* ------------------------ COPLIEN FORM ----------------------- */
			pair()								: first(), second() {};
			pair(const T1& a, const T2& b)		: first(a), second(b) {};
			pair(const pair<T1, T2>& copy)		: first(copy.first), second(copy.second) {};
			template		<typename U, typename V>
			pair(const pair<U, V>& copy)		: first(copy.first), second(copy.second) {};
			~pair()	{};

			pair&			operator=(const pair& assign)
			{
				if (this != &assign)
				{
					first = assign.first;
					second = assign.second;
				}
				return (*this);
			}

		/* ------------------------------------------------------------- */
		/* ------------------ PUBLIC MEMBER VARIABLES ------------------ */			
			T1				first;
			T2				second;
	};

	/**
	* ------------------------------------------------------------- *
	* ---------------------- FT::ALLOCATOR ------------------------ *
	* - Coplien form:
	* (constructor)		Creates a new allocator instance
	* (destructor)		Destructs an allocator instance
	*
	* - Member functions:
	* Address			Obtains the address of an object
	* Allocate			Allocates uninitialized storage
	* Deallocate		Deallocates storage
	* Construct			Constructs an object in allocated storage
	* Destroy			Destroys an object in allocated storage
	* ------------------------------------------------------------- *
	*/
 
	template			<class T>
	class				allocator
	{
		/* ------------------------------------------------------------- */
		/* --------------------------- ALIASES ------------------------- */
		public:
			typedef		T			value_type;
			typedef		T*			pointer;
			typedef		T&			reference;
			typedef		const T*	const_pointer;
			typedef		const T&	const_reference;
			typedef 	size_t		size_type;
			typedef		long int	difference_type;

		/* ------------------------------------------------------------- */
		/* ------------------------ COPLIEN FORM ----------------------- */
			allocator() throw() {};
			allocator(const allocator&) throw() {};
			template		<class U>
			allocator(const allocator<U>&) throw() {};
			~allocator() throw() {};

		/* ------------------------------------------------------------- */
		/* ---------------------- MEMBER FUNCTIONS --------------------- */
			pointer		address(reference x) const			{ return &x; }
			const_pointer
						address(const_reference x) const	{ return &x; }
			pointer		allocate(size_type n)
			{
				pointer ret;
				size_t size = n * sizeof(value_type);
				try
				{
					ret = reinterpret_cast<pointer>(::operator new(size));
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
				return ret;
			}

			void		deallocate (pointer p, size_type n)
			{
				(void)n;
				::operator delete(p);
			}

			void		construct(pointer p, const T& v) { new((void*)p)T(v); }
			void		destroy(pointer p) { p->~T(); }
	};


	/**
	* ------------------------------------------------------------- *
	* ------------------------- FT::LESS -------------------------- *
	*/
	template			<class T>
	struct				less
	{
		typedef			T		first_argument_type;
		typedef			T		second_argument_type;
		typedef			bool	result_type;
		
		bool			operator() (const T& x, const T& y) const {return x<y;}
	};

	/**
	* ------------------------------------------------------------- *
	* ---------------------- FT::ENABLE_IF ------------------------ *
	*/
	template			<bool B>
	struct				enable_if {};

	template			<>
	struct				enable_if<true> { typedef int type; };

	/**
	* ------------------------------------------------------------- *
	* --------------------- FT::IS_INTEGRAL ----------------------- *
	*/
	template				<typename T>
	struct					is_integral						{ static const bool value = false; };
	template				<>
	struct					is_integral<bool>				{ static const bool value = true;  };
	template				<>
	struct					is_integral<char>				{ static const bool value = true;  };
	template				<>
	struct					is_integral<short>				{ static const bool value = true;  };
	template				<>
	struct					is_integral<int>				{ static const bool value = true;  };
	template				<>
	struct					is_integral<long>				{ static const bool value = true;  };
	template				<>
	struct					is_integral<long long>			{ static const bool value = true;  };
	template				<>
	struct					is_integral<unsigned char>		{ static const bool value = true;  };
	template				<>
	struct					is_integral<unsigned short>		{ static const bool value = true;  };
	template				<>
	struct					is_integral<unsigned int>		{ static const bool value = true;  };
	template				<>
	struct					is_integral<unsigned long>		{ static const bool value = true;  };
	template				<>
	struct					is_integral<unsigned long long>	{ static const bool value = true;  };
}

#endif