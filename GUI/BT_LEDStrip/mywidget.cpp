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
    QByteArray responseCommandQueue("");
    QByteArray serialResponse("");

    ui->disconnectButton->setEnabled(false);
    ui->connectionStatus->setText("Disconnected");

    ui->LEDmodeSelection->addItem("Turn off LED",CMD_SET_OFF);
    ui->LEDmodeSelection->addItem("Set direct color mode",CMD_SET_DIRECT);
    ui->LEDmodeSelection->addItem("Set starry mode",CMD_SET_STARRY);
    ui->LEDmodeSelection->addItem("Set xmas mode",CMD_SET_XMAS);
    ui->LEDmodeSelection->addItem("Set party mode",CMD_SET_PARTY);
    ui->LEDmodeSelection->setEnabled(false);

    ui->colorPicker->init();
    ui->colorPicker->setEnabled(false);

    fillPortsInfo();
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(ui->colorPicker, SIGNAL(colorChanged(QColor)), this, SLOT(updateColor(QColor)));

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
    switch(index){
    case 0:ui->serialWriteCounter->setText(tr("%1").arg(serial->write(CMD_SET_OFF)));ui->colorPicker->setEnabled(false);break;
    case 1:ui->serialWriteCounter->setText(tr("%1").arg(serial->write(CMD_SET_DIRECT)));ui->colorPicker->setEnabled(true);break;
    case 2:ui->serialWriteCounter->setText(tr("%1").arg(serial->write(CMD_SET_STARRY)));ui->colorPicker->setEnabled(false);break;
    case 3:ui->serialWriteCounter->setText(tr("%1").arg(serial->write(CMD_SET_XMAS)));ui->colorPicker->setEnabled(false);break;
    case 4:ui->serialWriteCounter->setText(tr("%1").arg(serial->write(CMD_SET_PARTY)));ui->colorPicker->setEnabled(false);break;
    default:
        break;
    }
    serial->write("\r\n");
    responseCommandQueue = "DONE!\r\n";
}

void myWidget::readData()
{
    if(responseCommandQueue.isEmpty()==true){
        //we don't expect any data.
        return;
    }

    serialResponse.append(serial->readAll());

    if(serialResponse.endsWith('\n')){
        if(serialResponse!=responseCommandQueue){
            //QMessageBox::critical(this,"error","failed");
        }
        responseCommandQueue.clear();
        serialResponse.clear();
    }
}

void myWidget::updateColor(QColor color)
{
    QByteArray colorCommand;

    colorCommand.append('C');

    // RED
    if(color.red()/16<10){
        colorCommand.append(color.red()/16+0x30);
    }
    else{
        colorCommand.append(color.red()/16+0x41-0x0A);
    }

    if(color.red()%16<10){
        colorCommand.append(color.red()%16+0x30);
    }
    else{
        colorCommand.append(color.red()%16+0x41-0x0A);
    }

    //GREEN
    if(color.green()/16<10){
        colorCommand.append(color.green()/16+0x30);
    }
    else{
        colorCommand.append(color.green()/16+0x41-0x0A);
    }

    if(color.green()%16<10){
        colorCommand.append(color.green()%16+0x30);
    }
    else{
        colorCommand.append(color.green()%16+0x41-0x0A);
    }

    //BLUE
    if(color.blue()/16<10){
        colorCommand.append(color.blue()/16+0x30);
    }
    else{
        colorCommand.append(color.blue()/16+0x41-0x0A);
    }

    if(color.blue()%16<10){
        colorCommand.append(color.blue()%16+0x30);
    }
    else{
        colorCommand.append(color.blue()%16+0x41-0x0A);
    }

    colorCommand.append("\r\n");
    serial->write(colorCommand);

    ui->redSlider->setValue(color.red());
    ui->greenSlider->setValue(color.green());
    ui->blueSlider->setValue(color.blue());

}
