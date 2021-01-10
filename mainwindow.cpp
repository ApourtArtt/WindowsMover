#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

int MainWindow::x = 0;
int MainWindow::y = 0;
QString MainWindow::winName = "";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

BOOL CALLBACK MainWindow::foreach_window(HWND hWnd, LPARAM lparam)
{
    int length = GetWindowTextLength(hWnd);
    char* buffer = new char[length + 1];
    GetWindowTextA(hWnd, buffer, length + 1);
    QString windowTitle(buffer);
    if (windowTitle == winName)
    {
        SetWindowPos(hWnd, HWND_TOP, x, y, 0, 0, SWP_NOSIZE | SWP_NOOWNERZORDER);
    }
}

void MainWindow::on_MB_SET_clicked()
{
    x = ui->LE_X->text().toInt();
    y = ui->LE_Y->text().toInt();
    winName = ui->LE_WIN_NAME->text();

    EnumWindows(foreach_window, NULL);
}
