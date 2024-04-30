#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "sorting.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>

using namespace std;
vector <int> v;
vector <int> values = {700, 800, 900,1000,2000,3000,5000,6500,7000,10000,13000};
int n = values.back();
vector <int> help_str(5);

double* QSresults = new double[values.size()];
double* BSresults = new double[values.size()];
double* SSresults = new double[values.size()];
double* ISresults = new double[values.size()];
double* HSresults = new double[values.size()];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table->horizontalHeader()->setStyleSheet("background-color: black;");
    tablestart();
    //  connect(ui->vgeneration,SIGNAL(clicked()),this, SLOT(vgeneration()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_vgeneration_clicked()
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        v.push_back(rand() % 5000);
    }
    ui->message->setText("Вектор успешно сгенерирован!");
}
void MainWindow::filereading(string filename)
{
    ifstream reading(filename);
    if (reading) {
        for (int i = 0; i < n; i++) {
            reading >> v[i];
        }
    }
    else
        reading.close();
}

void MainWindow::tablestart(){
    ui->table->setColumnWidth(0, 80);

    ui->table->setRowCount(values.size());
    for (int i = 0; i < values.size(); i++) {
        ui->table->setItem(i,0, new QTableWidgetItem(QString::number(values[i])));

    }
      //ui->table->resizeColumnsToContents();
      // ui->table->resizeRowsToContents();
}

void MainWindow::calculate(string sort, double* results){
   vector <int> copyv = v;
    if (sort == "quicksort") {
        for (int i = 0; i < values.size(); i++) {
            auto begin = chrono::high_resolution_clock::now();
            quicksort(v, 0, values[i] - 1);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> seconds = end - begin;
            results[i] = (seconds.count() * 1000);
           v = copyv;
        }
    }
    if (sort == "bubblesort") {
        for (int i = 0; i < values.size(); i++) {
            auto begin = chrono::high_resolution_clock::now();
            bubblesort(v, values[i] - 1);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> seconds = end - begin;
            results[i] = (seconds.count() * 1000);
        }
    }
    if (sort == "selectionsort") {
        for (int i = 0; i < values.size(); i++) {
            auto begin = chrono::high_resolution_clock::now();
            selectionsort(v, values[i] - 1);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> seconds = end - begin;
            results[i] = (seconds.count() * 1000);
        }
    }
    if (sort == "insertionsort") {
        for (int i = 0; i < values.size(); i++) {
            auto begin = chrono::high_resolution_clock::now();
            insertionsort(v, values[i] - 1);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> seconds = end - begin;
            results[i] = (seconds.count() * 1000);
          //   v = copyv;
        }
    }
    if (sort == "heapsort") {
        for (int i = 0; i < values.size(); i++) {
            auto begin = chrono::high_resolution_clock::now();
            heapsort(v, values[i] - 1);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> seconds = end - begin;
            results[i] = (seconds.count() * 1000);
            v = copyv;
        }
    }
}
void MainWindow::addresults(int column, double *results){
    for (int i = 0; i < values.size(); i++) {
        ui->table->setItem(i,column, new QTableWidgetItem(QString::number(results[i])));
    }
}

void MainWindow::on_fileread_clicked()
{
    filereading("vector.txt");
    ui->message->setText("Вектор успешно считан!");
}

void MainWindow::on_calculate_clicked(){
    ui->table->clearContents();
    help_str = {0,0,0,0,0};
    for (int i = 0; i < values.size(); i++) {
        ui->table->setItem(i,0, new QTableWidgetItem(QString::number(values[i])));
    }
    ui->message->setText(" ");
    int i = 0;
    if(ui->cb_qs->isChecked()){
        help_str[0] = 1;
        i++;
        calculate("quicksort", QSresults);
        addresults(1,QSresults);
    }

    if(ui->cb_bs->isChecked()){
        help_str[1] = 1;
        i++;
        calculate("bubblesort", BSresults);
        addresults(2,BSresults);
    }
    if(ui->cb_ss->isChecked()){
        help_str[2] = 1;
        i++;
        calculate("selectionsort", SSresults);
        addresults(3,SSresults);
    }
    if(ui->cb_is->isChecked()){
        help_str[3] = 1;
        i++;
        calculate("insertionsort", ISresults);
        addresults(4,ISresults);
    }
    if(ui->cb_hs->isChecked()){
        i++;
        help_str[4] = 1;
        calculate("heapsort", HSresults);
        addresults(5,HSresults);
    }
    if (i == 0){
        ui->message->setText("!Не выбрана ни одна сортировка!");
    }
    else{
        ui->message->setText("Готово!");
    }
}

void MainWindow::on_save_res_clicked()
{
    ofstream res_vectors("res.txt");
    if (res_vectors) {
        for (int i = 0; i < help_str.size(); i++) {
            res_vectors << help_str[i] << ' ';
        }
        res_vectors << endl;
        for (int i = 0; i < values.size(); i++) {
            res_vectors << QSresults[i] << ' ';
        }
        res_vectors << endl;
        for (int i = 0; i < values.size(); i++) {
            res_vectors << BSresults[i] << ' ';
        }
        res_vectors << endl;
        for (int i = 0; i < values.size(); i++) {
            res_vectors << SSresults[i] << ' ';
        }
        res_vectors << endl;
        for (int i = 0; i < values.size(); i++) {
            res_vectors << ISresults[i] << ' ';
        }
        res_vectors << endl;
        for (int i = 0; i < values.size(); i++) {
            res_vectors << HSresults[i] << ' ';
        }
        ui->message->setText("Результаты сохранены в res.txt!");
    }
    else{
        ui->message->setText("Ошибка сохранения.");
    }
    res_vectors.close();
}



void MainWindow::on_show_graphics_clicked(){
    Dialog plots;
    plots.setModal(true);
    plots.exec();
}

