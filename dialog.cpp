//окно с графиками
#include "dialog.h"
#include "ui_dialog.h"
#include <QVector>
#include <Vector>
#include <vector>
#include <String>
#include <iostream>
#include <fstream>

using std::vector;
QVector <double> values = {700, 800,900,1000,2000,3000,5000,6500,7000,10000,13000};
QVector <double> QSresults(11);
QVector <double> BSresults(11);
QVector <double> SSresults(11);
QVector <double> ISresults(11);
QVector <double> HSresults(11);
std::string help;


void filereading(){
 double num = 0;
 std::string h;
 std::fstream in("res.txt");
   if (in) {

  std::getline(in,h);
      help = h;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            in >> num;
            if(i==0){
             QSresults[j] = num;
            }
            else if(i==1){
             BSresults[j] = num;
            }
            else if(i==2){
             SSresults[j] = num;
            }
            else if(i==3){
             ISresults[j] = num;
            }
            else if(i==4) {
             HSresults[j] = num;
            }
        }
    }
}
in.close();
}

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
ui->setupUi(this);

    this->setStyleSheet("background-color: black;");
    this->setAutoFillBackground(true);
  //  std::cout<<help[1];
    QBrush brus(QColor(0,0,0));
    ui->widget->setBackground(brus);
    ui->widget->setInteraction(QCP::iRangeZoom,true);
    ui->widget->setInteraction(QCP::iRangeDrag,true);
    //дизайн оси Х
    ui->widget->xAxis->setRange(values.first(), values.back());
    ui->widget->xAxis->setBasePen(QPen(Qt::white,1));
    ui->widget->xAxis->setTickPen(QPen(Qt::white,1));
    ui->widget->xAxis->setSubTickPen (QPen (Qt :: white, 1));
    ui->widget->xAxis->setTickLabelColor(Qt::white);
    ui->widget->xAxis->setLabel("n");
    ui->widget->xAxis->setLabelColor(Qt::white);
    ui->widget->xAxis->setUpperEnding (QCPLineEnding :: esSpikeArrow);
    //дизайн оси У
    ui->widget->yAxis->setBasePen(QPen(Qt::white,1));
    ui->widget->yAxis->setTickPen(QPen(Qt::white,1));
    ui->widget->yAxis->setSubTickPen (QPen (Qt :: white, 1));
    ui->widget->yAxis->setTickLabelColor(Qt::white);
    ui->widget->yAxis->setLabel("Время выполнения алгоритма");
    ui->widget->yAxis->setLabelColor(Qt::white);
    ui->widget->yAxis->setRange(0,1000);
    ui->widget->yAxis->setUpperEnding (QCPLineEnding :: esSpikeArrow);
    //добавление графиков
    QPen pen;
    pen.setWidth(2);
    filereading();

   // ui->label_6->setText(QString::fromStdString(help));

    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->addGraph();


    pen.setColor(Qt::magenta);

    ui->widget->graph(0)->addData(values, QSresults);
    ui->widget->graph(0)->setPen(pen);
    if(help[0]=='0'){
    ui->widget->graph(0)->setVisible(false);
    }
    ui->widget->replot();

   //ui->widget->addGraph();
    pen.setColor(Qt::blue);

    ui->widget->graph(1)->addData(values, BSresults);
     ui->widget->graph(1)->setPen(pen);
     if(help[2]=='0'){
      ui->widget->graph(1)->setVisible(false);
     }
     ui->widget->replot();


    //ui->widget->addGraph();
    pen.setColor(Qt::green);
    ui->widget->graph(2)->setPen(pen);
    ui->widget->graph(2)->addData(values, SSresults);
    if(help[4]=='0'){
       ui->widget->graph(2)->setVisible(false);
    }
    ui->widget->replot();

    //ui->widget->addGraph();
    pen.setColor(Qt::cyan);
    ui->widget->graph(3)->setPen(pen);
    ui->widget->graph(3)->addData(values, ISresults);
    if(help[6]=='0'){
       ui->widget->graph(3)->setVisible(false);
    }
    ui->widget->replot();

    //ui->widget->addGraph();
    pen.setColor(Qt::white);
    ui->widget->graph(4)->setPen(pen);
    ui->widget->graph(4)->addData(values, HSresults);

    if(help[8]=='0'){
       ui->widget->graph(4)->setVisible(false);
    }
    ui->widget->replot();

 //   ui->widget->replot();
    ui->widget->update();
}

Dialog::~Dialog()
{
    delete ui;
}

