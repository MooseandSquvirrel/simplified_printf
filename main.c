#include "ss_printf.h"

int		main(void)
{
	int byte;
	char *str= "moo";

	//ft_printf("This dog is %s %c %d %i %o %u %u %u %x %p right!\n", str, 'D', 100, 100, 100, -1, -2, 1, 6735, &str);
	byte = ft_printf("s: %s\nc:%c\nd: %d i: %i\n o:%o p:%p x:%x u:%u,%u", "yay", 'j', 34, 14, 16, str, 100, -1, 123);
	printf("\n bytes should be \n bytes  = %i\n", byte); //test %o 

	return (0);
}