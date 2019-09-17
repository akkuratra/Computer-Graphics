#include <math.h>
#include <time.h>
#include <GL/glut.h>
int count,x,y;
float arrx[20]={150, 300, 450,10, 50,200, 350};
float arry[20]={100, 300, 100,20, 50, 200, 50};
void init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}

void key(unsigned char key, int x, int y)
{
	++count;
   switch ( key )
   {
		case 27: // Escape key
      		glutDestroyWindow (1);
      		break;
   		case 32:// Space bar
   		glClear(GL_COLOR_BUFFER_BIT);
   			for(double i=0;i<=250;i+=0.1)
			{
				glClear(GL_COLOR_BUFFER_BIT);
		   		glColor4f(1,0,0,1);
				glBegin(GL_TRIANGLES);
				glVertex2f(arrx[4]+i,arry[4]);
				glVertex2f(arrx[5]+i,arry[5]);
				glVertex2f(arrx[6]+i,arry[6]);
		   		glEnd();
				glFlush();
   			}
   			for(double i=0;i<=300;i+=0.1)
			{	
				glClear(GL_COLOR_BUFFER_BIT);
		   		glColor4f(1,1,0,1);
				glBegin(GL_TRIANGLES);
				glVertex2f(arrx[0],arry[0]+i);
				glVertex2f(arrx[1],arry[1]+i);
				glVertex2f(arrx[2],arry[2]+i);
		   		glEnd();
				glFlush();
   			}
   			
   			for(double j=0;j<=rand();j+=0.1)
			{
				glClear(GL_COLOR_BUFFER_BIT);
		 		{
					 glBegin(GL_POLYGON);
					for(double i =0; i < 2* 3.14; i+=3.14/30)
					{
						glVertex2f(arrx[3]+j +cos(i) *50, arry[3]+sin(i)*50);
					}
					glEnd();
					glFlush();
				}
			}
			break;
   }
   
}
/*void changeColor()
{
	 glClear(GL_COLOR_BUFFER_BIT);
	 glBegin(GL_TRIANGLES);
	glColor4f(1,1,0,1);
        glVertex2i(150,100);
	glColor4f(1,1,0,1);
        glVertex2i(300,300);
	glColor4f(1,1,0,1);
        glVertex2i(450,100);
    glEnd();
    glFlush();
}*/

void triangle()
{
    glLineWidth(3);
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
	glColor4f(1,0,0,1);
        glVertex2i(arrx[0], arry[0]);
	glColor4f(1,0,0,1);
        glVertex2i(arrx[1], arry[1]);
	glColor4f(1,0,0,1);
        glVertex2i(arrx[2], arry[2]);
    glEnd();
    glBegin(GL_POLYGON);
		for(double i =0; i < 2* 3.14; i+=3.14/30)
		{
			glVertex2f(arrx[3] +cos(i) *50, arry[3]+sin(i)*50);
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
    glutCreateWindow("On key press animation");
    glutDisplayFunc(triangle);
    //glutDisplayFunc(circle);
    glutKeyboardFunc(key);
    init();
    glutMainLoop();
    return 0;
}
