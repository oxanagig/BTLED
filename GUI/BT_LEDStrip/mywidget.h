#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <qmessagebox.h>

namespace Ui {
class myWidget;
}


const QSerialPort::BaudRate BAUDTATE = QSerialPort::Baud115200;
const QSerialPort::DataBits DATABITS = QSerialPort::Data8;
const QSerialPort::Parity   PARITY   = QSerialPort::NoParity;
const QSerialPort::StopBits STOPBITS = QSerialPort::OneStop;
const QSerialPort::FlowControl FLOWCONTROL = QSerialPort::NoFlowControl;


class myWidget : public QWidget
{
    Q_OBJECT

public:
    explicit myWidget(QWidget *parent = 0);
    ~myWidget();

private slots:
    void on_refreshButton_clicked();

    void on_connectButton_clicked();

    void on_disconnectButton_clicked();

private:
    Ui::myWidget *ui;
    QSerialPort *serial;


private:
    void fillPortsInfo(void);
    void openSerialPort(void);
    void closeSerialPort(void);


};




#endif // MYWIDGET_H
