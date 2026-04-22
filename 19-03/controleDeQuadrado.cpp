/*
1 - Um quadrado se move pela tela com as teclas W, A, S, D.
- Ao clicar com o botão esquerdo do mouse, o quadrado muda de cor para vermelho.
- Ao clicar com o botão direito do mouse, o quadrado volta à cor original (azul).
- Utilize GLUT_LEFT_BUTTON e GLUT_RIGHT_BUTTON e glutPostRedisplay();
2 - Comente as funções keyboard() e mouse() explicando o que cada linha faz.
3 - Adapte o código para que:
- O quadrado aumente de tamanho com a tecla +.
- Diminua com a tecla -.
4 - Faça com que o clique do botão do meio reinicie a posição do quadrado para (0,0). */

#include <GL/glut.h>
#include <stdlib.h>

//Quadrado
float jogadorX = 0.0f;
float jogadorY = 0.0f;
float velocidade = 0.05f; 
float escala = 1.0f;

float r = 0.3f, g = 0.3f, b = 0.5f;

void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    glTranslatef(jogadorX, jogadorY, 0.0f); 
    
    glScalef(escala, escala, 1.0f);

    glBegin(GL_QUADS);
        glColor3f(r, g, b); 
        glVertex2f(-0.1f, -0.1f);
        glVertex2f( 0.1f, -0.1f);
        glVertex2f( 0.1f,  0.1f);
        glVertex2f(-0.1f,  0.1f);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

//Teclado

void tecladoEspecial(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            jogadorY += velocidade;
            break;
        case GLUT_KEY_DOWN:
            jogadorY -= velocidade; 
            break;
        case GLUT_KEY_LEFT:
            jogadorX -= velocidade;
            break;
        case GLUT_KEY_RIGHT:
            jogadorX += velocidade; 
            break;
    }

    glutPostRedisplay();
}

void clickmouse(int button, int state, int x, int y){
    if (state == GLUT_DOWN){
        switch (button){
            case GLUT_LEFT_BUTTON:
                r = 0.5f;
                g = 0.3f;
                b = 0.3f;
            break;
            case GLUT_RIGHT_BUTTON:
                r = 0.3f;
                g = 0.3f;
                b = 0.5f;
            break;
            case GLUT_MIDDLE_BUTTON:
                jogadorX = 0.0f;
                jogadorY = 0.0f;
            break;
        }
    }

    glutPostRedisplay();
} 

void tecladoNormal(unsigned char key, int x, int y) {
    //ESC
    if (key == 27) { 
        exit(0); 
    }
    if (key == '+'){
        escala += 0.3f;
    }
    if (key == '-'){
        escala -= 0.3f;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Controle de quadrado - Teclado e Mouse");
    
    glutDisplayFunc(desenhaCena);
    
    glutSpecialFunc(tecladoEspecial);
    glutKeyboardFunc(tecladoNormal);
    glutMouseFunc(clickmouse);
    
    glutMainLoop();
    return 0;
}
