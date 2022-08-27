/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:17:18 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/28 01:51:21 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

namespace ft
{

	// ENUM FOR THE NODE COLOR
	enum e_color
	{
		RED,
		BLACK,
		NIL
	};

	template <class Key, class Value>
		struct node
		{

			// MEMBER TYPES
			public :

				typedef ft::pair<const Key, Value>		value_type;
				typedef std::allocator<value_type>		allocator;

			// MEMBER OBJECTS
			public :

				node									*left;
				node									*right;
				node									*parent;
				value_type								*data;
				e_color									color;

			// MEMBER FUNCTIONS
			public :

				// DEFAULT CONSTRUCTOR
				node(Key key, Value value, node * nil = NULL, e_color color = BLACK) :
					left(nil),
					right(nil),
					parent(nil),
					data(NULL),
					color(color)
				{
					data = allocator().allocate(1);
					allocator().construct(data, value_type(key, value));
					return ;
				};

				// COPY CONSTRUCTOR
				node(const node & other)
				{
					data = NULL;
					*this = other;
					return ;
				};

				// OPERATOR =
				node& operator = (const node & other)
				{
					if (this == &other)
						return (*this);
					left = other.left;
					right = other.right;
					parent = other.parent;
					if (data)
					{
						allocator().destroy(data);
						allocator().deallocate(data, 1);
					}
					data = allocator().allocate(1);
					allocator().construct(data, value_type(other.data->first, other.data->second));
					color = other.color;
					return (*this);
				};

				// DESTRUCTOR
				~node(void)
				{
					if (data)
					{
						allocator().destroy(data);
						allocator().deallocate(data, 1);
						data = NULL;
					}
					return ;
				};

		}; // END OF CLASS NODE

}; // END OF NAMESPACE FT

#endif
