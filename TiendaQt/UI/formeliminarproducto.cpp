#include "formeliminarproducto.h"
#include "ui_formeliminarproducto.h"
#include <QMessageBox>

formEliminarProducto::formEliminarProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formEliminarProducto)
{
    ui->setupUi(this);
}

formEliminarProducto::~formEliminarProducto()
{
    delete ui;
}

void formEliminarProducto::on_idProductoAEliminar_editingFinished()
{
    QString stringId = this->ui->idProductoAEliminar->text();
       bool ok = false;
       stringId.toInt(&ok);

       if (!ok)
       {
           QMessageBox* msgbox = new QMessageBox(this);
           msgbox->setWindowTitle("Respuesta Invalida!");
           msgbox->setText("La ID solo puede ser un número enteros");
           msgbox->open();
           return this->ui->idProductoAEliminar->setText("");
       }

}

int formEliminarProducto::obtenerIdAEliminar()
{
    int idAEliminar = this->ui->idProductoAEliminar->text().toInt();
    return idAEliminar;
}

