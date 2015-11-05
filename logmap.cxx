/*
edited by: markus
     date: 2015-11-05
*/


#include <iostream>
#include <fstream>

using namespace std;

int main(){
	double x0 = 0.5;
	double x;
	int Nskip = 100;					// Number of iterations to skip
	int Nend  = 200;					// Number of total iterations
	double p[Nend-Nskip];					// declares array with Nend-Nskip entries

	ofstream out("output.dat");				// generates file with name output.dat

	for(double r=0; r <= 4; r += 0.001){
		x=x0;
		for(int i=1; i <= Nskip; i++)
			x = r*x*(1-x);
		for(int i=Nskip+1; i <= Nend; i++){
			x = r*x*(1-x);
			p[i-Nskip-1] = x;			// saves every x into new postition of array p
		}
		for(int i=0; i < Nend-Nskip; i++)
			out  << r << "\t" << p[i] << endl;	// prints r and every entry of array to file
	}

	out.close();						// closes generated file

	return 0;
}
