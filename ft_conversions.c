/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcosta-d <mcosta-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 02:11:54 by mcosta-d          #+#    #+#             */
/*   Updated: 2023/05/13 16:36:49 by mcosta-d         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_printf.h"

/*1. Char conversion - %c - prints a single character*/
void	ft_putchar(char c, int *i)
{
	*i += write(1, &c, 1);
}

/*2. String conversion - %s - Prints a string
(as defined by the common C convention)*/
void	ft_putstr(char *str, int *i)
{
	while (*str)
	{
		*i += write(1, str, 1);
		str++;
	}
}

/*3. Number conversion - %d - Prints a decimal (base 10) number
%i - Prints an integer in base 10
Without modifiers, they are basically the same*/

void	ft_putnbr(long long int nbr, int *i)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		*i += write(1, "-", 1);
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, i);
		ft_putnbr(nbr % 10, i);
	}
	else
	{
		nbr += 48;
		*i = write(1, &nbr, 1);
	}
}

/*4. Unsigned number conversion - %u - Prints an unsigned
decimal (base 10) number.*/

void	ft_putnbr_unsigned(unsigned long nbr, int *i)
{
	if (nbr >= 10)
	{
		ft_putnbr_unsigned(nbr / 10, i);
		ft_putnbr_unsigned(nbr % 10, i);
	}
	else
	{
		nbr += 48;
		*i = write(1, &nbr, 1);
	}
}

/*5. Hexadecimal lowercase - %x - Prints a number in
hexadecimal (base 16) lowercase format.*/

void	ft_puthexa_low(unsigned long nbr, int *i)
{
	char	str[20];
	int		index;

	index = 0;
	if (nbr == 0)
		ft_putchar('0', i);
	while (nbr != 0)
	{
		str[index] = "0123456789abcdef"[nbr % 16];
		nbr /= 16;
		index++;
	}
	while (index--)
		ft_putchar(str[index], i);
}

/*5. Hexadecimal uppercase - %X - Prints a number in
hexadecimal (base 16) uppercase format.*/

void	ft_puthexa_up(unsigned long nbr, int *i)
{
	char	str[20];
	int		index;

	index = 0;
	if (nbr == 0)
		ft_putchar('0', i);
	while (nbr != 0)
	{
		str[index] = "0123456789ABCDEF"[nbr % 16];
		nbr /= 16;
		index++;
	}
	while (index--)
		ft_putchar(str[index], i);
}

/*6. Adress (pointers) - %p - The void * pointer
argument has to be printed in hexadecimal format.*/

void	ft_putadress(unsigned long nbr, int *i)
{
	if (nbr == 0)
		ft_putstr("(nil)", i);
	else
	{
		ft_putstr("0x", i);
		ft_puthexa_low(nbr, i);
	}
}
