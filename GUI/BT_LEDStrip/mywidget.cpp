#include "mywidget.h"
#include "ui_mywidget.h"

#include <QtSerialPort/QSerialPortInfo>
#include <qstring.h>

QT_USE_NAMESPACE

myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);
    /*Initialization*/
    serial = new QSerialPort(this);
    ui->disconnectButton->setEnabled(false);
    ui->connectionStatus->setText("Disconnected");

    Color_List_Widget c;
    fillPortsInfo();


}

myWidget::~myWidget()
{
    delete ui;
}


void myWidget::fillPortsInfo()
{
    ui->serialPortListBox->clear();
    static const QString blankString = QObject::tr("N/A");
    QString description;
    QString manufacturer;
    QString serialNumber;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        QStringList list;
        description = info.description();
        manufacturer = info.manufacturer();
        serialNumber = info.serialNumber();
        list << info.portName()
             << (!description.isEmpty() ? description : blankString)
             << (!manufacturer.isEmpty() ? manufacturer : blankString)
             << (!serialNumber.isEmpty() ? serialNumber : blankString)
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : blankString)
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString);

        ui->serialPortListBox->addItem(list.first(), list);
    }
}

void myWidget::openSerialPort()
{
    QString string = ui->serialPortListBox->currentText();
    serial->setPortName(string);
    serial->setBaudRate(BAUDTATE);
    serial->setDataBits(DATABITS);
    serial->setParity(PARITY);
    serial->setStopBits(STOPBITS);
    serial->setFlowControl(FLOWCONTROL);
    if (serial->open(QIODevice::ReadWrite)) {
            ui->connectButton->setEnabled(false);
            ui->disconnectButton->setEnabled(true);
            ui->refreshButton->setEnabled(false);
            ui->connectionStatus->setText("Connected");
    } else {
        QMessageBox::critical(this, tr("Oops, Error TT"), serial->errorString());
    }
}

void myWidget::closeSerialPort()
{
    serial->close();
    ui->connectButton->setEnabled(true);
    ui->disconnectButton->setEnabled(false);
    ui->refreshButton->setEnabled(true);
    ui->connectionStatus->setText("Disconnected");
}

void myWidget::on_refreshButton_clicked()
{
    fillPortsInfo();
}

void myWidget::on_connectButton_clicked()
{
    openSerialPort();
}

void myWidget::on_disconnectButton_clicked()
{
    closeSerialPort();
}
