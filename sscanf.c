// sscanf.c - a file to muck around with string scanning of a url

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char str[1000];
    sscanf("GET /tile_x-1.0_y0.5_z8.bmp HTTP/1.1 HELLO", "GET %s HTTP/1.1\n", str);
    printf("%s\n", str);
    
    double x;
    double y;
    double z;

    sscanf(str, "/tile_x%lf_y%lf_z%lf.bmp", &x, &y, &z);

    printf("x: %lf, y:%lf, zoom: %lf\n", x, y, z);
    

    return EXIT_SUCCESS;
}
