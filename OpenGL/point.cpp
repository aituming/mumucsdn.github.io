#include <GL/glut.h>
#include <stdlib.h>

void init(void)
{
    glClearColor(0, 1, 0, 0);
//    glShadeModel(GL_FLAT);

}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    GLfloat pf[2] = {1.0, 1.0};
    glBegin(GL_POINTS);
        glColor3b(1, 0, 0);
        glVertex2f(0, 0);
        glColor3b(1, 0, 0);
        glVertex2d(1, 0);
        glColor3b(1, 0, 0);
        glVertex2i(0, 1);
        glColor3b(1, 0, 0);
        glVertex2fv(pf);
    glEnd();
//
    glBegin(GL_LINES);
        glColor3b(1, 1, 0);
        glVertex2d(1, 0);
        glVertex2d(0, 1);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3b(1, 1, 1);
        glVertex2f(0, 0);
        glVertex2f(-1, 0);
        glVertex2d(-1, -1);
    glEnd();

    glFlush();
}


int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutMainLoop( );

    return 0;
}
