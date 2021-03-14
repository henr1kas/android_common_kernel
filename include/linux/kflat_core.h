/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_KFLAT_CORE_H
#define _LINUX_KFLAT_CORE_H

#include <uapi/linux/kflat.h>

struct task_struct;

void kflat_task_init(struct task_struct *t);
void kflat_task_exit(struct task_struct *t);

enum kflat_mode {
	KFLAT_MODE_DISABLED = 0,
	KFLAT_MODE_ENABLED = 1,
};

#endif /* _LINUX_KFLAT_CORE_H */
