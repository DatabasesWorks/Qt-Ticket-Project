#ifndef CPTICKET_H
#define CPTICKET_H

#include <QString>
#include <QImage>

class QCodePrinter;

/**
 * @brief The CPTicket class
 *  ________________________
 * |   PARQUEADERO la 5TA   |
 * |    CRA. 13 NRO 5-37    |
 * |     CEL. 3157545014    |
 * |                        |
 * |     Recibo No: 199     |
 * |  ____________________  |
 * | |||||||||||||||||||||| |
 * |                        |
 * | TARIFA: CARROS NORMAL  |
 * | ENTRADA: 2019-09-04    |
 * | SALIDA: 2019-10-23     |
 * | TIEMPO: 2 Horas 30 Min |
 * | CAJERO: ADMIN          |
 * | www.sap-parking.com    |
 * |                        |
 * |     TOTAL: $25,000     |
 * |________________________|
 */
class CPTicket
{
public:
    enum CodeType
    {
        BARCODE,
        QRCODE
    };

    CPTicket();
    ~CPTicket();
    QImage print() const;

    void setCodeType(int type)
    {
        mCodeType = type;
    }

    int codeType() const
    {
        return mCodeType;
    }

    void setCabecera(const QString &cabecera)
    {
        mCabecera = cabecera;
    }

    void setReciboNo(int num)
    {
        mReciboNo = num;
    }

    void setPlaca(const QString &placa)
    {
        mPlaca = placa;
    }

    void setTarifa(const QString &tarifa)
    {
        mTarifa = tarifa;
    }

    void setFechaEntrada(const QString &entrada)
    {
        mFechaEntrada = entrada;
    }

    void setFechaSalida(const QString &salida)
    {
        mFechaSalida = salida;
    }

    void setTiempo(const QString &tiempo)
    {
        mTiempo = tiempo;
    }

    void setCajeroNombre(const QString &cajero)
    {
        mCajeroNombre = cajero;
    }

    void setPieDePagina(const QString &pie)
    {
        mPieDePagina = pie;
    }

    void setTotal(double total)
    {
        mTotal = total;
    }

    QString cabecera() const
    {
        return mCabecera;
    }

    int reciboNo() const
    {
        return mReciboNo;
    }

    QString placa() const
    {
        return mPlaca;
    }

    QString tarifa() const
    {
        return mTarifa;
    }

    QString fechaEntrada() const
    {
        return mFechaEntrada;
    }

    QString fechaSalida() const
    {
        return mFechaSalida;
    }

    QString tiempo() const
    {
        return mTiempo;
    }

    QString cajeroNombre() const
    {
        return mCajeroNombre;
    }

    QString pieDePagina() const
    {
        return mPieDePagina;
    }

    double total() const
    {
        return mTotal;
    }
private:
    int mCodeType;
    QString mCabecera;
    int mReciboNo;
    QString mPlaca;
    QString mTarifa;
    QString mFechaEntrada;
    QString mFechaSalida;
    QString mTiempo;
    QString mCajeroNombre;
    QString mPieDePagina;
    double mTotal;
    QCodePrinter *mPrinter;
};

#endif // CPTICKET_H
