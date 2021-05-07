/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _LINUX_KFLAT_IOCTLS_H
#define _LINUX_KFLAT_IOCTLS_H

#include <linux/types.h>

#define KFLAT_INIT					_IOR('c', 1, unsigned long)
#define KFLAT_GLOBAL_ENABLE			_IOR('c', 2, unsigned long)
#define KFLAT_LINEAR_MEMORY_REALLOC	_IOR('c', 3, unsigned long)
#define KFLAT_SET_FILTER_PID		_IOR('c', 4, unsigned long)
#define KFLAT_PROC_ENABLE			_IO('c', 100)
#define KFLAT_PROC_DISABLE			_IO('c', 101)
#define KFLAT_TEST					_IO('c', 102)
#define KFLAT_SET_FLAG				_IO('c', 103)
#define KFLAT_GLOBAL_DISABLE		_IO('c', 104)

#endif /* _LINUX_KFLAT_IOCTLS_H */
