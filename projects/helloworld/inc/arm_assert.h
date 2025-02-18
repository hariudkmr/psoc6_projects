#ifndef SASSERT_H
#define SASSERT_H

/**
 * @breif Structure to store items that can be printed out later
 */
typedef struct sAssertInfo
{
    uint32_t pc;
    uint32_t lr;
    uint32_t line;
    char     file[256];
    char     msg[256];
} sAssertInfo;

extern sAssertInfo g_assert_info;

#endif
