#include <err.h>
#include <inttypes.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/module.h>

uint64_t gva_to_gpa(uint64_t vaddr)
{
	uint64_t paddr = 0;

	int nsys;
	int ret;
	int modid;

	struct module_stat stat;
	stat.version = sizeof(stat);

	modid = modfind("sys/pt");
	if (modid < 0)
		errx(EXIT_FAILURE, "modinfo");

	ret = modstat(modid, &stat);
	if (ret < 0)
		errx(EXIT_FAILURE, "modstat");

	nsys = stat.data.intval;
	ret = syscall(nsys, vaddr, &paddr);

	return paddr;
}
