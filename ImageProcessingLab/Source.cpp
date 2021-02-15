#include<GL/Glut.h> 
#include<cstdio>

void myinit(void)
{

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // multiply the current matrix by identity matrix
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

float xStart, xEnd, yStart, yEnd;
// any x i.e 1>=a>=0.5 is rounded to 1
int Round(float a)
{
    if (a - int(a) >= 0.5)
        return int(a) + 1;
    else
        return int(a);
}

void bresenhamLineDrawing()
{
    float yDiff = yEnd - yStart;
    float xDiff = xEnd - xStart;


    float p0 = 2 * (yDiff)-xDiff;

    float x = xStart;
    float y = yStart;

    while ((x != xEnd + 1) && (y != yEnd + 1))
    {
        glBegin(GL_POINTS); // writes pixels on the frame buffer with the current drawing color
        glVertex2i(Round(x), Round(y));//sets vertex
        glEnd();
        if (p0 < 0)
        {
            x = x + 1;
            y = y;
            p0 = p0 + 2 * (yDiff);
        }
        else
        {
            x = x + 1;
            y = y + 1;
            p0 = 2 * (yDiff)-2 * (xDiff);
        }
    
    }

    glutPostRedisplay();
}

void display(void)
{
    bresenhamLineDrawing();// calls programmer defined function(drawline)
    glFlush(); // flushes the frame buffer to the screen
}

int main(int argc, char** argv)
{
    printf_s("Input xStart, yStart, xEnd, yEnd:\n");
    scanf_s("%f %f %f %f", &xStart, &yStart, &xEnd, &yEnd);
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);//sets the width and height of the window in pixels
    glutInitWindowPosition(10, 10);//sets the position of the window in pixels from top left corner 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//creates a single frame buffer of RGB color capacity.
    glutCreateWindow("Bresenham Line Drawing");//creates the window as specified by the user as above.
    myinit();
    glutDisplayFunc(display);//links the display event with the display event handler(display)
    glutIdleFunc(bresenhamLineDrawing);
    glutMainLoop();//loops the current event
}
