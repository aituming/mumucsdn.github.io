#include <GL/glut.h>
#include <stdlib.h>

static GLfloat spin = 0;
void init(void)
{
    glClearColor(0, 0, 0, 0); // 设置清除背景颜色
    glShadeModel(GL_FLAT); //设置着色模式
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // 用当前缓冲区清除值,
    glPushMatrix();                       //将当前矩阵压入栈
    glRotatef(spin, 0, 0, 1);           //旋转角度
    glColor3f(1, 1, 0);
    glRectf(-25, -25, 25, 25);
    glPopMatrix();
    glutSwapBuffers(); //交换双缓冲区指针
}

void spinDisplay(void)
{
    spin = (spin + 2.0) >= 360 ? spin-358 : spin + 2.0;
    glutPostRedisplay();
}

void spinRightDisplay(void)
{
    spin = (spin - 2.0) < 0 ?  spin + 360 :  spin -2.0;
    glutPostRedisplay();
}
//
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50, 50, -50, 50, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
    switch(button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(spinDisplay);

        }
        break;

    case GLUT_MIDDLE_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
        }
        break;
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(spinRightDisplay);
        }
    default:
        break;
    }
}

int main(int argc ,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
