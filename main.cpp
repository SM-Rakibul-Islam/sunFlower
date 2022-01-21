#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

const double PI = 3.141592654;

void circle(int xCen, int yCen, int radX, int radY)
{
    float theta;
    int i;

    glBegin(GL_POLYGON);
    for(i=0; i<360; i++)
    {
        theta=i*PI/180;
        glVertex2f(xCen + radX * cos(theta), yCen + radY * sin(theta));
    }
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //Stand
    glColor3ub (39, 139, 10);
    glLineWidth(10.0f);
    glBegin(GL_LINES);
    glVertex2f(150, 150);
    glVertex2f(150, -200);
    glEnd();

    //Flower
    int i;

    for(i = 0; i <= 360; i+=15)
    {
        glColor3ub(0, 0, 0);
        glPushMatrix();
        glTranslated(150, 150, 0);
        glRotated(i, 0, 0, 1);
        circle(0, 50, 15, 80);
        glColor3ub(255, 255, 0);
        circle(0, 50, 14, 79);
        glPopMatrix();
    }

    //Middle part
    glColor3ub(201, 126, 7);
    circle(150, 150, 40, 40);

    glColor3ub(147, 103, 37);
    circle(150, 150, 25, 25);

    glColor3ub(195, 136, 15);
    circle(150, 150, 20, 20);



    glFlush();
}

void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 400, -100, 400);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_MULTISAMPLE);
    glutInitWindowSize (700, 700);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("181-15-10869 S. M. Rakibul Islam G (Sunflower)");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
