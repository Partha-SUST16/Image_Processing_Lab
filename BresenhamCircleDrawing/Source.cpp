#include<GL/Glut.h> 
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include <iostream>
int x_center, y_center, r;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x + x_center, y + y_center);
	glEnd();
}
void plotEightWay(int x,int y)
{
	plot(x, y);
	plot(x, -y);
	plot(-x, y);
	plot(-x, -y);
	plot(y, x);
	plot(-y, x);
	plot(y, -x);
	plot(-y, -x);
}

void brasenhamCircle()
{
	int x = 0;
	int y = r;
	float decision = 3 - (2*r);
	plotEightWay(x, y);

	while (y > x)
	{
		if (decision <= 0)
		{
			decision = decision + (4 * x) + 6;
		}
		else
		{
			decision = decision + (4 * x) - (4 * y) + 10;
			y = y - 1;
		}
		x++;
		plotEightWay(x, y);
	}

}

void display(void)
{
	brasenhamCircle();

	glFlush();
}
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); // multiply the current matrix by identity matrix
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char** argv) {
	std::cout << "Enter the center co-ordinates and radius:\n";
	std::cin >> x_center >> y_center >> r;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Bresenham Circle Drawing Algorithm");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}