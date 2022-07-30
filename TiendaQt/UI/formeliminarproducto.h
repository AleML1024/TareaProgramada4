#ifndef FORMELIMINARPRODUCTO_H
#define FORMELIMINARPRODUCTO_H

#include <QDialog>

namespace Ui {
class formEliminarProducto;
}

class formEliminarProducto : public QDialog
{
    Q_OBJECT

public:
    explicit formEliminarProducto(QWidget *parent = nullptr);
    ~formEliminarProducto();
    void on_idProductoAEliminar_editingFinished();

    int obtenerIdAEliminar();

private slots:


private:
    Ui::formEliminarProducto *ui;
};

#endif // FORMELIMINARPRODUCTO_H
