#include <math.h>
#include <time.h>
#include <GL/glut.h>
void Bresenham(int,int, int, int);
void drawText(char *);
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1,1,1,1);
	glFlush();
}
int count=0, arrx[50], arry[50];
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
    y = 480-y;
  	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        arrx[count]=x;
        arry[count]=y;
        count++;
    }
    if(count%2==0)
    {
    	if(arrx[count-2]<arrx[count-1] && arry[count-2]<arry[count-1])
    	{
    		Bresenham(arrx[count-2], arry[count-2], arrx[count-1], arry[count-1]);
    	}
    	else if(arrx[count-2]>arrx[count-1] && arry[count-2]>arry[count-1])
    	{
    		Bresenham(arrx[count-1], arry[count-1], arrx[count-2], arry[count-2]);   		
 		}  
 		else if(arrx[count-2]<arrx[count-1] && arry[count-2]>arry[count-1])
 		{
 			Bresenham(arrx[count-2], arry[count-2], arrx[count-1], arry[count-1]);
    	}
    	else
    	{
    		Bresenham(arrx[count-1], arry[count-1], arrx[count-2], arry[count-2]);
    		
    	}
 	} 
}
void drawText(char *string)
{
	char *c;
	glRasterPos2f(400.0, 5.0);
	for(c=string; *c!='\0';c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}
void Bresenham(int x1, int y1, int x2, int y2)
{
			
	char buffer[15];
	int p,p2;
    int dx=(x2-x1);
    int dy=(y2-y1);
    int x,y;
    x=x1;
    y=y1;
    double m=(double)dy/(double)dx;
    p=(2*dy)-dx;
    p2=-(2*dx)-dy;
    if(m>1)
    {
    		do
	    	{
		   		if(p<=0)
		   		{
		   			glLineWidth(3);
		   			glPointSize(2);
			   		glBegin(GL_POINTS);
			   		glColor3f(1,0,0);
			   		glVertex2f(x,y); 	
			    	glEnd();
			    	glFlush();
  		 			p=p+2*dx;	
  		 		}
  		 		else
	 			{
 			  		glLineWidth(3);
			  	  	glPointSize(2);
			   		glBegin(GL_POINTS);
			   		glColor3f(1,0,0);
			   		glVertex2f(x,y); 	
			   	  	glEnd();
			    	glFlush();
			   		p=p-2*dy+2*dx;
			   		x++;
			   	}
			   	y++;
			}while(y<y2);

	}
	else if(m>0)
    {
    		do 
	    	{
		   		if(p<=0)
		   		{
		   			glLineWidth(3);
		   			glPointSize(2);
			   		glBegin(GL_POINTS);
			   		glColor3f(1,0,0);
			   		glVertex2f(x,y); 	
			    	glEnd();
			    	glFlush();
  		 			p=p+2*dy;	
  		 		}
  		 		else
	 			{
 			  		glLineWidth(3);
			  	  	glPointSize(2);
			   		glBegin(GL_POINTS);
			   		glColor3f(1,0,0);
			   		glVertex2f(x,y); 	
			   	  	glEnd();
			    	glFlush();
			   		p=p+2*dy-2*dx;
			   		y++;
			   	}
			   	x++;
			}while(x<x2);

	}
	else if(m<-1)
	{
			x=x2;
			y=y2;
	    	do
	    	{
		   		if(p2<=0)
		   		{
		   			glLineWidth(3);
		   			glPointSize(2);
			   		glBegin(GL_POINTS);
			   		glColor3f(1,0,0);
			   		glVertex2f(x,y); 	
			    	glEnd();
			    	glFlush();
  		 			p2=p2-2*dx;	
  		 		}
  		 		else
	 			{
 			  		glLineWidth(3);
			  	  	glPointSize(2);
			   		glBegin(GL_POINTS);
			   		glColor3f(1,0,0);
			   		glVertex2f(x,y); 	
			   	  	glEnd();
			    	glFlush();
			   		p2=p2-2*dy-2*dx;
			   		x++;
			   	}
			   	y--;
			}while(y>y2);

	}
	else
	{
		x=x2;
		y=y2;
			do 
	    	{
		   		if(p2<=0)
		   		{
		   			glLineWidth(3);
		   			glPointSize(2);
			   		glBegin(GL_POINTS);
			   		glColor3f(1,0,0);
			   		glVertex2f(x,y); 	
			    	glEnd();
			    	glFlush();
  		 			p2=p2-2*dy;	
  		 			x--;
  		 		}
  		 		else
	 			{
 			  		glLineWidth(3);
			  	  	glPointSize(2);
			   		glBegin(GL_POINTS);
			   		glColor3f(1,0,0);
			   		glVertex2f(x,y); 	
			   	  	glEnd();
			    	glFlush();
			   		p2=p2-2*dy-2*dx;
			   		x--;
			   		y++;
			   	}
			   	
			}while(x<x1);
	}
	glColor3f(1,0,0);
	gcvt(m, 5, buffer);
	drawText(buffer);
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Bresenham Implementation");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
