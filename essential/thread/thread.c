#include<unistd.h>
#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond1, cond2, cond3;
int num = 1;

void* fun1(void* arg){
	pthread_mutex_lock(&mutex);
	printf("Print1-%d\n", num++);
	pthread_cond_signal(&cond2);
	pthread_mutex_unlock(&mutex);
	while(num <= 100){
		pthread_mutex_lock(&mutex);
		while(num % 3 != 1)  //★ 重要  必须要有  保证等待解锁的是预期结果
			pthread_cond_wait(&cond1, &mutex);
		if(num <= 100)
			printf("Print1-%d\n", num++);
		pthread_cond_signal(&cond2);
		pthread_mutex_unlock(&mutex);
	}
}

void* fun2(void* arg){
	while(num <= 100){
		pthread_mutex_lock(&mutex);
		while(num % 3 != 2)
			pthread_cond_wait(&cond2, &mutex);
		if(num <= 100)
			printf("Print2-%d\n", num++);
		pthread_cond_signal(&cond3);
		pthread_mutex_unlock(&mutex);
	}
}
void* fun3(void* arg){
	while(num <= 100){
		pthread_mutex_lock(&mutex);
		while(num % 3 != 0 && num <= 100)
			pthread_cond_wait(&cond3, &mutex);
		if(num <= 100)
			printf("Print3-%d\n", num++);
		pthread_cond_signal(&cond1);
		pthread_mutex_unlock(&mutex);
	}
}

int main(){
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond1, NULL);
	pthread_cond_init(&cond2, NULL);
	pthread_cond_init(&cond3, NULL);  
	
	pthread_t p1, p2, p3;
	pthread_create(&p1, NULL, fun1, NULL);
	pthread_create(&p2, NULL, fun2, NULL);
	pthread_create(&p3, NULL, fun3, NULL);
	
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	pthread_join(p3, NULL);

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond1);
	pthread_cond_destroy(&cond2);
	pthread_cond_destroy(&cond3);

	return 0;

}

