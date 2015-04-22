#include "openglapp.h"
#include "mypanelopengl.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenGLApp w;
    w.setWindowTitle("Jesse's Cube Program");
    w.show();

    return a.exec();
}
