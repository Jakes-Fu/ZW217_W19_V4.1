#ifndef __PRIORITY_KERNEL_H__
#define __PRIORITY_KERNEL_H__

#include "os_api.h"

DECLARE_PRIORITY(PRI_RTOS_MANAGE)
#define PRI_RTOS_MANAGE   SCI_TASK_PRI(PRI_RTOS_MANAGE)

//extern const uint32 g_pri_PRI_HISR_PRIO_0;
DECLARE_PRIORITY(PRI_HISR_PRIO_0)
#define PRI_HISR_PRIO_0   SCI_TASK_PRI(PRI_HISR_PRIO_0)

DECLARE_PRIORITY(PRI_HISR_PRIO_1)
#define PRI_HISR_PRIO_1   SCI_TASK_PRI(PRI_HISR_PRIO_1)

DECLARE_PRIORITY(PRI_HISR_PRIO_2)
#define PRI_HISR_PRIO_2   SCI_TASK_PRI(PRI_HISR_PRIO_2)

DECLARE_PRIORITY(PRI_RTOS_KERNEL)
#define PRI_RTOS_KERNEL   SCI_TASK_PRI(PRI_RTOS_KERNEL)

DECLARE_PRIORITY(PRI_CHNG_FREQ_TASK)
#define PRI_CHNG_FREQ_TASK   SCI_TASK_PRI(PRI_CHNG_FREQ_TASK)

#endif /*__PRIORITY_KERNEL_H__*/