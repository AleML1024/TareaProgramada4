#include "formagregarproducto.h"
#include "ui_formagregarproducto.h"
#include <QMessageBox>

formAgregarProducto::formAgregarProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formAgregarProducto)
{
    ui->setupUi(this);
}

formAgregarProducto::~formAgregarProducto()
{
    delete ui;
}

string formAgregarProducto::on_nombreProducto_editingFinished()
{
    return  this->ui->nombreProducto->text().toStdString();
}


void formAgregarProducto::on_existenciasProducto_editingFinished()
{
    QString stringExistencias = this->ui->existenciasProducto->text();
       bool ok = false;
       stringExistencias.toInt(&ok);

       if (!ok)
       {
           QMessageBox* msgbox = new QMessageBox(this);
           msgbox->setWindowTitle("Respuesta Invalida!");
           msgbox->setText("Las existencias solo pueden ser números enteros");
           msgbox->open();
           return this->ui->existenciasProducto->setText("");
       }
}

int formAgregarProducto::obtenerExistencias()
{
    int existencias = this->ui->existenciasProducto->text().toInt();
    return existencias;
}

void formAgregarProducto::agregarProductoALista(int id, string nombreP, int existencias)
{
       QString stringID = QString::number(id);
       this->ui->idProducto->setText(stringID);

        QString stringNombre = QString::fromStdString(nombreP);
        this->ui->nombreProducto->setText(stringNombre);

        QString stringExistencias = QString::number(existencias);
        this->ui->existenciasProducto->setText(stringExistencias);
}

