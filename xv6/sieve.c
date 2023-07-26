/* Prime number sieve: a realization in Unix processes of the classic
   coroutine model described by McIlroy at Cambridge in 1968 */

#include <stdio.h>
#include <unistd.h>

void source() {
	int n;
	for(n=2; ; n++)
		write(1, &n, sizeof(n));
}

void cull(int p) {
	int n;
	for( ; ; ) {
		read(0, &n, sizeof(n));
		if(n%p != 0)
			write(1, &n, sizeof(n));
}	}

	/* connect stdin (k=0) or stdout (k=1) to pipe */

void redirect(int k, int pd[2]) {
	dup2(pd[k], k);
	close(pd[0]);
	close(pd[1]);
}

void sink() {
	int pd[2];
	int p;			/* a prime */
	for( ; ; ) {
		read(0, &p, sizeof(p));
		printf("%d\n", p);
		fflush(stdout);
		pipe(pd);
		if(fork()) {
			redirect(0, pd);
			continue;
		} else {
			redirect(1, pd);
			cull(p);
}	}	}

int main() {
	int pd[2];		/* pipe descriptors */
	pipe(pd);
	if(fork()) {		/* parent process */
		redirect(0, pd);
		sink();
	} else {		/* child process */
		redirect(1, pd);
		source();
}	}
