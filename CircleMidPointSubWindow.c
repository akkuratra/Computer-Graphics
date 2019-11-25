#include <math.h>
#include <time.h>
#include <GL/glut.h>
int xcentre, ycentre;
float rx,ry,xc=300,yc=300;
void circle(int,int);
int count=0, arrx[30], arry[30],r=45;
void mainWindow()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1,1,0.5,0);
	glFlush();
}
void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2f(x+xcentre,y+ycentre);
	glEnd();
	glFlush();
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
	
void init()
{
	glClearColor(0.5,0.5,0.5,0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,640,0,480);
	glClear(GL_COLOR_BUFFER_BIT);
}
void init2()
{
	glClearColor(1,0.5,0.5,0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,640,0,480);
	glClear(GL_COLOR_BUFFER_BIT);
}
void ellipse(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1, 0.0, 0.0);
	glPointSize(2);
	ellipseMidpoint();
	glFlush ();
}

void mouse(int btn, int state, int x, int y)
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.5,0.5,0.5,0);
	glFlush();
	glColor3f(0.0,0.3,0.7);
	glBegin(GL_POLYGON);
	glVertex2i(50, 50);
	glVertex2i(100, 50);
	glVertex2i(100, 100);   
	glVertex2i(50, 100); 
	glEnd();
	glFlush();     
	//ellipse();
}
void mouse2(int btn, int state, int x, int y)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	y = 480-y;
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP)
	{
	arrx[count]=x;
	arry[count]=y;
	circle(arrx[count], arry[count]);
	 count++;      
	}    
}

void circle(int xc, int yc)
{		
	float p=1-r;
	int x=0;
	int y=r;
	xcentre=xc;
	ycentre=yc;
	do
	{
	if(p<0)
	{
	p=p+(2*x)+3;	
	x++;
	}
	else
 	{
	p=p+2*(x+1)-2*(y)+3;
	x++;
	y--;
  	}
  	glLineWidth(3);
    	glPointSize(3);
	glBegin(GL_POINTS);
	glColor3f(0,0,0);
	plot(x,y);
	plot(x,-y);
	plot(-x, y);
	plot(-x,-y);
	plot(y, x);
	plot(-y, x);
	plot(y,-x);
	plot(-y, -x);
	glEnd();
    	glFlush();
}while(y>=x);	  
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(200,200);
	int win=glutCreateWindow("Circle Generation using Mid-Point Theorem Implentation");
	glutDisplayFunc(mainWindow);
	//Upper Subwindow
	int sub=glutCreateSubWindow(win, 0, 0, 640, 240);
	init();
	glutSetWindow(sub);
	//glutDisplayFunc(window);
	glutMouseFunc(mouse);	
	//lower subwindow
	int sub2=glutCreateSubWindow(win, 0, 240, 640, 480);
	init2();
	glutSetWindow(sub2);
	glutMouseFunc(mouse2);
        glutMainLoop();
        return 0;
}
