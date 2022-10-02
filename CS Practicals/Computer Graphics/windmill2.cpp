#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

const double PI = 3.141592654;

int frameNumber = 0;

void drawWindmill()
{
	int i;
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.1f, 0);
	glVertex2f(0.1f, 0);
	glVertex2f(0.05f, 3);
	glVertex2f(-0.05f, 3);
	glEnd();
	glTranslatef(0, 3, 0);
	glRotated(frameNumber * (180.0 / 46), 0, 0, 1);
	glColor3f(1.0f, 1.0f, 1.0f);
	for (i = 0; i < 3; i++)
	{
		glRotated(120, 0, 0, 1);
		glBegin(GL_POLYGON);
		glVertex2f(0, 0);
		glVertex2f(0.5f, 0.1f);
		glVertex2f(1.5f, 0);
		glVertex2f(0.5f, -0.1f);
		glEnd();
	}
}

void display()
{

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glPushMatrix();
	glTranslated(3.2, 0.2, 0);
	glScaled(0.7, 0.7, 1);
	drawWindmill();
	glPopMatrix();

	glutSwapBuffers();
}

void doFrame(int v)
{
	frameNumber++;
	glutPostRedisplay();
	glutTimerFunc(30, doFrame, 0);
}

void init()
{
	glClearColor(0.53f, 0.81f, 0.92f, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 7, -1, 4, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(700, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Kshitij's Windmill");

	init();

	glutDisplayFunc(display);
	glutTimerFunc(200, doFrame, 0);

	glutMainLoop();
	return 0;
}