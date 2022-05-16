#ifndef			VECTOR_HPP
# define		VECTOR_HPP

# include		<memory>
# include		<limits>
# include		<stdexcept>
# include		<iostream>

# include		"utils.hpp"
# include		"iterator.hpp"

namespace		ft
{
	// --------------------------------------------------------
	// ****** Vector Iterator starts
	// : class
	//   vector_iterator<T>
	template	<typename T>
	class		vector_iterator
	{
	public:
		typedef	T													iterator_type;
		typedef iterator_traits<iterator_type>::value_type			value_type;
		typedef iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef iterator_traits<iterator_type>::pointer				pointer;
		typedef iterator_traits<iterator_type>::reference			reference;
		typedef iterator_traits<iterator_type>::difference_type		difference_type;
		
	private:
		pointer _ptr;

	};
	// ****** Vector Iterator ends
	// --------------------------------------------------------
};

#endif