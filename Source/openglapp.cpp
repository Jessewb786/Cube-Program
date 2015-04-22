#include "openglapp.h"
#include "ui_openglapp.h"

OpenGLApp::OpenGLApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OpenGLApp)
{
    ui->setupUi(this);

}

OpenGLApp::~OpenGLApp()
{
    delete ui;
}

void OpenGLApp::on_transButton_clicked()
{
    emit sendTranslation(ui->xTrans->value(), ui->yTrans->value(), ui->zTrans->value());
    ui->xTrans->setValue(0.0);
    ui->yTrans->setValue(0.0);
    ui->zTrans->setValue(0.0);
}

void OpenGLApp::on_scaleButton_clicked()
{
    emit sendScale(ui->xScale->value(), ui->yScale->value(), ui->zScale->value());
    ui->xScale->setValue(1.0);
    ui->yScale->setValue(1.0);
    ui->zScale->setValue(1.0);
}

void OpenGLApp::on_rotButton_clicked()
{
    emit sendRotation(ui->xRot->value(), ui->yRot->value(), ui->zRot->value(), ui->xPos->value(), ui->yPos->value(), ui->zPos->value(), ui->arbitrary->isChecked());
    ui->xRot->setValue(0);
    ui->yRot->setValue(0);
    ui->zRot->setValue(0);
    ui->xPos->setValue(0.0);
    ui->yPos->setValue(0.0);
    ui->zPos->setValue(0.0);

}

void OpenGLApp::on_mirrorButton_clicked()
{
    emit sendMirror(ui->xMirror->isChecked(), ui->yMirror->isChecked(), ui->zMirror->isChecked());
}

void OpenGLApp::on_shearButton_clicked()
{
    emit sendShear(ui->xShear->isChecked(), ui->yShear->isChecked(), ui->zShear->isChecked());
}

void OpenGLApp::on_zScale_valueChanged(double arg1)
{
    if(ui->checkScale->isChecked()){
        ui->xScale->setValue(arg1);
        ui->yScale->setValue(arg1);
    }
}

void OpenGLApp::on_yScale_valueChanged(double arg1)
{
    if(ui->checkScale->isChecked()){
        ui->xScale->setValue(arg1);
        ui->zScale->setValue(arg1);
    }
}

void OpenGLApp::on_xScale_valueChanged(double arg1)
{
    if(ui->checkScale->isChecked()){
        ui->yScale->setValue(arg1);
        ui->zScale->setValue(arg1);
    }
}

void OpenGLApp::on_arbitrary_clicked(bool checked)
{
    if(checked){
        ui->xPos->setEnabled(true);
        ui->yPos->setEnabled(true);
        ui->zPos->setEnabled(true);
    }else{
        ui->xPos->setEnabled(false);
        ui->yPos->setEnabled(false);
        ui->zPos->setEnabled(false);
    }
}
