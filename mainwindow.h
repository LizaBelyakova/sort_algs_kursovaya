#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
               // void vgeneration();
    void tablestart();
    void filereading(string filename);
    void calculate(string sort, double* results);
    void addresults(int column, double* results);

    void on_fileread_clicked();
    void on_calculate_clicked();
    void on_save_res_clicked();
    void on_vgeneration_clicked();
    void on_show_graphics_clicked();
};
#endif // MAINWINDOW_H
