#ifndef CALCDISTANCE_H_INCLUDED
#define CALCDISTANCE_H_INCLUDED

#include <stdio.h>
#include <math.h>
#include <algorithm>

#define PI 3.14159265358979323846
#define RADIUS 6372.79756085
#define TO_RAD PI / 180

float min(float a,float b){
    if(a<b) return a;
    else return b;
}

float CalcDistance(float latitud1, float longitud1, float latitud2, float longitud2){
    double haversine;
    double temp;
    double distancia_puntos;

    latitud1 = latitud1  * TO_RAD;
    longitud1 = longitud1 * TO_RAD;
    latitud2 = latitud2 * TO_RAD;
    longitud2 = longitud2 * TO_RAD;

    haversine = (pow(sin((1.0 / 2) * (latitud2 - latitud1)), 2)) + ((cos(latitud1)) * (cos(latitud2)) * (pow(sin((1.0 / 2) * (longitud2 - longitud1)), 2)));
    temp = 2 * asin(min(1.0, sqrt(haversine)));
    distancia_puntos = RADIUS * temp;

   return distancia_puntos;
}


#endif // CALCDISTANCE_H_INCLUDED
