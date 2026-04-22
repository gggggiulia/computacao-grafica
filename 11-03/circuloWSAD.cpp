/*Círculo controlável pelas teclas w, s, a, d.
Bibliotecas para o Mac.*/
#include <GLUT/glut.h>
#include <OpenGL/gl.h>

float x = 0.0f;
float y = 0.0f;
float step = 0.1f;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(x, y, 0.0f);
    glColor3f(1.0f, 0.2f, 0.5f); //Rosa!
    glutSolidSphere(0.2, 25, 25);

    glutSwapBuffers();
}

void keyboard(unsigned char tecla, int xMouse, int yMouse){
    switch(tecla){
        case 'w':
            y += step;
            break;
        case 's':
            y -= step;
            break;
        case 'a':
            x -= step;
            break;
        case 'd':
            x += step;
            break;
    }
    glutPostRedisplay(); //Redesenhar a cada uso das teclas
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    int mode = GLUT_DOUBLE | GLUT_RGB;
    glutInitDisplayMode(mode);
    glutInitWindowSize(500,500);
    glutCreateWindow("Círculo para o teclado");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
