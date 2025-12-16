//Sensor System : printing image from c

#include<stdio.h>

typedef struct 
{
    /* data  = 8 bytes*/
    int id;
    float data;
} temp_sensor;

struct humidity
{
    /* data  = 8 bytes*/
    int id ;
    float data;
};

typedef union sensor_head
{
    /* data  = 8 bytes */
    temp_sensor temp ;
    struct humidity hum;
}__attribute__((packed))uni;   
typedef struct sensor{
    /* data  =  9 bytes*/
    int id;
    char name;
    union sensor_head sensor;
}__attribute__((packed)) sense ;    // correct syntax 

int main()
{
    //Array 
    int arr[100][100] = {0};

    //Initialize struct 
    struct sensor sense;
    temp_sensor t;
    uni sh;
    //Accessing 
    sense.id = 0;
    //sense.name = "temperature";
    sense.sensor.temp.id = 0; 
    sense.sensor.temp.data = 23.3;
    printf("%f\n",sense.sensor.temp.data);
    printf("size of sense struct : %ld\n", sizeof(struct sensor));
    // size of sense :
    //scanf(%c);
    return 0;
}