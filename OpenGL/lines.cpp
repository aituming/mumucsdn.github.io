#include <GL/glut.h>

#define drawOneLine(x1, y1, x2, y2) glBegin(GL_LINES); \
    glVertex2f((x1), (y1)); glVertex2f((x2), (y2)); glEnd();

void init()
{
    glClearColor(0, 0, 0, 0);
    glShadeModel(GL_FLAT);
}

void display()
{
    int i;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);

    glEnable(GL_LINE_STIPPLE);

    //画点线
    glLineStipple(1, 0x0101); //定义点画线模式
    drawOneLine(50, 125, 150, 125);
    glLineStipple(1, 0x00FF);
    drawOneLine(150, 125, 250, 125);
    glLineStipple(1, 0x1C47);
    drawOneLine(250, 125, 350, 125);

    glLineWidth(5.0);
    glLineStipple(1, 0x0101);
    drawOneLine(50, 100, 150, 100);
    glLineStipple(1, 0x00FF);
    drawOneLine(150, 100, 250, 100);
    glLineStipple(1, 0x1C47);
    drawOneLine(250, 100, 350, 100);
    glLineWidth(1);

    glLineStipple(1, 0x1C47);
    glBegin(GL_LINE_STRIP);  //画一系列的连接直线
    for (i = 0; i < 7; i++)
    {
        glVertex2f(50 + ((GLfloat) i * 50), 75);
    }
    glEnd();

    for (i = 0; i < 6; i++)
    {
        drawOneLine(50 + ((GLfloat) i * 50), 50, 50 + ((GLfloat) (i+1) * 50), 50);
    }

    glLineStipple(5, 0x1C47);
    drawOneLine(50, 25, 350, 25);

    glDisable(GL_LINE_STIPPLE);
    glFlush();

}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, (GLdouble) w, 0, (GLdouble) h);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 150);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}


