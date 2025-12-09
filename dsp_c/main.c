#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

#define PI 3.14159265
#define SAMPLE_RATE 44100

int main(){
    const double sample_r = (SAMPLE_RATE);
    //VARIABLES
    char chord;
    float freq_Aw; 
    float freq_Bw;
    float freq_cw;           
    double sine_wave1;
    double sine_wave2;
    double sine_wave3;
    double total_sine_wave;
    double theta1;
    double theta2;
    double theta3;
    int num_sample;
    int duration_in_sec;
    int status = 0;

    //A Major Chord: A, C#, E
    float Freq_A = 440.00;
    float Freq_c = 277.18;
    float Freq_B = 329.63;
    
    //User inputs
    printf("Enter Chord you want to create? (currently supports A Major: put A) :");
    scanf("%c", &chord);    
    printf("Enter Duration for which Sine wave is to be generated (in seconds): ");
    scanf("%d", &duration_in_sec);

    //Converting into correct format
    freq_Aw = 2*PI*Freq_A;
    freq_cw = 2*PI*Freq_c;
    freq_Bw = 2*PI*Freq_B;

    num_sample = SAMPLE_RATE*duration_in_sec;

    //PCM Array definition
    short int pcm_array[num_sample];

    if (chord == 'A'){
    //For generating sine wave
        for (int n = 0; n < num_sample; n++){
            theta1  = (freq_Aw * n * (1/sample_r)) ;                           // t = nTs
            theta2  = (freq_Aw * n * (1/sample_r)) ;                           // t = nTs
            theta3  = (freq_Aw * n * (1/sample_r)) ;                           // t = nTs

            //printf("DEBUG: theta at %d is %f\n",n, theta1 );

            sine_wave1 = (32657)*sin(theta1);
            sine_wave2 = (32657)*sin(theta2);                                      
            sine_wave3 = (32657)*sin(theta3);

            //printf("DEBUG: n: %d\t sine values1: %f\t sine values2: %f\t sine values 3: %f\n", n, sine_wave1, sine_wave2, sine_wave3);
            
            total_sine_wave = sine_wave1 + sine_wave2 + sine_wave3;

            //Storing in PCM array
            pcm_array[n]= (short int)total_sine_wave;

            //printf("DEBUG: Value stored in array at %d is %d\n", n, pcm_array[n]);
        }
    }
    //Store as a .raw file.
    FILE* file_ptr;
    file_ptr = fopen("sine.raw", "wb");
    
    if (file_ptr == NULL){
        printf("The file ptr is not opening!!");
        return -1;
    } 
    //Write to the .raw file
    status = fwrite(&pcm_array, 2 ,sizeof(pcm_array),file_ptr);
    if (!status){
        printf("Success!!\n");
        return -1;
    }
    fclose(file_ptr);
    return 0;
}



