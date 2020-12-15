#include <stdio.h>

float raw_input = 50;
float beta = 0.2;

float LowPassFilter(float raw);

int main()
{
    float output_arr[100];
    for(int i = 0; i<100; ++i){
        output_arr[i] = LowPassFilter(raw_input);
    }

    return 0;
}

float LowPassFilter(float raw)
{
    /* equation: yt := ß xt + (1-ß) yt-1 */
    static float output_prev = 0.0;
    float output = beta * raw + (1-beta)*output_prev;
    output_prev = output;

    return output;
}