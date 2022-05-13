#include <unistd.h>

int A(int m, int n)
{
	if (!m)
		return n + 1;
	if (!n)
		return A(m - 1, 1);
	return A(m-1,A(m,n-1));
}

int main(int argc, char** argv)
{
	return A(getpid(), getppid());
}
