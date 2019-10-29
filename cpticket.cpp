#include "cpticket.h"
#include "qcodeprinter.h"
#include <QPainter>

CPTicket::CPTicket()
{
    mCodeType = BARCODE;
    mCabecera = "";
    mReciboNo = 0;
    mPlaca = "";
    mTarifa = "";
    mFechaEntrada = "";
    mFechaSalida = "";
    mTiempo = "";
    mCajeroNombre = "";
    mPieDePagina = "";
    mTotal = 0.0;
    mPrinter = new QCodePrinter;
}

CPTicket::~CPTicket()
{
    delete mPrinter;
}

QImage CPTicket::print() const
{
    // declaramos el lienzo
    QImage img(QSize(300, 400), QImage::Format_ARGB32);

    // declaramos el pintador
    QPainter painter(&img);

    // declaramos la fuente
    QFont font("arial", 14);
    QFontMetricsF fm(font);
    painter.setFont(font);
    painter.fillRect(0, 0, img.width(), img.height(), Qt::white);

    // pintamos la cabecera
    QStringList cabeceraLineas = mCabecera.split("\n");
    const int nLineas = cabeceraLineas.size();
    const int inc = int(fm.height());
    int y = inc;
    for (int iL = 0; iL < nLineas; ++iL)
    {
        QString linea = cabeceraLineas.at(iL);
        const int len = int(fm.width(linea));
        painter.drawText((img.width() - len)/2, y, cabeceraLineas.at(iL));
        y += inc;
    }

    // pintamos el número de recibo
    QString reciboNo = QString("Recibo No: %1").arg(mReciboNo);
    painter.drawText(int(img.width() - fm.width(reciboNo))/2, y, reciboNo);

    // pintamos el código en una imagen
    QImage codeImage;
    if (mCodeType == BARCODE)
    {
        codeImage = mPrinter->printBarcode(mPlaca, QSize(200, 100), Qt::black);
    }
    else if (mCodeType == QRCODE)
    {
        codeImage = mPrinter->printQrcode(mPlaca, QSize(100, 100), Qt::black);
    }

    // pintamos la imagen del código
    painter.drawPixmap(QPoint((img.width() - codeImage.width())/2, y += 5), QPixmap::fromImage(codeImage));

    // pintamos la tarifa
    QString tarifa = QString("TARIFA: %1").arg(mTarifa);
    painter.drawText(int(img.width() - fm.width(tarifa))/2, y += (codeImage.height() + int(fm.height())), tarifa);

    // pintamos la entrada
    QString entrada = QString("ENTRADA: %1").arg(mFechaEntrada);
    painter.drawText(int(img.width() - fm.width(entrada))/2, y += int(fm.height()), entrada);

    // pintamos la salida
    QString salida = QString("SALIDA: %1").arg(mFechaSalida);
    painter.drawText(int(img.width() - fm.width(salida))/2, y += int(fm.height()), salida);

    // pintamos el tiempo
    QString tiempo = QString("TIEMPO: %1").arg(mTiempo);
    painter.drawText(int(img.width() - fm.width(tiempo))/2, y += int(fm.height()), tiempo);

    // pintamos el nombre del cajero
    QString cajero = QString("CAJERO: %1").arg(mCajeroNombre);
    painter.drawText(int(img.width() - fm.width(cajero))/2, y += int(fm.height()), cajero);

    // pintamos el pié de página
    painter.drawText(int(img.width() - fm.width(mPieDePagina))/2, y += int(fm.height()), mPieDePagina);

    // pintamos el total
    QString total = QString("TOTAL: %1").arg(mTotal);
    painter.drawText(int(img.width() - fm.width(total))/2, y += int(fm.height()), total);

    return img;
}
