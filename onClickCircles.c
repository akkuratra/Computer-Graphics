#include <math.h>
#include <time.h>
#include <GL/glut.h>
int count;
void delay(float ms){
    clock_t goal = ms + clock();
    while(goal>clock());
}

void init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}

void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		circles(x,y);
		++count;
	}
}


void circles(int x, int y)
{
	
	if(count%3==0)
	{
		glColor3f(1,0,0);
	}
	else if(count%3==1)
	{
		glColor3f(0,1,0);
	}
	else
	{
		glColor3f(0,0,1);
	}
	
    glBegin(GL_POLYGON);
	for(double i =0; i < 2* 3.14; i+=3.14/30)
	{
		glVertex2f(x +cos(i) *50, (480-y)+sin(i)*50);
	}
	glEnd();
	glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(300,300);
    glutCreateWindow("On click circles");
    init();
    glutDisplayFunc(circles);
    glutMouseFunc(mouse);
    
    glutMainLoop();
    return 0;
}
