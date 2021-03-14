/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _LINUX_KFLAT_IOCTLS_H
#define _LINUX_KFLAT_IOCTLS_H

#include <linux/types.h>

#define KFLAT_INIT					_IOR('c', 1, unsigned long)
#define KFLAT_PROC_ENABLE			_IO('c', 100)
#define KFLAT_PROC_DISABLE			_IO('c', 101)
#define KFLAT_TEST					_IO('c', 102)

#endif /* _LINUX_KFLAT_IOCTLS_H */
