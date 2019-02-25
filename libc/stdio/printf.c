#include <limits.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

static bool print(const char* data, size_t length) {
	const unsigned char* bytes = (const unsigned char*) data;
	for (size_t i = 0; i < length; i++)
		if (putchar(bytes[i]) == EOF)
			return false;
	return true;
}

static void reverse(char str[], int length) 
{ 
	char temp;
	for (int i = 0; i < length/2; i++)
	{
		temp = str[i];
		str[i] = str[length -1 -i];
		str[length -1 -i] = temp;
	}
} 

static const char* itoa(unsigned int value, char* str, size_t base, bool caps, bool sign)
{
	bool is_negative = false;
	size_t i = 0;

	if(value == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}

	if (value > INT_MAX && sign)
	{
		is_negative = true;

		value = -value;
	}

	while (value != 0)
	{
		size_t rem = value % base;
		str[i++] = (rem > 9) ? (rem-10) + (caps ? 'A' : 'a') : rem + '0' ;
		value = value/base;
	}

	if(is_negative)
	{
		str[i++] = '-';
	}

	str[i] = '\0';
	reverse(str, i);
	return str;
}

int printf(const char* restrict format, ...) {
	va_list parameters;
	va_start(parameters, format);

	int written = 0;

	while (*format != '\0') {
		size_t maxrem = INT_MAX - written;

		if (format[0] != '%' || format[1] == '%') {
			if (format[0] == '%')
				format++;
			size_t amount = 1;
			while (format[amount] && format[amount] != '%')
				amount++;
			if (maxrem < amount) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(format, amount))
				return -1;
			format += amount;
			written += amount;
			continue;
		}

		const char* format_begun_at = format++;

		if (*format == 'c') {
			format++;
			char c = (char) va_arg(parameters, int /* char promotes to int */);
			if (!maxrem) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(&c, sizeof(c)))
				return -1;
			written++;
		} else if (*format == 'i' || *format == 'd'){
			format++;
			char buffer[100];
			int integer = va_arg(parameters, int);
			const char* str = itoa(integer, buffer, 10, false, true);
			//format integer as string here
			size_t len = strlen(str);
			if(maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(str, len))
				return -1;
			written += len;
		} else if (*format == 'o'){
			format++;
			char buffer[100];
			unsigned int integer = va_arg(parameters, unsigned int);
			const char* str = itoa(integer, buffer, 8, false, false);
			//format integer as string here
			size_t len = strlen(str);
			if(maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(str, len))
				return -1;
			written += len;
		} else if (*format == 's') {
			format++;
			const char* str = va_arg(parameters, const char*);
			size_t len = strlen(str);
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(str, len))
				return -1;
			written += len;
		} else if (*format == 'u'){
			format++;
			char buffer[100];
			unsigned int integer = va_arg(parameters, unsigned int);
			const char* str = itoa(integer, buffer, 10, false, false);
			//format integer as string here
			size_t len = strlen(str);
			if(maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(str, len))
				return -1;
			written += len;
		} else if (*format == 'x'){
			format++;
			char buffer[100];
			unsigned int integer = va_arg(parameters, unsigned int);
			const char* str = itoa(integer, buffer, 16, false, false);
			//format integer as string here
			size_t len = strlen(str);
			if(maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(str, len))
				return -1;
			written += len;
		} else if (*format == 'X'){
			format++;
			char buffer[100];
			unsigned int integer = va_arg(parameters, unsigned int);
			const char* str = itoa(integer, buffer, 16, true, false);
			//format integer as string here
			size_t len = strlen(str);
			if(maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(str, len))
				return -1;
			written += len;
		} else {
			format = format_begun_at;
			size_t len = strlen(format);
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(format, len))
				return -1;
			written += len;
			format += len;
		}
	}

	va_end(parameters);
	return written;
}
