#include<GL/glut.h>
#include<stdio.h>

float rx,ry,xc=300,yc=300;

void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1, 0.0, 0.0);
	glLineWidth(3);
	glPointSize(2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void drawEllipse(float x, float y)
{
	glBegin(GL_POINTS);
	    glVertex2f(xc+x,yc+y);
	    glVertex2f(xc-x,yc+y);
	    glVertex2f(xc+x,yc-y);
	    glVertex2f(xc-x,yc-y);
	glEnd();
}

void ellipseMidpoint()
{
    float rxSq = rx * rx;
    float rySq = ry * ry;
    float x = 0, y = ry, p;
    float px = 0, py = 2 * rxSq * y;
    drawEllipse(x, y);

    p = rySq - (rxSq * ry) + (0.25 * rxSq);
    while (px < py)
    {
        x++;
        px = px + 2 * rySq;
        if (p < 0)
            p = p + rySq + px;
        else
        {
            y--;
            py = py - 2 * rxSq;
            p = p + rySq + px - py;
        }
        drawEllipse(x, y);
    }

    p = rySq*(x+0.5)*(x+0.5) + rxSq*(y-1)*(y-1) - rxSq*rySq;
    while (y > 0)
    {
        y--;
        py = py - 2 * rxSq;
        if (p > 0)
            p = p + rxSq - py;
        else
        {
            x++;
            px = px + 2 * rySq;
            p = p + rxSq - py + px;
        }
        drawEllipse(x, y);
    }
}

void ellipse(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1, 0.0, 0.0);
	glPointSize(2);
	ellipseMidpoint();
	glFlush ();
}

int main(int args , char** argv)
{
	printf("\nEnter a: ");
	scanf("%f",&rx);
	printf("\nEnter b: ");
	scanf("%f",&ry);
	glutInit(&args, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Ellipse Generation using Mid Point Theorem");
	glutDisplayFunc(ellipse);
	myInit();
	glutMainLoop();
}
