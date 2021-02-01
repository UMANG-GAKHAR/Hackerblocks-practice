#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long matrix[103][103][103] = {0};
void update(long long n,long long x,long long y,long long z,long long  val) {
    long long y1,x1;

    while(z <= 102) {
        x1 = x;
        while(x1 <= 102) {
            y1 = y;
            while(y1 <= 102) {
                matrix[x1][y1][z] += val;
                y1 += (y1 & -y1 );
            }
            x1 += (x1 & -x1);
        }
        z += (z & -z);
    }

}

long long calculate_sum(long long  x,long long y,long long z) {
    long long y1,x1,sum=0;
    while (z>0) {
        x1=x;
        while(x1>0) {
            y1=y;
            while(y1>0) {
                sum += matrix[x1][y1][z];
                y1-= (y1 & -y1);   
            }
            x1 -= (x1 & -x1);
        }
        z -= (z & -z);

    }
    return sum;
}
void process(long long n,long long m) {
    long long int x,y,z,x0,y0,z0;
    long long int value1,value2,val;
    int command;
    long long int count1 = 0;
    memset(matrix,0,sizeof(matrix));
    while(m--) {
        cin >> command;

        if(command==2) {
            scanf("%lld %lld %lld %lld %lld %lld",&x0,&y0,&z0,&x,&y,&z);
            value1 = calculate_sum(x+1,y+1,z+1)- calculate_sum(x0,y+1,z+1) 
                    - calculate_sum(x+1,y0,z+1) + calculate_sum(x0,y0,z+1);

            value2 = calculate_sum(x+1,y+1,z0) - calculate_sum(x0,y+1,z0)
                    - calculate_sum(x+1,y0,z0)  + calculate_sum(x0,y0,z0);

            printf("%lld\n",count1 - (value1 - value2));
            //PrintMatrix(n);
        }
        if(command==1) {

            scanf("%lld %lld %lld %lld",&x,&y,&z,&val);
            x++; y++; z++;
            count1 += val; 
            update(n,x,y,z,val);
        }
    }
}
int main() {
    long long cases = 1;
    while(cases--) {

        long long n,m; scanf("%lld %lld",&n,&m);
        process(n,m);
    }
    return 0;
}
