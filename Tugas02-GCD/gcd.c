#include <stdio.h>
int gcd(int m, int n)
{
 if (m == 0) return m;
 if (n == 0) return n;
 if (m == n) return n;

    return 0;
}

int main(){

 int m, n, r;
    printf(" masukkan angka pertama : "); scanf ("%d",&m);
    printf(" masukkan angka kedua   : "); scanf ("%d",&n);


while((r = m % n) != 0) {
        m = n;
        n = r;
}
    printf(" nilai gcd adalah : %d", n );
    

    return 0;
}
