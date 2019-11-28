#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

int main(){
    
    float rho = 0.01;
    float T = 40;
    float t_max = 0.1;
    float L = 1.0;
    float Dx = 1.0/100;
    float c = sqrt(T/rho);
    float c1 = c;
    float ratio = c*c/(c1*c1);
    
    
    float xi[101][3];
    
    for(int i=0; i < 81; ++i){
        xi[i][0] = 0.00125*i;
    }
    
    for(int j=81; j < 101; ++j){
        xi[j][0] = 0.1 - 0.005*(j - 80);
    }
    
    outfile.open("solu.dat");
    
    float x=0;
    float y =0;
    
    for(int k=0; k < 100; ++k){
        
        x = 2.0 * k - 100.0;
        y = 300.0*xi[k][0];
        
        outfile << x << y << " ";
    }
    
     outfile << "\n";
    
    for(int h=1; h<100; ++h){
        xi[h][1] = xi[h][0] + 0.5*ratio*(xi[h+1][0]+xi[h-1][0]-2*xi[h][0]);
        
        for(int i=1; i < 100; ++i){
            xi[i][2] = 2*xi[i][1]-xi[i][0] + ratio * (xi[i+1][1]+xi[i-1]               [1]-2*xi[i][1]);
        }
		
		
		
		for(int j=1; j<100; ++j){
			x=2*j -100;
			y=300*xi[j][2];
			
			outfile << x << y << " ";
		}
		outfile << "\n";
		
		for(int k =0; k<101; ++k){
			xi[k][0]=xi[k][1];
			xi[k][1]=xi[k][2];
		}
    }   
	
	outfile.close();
    
    
    
    return 0;
}

