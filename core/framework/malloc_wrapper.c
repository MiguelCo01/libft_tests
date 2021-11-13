#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>

/* Malloc Mode: 0 - original, 1 - always null*/
static int	g_malloc_mode = 0;

void	mock_malloc(int mode)
{
	g_malloc_mode = mode;
}

void	*malloc(size_t sz)
{
	void	*(*libc_malloc)(size_t);

	libc_malloc = dlsym(RTLD_NEXT, "malloc");
	if (g_malloc_mode == 0)
	{
		//printf("Original malloc\n");
		return (libc_malloc(sz));
	}
	else
		return ((void *) NULL);
}

void	free(void *p)
{
	void	(*libc_free)(void*);

	libc_free = dlsym(RTLD_NEXT, "free");
	//printf("free\n");
	libc_free(p);
}
