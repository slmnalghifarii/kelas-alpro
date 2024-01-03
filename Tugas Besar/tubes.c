#include <stdio.h>
 #include <math.h>
 
 #define PI	3.14159
 FILE *fh;
 double L , g, q, F, drive_freq;
 double theta, omega;
 double t, dt, t_max;
 
    void init();
    void calc();
    int main(int argc, char* argv[]) {
        fh = fopen("pendulum.txt", "w");
        init();
        calc();

        return 0;
    }
    
void init() 
 {
    
    theta = 0.2;
    theta = 1.5;
    omega = 0.0;
     
     t = 0.0;
     t_max = 10;
     dt = 0.04;
     q = 0.6;
     F = 0;
     drive_freq = 2.0;
     g = 9.8;
     L = 1.0; 
 
     return;
 }
 
 void calc()
 {
     while(t < t_max) {
         fprintf(fh, "%g\t%g\n",t,theta);
         omega += -q * omega * dt -(g / L) * sin(theta) * dt + 
             F * sin(drive_freq * t) * dt;
         theta += omega * dt;
         t += dt;
     }
    fclose(fh);
     return;
 }