///Week12-4_keyboard_mouse
///要能用 mouse 來移動，同時要解決存讀檔的問題
#include <stdio.h>///要檔案的Input/Output
#include <GL/glut.h>
float teapotX=0,teapotY=0;
FILE * fout = NULL; ///step02-1
FILE * fin = NULL; ///step02-1
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX,teapotY,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    teapotX=(x-150)/150.0;
    teapotY=(150-y)/150.0;
    if(state==GLUT_DOWN)
    {///如果mouse按下去
        if(fout==NULL) fout = fopen("file4.txt","w");
        fprintf(fout,"%f %f\n",teapotX,teapotY);
    }
    display();
}
void keyboard(unsigned char key, int x,int y)
{
    if(fin==NULL)
    {
        fclose(fout);///step02-2
        fin = fopen("file4.txt","r");///step02-2
    }
    fscanf(fin,"%f%f",&teapotX,&teapotY);
    display();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///step02-2
    glutMouseFunc(mouse);///step02-1

    glutMainLoop();
}
