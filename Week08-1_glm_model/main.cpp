#include <GL/glut.h>
#include "glm.h" ///把source.zip裡的 glm.h放在同目錄中
GLMmodel *pmodel = NULL; ///模型的指標，一開始NULL空的
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(pmodel==NULL)
    {
        pmodel=glmReadOBJ("F-16.obj"); ///檔名照你的檔名打
        glmUnitize(pmodel); ///縮放成Unit單位大小(-1...+1)
    }
    glmDraw(pmodel,GLM_SMOOTH | GLM_MATERIAL);

    ///glutSolidTeapot(0.3);
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week08");

    glutDisplayFunc(display);
    glutMainLoop();
}
