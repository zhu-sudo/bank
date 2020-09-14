#include <stdio.h>
#include <unistd.h>

int main(int argc,const char* argv[])
{
	printf("file:%s pid:%u",__FILE__,getpid());
	pause();
}
