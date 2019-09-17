#include <math.h>
#include <time.h>
#include <GL/glut.h>
int xcentre, ycentre;
void circle(int,int);
int count=0, arrx[30], arry[30],r=45;
void window()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2f(x+xcentre,y+ycentre);
	glEnd();
	glFlush();
}
	
void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
    glClear(GL_COLOR_BUFFER_BIT);
}

void mouse(int btn, int state, int x, int y)
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
	   		glColor3f(1,0,0);
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
    glutCreateWindow("Circle Generation using Mid-Point Theorem Implentation");
    glutDisplayFunc(window);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
