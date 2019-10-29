#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cpticket.h"
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->barcodeRadiobutton->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_printButton_clicked()
{
    CPTicket ticket;

    // asignamos el tipo de código
    if (ui->barcodeRadiobutton->isChecked())
    {
        ticket.setCodeType(CPTicket::BARCODE);
    }
    else
    {
        ticket.setCodeType(CPTicket::QRCODE);
    }

    // asignamos la cabecera
    QString cabecera;
    cabecera += "PARQUEADERO la 5TA\n";
    cabecera += "CRA. 13 NRO 5-37\n";
    cabecera += "CEL. 3157545014\n";
    ticket.setCabecera(cabecera);

    // asignamos el número de recibo
    ticket.setReciboNo(550);

    // asignamos número de placa
    ticket.setPlaca("FFF555");

    // asignamos el nombre de la tarifa
    ticket.setTarifa("CARROS NORMAL");

    // asignamos la fecha de entrada
    QDate entrada = QDate::currentDate();
    QString fechaEntrada = entrada.toString("yyyy-MM-dd");
    ticket.setFechaEntrada(fechaEntrada);

    // asignamos la fecha de salida
    QDate salida = QDate::currentDate();
    QString fechaSalida = salida.toString("yyyy-MM-dd");
    ticket.setFechaSalida(fechaSalida);

    // asignamos tiempo
    ticket.setTiempo("2 Horas 30 Min");

    // asignamos nombre del cajero
    ticket.setCajeroNombre("ADMIN");

    // asignamos pié de página
    ticket.setPieDePagina("www.sap-parking.com");

    // asignamos total
    ticket.setTotal(25000.0);

    // imprimimos el ticket
    ui->label->setPixmap(QPixmap::fromImage(ticket.print()));
}
