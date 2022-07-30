#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <sstream>
#include <fstream>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->tienda = new Tienda();
}

MainWindow::~MainWindow()
{
    delete ui;
}



string MainWindow::on_nombreTienda_editingFinished()
{
    return  this->ui->nombreTienda->text().toStdString();

}


string MainWindow::on_direccionITienda_editingFinished()
{
     return  this->ui->direccionITienda->text().toStdString();
}


string MainWindow::on_direccionFTienda_editingFinished()
{
    return  this->ui->direccionFTienda->text().toStdString();
}


string MainWindow::on_numeroTienda_editingFinished()
{
    return  this->ui->numeroTienda->text().toStdString();
}


void MainWindow::on_CrearTienda_clicked()
{
   string nombreT = on_nombreTienda_editingFinished();
   string direccionI = on_direccionITienda_editingFinished();
   string direccionF = on_direccionFTienda_editingFinished();
   string telefono = on_numeroTienda_editingFinished();

   tienda = new Tienda(nombreT, direccionI, direccionF, telefono);

   QMessageBox *msgbox = new QMessageBox(this);
   msgbox->setWindowTitle("Aviso");
   msgbox->setText("Se ha creado su tienda con éxito");
   msgbox->open();
}


void MainWindow::on_AgregarProducto_clicked()
{
    formAgregarProducto formAgregarProducto(this);
    int result = formAgregarProducto.exec();

    if (result == QDialog::Accepted) {
        string nombreP = formAgregarProducto.on_nombreProducto_editingFinished();
        int existencias = formAgregarProducto.obtenerExistencias();
        int id = tienda->ObtenerCantidadDeProductos() +1;
        try {
                    Producto *producto = new Producto(id, nombreP, existencias);
                    tienda->AgregarProducto(producto);

                    QString nombrePLista = QString::fromStdString(nombreP);

                    QListWidgetItem *itemNuevo = new QListWidgetItem(nombrePLista);
                    itemNuevo->setData(1 , id);
                    this->ui->listaProductos->addItem(itemNuevo);

                    QMessageBox *msgbox = new QMessageBox(this);
                    msgbox->setWindowTitle("Aviso");
                    msgbox->setText("Se ha agregado su producto con éxito");
                    msgbox->open();
                }
                catch (ExcepcionRespuestaInvalida &e) {
                    QMessageBox *msgbox = new QMessageBox(this);
                    msgbox->setWindowTitle("ERROR");
                    msgbox->setText("Datos de producto inválidos");
                    msgbox->open();
                }
    }else{
        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("ERROR");
        msgbox->setText("No aceptó");
        msgbox->open();
    }



}

void MainWindow::on_ConsultarProducto_clicked()
{
    QListWidgetItem *itemSeleccionado = this->ui->listaProductos->currentItem();
    formAgregarProducto formAgregarProducto {this};
        if (itemSeleccionado == nullptr)
        {
            // no hay ítem seleccionado
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Aviso");
            msgbox->setText("No hay ítem seleccionado");
            msgbox->open();
        }
        else
        {
            QString stringID = itemSeleccionado->data(1).toString();

            int idProducto = stringID.toInt();

            string nombre = tienda->ObtenerNombreProducto(idProducto);
            int existencias = tienda->ObtenerExistenciasProducto(idProducto);

            formAgregarProducto.agregarProductoALista(idProducto, nombre, existencias);

            int result = formAgregarProducto.exec();

        }
}



void MainWindow::on_ModificarProducto_clicked()
{
    formModificarProducto formModificarProducto(this);
    int result = formModificarProducto.exec();

    if (result == QDialog::Accepted) {
        int idAModificar = formModificarProducto.obtenerIdModificado();
        string nombrePModificado = formModificarProducto.on_nombreProductoModificado_editingFinished();
        int existenciasModificado = formModificarProducto.obtenerExistenciasModificado();

        if(idAModificar > tienda->ObtenerCantidadDeProductos())
        {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("ERROR");
            msgbox->setText("El producto no existe");
            msgbox->open();
        }else{
            tienda->ModificarProducto(idAModificar, nombrePModificado, existenciasModificado);
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Aviso");
            msgbox->setText("Se ha modificado su producto con éxito");
            msgbox->open();
        }
    }
}


void MainWindow::on_EliminarProducto_clicked()
{
    formEliminarProducto formEliminarProducto(this);
    int result = formEliminarProducto.exec();

    if (result == QDialog::Accepted) {
        int idAEliminar = formEliminarProducto.obtenerIdAEliminar();

        if(idAEliminar > tienda->ObtenerCantidadDeProductos())
        {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("ERROR");
            msgbox->setText("El producto no existe");
            msgbox->open();
        }else{
            tienda->EliminarProducto(idAEliminar);
            QListWidgetItem *itemSeleccionado = this->ui->listaProductos->currentItem();
            delete itemSeleccionado;
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Aviso");
            msgbox->setText("Se ha eliminado su producto con éxito");
            msgbox->open();
        }
    }
}


void MainWindow::on_Guardar_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
               "Guardar archivo de datos", "",
               tr("Archivo de datos (*.dat);;All Files (*)"));


       if (fileName != "")
       {
           // Convertir QString a std::string
           std::string name = fileName.toStdString();
           ofstream ofs(name, ifstream::out);

           if(!ofs.is_open())
           {
               QMessageBox *msgbox = new QMessageBox(this);
               msgbox->setWindowTitle("Error al guardar");
               msgbox->setText("Error escribiendo el archivo");
               msgbox->open();
               return;
           }
           tienda->GuardarArchivo(&ofs);
           ofs.close();
       }
}


void MainWindow::on_Cargar_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
           "Abrir archivo de datos", "",
           tr("Archivo de datos (*.dat);;All Files (*)"));

       if (fileName != "")
       {
           std::string name = fileName.toStdString();

           std::ifstream archivoSalida;

           archivoSalida.open(name, std::ios::in|std::ios::binary);

           if (!archivoSalida.is_open()) {
               QMessageBox *msgbox = new QMessageBox(this);
               msgbox->setWindowTitle("Error");
               msgbox->setText("Error recuperando los datos del archivo");
               msgbox->open();
               return;
           }
           delete tienda;

           Tienda *tienda = new Tienda();
           tienda->CargarArchivo(&archivoSalida, tienda);
           archivoSalida.close();
           QString nombreUI = QString::fromStdString(tienda->ObtenerNombreT());
           this->ui->nombreTienda->setText(nombreUI);
           QString direccionIUI = QString::fromStdString(tienda->ObtenerDireccionI());
           this->ui->direccionITienda->setText(direccionIUI);
           QString direccionFUI = QString::fromStdString(tienda->ObtenerDireccionF());
           this->ui->direccionFTienda->setText(direccionFUI);
           QString numeroUI = QString::fromStdString(tienda->ObtenerTelefono());
           this->ui->numeroTienda->setText(numeroUI);

           this->ui->listaProductos->clear();

           formAgregarProducto formAgregarProducto;
           for(int i = 0; i < tienda->ObtenerCantidadDeProductos(); i++)
           {
               int idTemp = i+1;
               string nombre = tienda->ObtenerNombreProducto(idTemp);
               int existencias = tienda->ObtenerExistenciasProducto(idTemp);

               QString nombrePLista = QString::fromStdString(nombre);

               QListWidgetItem *itemNuevo = new QListWidgetItem(nombrePLista);
               itemNuevo->setData(1 , idTemp);
               this->ui->listaProductos->addItem(itemNuevo);
               formAgregarProducto.agregarProductoALista(idTemp, nombre, existencias);
           }

       }
}




