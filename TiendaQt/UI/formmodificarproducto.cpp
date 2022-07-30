#include "formmodificarproducto.h"
#include "ui_formmodificarproducto.h"
#include <QMessageBox>

formModificarProducto::formModificarProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formModificarProducto)
{
    ui->setupUi(this);
}

formModificarProducto::~formModificarProducto()
{
    delete ui;
}

string formModificarProducto::on_nombreProductoModificado_editingFinished()
{
    return this->ui->nombreProductoModificado->text().toStdString();
}


void formModificarProducto::on_existenciasProductoModificado_editingFinished()
{
    QString stringExistencias = this->ui->existenciasProductoModificado->text();
       bool ok = false;
       stringExistencias.toInt(&ok);

       if (!ok)
       {
           QMessageBox* msgbox = new QMessageBox(this);
           msgbox->setWindowTitle("Respuesta Invalida!");
           msgbox->setText("Las existencias solo pueden ser números enteros");
           msgbox->open();
           return this->ui->existenciasProductoModificado->setText("");
       }
}

int formModificarProducto::obtenerExistenciasModificado()
{
    int existenciasProductoModificado = this->ui->existenciasProductoModificado->text().toInt();
    return existenciasProductoModificado;
}

void formModificarProducto::on_idProductoModificado_editingFinished()
{
    QString stringId = this->ui->idProductoModificado->text();
       bool ok = false;
       stringId.toInt(&ok);

       if (!ok)
       {
           QMessageBox* msgbox = new QMessageBox(this);
           msgbox->setWindowTitle("Respuesta Invalida!");
           msgbox->setText("La ID solo puede ser un número enteros");
           msgbox->open();
           return this->ui->idProductoModificado->setText("");
       }
}

int formModificarProducto::obtenerIdModificado()
{
    int idProductoModificado = this->ui->idProductoModificado->text().toInt();
    return idProductoModificado;
}

