#include <math.h>
#include <time.h>
#include <GL/glut.h>
int count=0, arrx[30], arry[30];
void floodFill4(int, int, float*, float*);
void draw();
void displayPoints()
{
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,1,0);
	glPointSize(5);
	glBegin(GL_POINTS);
	for(int i=0; i<30;i++)
	{
		glVertex2f(arrx[i], arry[i]);
	}
	glEnd();
	glFlush();
}		
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1,1,1,1);
	glFlush();
}
void init()
{
	glClearColor(0.5,0.5,0.5,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,640,0,480);
	glClear(GL_COLOR_BUFFER_BIT);
}
void mouse(int btn, int state, int x, int y)
{
	//glClear(GL_COLOR_BUFFER_BIT);
	y = 480-y;
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
	arrx[count]=x;
	arry[count]=y;
	count++;
	displayPoints();
	}
	if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	{
	float newcolor[]={1.0, 0.0, 0.0};
	float oldcolor[]={1.0,1.0,0.0};
	floodFill4(x, y, newcolor, oldcolor);
	}    
}
void key(unsigned char key, int x, int y)
{
	if(key==32)//space bar
	{
		draw();
	}
}
void floodFill4(int x, int y, float* newcolor, float* oldcolor)
{
	float interior[3];
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, interior);
	if(interior[0]==oldcolor[0] && interior[1]==oldcolor[1] && interior[2]==oldcolor[2])
	{
	glColor3f(newcolor[0],newcolor[1],newcolor[2]);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
	floodFill4(x,y+1,newcolor, oldcolor);
	floodFill4(x-1,y,newcolor, oldcolor);
	floodFill4(x+1,y,newcolor, oldcolor);
	floodFill4(x,y-1,newcolor, oldcolor);
	}
}
void draw()
{
	glLineWidth(3);
	glPointSize(2);
	glColor4f(1,1,0,1);
	glBegin(GL_POLYGON);
	for(int i=0;i<30;i++)
	{
	while(arrx[i]!='\0')
    	{
	glVertex2d(arrx[i],arry[i]);
	i++;
    	}
	}	  
	glEnd();
	glFlush();
    	
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(200,200);
	glutCreateWindow("BoundaryFill");
	//glutDisplayFunc(DDA);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(key);
	init();
	glutMainLoop();
	return 0;
}
