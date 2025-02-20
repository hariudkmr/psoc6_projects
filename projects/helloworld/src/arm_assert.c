#include "arm_assert.h"

/*! \fn     GPIO Write
    \brief  Controls the GPIO State using the below functions.
    \param  gpio_pin pin -> Index of the GPIO Configuration in GPIO
    \param  gpio_state state -> State of the GPIO pin
    \return no return value
*/
void __assert_func(const char *file, int line, const char *func, const char* failedexpr){
	snprintf(g_assert_info.msg, sizeof(g_assert_info.msg), "Assert :%s at %s\n", failedexpr, func);
	strncpy(g_assert_info.file, file, sizeof(g_assert_info.file));
	g_assert_info.line = line;

	__asm("bkpt 1");
}

void assert_path_A(void)
{
	assert(0);
}
