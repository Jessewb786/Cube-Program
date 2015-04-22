#ifndef OPENGLAPP_H
#define OPENGLAPP_H

#include <QMainWindow>

namespace Ui {
class OpenGLApp;
}

class OpenGLApp : public QMainWindow
{
    Q_OBJECT

public:
    explicit OpenGLApp(QWidget *parent = 0);
    ~OpenGLApp();

private:
    Ui::OpenGLApp *ui;

signals:
    void sendTranslation(double, double, double);
    void sendScale(double,double,double);
    void sendRotation(double, double,double,double,double,double,bool);
    void sendMirror(bool,bool,bool);
    void sendShear(bool,bool,bool);

private slots:
    void on_transButton_clicked();
    void on_scaleButton_clicked();
    void on_rotButton_clicked();
    void on_mirrorButton_clicked();
    void on_shearButton_clicked();
    void on_zScale_valueChanged(double);
    void on_yScale_valueChanged(double);
    void on_xScale_valueChanged(double arg1);
    void on_arbitrary_clicked(bool checked);
};

#endif // OPENGLAPP_H
