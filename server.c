#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

#define SUB_MAX 9

pid_t pid[SUB_MAX];
const char* bin[SUB_MAX] = {"open","destory","login",
	"unlock","save","take","transfer","query","modify"};

void sigint(int num)
{
	for(int i=0; i<SUB_MAX; i++)
	{
		kill(pid[i],9);
		printf("结束子进程 %s \n",bin[i]);
		usleep(300000);
	}
}

int main(int argc,const char* argv[])
{
	signal(SIGINT,sigint);
	for(int i=0; i<SUB_MAX; i++)
	{
		pid[i] = vfork();
		if(0 == pid[i])
		{
			execl(bin[i],bin[i],NULL);
		}
		printf("启动子进程%s\n",bin[i]);
		usleep(300000);
	}
	
	while(-1 != wait(NULL));
}
