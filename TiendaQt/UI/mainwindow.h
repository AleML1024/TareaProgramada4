#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../libTienda/tienda.h"
#include "../libTienda/producto.h"
#include "../libTienda/excepcionRespuestaInvalida.h"
#include "QMessageBox"
#include "formagregarproducto.h"
#include "formmodificarproducto.h"
#include "formeliminarproducto.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    string on_nombreTienda_editingFinished();

    string on_direccionITienda_editingFinished();

    string on_direccionFTienda_editingFinished();

    string on_numeroTienda_editingFinished();

    void on_CrearTienda_clicked();

    void on_AgregarProducto_clicked();

    void on_ModificarProducto_clicked();

    void on_EliminarProducto_clicked();

    void on_Guardar_clicked();

    void on_Cargar_clicked();

    void on_ConsultarProducto_clicked();

private:
    Ui::MainWindow *ui;
    Tienda* tienda;
};
#endif // MAINWINDOW_H
