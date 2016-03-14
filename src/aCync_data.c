#include <pthread.h>
#include "aCync.h"

static pthread_mutex_t input_data_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t output_data_lock = PTHREAD_MUTEX_INITIALIZER;
//From userspace perspective
static int input_data = 0;
static int output_data = 0;

int get_input_data(void)
{
    int retval;
    pthread_mutex_lock(&input_data_lock);
    retval = input_data;
    pthread_mutex_unlock(&input_data_lock);
    return retval;
}

void set_input_data(int data)
{
    pthread_mutex_lock(&input_data_lock);
    input_data = data;
    pthread_mutex_unlock(&input_data_lock);
}

int get_output_data(void)
{
    int retval;
    pthread_mutex_lock(&output_data_lock);
    retval = output_data;
    pthread_mutex_unlock(&output_data_lock);
    return retval;
}

void set_output_data(int data)
{
    pthread_mutex_lock(&output_data_lock);
    output_data = data;
    pthread_mutex_unlock(&output_data_lock);
}

