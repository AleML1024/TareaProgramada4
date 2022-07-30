#ifndef FORMAGREGARPRODUCTO_H
#define FORMAGREGARPRODUCTO_H

#include <QDialog>

using namespace std;

namespace Ui {
class formAgregarProducto;
}

class formAgregarProducto : public QDialog
{
    Q_OBJECT

public:
    explicit formAgregarProducto(QWidget *parent = nullptr);
    ~formAgregarProducto();

    string on_nombreProducto_editingFinished();

    void on_existenciasProducto_editingFinished();

    int obtenerExistencias();

    void agregarProductoALista(int id, string nombreP, int existencias);
private slots:


private:
    Ui::formAgregarProducto *ui;
};

#endif // FORMAGREGARPRODUCTO_H
