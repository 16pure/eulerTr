#include<stdio.h>
#include<math.h>


double eulerTr(double *x,double *y,double *z,double phi,double theta,double psi);
double eulerinvTr(double *x,double *y,double *z,double phi,double theta,double psi);


double eulerTr(double *x,double *y,double *z,double phi,double theta,double psi)
	{
		double Rx[3][3]={{1,0,0},{0,cos(phi),sin(phi)},{0,-sin(phi),cos(phi)}};
		double Ry[3][3]={{cos(theta),0,-sin(theta)},{0,1,0},{sin(theta),0,cos(theta)}};
		double Rz[3][3]={{cos(psi),sin(psi),0},{-sin(psi),cos(psi),0},{0,0,1}};

		double R[3][3]={{cos(theta)*cos(psi),cos(theta)*sin(psi),-sin(theta)},{sin(phi)*sin(theta)*cos(psi)-cos(phi)*sin(psi),sin(phi)*sin(theta)*sin(psi)+cos(phi)*cos(psi), sin(phi)*cos(theta)},{cos(phi)*sin(theta)*cos(psi)+sin(phi)*sin(psi),cos(phi)*sin(theta)*sin(psi)-sin(phi)*cos(psi),cos(phi)*cos(theta)}};
		
		double X,Y,Z;

		
		

		X=(*x)*R[0][0]+(*y)*R[0][1]+(*z)*R[0][2];
	
		Y=(*x)*R[1][0]+(*y)*R[1][1]+(*z)*R[1][2];

		Z=(*x)*R[2][0]+(*y)*R[2][1]+(*z)*R[2][2];

		*x=X;
		*y=Y;
		*z=Z;
		return 0;
	}


double eulerinvTr(double *x,double *y,double *z,double phi,double theta,double psi)
	{	
		double Rinv[3][3]={{cos(theta)*cos(psi),sin(phi)*sin(theta)*cos(psi)-cos(phi)*sin(psi),cos(phi)*sin(theta)*cos(psi)+sin(phi)*sin(psi)},{cos(theta)*sin(psi),sin(phi)*sin(theta)*sin(psi)+cos(phi)*cos(psi),cos(phi)*sin(theta)*sin(psi)-sin(phi)*cos(psi)},{-sin(theta),sin(phi)*cos(theta),cos(phi)*cos(theta)}};

		double X,Y,Z;
		

		X=(*x)*Rinv[0][0]+(*y)*Rinv[0][1]+(*z)*Rinv[0][2];

                Y=(*x)*Rinv[1][0]+(*y)*Rinv[1][1]+(*z)*Rinv[1][2];

                Z=(*x)*Rinv[2][0]+(*y)*Rinv[2][1]+(*z)*Rinv[2][2];

		*x=X;
                *y=Y;
                *z=Z;

		return 0;
	}


int main(){

	double x,y,z;
 	double phi, theta, psi;
 
	x=1.0;
 	y=2.0;
 	z=3.0;
 
 	phi   = 60.0 * M_PI/180.0;
 	theta = 20.0 * M_PI/180.0;
 	psi   = 15.0 * M_PI/180.0;

	eulerTr(&x, &y, &z, phi, theta, psi);
 	printf("%f,%f,%f\n",x,y,z);
 
 	eulerinvTr(&x, &y, &z,phi, theta, psi);
 	printf("%f,%f,%f\n",x,y,z);

	eulerTr(&x, &y, &z, phi, theta, psi);
        printf("%f,%f,%f\n",x,y,z);
 
}
	
