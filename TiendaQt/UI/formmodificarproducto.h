#ifndef FORMMODIFICARPRODUCTO_H
#define FORMMODIFICARPRODUCTO_H

#include <QDialog>

using namespace std;

namespace Ui {
class formModificarProducto;
}

class formModificarProducto : public QDialog
{
    Q_OBJECT

public:
    explicit formModificarProducto(QWidget *parent = nullptr);
    ~formModificarProducto();
    string on_nombreProductoModificado_editingFinished();

    void on_existenciasProductoModificado_editingFinished();

    int obtenerExistenciasModificado();

    void on_idProductoModificado_editingFinished();

    int obtenerIdModificado();


private slots:

private:
    Ui::formModificarProducto *ui;
};

#endif // FORMMODIFICARPRODUCTO_H
