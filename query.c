#include <stdio.h>
#include <unistd.h>

int main(int argc,const char* argv[])
{
	printf("file:%s pid:%u\n",__FILE__,getpid());
	pause();
}
