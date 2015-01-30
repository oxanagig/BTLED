#include "mywidget.h"
#include "ui_mywidget.h"

QT_USE_NAMESPACE

myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);

    /*Initialization*/
    serial = new QSerialPort(this);
    QByteArray serialResponse;

    ui->disconnectButton->setEnabled(false);
    ui->connectionStatus->setText("Disconnected");

    ui->LEDmodeSelection->addItem("Turn off LED",CMD_SET_OFF);
    ui->LEDmodeSelection->addItem("Set direct color mode",CMD_SET_DIRECT);
    ui->LEDmodeSelection->addItem("Set starry mode",CMD_SET_STARRY);
    ui->LEDmodeSelection->addItem("Set xmas mode",CMD_SET_XMAS);
    ui->LEDmodeSelection->addItem("Set party mode",CMD_SET_PARTY);
    ui->LEDmodeSelection->setEnabled(false);

    fillPortsInfo();
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));

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
            ui->LEDmodeSelection->setEnabled(true);
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
    ui->LEDmodeSelection->setEnabled(false);
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

void myWidget::on_LEDmodeSelection_currentIndexChanged(int index)
{
 /*   switch(index){
    case 0:ui->serialWriteCounter->setText(tr("%1").arg(serial->write(CMD_SET_OFF)));break;
    case 1:ui->serialWriteCounter->setText(tr("%1").arg(serial->write(CMD_SET_DIRECT)));break;
    case 2:ui->serialWriteCounter->setText(tr("%1").arg(serial->write(CMD_SET_STARRY)));break;
    case 3:ui->serialWriteCounter->setText(tr("%1").arg(serial->write(CMD_SET_XMAS)));break;
    case 4:ui->serialWriteCounter->setText(tr("%1").arg(serial->write(CMD_SET_PARTY)));break;
    default:
        break;
    }
    serialResponse = "DONE!\r\n";
    */

    serial->write("\r\n");
}

void myWidget::readData()
{
    QByteArray data = serial->readAll();
    if(serialResponse.isEmpty() != true){
        if(data!=serialResponse)
        {
            QMessageBox::critical(this,"Oops, error. TT","Failed");
        }
        serialResponse.clear();
    }
}
