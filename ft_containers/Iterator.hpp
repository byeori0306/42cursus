/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:42:32 by dahpark           #+#    #+#             */
/*   Updated: 2022/05/01 22:41:14 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP_
#define ITERATOR_HPP_

namespace ft {
	/* Category tag */
	struct output_iterator_tag {};
	struct input_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};
	
	/* iterator_traits */
	template <class Iterator>
	class iterator_traits {
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};
	
	template <class T>
	class iterator_traits<T*> {
		public:
			typedef ptrdiff_t					difference_type;
			typedef T							value_type;
			typedef T*							pointer;
			typedef T&							reference;
			typedef random_access_iterator_tag	iterator_category;
	};

	template <class T>
	class iterator_traits<const T*> {
		public:
			typedef ptrdiff_t					difference_type;
			typedef T							value_type;
			typedef const T*					pointer;
			typedef const T&					reference;
			typedef random_access_iterator_tag	iterator_category;
	};

	/* Predefined iterator */
	template <class Iterator>
	class reverse_iterator {
		private:
			Iterator _current;
		public:
			/* Member types */
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;

			/* Member functions */
			// default constructor
			reverse_iterator() { }
			// initialization constructor
			explicit reverse_iterator (iterator_type it) : _current(it) { }
			// copy / type-cast constructor
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) : _current(rev_it.base()) { }
			// destructor
			~reverse_iterator() { }

			// Return base iterator
			iterator_type base() const {
				return (_current);
			}

			reference operator*() const {
				Iterator temp = _current;
				return (*--temp);
			}
			reverse_iterator operator+ (difference_type n) const {
				return (reverse_iterator(_current - n));
			}
			reverse_iterator& operator++() {
				--_current;
				return (*this);
			}
			reverse_iterator  operator++(int) {
				reverse_iterator temp = *this;
				--_current;
				return (temp);
			}
			reverse_iterator& operator+= (difference_type n) {
				_current -= n;
				return (*this);
			}
			reverse_iterator operator- (difference_type n) const {
				return (reverse_iterator(_current + n));
			}
			reverse_iterator& operator--() {
				++_current;
				return (*this);
			}
			reverse_iterator  operator--(int) {
				reverse_iterator temp = *this;
				++_current;
				return (temp);
			}
			reverse_iterator& operator-= (difference_type n) {
				_current += n;
				return (*this);
			}
			pointer operator->() const {
				return (&(operator*()));
			}
			reference operator[] (difference_type n) const {
				return (base()[-n-1]);
			}
	};

	/* Non-member function overloads */
	template <class Iterator>
  	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() == rhs.base());
	}
	template <class Iterator>
  	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() != rhs.base());
	}
	template <class Iterator>
  	bool operator< (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() > rhs.base());
	}
	template <class Iterator>
  	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() >= rhs.base());
	}
	template <class Iterator>
  	bool operator> (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() < rhs.base());
	}
	template <class Iterator>
  	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
  	reverse_iterator<Iterator> operator+ (
        typename reverse_iterator<Iterator>::difference_type n,
        const reverse_iterator<Iterator>& rev_it) 
	{ return (rev_it + n); }
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (
    	const reverse_iterator<Iterator>& lhs,
    	const reverse_iterator<Iterator>& rhs)
	{ return (lhs.base() - rhs.base()); }
} // namespace ft

#endif