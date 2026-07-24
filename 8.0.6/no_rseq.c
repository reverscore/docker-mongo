#define _GNU_SOURCE
#include <dlfcn.h>
#include <errno.h>
#include <stdarg.h>
#include <stdint.h>
#include <sys/syscall.h>

#ifndef __NR_rseq
#if defined(__x86_64__)
#define __NR_rseq 334
#elif defined(__aarch64__)
#define __NR_rseq 293
#elif defined(__arm__)
#define __NR_rseq 398
#elif defined(__powerpc64__)
#define __NR_rseq 387
#else
#define __NR_rseq 334
#endif
#endif

int rseq(void *rseq_area, uint32_t rseq_len, int flags, uint32_t sig) {
    errno = EPERM;
    return -1;
}

long syscall(long number, ...) {
    static long (*real_syscall)(long, ...) = (void *)0;
    static int init = 0;

    if (!init) {
        init = 1;
        real_syscall = dlsym(RTLD_NEXT, "syscall");
    }

    if (number == __NR_rseq) {
        errno = EPERM;
        return -1;
    }

    if (!real_syscall) {
        errno = ENOSYS;
        return -1;
    }

    va_list args;
    va_start(args, number);
    long a1 = va_arg(args, long);
    long a2 = va_arg(args, long);
    long a3 = va_arg(args, long);
    long a4 = va_arg(args, long);
    long a5 = va_arg(args, long);
    long a6 = va_arg(args, long);
    va_end(args);

    return real_syscall(number, a1, a2, a3, a4, a5, a6);
}
