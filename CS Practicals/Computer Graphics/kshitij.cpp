#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

#define Point pair<float, float>
#define x first
#define y second

float CPW = 100;
float CPH = 100;

int factorial(int n)
{
	if (n <= 1)
		return (1);
	else
		n = n * factorial(n - 1);
	return n;
}

float binomial_coff(float n, float k)
{
	float ans;
	ans = factorial(n) / (factorial(k) * factorial(n - k));
	return ans;
}

// void drawDot(Point p)
// {
// 	glColor3f(0.0, 0.0, 0.0);
// 	glBegin(GL_POINTS);
// 	glVertex2f(p.x, p.y);
// 	glEnd();
// }

void drawLine(Point p1, Point p2)
{
	glBegin(GL_LINES);
	glVertex2f(p1.x, p1.y);
	glVertex2f(p2.x, p2.y);
	glEnd();
}

void drawBezier(vector<Point> PT)
{
	for (int i = 0; i < 4; i++)
	{
		PT[i].y = CPH - PT[i].y;
		// drawDot(PT[i]);
	}
	Point p1 = PT[0];
	for (double t = 0.0; t <= 1.0; t += 0.02)
	{
		Point p2 = {0, 0};
		for (int i = 0; i < 4; i++)
		{
			p2.x = p2.x + binomial_coff((float)3, (float)i) * pow(t, (double)i) * pow((1 - t), (3 - i)) * PT[i].x;
			p2.y = p2.y + binomial_coff((float)3, (float)i) * pow(t, (double)i) * pow((1 - t), (3 - i)) * PT[i].y;
		}
		drawLine(p1, p2);
		p1 = p2;
	}
}

void writeName()
{
	drawBezier({{10, 20}, {36, 20}, {63, 20}, {90, 20}});
	drawBezier({{13, 20}, {13, 30}, {13, 40}, {13, 50}});
	drawBezier({{13, 20}, {13, 8}, {18, 8}, {35, 20}});
	drawBezier({{35, 20}, {35, 30}, {35, 40}, {35, 50}});
	drawBezier({{35, 30}, {26, 38}, {19, 25}, {23, 23}});
	drawBezier({{23, 23}, {32, 27}, {17, 32}, {17, 38}});
	drawBezier({{17, 38}, {18, 47}, {32, 47}, {29, 40}});
	drawBezier({{29, 40}, {26, 36}, {25, 45}, {27, 50}});
	drawBezier({{39, 20}, {39, 30}, {39, 40}, {39, 50}});
	drawBezier({{39, 20}, {39, 8}, {44, 8}, {61, 20}});
	drawBezier({{61, 20}, {61, 30}, {61, 40}, {61, 50}});
	drawBezier({{61, 30}, {43, 30}, {43, 35}, {48, 50}});
	drawBezier({{87, 20}, {87, 30}, {87, 40}, {87, 50}});
	drawBezier({{87, 30}, {83, 30}, {79, 30}, {78, 30}});
	drawBezier({{78, 30}, {90, 43}, {73, 50}, {67, 30}});
}

void myDisplay()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, CPW, 0.0, CPH);
	glPointSize(3);

	glPushMatrix();
	glLineWidth(3);
	glColor4f(1.0, 0.0, 0.0, 0.3);
	glTranslatef(-1.0, -1.0, 0);
	writeName();
	glPopMatrix();

	glPushMatrix();
	glLineWidth(5);
	glColor3f(0.0, 0.0, 1.0);
	writeName();
	glPopMatrix();

	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 500);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Kshitij's Name");
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}