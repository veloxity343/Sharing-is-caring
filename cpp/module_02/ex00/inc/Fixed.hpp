/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:44:32 by rcheong           #+#    #+#             */
/*   Updated: 2024/12/21 09:51:29 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class Fixed
{
	private:
		int	_fp_value;
		static const int _fract_bits;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		~Fixed();
		Fixed &operator=(const Fixed &src);
		int getRawBits(void)const;
		void setRawBits(int const raw);
};
