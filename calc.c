#include <stdio.h>
#include <math.h>


struct point 
{
	double x;
	double y;
};



struct triangle 
{
	struct point a;
	struct point b;
	struct point c;
};


double distance (struct point a, struct point b);
double radius (struct triangle t);


double distance (struct point a, struct point b)
{
	double p;
	double o;
	p = (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
	o = sqrt(p);
	return o;
}

double radius (struct triangle t)
{
	double a;
	double p;
	double r;
	
	a = 0.5*fabs((t.b.x - t.a.x)*(t.c.y - t.a.y) -
       		 (t.c.x - t.a.x)*(t.b.y - t.a.y));
	
	p = distance(t.a, t.b) + distance(t.b, t.c) + distance(t.c, t.a);

	r = 2*a/p;
	
	return r;	
}

int main(void)
{
	struct triangle t = (struct triangle){{2., 2.}, {-2., 1.}, {0., -3.}};
	double r = radius(t);
	printf("radius = %f\n", r);	
	return 0;
}



