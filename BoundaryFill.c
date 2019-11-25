#include <math.h>
#include <time.h>
#include <GL/glut.h>
int count=0, arrx[30], arry[30];
void boundaryFill4(int, int, float*, float*);
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
	 float fcolor[]={1.0, 0.0, 0.0};
	float bcolor[]={1.0,1.0,1.0};
	boundaryFill4(x, y, fcolor, bcolor);
	}
}
void key(unsigned char key, int x, int y)
{
	if(key==32)//space bar
	{
		draw();
	}
}
void boundaryFill4(int x, int y, float* fillcolor, float* boundary)
{
	float interior[3];
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, interior);
	if((interior[0]!=boundary[0] || interior[1]!=boundary[1] || interior[2]!=boundary[2] )&& (interior[0]!=fillcolor[0] || interior[1]!=fillcolor[1] || interior[2]!=fillcolor[2]))
	{
	glColor3f(fillcolor[0],fillcolor[1],fillcolor[2]);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
	boundaryFill4(x,y+1,fillcolor, boundary);
	boundaryFill4(x-1,y,fillcolor, boundary);
	boundaryFill4(x+1,y,fillcolor, boundary);
	boundaryFill4(x,y-1,fillcolor, boundary);
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
	glutCreateWindow("On click polygon formation and colour fill");
	 //glutDisplayFunc(DDA);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(key);
	init();
	glutMainLoop();
	return 0;
}
