#include<GL/Glut.h> 
#include<cstdlib>
#include<cstdio>
#include<cmath>
float xStart, xEnd, yStart, yEnd;

void display(void)
{
	float dy, dx, step, x, y, k ;
	dx = xEnd - xStart;
	dy = yEnd - yStart;

	if (abs(dx) > abs(dy))
	{
		step = abs(dx);
	}
	else
		step = abs(dy);

	float xIncrement = dx / step;
	float yIncrement = dy / step;

	x = xStart;
	y = yStart;
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();

	for (k = 1; k <= step; k++ )
	{
		x = x + xIncrement;
		y = y + yIncrement;

		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
	}


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
	printf_s("Input xStart, yStart, xEnd, yEnd:\n");
	scanf_s("%f %f %f %f", &xStart, &yStart, &xEnd, &yEnd);
	

	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);//sets the width and height of the window in pixels
	glutInitWindowPosition(10, 10);//sets the position of the window in pixels from top left corner 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//creates a single frame buffer of RGB color capacity.
	glutCreateWindow("DDA Line Algorithm");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}