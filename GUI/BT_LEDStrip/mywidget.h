#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QtSerialPort>
#include <QTimer>
#include <colorpicker.h>

namespace Ui {
class myWidget;
}

//serial port
const QSerialPort::BaudRate BAUDTATE = QSerialPort::Baud115200;
const QSerialPort::DataBits DATABITS = QSerialPort::Data8;
const QSerialPort::Parity   PARITY   = QSerialPort::NoParity;
const QSerialPort::StopBits STOPBITS = QSerialPort::OneStop;
const QSerialPort::FlowControl FLOWCONTROL = QSerialPort::NoFlowControl;

//LED SET command
const char CMD_SET_OFF[]="SetLED Off";
const char CMD_SET_DIRECT[]="SetLED DIRECT";
const char CMD_SET_STARRY[]="SetLED STARRY";
const char CMD_SET_XMAS[]="SetLED XMAS";
const char CMD_SET_PARTY[]="SetLED PARTY";

//LED GET command
const char CMD_GET_STATE[]="GetLEDState\r\n";

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

    void readData(void);

    void on_LEDmodeSelection_currentIndexChanged(int index);

    void updateColor(QColor color);

private:
    Ui::myWidget *ui;
    QSerialPort *serial;
    QByteArray serialResponse;
    QByteArray responseCommandQueue;


private:
    void fillPortsInfo(void);
    void openSerialPort(void);
    void closeSerialPort(void);




};




#endif // MYWIDGET_H
