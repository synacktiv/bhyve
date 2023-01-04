#include <sys/types.h>
#include <sys/param.h>
#include <sys/proc.h>
#include <sys/module.h>
#include <sys/sysent.h>
#include <sys/kernel.h>
#include <sys/sysproto.h>
#include <sys/systm.h>

#include <vm/vm.h>
#include <vm/pmap.h>
#include <vm/vm_map.h>

struct pt_args
{
	vm_offset_t vaddr;
	uint64_t    *res;
};

static int pt(struct thread *td, void *args)
{
	struct pmap *pmap;
	struct pt_args *user = args;

	vm_offset_t vaddr = user->vaddr;
	uint64_t *res = user->res;

	uint64_t paddr;

	pmap = &td->td_proc->p_vmspace->vm_pmap;
	paddr = pmap_extract(pmap, vaddr);

	return copyout(&paddr, res, sizeof(uint64_t));
}

static struct sysent pt_sysent = {
   .sy_narg = 2,
   .sy_call = pt
};

static int offset=NO_SYSCALL;

static int load(struct module *module, int cmd, void *arg)
{
	int error=0;
	switch(cmd) {
		case MOD_LOAD:
			uprintf("loading syscall at offset %d\n", offset);
			break;
		case MOD_UNLOAD:
			uprintf("unloading syscall from offset %d\n", offset);
			break;
		default:
			error=EOPNOTSUPP;
			break;
	}
	return error;
}

SYSCALL_MODULE(pt, &offset, &pt_sysent, load, NULL);
